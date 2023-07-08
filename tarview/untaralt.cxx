#include <iostream>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <cstring>

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
int read_property(std::ifstream& file, int size) {
    char* buffer = new char[size + 1];
    file.read(buffer, size);
    buffer[size] = '\0';
    int result = oct2dec(std::stoi(buffer));
    delete[] buffer;
    return result;
}

// Extracts a file from a tar archive
void extract_file(std::ifstream& file, const std::string& filename, int filesize) {
    char* content = new char[filesize];
    file.read(content, filesize);
    std::ofstream output(filename, std::ios::binary);
    if (!output) {
        std::cerr << "Could not open file " << filename << " for writing\n";
        delete[] content;
        return;
    }
    output.write(content, filesize);
    output.close();
    delete[] content;
}

// The main untar function
int untar(const std::string& tarfile, const std::string& outdir, int chmod, bool extract) {
    std::ifstream thandle(tarfile, std::ios::binary);
    if (!thandle) {
        std::cerr << "Could not open file " << tarfile << "\n";
        return -1;
    }
    thandle.seekg(0, std::ios::end);
    int TarSize = thandle.tellg();
    int TarSizeEnd = TarSize - 1024;
    thandle.seekg(0, std::ios::beg);
    while (thandle.tellg() < TarSizeEnd) {
        int FileNameSize = read_property(thandle, 100);
        char* FileName = new char[FileNameSize + 1];
        thandle.read(FileName, FileNameSize);
        FileName[FileNameSize] = '\0';
        thandle.seekg(56, std::ios::cur);
        int FileType = read_property(thandle, 1);
        thandle.seekg(-57, std::ios::cur);
        int FileMode = read_property(thandle, 8);
        int OwnerID = read_property(thandle, 8);
        int GroupID = read_property(thandle, 8);
        int FileSize = read_property(thandle, 12);
        int LastEdit = read_property(thandle, 12);
        int Checksum = read_property(thandle, 8);
        FileType = read_property(thandle, 1);
        int LinkedFile = read_property(thandle, 100);
        thandle.seekg(255, std::ios::cur);
        if (extract) {
            if (FileType == 0 || FileType == 7) {
                std::cout << "inflating file " << FileName << "\n";
                extract_file(thandle, FileName, FileSize);
            }
            if (FileType == 5) {
                std::cout << "inflating dir  " << FileName << "\n";
                mkdir(FileName, 0755);
            }
        }
        delete[] FileName;
    }
    thandle.close();
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        untar(argv[1], "./", 0755, true);
    } else if (argc == 3) {
        untar(argv[1], argv[2], 0755, true);
    } else {
        std::cerr << "Usage: " << argv[0] << " tarfile [outdir]\n";
        return -1;
    }
    return 0;
}
