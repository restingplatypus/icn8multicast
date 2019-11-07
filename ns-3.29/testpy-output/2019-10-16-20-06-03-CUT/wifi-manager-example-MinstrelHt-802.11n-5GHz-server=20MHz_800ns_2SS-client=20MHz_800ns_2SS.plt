set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11n-5GHz-server=20MHz_800ns_2SS-client=20MHz_800ns_2SS.eps"
set title "Results for 802.11n-5GHz with MinstrelHt\nserver: width=20MHz GI=800ns nss=2\nclient: width=20MHz GI=800ns nss=2"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:160]
set key top left
plot "-"  title "802.11n-5GHz-rate selected" with lines, "-"  title "802.11n-5GHz-observed" with lines
30 6.5
29 78
28 117
27 130
26 130
25 130
24 130
23 130
22 130
21 130
20 130
19 130
18 130
17 130
16 130
15 117
14 78
13 78
12 78
11 78
10 78
9 78
8 52
7 78
e
30 13.5987
29 73.0726
28 105.595
27 117.719
26 118.456
25 118.456
24 118.702
23 118.784
22 118.62
21 118.538
20 118.456
19 118.374
18 112.64
17 70.1235
16 32.4403
15 0
14 27.7709
13 67.9936
12 56.1971
11 0.4096
10 0
9 0
8 14.9914
7 7.3728
e
