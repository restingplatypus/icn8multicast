set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Aarf-802.11a.eps"
set title "Results for 802.11a with Aarf\n"
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
21 48
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
27 16.7117
26 24.7398
25 24.4941
24 25.0675
23 23.9206
22 20.0704
21 16.8755
20 19.415
19 19.7427
18 19.3331
17 18.2682
16 13.7626
15 15.2371
14 14.7456
13 10.4038
12 12.3699
11 12.5338
10 12.288
9 8.76544
8 9.17504
7 6.79936
e
