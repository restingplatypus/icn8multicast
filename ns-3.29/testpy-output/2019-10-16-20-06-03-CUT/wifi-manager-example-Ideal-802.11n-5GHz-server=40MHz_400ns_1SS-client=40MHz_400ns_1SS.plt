set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11n-5GHz-server=40MHz_400ns_1SS-client=40MHz_400ns_1SS.eps"
set title "Results for 802.11n-5GHz with Ideal\nserver: width=40MHz GI=400ns nss=1\nclient: width=40MHz GI=400ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:160]
set key top left
plot "-"  title "802.11n-5GHz-rate selected" with lines, "-"  title "802.11n-5GHz-observed" with lines
30 150
29 150
28 150
27 150
26 150
25 150
24 150
23 135
22 120
21 90
20 90
19 90
18 90
17 90
16 60
15 60
14 60
13 45
12 45
11 45
10 45
9 30
8 30
7 30
e
30 133.038
29 135.905
28 135.987
27 136.069
26 135.741
25 134.267
24 125.338
23 115.18
22 105.923
21 82.4934
20 83.1488
19 82.985
18 83.0669
17 79.7082
16 54.231
15 55.3779
14 53.7395
13 39.895
12 41.4515
11 41.2877
10 38.0928
9 27.7709
8 27.5251
7 21.545
e
