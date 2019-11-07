set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11n-5GHz-server=40MHz_400ns_1SS-client=40MHz_400ns_1SS.eps"
set title "Results for 802.11n-5GHz with MinstrelHt\nserver: width=40MHz GI=400ns nss=1\nclient: width=40MHz GI=400ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:160]
set key top left
plot "-"  title "802.11n-5GHz-rate selected" with lines, "-"  title "802.11n-5GHz-observed" with lines
30 6.5
29 43.3333
28 81
27 90
26 90
25 121.5
24 121.5
23 121.5
22 135
21 90
20 121.5
19 81
18 81
17 81
16 81
15 81
14 43.3333
13 81
12 135
11 81
10 43.3333
9 15
8 90
7 7.22222
e
30 8.51968
29 41.8611
28 73.5642
27 82.4934
26 84.5414
25 107.561
24 111.002
23 106.414
22 52.5926
21 35.881
20 44.073
19 60.7846
18 70.615
17 72.0077
16 29.1635
15 0
14 9.17504
13 7.04512
12 2.53952
11 5.40672
10 3.93216
9 5.07904
8 4.66944
7 2.8672
e
