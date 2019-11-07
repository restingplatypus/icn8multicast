set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Arf-802.11-10MHz.eps"
set title "Results for 802.11-10MHz with Arf\n"
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
22 24
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
11 12
10 9
9 6
8 6
7 4.5
e
27 4.75136
26 13.271
25 13.5168
24 13.1891
23 12.8614
22 10.1581
21 9.0112
20 9.8304
19 9.66656
18 9.74848
17 9.25696
16 7.29088
15 7.45472
14 7.20896
13 5.57056
12 5.98016
11 6.06208
10 5.65248
9 4.42368
8 4.34176
7 3.35872
e
