set terminal postscript eps color enh "Times-BoldItalic"
set output "80211n-mimo-throughput.eps"
set xlabel "Distance (Meters)"
set ylabel "Throughput (Mbit/s)"
set xrange [0:100]
set yrange [0:600]
set ytics 0,50,600
set style line 1 dashtype 1 linewidth 5
set style line 2 dashtype 1 linewidth 5
set style line 3 dashtype 1 linewidth 5
set style line 4 dashtype 1 linewidth 5
set style line 5 dashtype 1 linewidth 5
set style line 6 dashtype 1 linewidth 5
set style line 7 dashtype 1 linewidth 5
set style line 8 dashtype 1 linewidth 5
set style line 9 dashtype 2 linewidth 5
set style line 10 dashtype 2 linewidth 5
set style line 11 dashtype 2 linewidth 5
set style line 12 dashtype 2 linewidth 5
set style line 13 dashtype 2 linewidth 5
set style line 14 dashtype 2 linewidth 5
set style line 15 dashtype 2 linewidth 5
set style line 16 dashtype 2 linewidth 5
set style line 17 dashtype 3 linewidth 5
set style line 18 dashtype 3 linewidth 5
set style line 19 dashtype 3 linewidth 5
set style line 20 dashtype 3 linewidth 5
set style line 21 dashtype 3 linewidth 5
set style line 22 dashtype 3 linewidth 5
set style line 23 dashtype 3 linewidth 5
set style line 24 dashtype 3 linewidth 5
set style line 25 dashtype 4 linewidth 5
set style line 26 dashtype 4 linewidth 5
set style line 27 dashtype 4 linewidth 5
set style line 28 dashtype 4 linewidth 5
set style line 29 dashtype 4 linewidth 5
set style line 30 dashtype 4 linewidth 5
set style line 31 dashtype 4 linewidth 5
set style line 32 dashtype 4 linewidth 5
set style increment user
plot "-"  title "HtMcs0" with lines, "-"  title "HtMcs1" with lines, "-"  title "HtMcs2" with lines, "-"  title "HtMcs3" with lines, "-"  title "HtMcs4" with lines, "-"  title "HtMcs5" with lines, "-"  title "HtMcs6" with lines, "-"  title "HtMcs7" with lines, "-"  title "HtMcs8" with lines, "-"  title "HtMcs9" with lines, "-"  title "HtMcs10" with lines, "-"  title "HtMcs11" with lines, "-"  title "HtMcs12" with lines, "-"  title "HtMcs13" with lines, "-"  title "HtMcs14" with lines, "-"  title "HtMcs15" with lines, "-"  title "HtMcs16" with lines, "-"  title "HtMcs17" with lines, "-"  title "HtMcs18" with lines, "-"  title "HtMcs19" with lines, "-"  title "HtMcs20" with lines, "-"  title "HtMcs21" with lines, "-"  title "HtMcs22" with lines, "-"  title "HtMcs23" with lines, "-"  title "HtMcs24" with lines, "-"  title "HtMcs25" with lines, "-"  title "HtMcs26" with lines, "-"  title "HtMcs27" with lines, "-"  title "HtMcs28" with lines, "-"  title "HtMcs29" with lines, "-"  title "HtMcs30" with lines, "-"  title "HtMcs31" with lines
0 5.18144
10 5.2992
20 5.41696
30 5.41696
40 5.53472
50 5.65248
60 5.65248
70 5.53472
80 5.2992
90 5.18144
100 0
e
0 11.1872
10 10.8339
20 11.4227
30 11.1872
40 11.305
50 10.7162
60 11.0694
70 11.5405
80 0.11776
90 0
100 0
e
0 17.4285
10 16.0154
20 16.6042
30 16.8397
40 16.0154
50 16.3686
60 14.6022
70 0
80 0
90 0
100 0
e
0 23.4342
10 23.3165
20 23.081
30 21.9034
40 22.2566
50 0
60 0
70 0
80 0
90 0
100 0
e
0 33.5616
10 34.7392
20 32.9728
30 33.6794
40 0
50 0
60 0
70 0
80 0
90 0
100 0
e
0 43.8067
10 44.631
20 43.8067
30 0
40 0
50 0
60 0
70 0
80 0
90 0
100 0
e
0 52.0499
10 52.6387
20 51.9322
30 0
40 0
50 0
60 0
70 0
80 0
90 0
100 0
e
0 54.4051
10 58.5267
20 57.2314
30 0
40 0
50 0
60 0
70 0
80 0
90 0
100 0
e
0 11.4227
10 10.5984
20 11.0694
30 11.305
40 11.4227
50 10.7162
60 11.6582
70 10.5984
80 10.5984
90 11.4227
100 11.0694
e
0 22.6099
10 22.8454
20 23.081
30 22.6099
40 21.9034
50 21.5501
60 23.1987
70 22.8454
80 21.6678
90 1.29536
100 1.29536
e
0 33.0906
10 33.7971
20 32.7373
30 32.855
40 33.4438
50 32.855
60 32.5018
70 32.0307
80 34.6214
90 2.00192
100 0.11776
e
0 46.7507
10 45.2198
20 47.104
30 44.0422
40 46.633
50 44.0422
60 2.59072
70 0.35328
80 0
90 0
100 0
e
0 69.4784
10 65.7101
20 65.9456
30 70.0672
40 65.9456
50 67.0054
60 0
70 0
80 0
90 0
100 0
e
0 91.3818
10 92.4416
20 92.4416
30 92.5594
40 77.3683
50 0
60 0
70 0
80 0
90 0
100 0
e
0 102.216
10 103.04
20 97.9763
30 102.333
40 0
50 0
60 0
70 0
80 0
90 0
100 0
e
0 105.984
10 106.102
20 109.517
30 105.866
40 0
50 0
60 0
70 0
80 0
90 0
100 0
e
0 17.4285
10 15.8976
20 16.2509
30 16.0154
40 16.4864
50 16.0154
60 17.5462
70 17.4285
80 17.3107
90 16.6042
100 15.8976
e
0 32.384
10 33.4438
20 32.0307
30 34.857
40 32.0307
50 32.855
60 34.857
70 32.6195
80 34.7392
90 2.00192
100 2.00192
e
0 49.4592
10 50.1658
20 48.1638
30 52.1677
40 51.6966
50 49.6947
60 49.8125
70 50.6368
80 52.7565
90 2.944
100 2.944
e
0 66.7699
10 65.8278
20 69.3606
30 65.1213
40 66.4166
50 67.4765
60 4.00384
70 4.00384
80 4.00384
90 4.00384
100 0.11776
e
0 104.1
10 104.335
20 104.1
30 105.277
40 101.156
50 100.449
60 4.94592
70 4.94592
80 0.35328
90 0
100 0
e
0 125.414
10 128.594
20 129.772
30 137.073
40 130.478
50 131.067
60 0
70 0
80 0
90 0
100 0
e
0 152.617
10 144.845
20 153.206
30 146.376
40 148.613
50 86.7891
60 0
70 0
80 0
90 0
100 0
e
0 158.387
10 161.92
20 168.632
30 167.219
40 154.148
50 0
60 0
70 0
80 0
90 0
100 0
e
0 21.5501
10 23.1987
20 22.9632
30 21.1968
40 23.1987
50 22.6099
60 22.8454
70 22.4922
80 22.0211
90 23.3165
100 22.6099
e
0 46.9862
10 43.8067
20 46.3974
30 46.9862
40 44.3955
50 43.1002
60 46.633
70 46.9862
80 47.104
90 2.59072
100 0
e
0 68.4186
10 66.2989
20 67.8298
30 65.5923
40 65.5923
50 69.9494
60 69.1251
70 67.8298
80 66.0634
90 4.00384
100 4.00384
e
0 87.2602
10 87.0246
20 89.0266
30 91.9706
40 89.8509
50 85.2582
60 4.94592
70 4.94592
80 4.94592
90 4.94592
100 4.94592
e
0 132.951
10 134.129
20 131.42
30 137.19
40 125.885
50 126.71
60 4.94592
70 4.94592
80 4.94592
90 0.5888
100 0
e
0 176.876
10 178.053
20 177.229
30 165.806
40 177.818
50 161.213
60 4.94592
70 0
80 0
90 0
100 0
e
0 199.485
10 198.897
20 194.893
30 190.771
40 197.837
50 172.401
60 0.23552
70 0
80 0
90 0
100 0
e
0 202.312
10 210.79
20 219.387
30 203.96
40 210.673
50 203.489
60 0
70 0
80 0
90 0
100 0
e
