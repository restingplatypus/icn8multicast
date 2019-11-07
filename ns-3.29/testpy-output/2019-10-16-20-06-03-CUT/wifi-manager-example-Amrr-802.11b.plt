set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Amrr-802.11b.eps"
set title "Results for 802.11b with Amrr\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [-6:15]
set yrange [0:15]
set key top left
plot "-"  title "802.11b-rate selected" with lines, "-"  title "802.11b-observed" with lines
11 1
10 1
9 1
8 1
7 1
6 1
5 1
4 1
3 1
2 1
1 1
0 1
-1 1
e
11 0.8192
10 0.90112
9 0.90112
8 0.8192
7 0.90112
6 0.90112
5 0.8192
4 0.90112
3 0.90112
2 0.8192
1 1.06496
0 0.65536
-1 0.57344
e
