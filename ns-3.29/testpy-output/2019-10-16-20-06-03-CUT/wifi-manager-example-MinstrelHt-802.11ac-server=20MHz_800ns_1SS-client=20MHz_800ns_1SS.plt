set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11ac-server=20MHz_800ns_1SS-client=20MHz_800ns_1SS.eps"
set title "Results for 802.11ac with MinstrelHt\nserver: width=20MHz GI=800ns nss=1\nclient: width=20MHz GI=800ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:120]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 6.5
34 65
33 78
32 78
31 78
30 78
29 78
28 78
27 65
26 65
25 65
24 65
23 65
22 58.5
21 39
20 39
19 39
18 39
17 39
16 39
15 26
14 39
13 65
12 39
11 58.5
10 26
9 26
e
35 11.8784
34 60.2931
33 71.9258
32 72.0077
31 72.0077
30 71.8438
29 70.615
28 43.5814
27 28.2624
26 52.4288
25 60.0474
24 56.361
23 19.3331
22 12.3699
21 26.2144
20 35.881
19 36.0448
18 35.799
17 35.0618
16 13.1072
15 8.192
14 8.92928
13 5.40672
12 6.88128
11 6.88128
10 2.29376
9 2.29376
e
