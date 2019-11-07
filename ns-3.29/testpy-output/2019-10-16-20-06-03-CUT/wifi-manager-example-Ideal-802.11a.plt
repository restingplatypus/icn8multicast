set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11a.eps"
set title "Results for 802.11a with Ideal\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:30]
set yrange [0:60]
set key top left
plot "-"  title "802.11a-rate selected" with lines, "-"  title "802.11a-observed" with lines
27 54
26 54
25 54
24 54
23 54
22 48
21 36
20 36
19 36
18 36
17 36
16 24
15 24
14 24
13 18
12 18
11 18
10 18
9 12
8 12
7 12
e
27 24.4941
26 24.6579
25 24.4122
24 25.2314
23 23.7568
22 23.0195
21 19.9066
20 19.9885
19 19.9885
18 19.8246
17 18.432
16 15.5648
15 15.5648
14 14.7456
13 12.4518
12 12.6976
11 12.6976
10 11.9603
9 7.86432
8 9.17504
7 7.61856
e
