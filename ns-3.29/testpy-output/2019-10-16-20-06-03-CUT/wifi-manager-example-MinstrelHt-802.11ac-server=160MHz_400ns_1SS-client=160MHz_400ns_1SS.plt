set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11ac-server=160MHz_400ns_1SS-client=160MHz_400ns_1SS.eps"
set title "Results for 802.11ac with MinstrelHt\nserver: width=160MHz GI=400ns nss=1\nclient: width=160MHz GI=400ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:960]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 6.5
34 150
33 292.5
32 325
31 585
30 650
29 650
28 650
27 650
26 650
25 650
24 650
23 650
22 585
21 650
20 325
19 585
18 325
17 585
16 585
15 585
14 780
13 292.5
12 585
11 585
10 325
9 65
e
35 21.8726
34 135.66
33 248.218
32 276.89
31 448.758
30 492.995
29 492.503
28 492.995
27 500.777
26 488.817
25 486.195
24 421.151
23 107.561
22 9.25696
21 0
20 70.3693
19 0
18 0
17 0
16 0
15 0
14 0
13 2.70336
12 0
11 0.32768
10 1.31072
9 0.65536
e
