import sys
import time

def main(argv):
    start = 0
    end = 0
    step = 1
    file = None

    if len(argv) >= 2:
        end = int(argv[1])
    if len(argv) >= 3:
        start = int(argv[2])
    if len(argv) >= 4:
        step = int(argv[3])
    if len(argv) >= 5:
        file = open(argv[4], 'w')

    print(f"Executing {argv[0]} with arguments {end}, {start}, {step}")
    if file:
        file.write(f"Executing {argv[0]} with arguments {end}, {start}, {step}\n")
        print(f"Writing output to file {argv[4]}")
        file.write(f"Writing output to file {argv[4]}\n")

    if step == 0:
        step = 1

    tstart = time.time()

    if end <= start:
        i = start
        while i >= end:
            print(i)
            if file:
                file.write(f"{i}\n")
            i -= step
    else:
        i = start
        while i <= end:
            print(i)
            if file:
                file.write(f"{i}\n")
            i += step

    tend = time.time()
    tcheck = tend - tstart

    print(f"{argv[0]} executed in {tcheck} seconds")
    if file:
        file.write(f"{argv[0]} executed in {tcheck} seconds\n")
        file.close()

if __name__ == "__main__":
    main(sys.argv)
