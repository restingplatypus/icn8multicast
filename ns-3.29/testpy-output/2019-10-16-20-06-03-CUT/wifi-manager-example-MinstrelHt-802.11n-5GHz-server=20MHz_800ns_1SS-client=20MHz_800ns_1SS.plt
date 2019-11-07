set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11n-5GHz-server=20MHz_800ns_1SS-client=20MHz_800ns_1SS.eps"
set title "Results for 802.11n-5GHz with MinstrelHt\nserver: width=20MHz GI=800ns nss=1\nclient: width=20MHz GI=800ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:80]
set key top left
plot "-"  title "802.11n-5GHz-rate selected" with lines, "-"  title "802.11n-5GHz-observed" with lines
30 6.5
29 65
28 65
27 65
26 65
25 65
24 65
23 65
22 65
21 58.5
20 39
19 39
18 39
17 39
16 39
15 39
14 26
13 39
12 26
11 58.5
10 6.5
9 26
8 6.5
7 26
e
30 14.0083
29 59.9654
28 60.1293
27 59.9654
26 60.1293
25 59.8016
24 56.7706
23 18.5958
22 11.1411
21 8.27392
20 22.528
19 36.1267
18 35.881
17 34.8979
16 13.7626
15 12.6976
14 11.305
13 2.94912
12 2.70336
11 2.29376
10 2.37568
9 0.24576
8 1.55648
7 0.4096
e
