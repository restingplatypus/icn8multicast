set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11ac-server=40MHz_400ns_1SS-client=40MHz_400ns_1SS.eps"
set title "Results for 802.11ac with MinstrelHt\nserver: width=40MHz GI=400ns nss=1\nclient: width=40MHz GI=400ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:240]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 6.5
34 150
33 180
32 200
31 200
30 200
29 200
28 200
27 150
26 150
25 150
24 150
23 150
22 200
21 72.2222
20 65
19 72.2222
18 135
17 65
16 6.5
15 6.5
14 135
13 72.2222
12 200
11 65
10 72.2222
9 65
e
35 20.1523
34 130.908
33 159.826
32 176.374
31 177.029
30 166.052
29 74.711
28 60.2112
27 123.617
26 135.414
25 130.908
24 126.321
23 39.6493
22 0
21 5.57056
20 9.09312
19 0
18 0
17 0
16 2.21184
15 1.06496
14 2.62144
13 0.32768
12 0.32768
11 0.32768
10 0
9 1.31072
e
