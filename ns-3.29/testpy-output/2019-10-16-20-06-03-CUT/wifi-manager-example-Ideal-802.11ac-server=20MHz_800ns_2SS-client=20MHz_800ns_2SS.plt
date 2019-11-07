set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11ac-server=20MHz_800ns_2SS-client=20MHz_800ns_2SS.eps"
set title "Results for 802.11ac with Ideal\nserver: width=20MHz GI=800ns nss=2\nclient: width=20MHz GI=800ns nss=2"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:240]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 156
34 156
33 156
32 156
31 156
30 156
29 156
28 130
27 130
26 130
25 130
24 130
23 117
22 104
21 78
20 78
19 78
18 78
17 78
16 52
15 52
14 52
13 39
12 39
11 39
10 39
9 26
e
35 139.756
34 140.493
33 140.984
32 140.493
31 140.82
30 140.247
29 141.312
28 119.357
27 118.456
26 118.538
25 118.538
24 118.292
23 107.233
22 96.5837
21 73.9738
20 71.9258
19 72.0077
18 71.9258
17 72.0896
16 50.4627
15 48.087
14 47.9232
13 37.0278
12 35.881
11 35.799
10 35.9629
9 24.9856
e
