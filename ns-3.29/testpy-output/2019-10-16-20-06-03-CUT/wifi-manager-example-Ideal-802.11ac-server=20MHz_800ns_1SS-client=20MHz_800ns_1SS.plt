set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11ac-server=20MHz_800ns_1SS-client=20MHz_800ns_1SS.eps"
set title "Results for 802.11ac with Ideal\nserver: width=20MHz GI=800ns nss=1\nclient: width=20MHz GI=800ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:120]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 78
34 78
33 78
32 78
31 78
30 78
29 78
28 65
27 65
26 65
25 65
24 65
23 58.5
22 52
21 39
20 39
19 39
18 39
17 39
16 26
15 26
14 26
13 19.5
12 19.5
11 19.5
10 19.5
9 13
e
35 71.4342
34 71.9258
33 72.0896
32 72.1715
31 72.0896
30 71.9258
29 69.632
28 59.1462
27 59.8835
26 60.2112
25 59.9654
24 57.4259
23 49.152
22 45.5475
21 35.9629
20 35.9629
19 35.9629
18 35.881
17 35.1437
16 23.4291
15 23.9206
14 23.593
13 17.2851
12 17.9405
11 17.9405
10 16.384
9 11.7146
e
