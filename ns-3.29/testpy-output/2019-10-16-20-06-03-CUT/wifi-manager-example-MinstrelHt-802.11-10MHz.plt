set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11-10MHz.eps"
set title "Results for 802.11-10MHz with MinstrelHt\n"
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
21 24
20 24
19 18
18 18
17 18
16 18
15 18
14 12
13 12
12 9
11 9
10 9
9 6
8 6
7 6
e
27 2.70336
26 10.6496
25 13.271
24 13.353
23 13.0253
22 5.65248
21 2.62144
20 0.8192
19 4.9152
18 8.02816
17 6.63552
16 3.52256
15 1.14688
14 3.35872
13 0.65536
12 0.57344
11 4.17792
10 4.83328
9 1.47456
8 0.98304
7 1.6384
e
