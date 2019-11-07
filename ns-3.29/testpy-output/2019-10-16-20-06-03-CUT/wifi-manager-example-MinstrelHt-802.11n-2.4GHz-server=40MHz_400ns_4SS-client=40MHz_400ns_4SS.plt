set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11n-2.4GHz-server=40MHz_400ns_4SS-client=40MHz_400ns_4SS.eps"
set title "Results for 802.11n-2.4GHz with MinstrelHt\nserver: width=40MHz GI=400ns nss=4\nclient: width=40MHz GI=400ns nss=4"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:640]
set key top left
plot "-"  title "802.11n-2.4GHz-rate selected" with lines, "-"  title "802.11n-2.4GHz-observed" with lines
30 6.5
29 26
28 26
27 28.8889
26 28.8889
25 28.8889
24 40.5
23 40.5
22 54
21 54
20 54
19 54
18 54
17 54
16 54
15 60
14 60
13 60
12 60
11 78
10 78
9 78
8 78
7 60
e
30 7.29088
29 22.3642
28 23.593
27 25.641
26 25.8048
25 26.4602
24 34.7341
23 36.3725
22 47.0221
21 48.6605
20 47.9232
19 48.6605
18 48.3328
17 48.3328
16 48.8243
15 51.3638
14 54.1491
13 53.7395
12 53.8214
11 61.1942
10 70.697
9 57.4259
8 51.4458
7 51.0362
e
