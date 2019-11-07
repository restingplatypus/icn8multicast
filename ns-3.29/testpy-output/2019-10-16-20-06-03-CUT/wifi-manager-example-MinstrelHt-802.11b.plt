set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11b.eps"
set title "Results for 802.11b with MinstrelHt\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [-6:15]
set yrange [0:15]
set key top left
plot "-"  title "802.11b-rate selected" with lines, "-"  title "802.11b-observed" with lines
11 1
10 1
9 11
8 11
7 11
6 11
5 11
4 11
3 11
2 11
1 11
0 11
-1 1
e
11 0.8192
10 1.06496
9 4.99712
8 5.16096
7 4.58752
6 1.39264
5 1.06496
4 1.14688
3 0.65536
2 0.24576
1 0.16384
0 0.32768
-1 0.32768
e
