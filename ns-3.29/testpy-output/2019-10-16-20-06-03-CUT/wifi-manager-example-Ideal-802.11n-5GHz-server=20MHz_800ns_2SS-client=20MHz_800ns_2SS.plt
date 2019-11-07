set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11n-5GHz-server=20MHz_800ns_2SS-client=20MHz_800ns_2SS.eps"
set title "Results for 802.11n-5GHz with Ideal\nserver: width=20MHz GI=800ns nss=2\nclient: width=20MHz GI=800ns nss=2"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:160]
set key top left
plot "-"  title "802.11n-5GHz-rate selected" with lines, "-"  title "802.11n-5GHz-observed" with lines
30 130
29 130
28 130
27 130
26 130
25 130
24 130
23 117
22 104
21 78
20 78
19 78
18 78
17 78
16 52
15 52
14 52
13 39
12 39
11 39
10 39
9 26
8 26
7 26
e
30 116.081
29 118.456
28 118.948
27 118.62
26 117.965
25 118.784
24 118.211
23 108.052
22 96.9933
21 73.4822
20 72.0896
19 72.0896
18 72.0077
17 72.0896
16 49.8074
15 47.8413
14 48.0051
13 36.5363
12 35.9629
11 35.881
10 35.9629
9 24.6579
8 23.9206
7 24.0026
e
