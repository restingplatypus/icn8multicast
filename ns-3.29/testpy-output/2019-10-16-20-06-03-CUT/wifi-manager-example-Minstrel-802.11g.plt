set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Minstrel-802.11g.eps"
set title "Results for 802.11g with Minstrel\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [-6:30]
set yrange [0:60]
set key top left
plot "-"  title "802.11g-rate selected" with lines, "-"  title "802.11g-observed" with lines
27 1
26 18
25 54
24 54
23 54
22 54
21 54
20 36
19 36
18 36
17 36
16 36
15 36
14 24
13 24
12 24
11 18
10 18
9 18
8 18
7 12
6 18
5 18
4 12
3 5.5
2 36
1 6
0 1
-1 9
e
27 0.98304
26 10.7315
25 18.3501
24 18.1862
23 17.5309
22 4.9152
21 1.06496
20 5.57056
19 10.3219
18 10.0762
17 9.50272
16 3.35872
15 1.39264
14 4.75136
13 1.6384
12 1.2288
11 3.60448
10 7.20896
9 2.62144
8 0.73728
7 1.80224
6 0.8192
5 0.08192
4 0.24576
3 0.08192
2 0.08192
1 0.16384
0 0.24576
-1 0.24576
e
