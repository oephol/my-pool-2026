#!/usr/bin/perl

use strict;
use warnings;

die "Usage: $0 width height density(0-100)\n" unless @ARGV == 3;

my ($x, $y, $density) = @ARGV;

die "Density must be between 0 and 100\n"
    if $density < 0 || $density > 100;

print "$y.ox\n";

for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (rand(100) < $density) {
            print "o";
        } else {
            print ".";
        }
    }
    print "\n";
}
