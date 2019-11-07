set terminal post eps color enhanced
set output "throughput-rrpaa.eps"
set title "Throughput (AP to STA) vs time"
set xlabel "Time (seconds)"
set ylabel "Throughput (Mb/s)"
plot "-"  title "Throughput Mbits/s" with lines
5 27.3208
15 24.2195
25 24.833
35 20.5957
45 14.5067
e
