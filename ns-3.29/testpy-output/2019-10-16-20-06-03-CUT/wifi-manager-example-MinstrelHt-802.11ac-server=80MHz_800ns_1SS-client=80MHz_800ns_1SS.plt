set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11ac-server=80MHz_800ns_1SS-client=80MHz_800ns_1SS.eps"
set title "Results for 802.11ac with MinstrelHt\nserver: width=80MHz GI=800ns nss=1\nclient: width=80MHz GI=800ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:480]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 6.5
34 292.5
33 292.5
32 390
31 390
30 390
29 390
28 390
27 292.5
26 292.5
25 292.5
24 292.5
23 292.5
22 175.5
21 175.5
20 175.5
19 175.5
18 175.5
17 175.5
16 175.5
15 175.5
14 135
13 39
12 390
11 39
10 135
9 175.5
e
35 19.0874
34 235.848
33 253.215
32 318.833
31 321.618
30 294.093
29 119.357
28 81.5923
27 233.8
26 245.105
25 249.61
24 222.986
23 76.841
22 67.584
21 138.936
20 157.368
19 151.716
18 157.532
17 149.094
16 62.8326
15 0.16384
14 0
13 0
12 11.1411
11 5.48864
10 6.38976
9 5.24288
e
