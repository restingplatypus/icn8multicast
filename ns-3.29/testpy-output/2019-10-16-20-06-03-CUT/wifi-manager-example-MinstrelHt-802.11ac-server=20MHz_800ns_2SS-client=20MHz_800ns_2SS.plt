set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11ac-server=20MHz_800ns_2SS-client=20MHz_800ns_2SS.eps"
set title "Results for 802.11ac with MinstrelHt\nserver: width=20MHz GI=800ns nss=2\nclient: width=20MHz GI=800ns nss=2"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:240]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 6.5
34 130
33 130
32 130
31 130
30 130
29 156
28 156
27 156
26 156
25 156
24 156
23 156
22 156
21 156
20 130
19 130
18 130
17 130
16 130
15 78
14 78
13 78
12 78
11 78
10 78
9 52
e
35 15.319
34 114.934
33 117.883
32 118.456
31 118.292
30 119.194
29 139.182
28 140.82
27 140.902
26 140.575
25 140.493
24 140.82
23 138.363
22 107.889
21 15.8106
20 96.1741
19 118.866
18 113.705
17 68.0755
16 35.3894
15 35.9629
14 71.9258
13 71.9258
12 47.1859
11 3.03104
10 0
9 0
e
