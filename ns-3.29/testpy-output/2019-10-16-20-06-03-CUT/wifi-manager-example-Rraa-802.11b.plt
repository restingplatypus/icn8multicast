set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Rraa-802.11b.eps"
set title "Results for 802.11b with Rraa\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [-6:15]
set yrange [0:15]
set key top left
plot "-"  title "802.11b-rate selected" with lines, "-"  title "802.11b-observed" with lines
11 11
10 11
9 11
8 11
7 11
6 11
5 11
4 11
3 11
2 11
1 11
0 11
-1 11
e
11 5.3248
10 5.16096
9 5.3248
8 5.3248
7 4.5056
6 2.21184
5 0
4 0
3 0
2 0
1 0
0 0
-1 0
e
