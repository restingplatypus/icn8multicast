set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11ac-server=160MHz_800ns_1SS-client=160MHz_800ns_1SS.eps"
set title "Results for 802.11ac with MinstrelHt\nserver: width=160MHz GI=800ns nss=1\nclient: width=160MHz GI=800ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:960]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 6.5
34 585
33 780
32 780
31 780
30 780
29 780
28 780
27 702
26 526.5
25 526.5
24 526.5
23 526.5
22 526.5
21 468
20 351
19 351
18 351
17 351
16 526.5
15 351
14 292.5
13 585
12 351
11 65
10 292.5
9 585
e
35 23.511
34 445.317
33 571.965
32 569.016
31 563.528
30 499.057
29 184.074
28 95.191
27 95.191
26 384.778
25 414.761
24 415.334
23 369.705
22 155.73
21 112.886
20 25.2314
19 141.312
18 295.567
17 261.98
16 76.759
15 0
14 0
13 0
12 0
11 0
10 0
9 6.38976
e
