set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Arf-802.11a.eps"
set title "Results for 802.11a with Arf\n"
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
22 48
21 48
20 36
19 36
18 36
17 36
16 24
15 24
14 24
13 18
12 18
11 18
10 18
9 12
8 12
7 9
e
27 16.7117
26 24.7398
25 24.4941
24 25.0675
23 23.9206
22 18.9235
21 16.7117
20 17.9405
19 18.1043
18 17.7766
17 17.2032
16 13.4349
15 14.0902
14 13.5987
13 10.7315
12 11.5507
11 11.5507
10 11.3869
9 8.27392
8 8.51968
7 6.5536
e
