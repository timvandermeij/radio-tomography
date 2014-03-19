#!/bin/sh
/usr/bin/gnuplot<<\EOF

set xlabel "Height"
set ylabel "RSSI"
set key outside
set ytics
set yrange [-50:0]
set tics out nomirror
set my2tics 0

set style data histogram
set style histogram cluster gap 3
set style fill solid border -1
set term svg size 2000,1200
set output 'histogram-height.svg'

# attempt to set xtics so they are positioned numerically on x axis:
set xtics ("1" 0, "2" 1)

# ti col reads the first entry of the column, uses it as title name
plot 'height.dat' using 2:xtic(1) ti col,  '' u 3 ti col, '' u 4 ti col, '' u 5 ti col, '' u 6 ti col, '' u 7 ti col, '' u 8 ti col, '' u 9 ti col

EOF
