set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-MinstrelHt-802.11n-5GHz-server=40MHz_400ns_4SS-client=40MHz_400ns_4SS.eps"
set title "Results for 802.11n-5GHz with MinstrelHt\nserver: width=40MHz GI=400ns nss=4\nclient: width=40MHz GI=400ns nss=4"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:35]
set yrange [0:640]
set key top left
plot "-"  title "802.11n-5GHz-rate selected" with lines, "-"  title "802.11n-5GHz-observed" with lines
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
16 60
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
30 7.53664
29 23.511
28 24.0026
27 26.1325
26 26.4602
25 26.9517
24 35.9629
23 37.847
22 46.9402
21 49.6435
20 49.0701
19 49.4797
18 49.5616
17 49.3158
16 53.9034
15 54.8045
14 54.9683
13 55.0502
12 55.8694
11 65.3722
10 72.0896
9 67.9117
8 62.3411
7 60.7027
e
