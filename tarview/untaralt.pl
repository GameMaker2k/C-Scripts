#!/usr/bin/perl
use strict;
use warnings;
use File::Path qw(make_path);

# Converts an octal number to a decimal number
sub oct2dec {
    my $num = shift;
    my $total = 0;
    my $power = 1;
    while ($num > 0) {
        $total += $power * ($num % 10);
        $num = int($num / 10);
        $power *= 8;
    }
    return $total;
}

# Reads a property from a file
sub read_property {
    my ($file, $size) = @_;
    my $buffer;
    read($file, $buffer, $size);
    return oct2dec(int($buffer));
}

# Extracts a file from a tar archive
sub extract_file {
    my ($file, $filename, $filesize) = @_;
    my $content;
    read($file, $content, $filesize);
    open my $output, '>', $filename or die "Could not open file '$filename' $!";
    print $output $content;
    close $output;
}

# The main untar function
sub untar {
    my ($tarfile, $outdir, $chmod, $extract) = @_;
    open my $thandle, '<', $tarfile or die "Could not open file '$tarfile' $!";
    seek($thandle, 0, 2);
    my $TarSize = tell($thandle);
    my $TarSizeEnd = $TarSize - 1024;
    seek($thandle, 0, 0);
    while (tell($thandle) < $TarSizeEnd) {
        my $FileNameSize = read_property($thandle, 100);
        my $FileName;
        read($thandle, $FileName, $FileNameSize);
        seek($thandle, 56, 1);
        my $FileType = read_property($thandle, 1);
        seek($thandle, -57, 1);
        my $FileMode = read_property($thandle, 8);
        my $OwnerID = read_property($thandle, 8);
        my $GroupID = read_property($thandle, 8);
        my $FileSize = read_property($thandle, 12);
        my $LastEdit = read_property($thandle, 12);
        my $Checksum = read_property($thandle, 8);
        $FileType = read_property($thandle, 1);
        my $LinkedFile = read_property($thandle, 100);
        seek($thandle, 255, 1);
        if ($extract) {
            if ($FileType == 0 || $FileType == 7) {
                print "inflating file $FileName\n";
                extract_file($thandle, $FileName, $FileSize);
            }
            if ($FileType == 5) {
                print "inflating dir  $FileName\n";
                make_path($FileName, {mode => 0755});
            }
        }
    }
    close $thandle;
}

my $argc = @ARGV;
if ($argc == 1) {
    untar($ARGV[0], "./", 0755, 1);
} elsif ($argc == 2) {
    untar($ARGV[0], $ARGV[1], 0755, 1);
} else {
    print "Usage: $0 tarfile [outdir]\n";
    exit 1;
}
