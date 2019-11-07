set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Cara-802.11-10MHz.eps"
set title "Results for 802.11-10MHz with Cara\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:30]
set yrange [0:60]
set key top left
plot "-"  title "802.11-10MHz-rate selected" with lines, "-"  title "802.11-10MHz-observed" with lines
27 18
26 27
25 27
24 27
23 27
22 27
21 18
20 18
19 18
18 18
17 18
16 18
15 18
14 12
13 9
12 9
11 9
10 9
9 6
8 6
7 6
e
27 4.75136
26 13.271
25 13.5168
24 13.1891
23 12.6976
22 9.17504
21 7.94624
20 8.43776
19 8.51968
18 8.43776
17 8.192
16 6.71744
15 6.63552
14 6.63552
13 5.40672
12 5.40672
11 5.24288
10 5.07904
9 3.93216
8 4.01408
7 3.85024
e
