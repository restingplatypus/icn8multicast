set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Arf-802.11-holland.eps"
set title "Results for 802.11-holland with Arf\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:30]
set yrange [0:60]
set key top left
plot "-"  title "802.11-holland-rate selected" with lines, "-"  title "802.11-holland-observed" with lines
27 54
26 54
25 54
24 54
23 54
22 36
21 54
20 54
19 36
18 36
17 36
16 36
15 18
14 18
13 18
12 36
11 18
10 18
9 12
8 12
7 12
e
27 19.0054
26 24.4122
25 24.1664
24 24.8218
23 23.593
22 17.367
21 17.9405
20 18.0224
19 18.1043
18 17.6128
17 17.367
16 11.7146
15 11.6326
14 11.7965
13 11.6326
12 11.7146
11 11.7146
10 11.0592
9 8.35584
8 8.43776
7 7.7824
e
