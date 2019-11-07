set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11ac-server=40MHz_400ns_1SS-client=40MHz_400ns_1SS.eps"
set title "Results for 802.11ac with Ideal\nserver: width=40MHz GI=400ns nss=1\nclient: width=40MHz GI=400ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:240]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 200
34 200
33 200
32 200
31 200
30 200
29 180
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
e
35 176.292
34 178.176
33 178.012
32 177.603
31 177.029
30 163.43
29 153.682
28 133.939
27 135.414
26 135.25
25 134.431
24 121.897
23 114.688
22 109.281
21 82.3296
20 83.0669
19 83.0669
18 83.1488
17 79.2986
16 54.8864
15 55.296
14 53.248
13 40.8781
12 41.6154
11 41.3696
10 38.4205
9 27.2794
e
