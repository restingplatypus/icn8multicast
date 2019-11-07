set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11n-5GHz-server=20MHz_400ns_1SS-client=20MHz_400ns_1SS.eps"
set title "Results for 802.11n-5GHz with Ideal\nserver: width=20MHz GI=400ns nss=1\nclient: width=20MHz GI=400ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:80]
set key top left
plot "-"  title "802.11n-5GHz-rate selected" with lines, "-"  title "802.11n-5GHz-observed" with lines
30 72.2222
29 72.2222
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
8 14.4444
7 14.4444
e
30 65.3722
29 66.7648
28 66.7648
27 66.9286
26 66.6829
25 66.6829
24 62.0954
23 57.4259
22 50.7085
21 39.8131
20 40.0589
19 40.0589
18 40.0589
17 39.3216
16 25.9686
15 26.7059
14 24.7398
13 20.48
12 19.9885
11 19.8246
10 18.2682
9 13.1072
8 13.271
7 11.5507
e
