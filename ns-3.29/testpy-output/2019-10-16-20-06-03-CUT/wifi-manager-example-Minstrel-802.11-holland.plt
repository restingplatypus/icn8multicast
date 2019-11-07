set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Minstrel-802.11-holland.eps"
set title "Results for 802.11-holland with Minstrel\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:30]
set yrange [0:60]
set key top left
plot "-"  title "802.11-holland-rate selected" with lines, "-"  title "802.11-holland-observed" with lines
27 6
26 54
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
15 18
14 18
13 18
12 18
11 18
10 18
9 18
8 12
7 18
e
27 5.3248
26 24.4941
25 24.3302
24 24.4122
23 22.7738
22 9.99424
21 2.4576
20 11.7965
19 12.0422
18 12.2061
17 12.0422
16 7.20896
15 2.12992
14 1.47456
13 8.02816
12 9.99424
11 9.58464
10 9.4208
9 2.21184
8 1.06496
7 3.6864
e
