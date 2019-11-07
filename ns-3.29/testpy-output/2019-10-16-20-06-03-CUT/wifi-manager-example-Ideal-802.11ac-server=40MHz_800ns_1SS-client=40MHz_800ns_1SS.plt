set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11ac-server=40MHz_800ns_1SS-client=40MHz_800ns_1SS.eps"
set title "Results for 802.11ac with Ideal\nserver: width=40MHz GI=800ns nss=1\nclient: width=40MHz GI=800ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:240]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 180
34 180
33 180
32 180
31 180
30 180
29 162
28 135
27 135
26 135
25 135
24 135
23 121.5
22 108
21 81
20 81
19 81
18 81
17 81
16 54
15 54
14 54
13 40.5
12 40.5
11 40.5
10 40.5
9 27
e
35 159.826
34 161.3
33 161.792
32 160.809
31 160.563
30 149.504
29 137.626
28 122.225
27 123.044
26 122.47
25 122.143
24 113.213
23 102.892
22 94.2899
21 74.6291
20 74.9568
19 74.8749
18 74.9568
17 71.1066
16 50.7085
15 49.8893
14 48.9062
13 35.4714
12 37.2736
11 37.1098
10 35.6352
9 23.1014
e
