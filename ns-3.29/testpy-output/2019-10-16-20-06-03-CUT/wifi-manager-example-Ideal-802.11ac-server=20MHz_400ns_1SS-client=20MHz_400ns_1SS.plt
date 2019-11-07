set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11ac-server=20MHz_400ns_1SS-client=20MHz_400ns_1SS.eps"
set title "Results for 802.11ac with Ideal\nserver: width=20MHz GI=400ns nss=1\nclient: width=20MHz GI=400ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:120]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 86.6667
34 86.6667
33 86.6667
32 86.6667
31 86.6667
30 86.6667
29 86.6667
28 72.2222
27 72.2222
26 72.2222
25 72.2222
24 72.2222
23 65
22 57.7778
21 43.3333
20 43.3333
19 43.3333
18 43.3333
17 43.3333
16 28.8889
15 28.8889
14 28.8889
13 21.6667
12 21.6667
11 21.6667
10 21.6667
9 14.4444
e
35 79.2986
34 79.872
33 80.3635
32 80.1178
31 79.9539
30 79.9539
29 77.2506
28 64.8806
27 66.519
26 66.9286
25 66.519
24 60.457
23 57.9994
22 50.9542
21 39.6493
20 40.0589
19 39.977
18 39.8131
17 38.0109
16 25.8048
15 26.624
14 25.8867
13 19.2512
12 19.9066
11 19.9066
10 18.8416
9 12.288
e
