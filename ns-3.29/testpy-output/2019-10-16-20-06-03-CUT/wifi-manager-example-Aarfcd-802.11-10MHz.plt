set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Aarfcd-802.11-10MHz.eps"
set title "Results for 802.11-10MHz with Aarfcd\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:30]
set yrange [0:60]
set key top left
plot "-"  title "802.11-10MHz-rate selected" with lines, "-"  title "802.11-10MHz-observed" with lines
27 18
26 27
25 27
24 27
23 27
22 24
21 18
20 18
19 18
18 18
17 18
16 12
15 12
14 12
13 12
12 9
11 9
10 9
9 6
8 6
7 6
e
27 4.66944
26 13.1891
25 13.4349
24 13.353
23 12.6976
22 9.91232
21 8.84736
20 10.4858
19 10.4858
18 10.4858
17 10.1581
16 7.70048
15 8.02816
14 8.02816
13 5.65248
12 6.30784
11 6.47168
10 6.144
9 4.5056
8 4.66944
7 4.096
e
