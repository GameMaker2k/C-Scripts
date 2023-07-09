#!/usr/bin/perl
use strict;
use warnings;
use Time::HiRes qw(time);

my $start = 0;
my $end = 0;
my $step = 1;
my $file;

if ($#ARGV >= 0) {
    $end = $ARGV[0];
}
if ($#ARGV >= 1) {
    $start = $ARGV[1];
}
if ($#ARGV >= 2) {
    $step = $ARGV[2];
}
if ($#ARGV >= 3) {
    open($file, '>', $ARGV[3]) or die "Could not open file '$ARGV[3]' $!";
}

print "Executing $0 with arguments $end, $start, $step\n";
if ($file) {
    print $file "Executing $0 with arguments $end, $start, $step\n";
    print "Writing output to file $ARGV[3]\n";
    print $file "Writing output to file $ARGV[3]\n";
}

if ($step == 0) {
    $step = 1;
}

my $tstart = time;

if ($end <= $start) {
    for (my $i = $start; $i >= $end; $i -= $step) {
        print "$i\n";
        if ($file) {
            print $file "$i\n";
        }
    }
} else {
    for (my $i = $start; $i <= $end; $i += $step) {
        print "$i\n";
        if ($file) {
            print $file "$i\n";
        }
    }
}

my $tend = time;
my $tcheck = $tend - $tstart;

print "$0 executed in $tcheck seconds\n";
if ($file) {
    print $file "$0 executed in $tcheck seconds\n";
    close $file;
}
