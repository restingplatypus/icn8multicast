set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11ac-server=160MHz_400ns_1SS-client=160MHz_400ns_1SS.eps"
set title "Results for 802.11ac with Ideal\nserver: width=160MHz GI=400ns nss=1\nclient: width=160MHz GI=400ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:960]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 866.667
34 866.667
33 866.667
32 866.667
31 866.667
30 866.667
29 780
28 650
27 650
26 650
25 650
24 650
23 585
22 520
21 390
20 390
19 390
18 390
17 390
16 260
15 260
14 260
13 195
12 195
11 195
10 195
9 130
e
35 614.646
34 619.643
33 614.646
32 619.643
31 615.301
30 536.084
29 519.782
28 497.091
27 494.469
26 497.828
25 492.913
24 423.936
23 408.125
22 388.956
21 324.157
20 324.649
19 326.615
18 319.98
17 300.728
16 224.215
15 225.28
14 207.34
13 170.148
12 173.015
11 171.786
10 154.747
9 113.213
e
