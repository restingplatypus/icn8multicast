set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Minstrel-802.11-5MHz.eps"
set title "Results for 802.11-5MHz with Minstrel\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:30]
set yrange [0:60]
set key top left
plot "-"  title "802.11-5MHz-rate selected" with lines, "-"  title "802.11-5MHz-observed" with lines
27 1.5
26 9
25 13.5
24 13.5
23 13.5
22 13.5
21 12
20 12
19 9
18 9
17 9
16 9
15 9
14 6
13 6
12 6
11 4.5
10 4.5
9 4.5
8 6
7 9
e
27 1.39264
26 5.3248
25 7.04512
24 7.04512
23 6.38976
22 3.35872
21 2.37568
20 0.8192
19 3.2768
18 4.34176
17 4.25984
16 1.72032
15 1.14688
14 2.12992
13 0.65536
12 0.08192
11 2.62144
10 2.8672
9 0.32768
8 0
7 0.16384
e
