set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Aarf-802.11-10MHz.eps"
set title "Results for 802.11-10MHz with Aarf\n"
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
16 12
15 12
14 12
13 9
12 9
11 9
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
22 10.8954
21 9.66656
20 10.6496
19 10.5677
18 10.4858
17 10.0762
16 7.53664
15 8.02816
14 7.94624
13 6.06208
12 6.22592
11 6.5536
10 6.22592
9 4.5056
8 4.75136
7 3.44064
e
