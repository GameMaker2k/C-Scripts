#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    long int start = 0, end = 0, step = 1;
    FILE *fp = NULL;
    time_t tstart, tend;
    double tcheck;

    if(argc >= 2) {
        end = strtol(argv[1], NULL, 0);
    }
    if(argc >= 3) {
        start = strtol(argv[2], NULL, 0);
    }
    if(argc >= 4) {
        step = strtol(argv[3], NULL, 0);
    }
    if(argc >= 5) {
        fp = fopen(argv[4], "w+");
    }

    printf("Executing %s with arguments %ld, %ld, %ld\n", argv[0], end, start, step);
    if(fp) {
        fprintf(fp, "Executing %s with arguments %ld, %ld, %ld\n", argv[0], end, start, step);
        printf("Writing output to file %s\n", argv[4]);
        fprintf(fp, "Writing output to file %s\n", argv[4]);
    }

    if(step == 0) {
        step = 1;
    }

    tstart = time(NULL);

    if(end <= start) {
        for(long int i = start; i >= end; i -= step) {
            printf("%ld\n", i);
            if(fp) {
                fprintf(fp, "%ld\n", i);
            }
        }
    } else {
        for(long int i = start; i <= end; i += step) {
            printf("%ld\n", i);
            if(fp) {
                fprintf(fp, "%ld\n", i);
            }
        }
    }

    tend = time(NULL);
    tcheck = difftime(tend, tstart);

    printf("%s executed in %.0f seconds\n", argv[0], tcheck);
    if(fp) {
        fprintf(fp, "%s executed in %.0f seconds\n", argv[0], tcheck);
        fclose(fp);
    }

    return 0;
}
