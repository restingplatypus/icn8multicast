set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Minstrel-802.11-10MHz.eps"
set title "Results for 802.11-10MHz with Minstrel\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:30]
set yrange [0:60]
set key top left
plot "-"  title "802.11-10MHz-rate selected" with lines, "-"  title "802.11-10MHz-observed" with lines
27 3
26 18
25 27
24 27
23 27
22 27
21 27
20 18
19 18
18 18
17 18
16 18
15 12
14 12
13 3
12 12
11 9
10 9
9 9
8 9
7 6
e
27 2.70336
26 10.7315
25 13.4349
24 13.1891
23 13.0253
22 5.98016
21 1.2288
20 0.32768
19 2.4576
18 6.9632
17 7.29088
16 3.76832
15 0.8192
14 1.6384
13 0.65536
12 1.06496
11 4.75136
10 4.5056
9 1.80224
8 0.90112
7 2.70336
e
