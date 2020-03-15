# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    gen_map.pl                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 23:46:53 by lgavalda          #+#    #+#              #
#    Updated: 2019/07/24 15:46:44 by lgavalda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/perl

use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $i = 0; $i < $x; $i++) {
		if (int(rand($y) * 2) < $density) {
			print "o";
		}
		else {
			print ".";
		}
	}
	print "\n";
}
