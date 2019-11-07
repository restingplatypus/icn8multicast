set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11a.eps"
set title "Results for 802.11a with MinstrelHt\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:30]
set yrange [0:60]
set key top left
plot "-"  title "802.11a-rate selected" with lines, "-"  title "802.11a-observed" with lines
27 6
26 54
25 54
24 54
23 54
22 54
21 54
20 48
19 36
18 36
17 36
16 36
15 24
14 24
13 24
12 24
11 18
10 18
9 18
8 18
7 12
e
27 5.40672
26 24.2483
25 24.8218
24 24.8218
23 23.1014
22 9.8304
21 2.78528
20 2.048
19 11.0592
18 12.6976
17 12.2061
16 7.61856
15 0.98304
14 8.43776
13 2.78528
12 2.12992
11 6.5536
10 7.61856
9 2.37568
8 1.06496
7 3.44064
e
