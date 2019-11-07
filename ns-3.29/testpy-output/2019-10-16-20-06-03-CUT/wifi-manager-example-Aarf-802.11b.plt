set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Aarf-802.11b.eps"
set title "Results for 802.11b with Aarf\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [-6:15]
set yrange [0:15]
set key top left
plot "-"  title "802.11b-rate selected" with lines, "-"  title "802.11b-observed" with lines
11 2
10 11
9 11
8 11
7 11
6 5.5
5 5.5
4 5.5
3 2
2 2
1 2
0 1
-1 1
e
11 0.90112
10 3.35872
9 5.16096
8 5.3248
7 4.58752
6 3.19488
5 3.44064
4 3.03104
3 1.55648
2 1.47456
1 1.31072
0 0.8192
-1 0.8192
e
