set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11ac-server=80MHz_800ns_1SS-client=80MHz_800ns_1SS.eps"
set title "Results for 802.11ac with Ideal\nserver: width=80MHz GI=800ns nss=1\nclient: width=80MHz GI=800ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:480]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 390
34 390
33 390
32 390
31 390
30 390
29 351
28 292.5
27 292.5
26 292.5
25 292.5
24 292.5
23 263.25
22 234
21 175.5
20 175.5
19 175.5
18 175.5
17 175.5
16 117
15 117
14 117
13 87.75
12 87.75
11 87.75
10 87.75
9 58.5
e
35 322.028
34 323.502
33 323.912
32 324.239
31 322.028
30 288.358
29 276.316
28 251.494
27 251.658
26 251.085
25 251.167
24 227.492
23 206.111
22 198.984
21 156.549
20 158.024
19 156.959
18 157.041
17 145.736
16 108.626
15 106.988
14 102.482
13 79.2166
12 80.855
11 80.855
10 72.9907
9 53.7395
e
