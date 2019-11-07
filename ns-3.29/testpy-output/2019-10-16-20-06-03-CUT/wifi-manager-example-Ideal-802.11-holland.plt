set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11-holland.eps"
set title "Results for 802.11-holland with Ideal\n"
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
21 36
20 36
19 36
18 36
17 36
16 18
15 18
14 18
13 18
12 18
11 18
10 18
9 12
8 12
7 12
e
27 24.2483
26 24.3302
25 24.0845
24 24.8218
23 23.6749
22 19.9066
21 19.8246
20 19.8246
19 19.9066
18 19.5789
17 18.2682
16 12.7795
15 12.6157
14 12.5338
13 12.6157
12 12.6157
11 12.6976
10 11.9603
9 9.25696
8 9.25696
7 7.7824
e
