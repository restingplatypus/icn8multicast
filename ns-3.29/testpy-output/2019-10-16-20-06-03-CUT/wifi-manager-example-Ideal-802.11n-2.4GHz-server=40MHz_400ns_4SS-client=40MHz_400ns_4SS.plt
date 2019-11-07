set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11n-2.4GHz-server=40MHz_400ns_4SS-client=40MHz_400ns_4SS.eps"
set title "Results for 802.11n-2.4GHz with Ideal\nserver: width=40MHz GI=400ns nss=4\nclient: width=40MHz GI=400ns nss=4"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:640]
set key top left
plot "-"  title "802.11n-2.4GHz-rate selected" with lines, "-"  title "802.11n-2.4GHz-observed" with lines
30 600
29 600
28 600
27 600
26 600
25 600
24 600
23 540
22 480
21 360
20 360
19 360
18 360
17 360
16 240
15 240
14 240
13 180
12 180
11 180
10 180
9 120
8 120
7 120
e
30 369.869
29 413.778
28 416.973
27 413.532
26 409.764
25 417.628
24 416.891
23 383.713
22 355.86
21 281.559
20 283.116
19 279.347
18 280.822
17 282.214
16 202.015
15 197.263
14 198.41
13 156.549
12 153.928
11 154.993
10 154.337
9 109.281
8 106.988
7 106.824
e
