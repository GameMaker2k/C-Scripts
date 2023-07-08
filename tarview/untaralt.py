import os

# Converts an octal number to a decimal number
def oct2dec(num):
    total = 0
    power = 1
    while num > 0:
        total += power * (num % 10)
        num //= 10
        power *= 8
    return total

# Reads a property from a file
def read_property(file, size):
    buffer = file.read(size)
    return oct2dec(int(buffer))

# Extracts a file from a tar archive
def extract_file(file, filename, filesize):
    content = file.read(filesize)
    with open(filename, 'wb') as output:
        output.write(content)

# The main untar function
def untar(tarfile, outdir, chmod, extract):
    with open(tarfile, 'rb') as thandle:
        thandle.seek(0, os.SEEK_END)
        TarSize = thandle.tell()
        TarSizeEnd = TarSize - 1024
        thandle.seek(0, os.SEEK_SET)
        while thandle.tell() < TarSizeEnd:
            FileNameSize = read_property(thandle, 100)
            FileName = thandle.read(FileNameSize).decode()
            thandle.seek(56, os.SEEK_CUR)
            FileType = read_property(thandle, 1)
            thandle.seek(-57, os.SEEK_CUR)
            FileMode = read_property(thandle, 8)
            OwnerID = read_property(thandle, 8)
            GroupID = read_property(thandle, 8)
            FileSize = read_property(thandle, 12)
            LastEdit = read_property(thandle, 12)
            Checksum = read_property(thandle, 8)
            FileType = read_property(thandle, 1)
            LinkedFile = read_property(thandle, 100)
            thandle.seek(255, os.SEEK_CUR)
            if extract:
                if FileType == 0 or FileType == 7:
                    print(f"inflating file {FileName}")
                    extract_file(thandle, FileName, FileSize)
                if FileType == 5:
                    print(f"inflating dir  {FileName}")
                    os.mkdir(FileName, 0o755)

if __name__ == "__main__":
    import sys
    if len(sys.argv) == 2:
        untar(sys.argv[1], "./", 0o755, True)
    elif len(sys.argv) == 3:
        untar(sys.argv[1], sys.argv[2], 0o755, True)
    else:
        print(f"Usage: {sys.argv[0]} tarfile [outdir]")
        sys.exit(-1)
