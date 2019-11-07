set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11ac-server=80MHz_400ns_1SS-client=80MHz_400ns_1SS.eps"
set title "Results for 802.11ac with Ideal\nserver: width=80MHz GI=400ns nss=1\nclient: width=80MHz GI=400ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:480]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 433.333
34 433.333
33 433.333
32 433.333
31 433.333
30 433.333
29 390
28 325
27 325
26 325
25 325
24 325
23 292.5
22 260
21 195
20 195
19 195
18 195
17 195
16 130
15 130
14 130
13 97.5
12 97.5
11 97.5
10 97.5
9 65
e
35 352.911
34 354.55
33 355.041
32 354.796
31 352.01
30 314.491
29 302.367
28 277.463
27 275.333
26 276.972
25 275.251
24 249.283
23 228.311
22 217.334
21 174.162
20 173.588
19 172.933
18 172.851
17 164.004
16 117.391
15 118.292
14 109.199
13 92.4877
12 90.1939
11 89.2109
10 81.1827
9 57.9174
e
