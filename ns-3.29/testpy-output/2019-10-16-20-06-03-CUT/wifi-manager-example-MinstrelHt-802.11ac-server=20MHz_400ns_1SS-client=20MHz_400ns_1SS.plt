set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11ac-server=20MHz_400ns_1SS-client=20MHz_400ns_1SS.eps"
set title "Results for 802.11ac with MinstrelHt\nserver: width=20MHz GI=400ns nss=1\nclient: width=20MHz GI=400ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:120]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 6.5
34 72.2222
33 72.2222
32 78
31 78
30 86.6667
29 86.6667
28 86.6667
27 86.6667
26 72.2222
25 72.2222
24 72.2222
23 72.2222
22 86.6667
21 78
20 28.8889
19 26
18 6.5
17 65
16 72.2222
15 26
14 26
13 26
12 26
11 6.5
10 26
9 78
e
35 10.3219
34 64.471
33 67.2563
32 71.5981
31 72.0896
30 79.6262
29 77.0048
28 47.1859
27 31.6211
26 55.3779
25 66.6829
24 60.9485
23 23.593
22 7.7824
21 9.66656
20 9.66656
19 10.3219
18 8.02816
17 2.4576
16 3.44064
15 13.7626
14 23.1014
13 6.9632
12 0
11 4.99712
10 0.4096
9 1.31072
e
