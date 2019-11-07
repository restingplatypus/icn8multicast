set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11n-5GHz-server=40MHz_400ns_4SS-client=40MHz_400ns_4SS.eps"
set title "Results for 802.11n-5GHz with Ideal\nserver: width=40MHz GI=400ns nss=4\nclient: width=40MHz GI=400ns nss=4"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:640]
set key top left
plot "-"  title "802.11n-5GHz-rate selected" with lines, "-"  title "802.11n-5GHz-observed" with lines
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
30 453.263
29 460.554
28 463.34
27 457.032
26 462.111
25 462.275
24 462.93
23 425.738
22 386.089
21 303.186
20 300.892
19 301.384
18 301.302
17 299.5
16 211.681
15 209.715
14 209.469
13 161.546
12 160.072
11 160.399
10 159.744
9 112.64
8 109.527
7 109.199
e
