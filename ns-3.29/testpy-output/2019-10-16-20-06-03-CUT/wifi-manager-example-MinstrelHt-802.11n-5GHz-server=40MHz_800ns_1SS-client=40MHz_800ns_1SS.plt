set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11n-5GHz-server=40MHz_800ns_1SS-client=40MHz_800ns_1SS.eps"
set title "Results for 802.11n-5GHz with MinstrelHt\nserver: width=40MHz GI=800ns nss=1\nclient: width=40MHz GI=800ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:160]
set key top left
plot "-"  title "802.11n-5GHz-rate selected" with lines, "-"  title "802.11n-5GHz-observed" with lines
30 6.5
29 81
28 121.5
27 135
26 135
25 135
24 135
23 135
22 135
21 81
20 81
19 81
18 81
17 81
16 81
15 54
14 54
13 54
12 39
11 13.5
10 13.5
9 135
8 6.5
7 121.5
e
30 13.8445
29 75.9398
28 109.363
27 121.979
26 122.88
25 122.143
24 113.377
23 39.1578
22 18.1043
21 54.1491
20 74.711
19 74.711
18 74.8749
17 71.9258
16 29.4912
15 18.0224
14 40.5504
13 17.5309
12 0
11 3.85024
10 5.40672
9 4.42368
8 2.12992
7 2.4576
e
