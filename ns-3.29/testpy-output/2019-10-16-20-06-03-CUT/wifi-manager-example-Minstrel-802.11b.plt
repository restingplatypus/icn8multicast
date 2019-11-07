set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Minstrel-802.11b.eps"
set title "Results for 802.11b with Minstrel\n"
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
3 5.5
2 5.5
1 2
0 1
-1 11
e
11 0.8192
10 1.06496
9 4.9152
8 5.24288
7 4.83328
6 1.72032
5 0.90112
4 1.14688
3 0.8192
2 0.4096
1 0.32768
0 0.24576
-1 0.4096
e
