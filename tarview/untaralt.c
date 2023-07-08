#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#define TAR_END_SIZE 1024

// Converts an octal number to a decimal number
int oct2dec(int num) {
    int total = 0, power = 1;
    while(num > 0) {
        total += power * (num % 10);
        num /= 10;
        power *= 8;
    }
    return total;
}

// Reads a property from a file
int read_property(FILE *file, int size) {
    char *buffer = malloc(size + 1);
    if (!buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    fread(buffer, size, 1, file);
    buffer[size] = '\0';
    int result = oct2dec(atoi(buffer));
    free(buffer);
    return result;
}

// Extracts a file from a tar archive
void extract_file(FILE *file, char *filename, int filesize) {
    char *content = malloc(filesize);
    if (!content) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    fread(content, filesize, 1, file);
    FILE *output = fopen(filename, "wb+");
    if (output == NULL) {
        fprintf(stderr, "Could not open file %s for writing: %s\n", filename, strerror(errno));
        free(content);
        return;
    }
    fwrite(content, filesize, 1, output);
    fclose(output);
    free(content);
}

// The main untar function
int untar(char *tarfile, char *outdir, int chmod, bool extract) {
    FILE *thandle = fopen(tarfile, "rb");
    if (thandle == NULL) {
        fprintf(stderr, "Could not open file %s: %s\n", tarfile, strerror(errno));
        return -1;
    }
    fseek(thandle, 0L, SEEK_END);
    int TarSize = ftell(thandle);
    int TarSizeEnd = TarSize - TAR_END_SIZE;
    fseek(thandle, 0L, SEEK_SET);
    while (ftell(thandle) < TarSizeEnd) {
        int FileNameSize = read_property(thandle, 100);
        char *FileName = malloc(FileNameSize + 1);
        fread(FileName, FileNameSize, 1, thandle);
        FileName[FileNameSize] = '\0';
        fseek(thandle, 56L, SEEK_CUR);
        int FileType = read_property(thandle, 1);
        fseek(thandle, -57L, SEEK_CUR);
        int FileMode = read_property(thandle, 8);
        int OwnerID = read_property(thandle, 8);
        int GroupID = read_property(thandle, 8);
        int FileSize = read_property(thandle, 12);
        int LastEdit = read_property(thandle, 12);
        int Checksum = read_property(thandle, 8);
        FileType = read_property(thandle, 1);
        int LinkedFile = read_property(thandle, 100);
        fseek(thandle, 255L, SEEK_CUR);
        if (extract) {
            if (FileType == 0 || FileType == 7) {
                fprintf(stdout, "inflating file %s\n", FileName);
                extract_file(thandle, FileName, FileSize);
            }
            if (FileType == 5) {
                fprintf(stdout, "inflating dir  %s\n", FileName);
                mkdir(FileName, 0755);
            }
        }
        free(FileName);
    }
    fclose(thandle);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        untar(argv[1], "./", 0755, true);
    } else if (argc == 3) {
        untar(argv[1], argv[2], 0755, true);
    } else {
        fprintf(stderr, "Usage: %s tarfile [outdir]\n", argv[0]);
        return -1;
    }
    return 0;
}
