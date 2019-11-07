set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Cara-802.11a.eps"
set title "Results for 802.11a with Cara\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:30]
set yrange [0:60]
set key top left
plot "-"  title "802.11a-rate selected" with lines, "-"  title "802.11a-observed" with lines
27 54
26 54
25 54
24 54
23 54
22 54
21 48
20 48
19 36
18 48
17 36
16 24
15 24
14 24
13 18
12 18
11 18
10 24
9 12
8 12
7 12
e
27 16.7117
26 24.7398
25 24.4941
24 25.0675
23 23.3472
22 16.7936
21 15.6467
20 15.5648
19 15.8925
18 15.2371
17 14.8275
16 12.288
15 12.6157
14 12.2061
13 9.74848
12 10.24
11 10.24
10 10.0762
9 7.29088
8 7.70048
7 6.71744
e
