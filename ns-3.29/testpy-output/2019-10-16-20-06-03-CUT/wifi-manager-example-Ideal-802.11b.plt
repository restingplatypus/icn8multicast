set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11b.eps"
set title "Results for 802.11b with Ideal\n"
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
7 5.5
6 5.5
5 5.5
4 2
3 2
2 2
1 1
0 1
-1 1
e
11 4.9152
10 5.16096
9 5.40672
8 5.24288
7 3.60448
6 3.52256
5 3.52256
4 1.72032
3 1.55648
2 1.6384
1 0.90112
0 0.90112
-1 0.90112
e
