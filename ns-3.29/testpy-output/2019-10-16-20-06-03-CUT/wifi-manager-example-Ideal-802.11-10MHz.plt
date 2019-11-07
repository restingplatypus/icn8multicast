set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11-10MHz.eps"
set title "Results for 802.11-10MHz with Ideal\n"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:30]
set yrange [0:60]
set key top left
plot "-"  title "802.11-10MHz-rate selected" with lines, "-"  title "802.11-10MHz-observed" with lines
27 27
26 27
25 27
24 27
23 27
22 24
21 18
20 18
19 18
18 18
17 18
16 12
15 12
14 12
13 9
12 9
11 9
10 9
9 6
8 6
7 6
e
27 13.0253
26 13.5168
25 13.271
24 13.271
23 12.7795
22 12.1242
21 10.8134
20 10.6496
19 10.7315
18 10.7315
17 9.99424
16 8.27392
15 8.192
14 7.7824
13 6.5536
12 6.63552
11 6.47168
10 6.144
9 4.58752
8 4.83328
7 4.34176
e
