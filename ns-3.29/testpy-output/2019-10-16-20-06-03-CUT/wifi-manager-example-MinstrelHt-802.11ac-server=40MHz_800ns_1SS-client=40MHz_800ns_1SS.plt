set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11ac-server=40MHz_800ns_1SS-client=40MHz_800ns_1SS.eps"
set title "Results for 802.11ac with MinstrelHt\nserver: width=40MHz GI=800ns nss=1\nclient: width=40MHz GI=800ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:240]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 6.5
34 135
33 135
32 135
31 135
30 180
29 180
28 180
27 162
26 121.5
25 121.5
24 121.5
23 121.5
22 121.5
21 121.5
20 81
19 81
18 81
17 81
16 81
15 135
14 162
13 65
12 180
11 26
10 81
9 65
e
35 15.401
34 119.521
33 122.143
32 122.962
31 124.273
30 147.784
29 67.0925
28 42.1069
27 45.3018
26 99.1232
25 110.92
24 106.906
23 106.496
22 49.5616
21 0
20 24.3302
19 74.793
18 74.6291
17 71.1066
16 31.5392
15 0
14 0
13 5.65248
12 0
11 6.144
10 2.8672
9 2.048
e
