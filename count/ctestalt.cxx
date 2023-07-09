#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

int main(int argc, char *argv[]) {
    long int start = 0, end = 0, step = 1;
    std::ofstream file;
    time_t tstart, tend;
    double tcheck;

    if(argc >= 2) {
        end = std::strtol(argv[1], nullptr, 0);
    }
    if(argc >= 3) {
        start = std::strtol(argv[2], nullptr, 0);
    }
    if(argc >= 4) {
        step = std::strtol(argv[3], nullptr, 0);
    }
    if(argc >= 5) {
        file.open(argv[4]);
    }

    std::cout << "Executing " << argv[0] << " with arguments " << end << ", " << start << ", " << step << "\n";
    if(file.is_open()) {
        file << "Executing " << argv[0] << " with arguments " << end << ", " << start << ", " << step << "\n";
        std::cout << "Writing output to file " << argv[4] << "\n";
        file << "Writing output to file " << argv[4] << "\n";
    }

    if(step == 0) {
        step = 1;
    }

    tstart = time(nullptr);

    if(end <= start) {
        for(long int i = start; i >= end; i -= step) {
            std::cout << i << "\n";
            if(file.is_open()) {
                file << i << "\n";
            }
        }
    } else {
        for(long int i = start; i <= end; i += step) {
            std::cout << i << "\n";
            if(file.is_open()) {
                file << i << "\n";
            }
        }
    }

    tend = time(nullptr);
    tcheck = difftime(tend, tstart);

    std::cout << argv[0] << " executed in " << tcheck << " seconds\n";
    if(file.is_open()) {
        file << argv[0] << " executed in " << tcheck << " seconds\n";
        file.close();
    }

    return 0;
}
