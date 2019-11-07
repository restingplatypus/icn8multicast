set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Minstrel-802.11a.eps"
set title "Results for 802.11a with Minstrel\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:30]
set yrange [0:60]
set key top left
plot "-"  title "802.11a-rate selected" with lines, "-"  title "802.11a-observed" with lines
27 6
26 54
25 54
24 54
23 54
22 54
21 54
20 48
19 36
18 36
17 36
16 24
15 24
14 24
13 24
12 24
11 18
10 18
9 12
8 12
7 12
e
27 5.3248
26 24.9037
25 24.576
24 24.6579
23 23.1834
22 9.8304
21 1.55648
20 1.31072
19 8.68352
18 11.9603
17 12.5338
16 5.57056
15 1.96608
14 6.22592
13 2.37568
12 2.37568
11 4.42368
10 8.84736
9 2.62144
8 1.2288
7 1.2288
e
