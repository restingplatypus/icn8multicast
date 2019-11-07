set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11n-5GHz-server=40MHz_800ns_1SS-client=40MHz_800ns_1SS.eps"
set title "Results for 802.11n-5GHz with Ideal\nserver: width=40MHz GI=800ns nss=1\nclient: width=40MHz GI=800ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:160]
set key top left
plot "-"  title "802.11n-5GHz-rate selected" with lines, "-"  title "802.11n-5GHz-observed" with lines
30 135
29 135
28 135
27 135
26 135
25 135
24 135
23 121.5
22 108
21 81
20 81
19 81
18 81
17 81
16 54
15 54
14 54
13 40.5
12 40.5
11 40.5
10 40.5
9 27
8 27
7 27
e
30 120.259
29 123.208
28 123.126
27 123.044
26 122.634
25 122.716
24 112.148
23 106.332
22 94.6995
21 74.5472
20 74.8749
19 74.8749
18 74.5472
17 71.5162
16 50.2989
15 49.8074
14 48.4147
13 35.799
12 37.2736
11 37.1098
10 33.6691
9 24.1664
8 24.9856
7 22.1184
e
