set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11n-5GHz-server=20MHz_400ns_1SS-client=20MHz_400ns_1SS.eps"
set title "Results for 802.11n-5GHz with MinstrelHt\nserver: width=20MHz GI=400ns nss=1\nclient: width=20MHz GI=400ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:80]
set key top left
plot "-"  title "802.11n-5GHz-rate selected" with lines, "-"  title "802.11n-5GHz-observed" with lines
30 6.5
29 43.3333
28 65
27 65
26 65
25 72.2222
24 72.2222
23 72.2222
22 72.2222
21 58.5
20 72.2222
19 43.3333
18 43.3333
17 43.3333
16 43.3333
15 43.3333
14 28.8889
13 28.8889
12 43.3333
11 6.5
10 7.22222
9 58.5
8 7.22222
7 39
e
30 10.5677
29 40.8781
28 58.6547
27 59.9654
26 60.457
25 65.7818
24 61.1942
23 23.4291
22 12.7795
21 0
20 10.6496
19 32.8499
18 39.977
17 38.5024
16 13.9264
15 11.1411
14 18.6778
13 5.57056
12 4.01408
11 2.29376
10 2.37568
9 2.53952
8 2.29376
7 2.62144
e
