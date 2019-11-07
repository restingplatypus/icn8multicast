set terminal postscript eps color enh "Times-BoldItalic"
set output "wifi-manager-example-Ideal-802.11ac-server=160MHz_800ns_1SS-client=160MHz_800ns_1SS.eps"
set title "Results for 802.11ac with Ideal\nserver: width=160MHz GI=800ns nss=1\nclient: width=160MHz GI=800ns nss=1"
set xlabel "SNR (dB)"
set ylabel "Rate (Mb/s)"
set xrange [0:40]
set yrange [0:960]
set key top left
plot "-"  title "802.11ac-rate selected" with lines, "-"  title "802.11ac-observed" with lines
35 780
34 780
33 780
32 780
31 780
30 780
29 702
28 585
27 585
26 585
25 585
24 585
23 526.5
22 468
21 351
20 351
19 351
18 351
17 351
16 234
15 234
14 234
13 175.5
12 175.5
11 175.5
10 175.5
9 117
e
35 568.115
34 571.228
33 569.18
32 568.607
31 568.689
30 498.565
29 479.805
28 455.148
27 457.933
26 452.772
25 451.379
24 388.628
23 378.88
22 351.191
21 294.011
20 295.567
19 295.076
18 295.649
17 271.401
16 202.834
15 205.947
14 194.806
13 153.354
12 157.041
11 156.303
10 135.168
9 107.479
e
