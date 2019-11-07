set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11n-5GHz-server=20MHz_800ns_1SS-client=20MHz_800ns_1SS.eps"
set title "Results for 802.11n-5GHz with Ideal\nserver: width=20MHz GI=800ns nss=1\nclient: width=20MHz GI=800ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:80]
set key top left
plot "-"  title "802.11n-5GHz-rate selected" with lines, "-"  title "802.11n-5GHz-observed" with lines
30 65
29 65
28 65
27 65
26 65
25 65
24 65
23 58.5
22 52
21 39
20 39
19 39
18 39
17 39
16 26
15 26
14 26
13 19.5
12 19.5
11 19.5
10 19.5
9 13
8 13
7 13
e
30 58.8186
29 60.0474
28 60.1293
27 60.1293
26 60.0474
25 59.9654
24 54.8864
23 52.3469
22 45.056
21 35.7171
20 35.9629
19 36.1267
18 36.0448
17 34.3245
16 23.1014
15 24.0845
14 23.511
13 16.8755
12 17.9405
11 17.8586
10 15.1552
9 12.6157
8 12.0422
7 10.3219
e
