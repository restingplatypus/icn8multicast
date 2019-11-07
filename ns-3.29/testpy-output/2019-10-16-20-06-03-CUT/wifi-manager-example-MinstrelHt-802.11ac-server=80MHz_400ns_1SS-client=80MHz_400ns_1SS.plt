set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11ac-server=80MHz_400ns_1SS-client=80MHz_400ns_1SS.eps"
set title "Results for 802.11ac with MinstrelHt\nserver: width=80MHz GI=400ns nss=1\nclient: width=80MHz GI=400ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:480]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 6.5
34 150
33 292.5
32 325
31 390
30 433.333
29 433.333
28 325
27 325
26 325
25 325
24 325
23 292.5
22 292.5
21 150
20 150
19 150
18 72.2222
17 72.2222
16 433.333
15 292.5
14 135
13 390
12 325
11 72.2222
10 390
9 325
e
35 21.463
34 136.643
33 248.709
32 276.398
31 321.618
30 316.867
29 136.069
28 51.5277
27 228.557
26 271.237
25 273.613
24 242.401
23 80.3635
22 5.16096
21 19.0054
20 34.5702
19 0
18 10.8954
17 0.90112
16 0
15 0
14 4.75136
13 1.06496
12 0.65536
11 0
10 0
9 0.98304
e
