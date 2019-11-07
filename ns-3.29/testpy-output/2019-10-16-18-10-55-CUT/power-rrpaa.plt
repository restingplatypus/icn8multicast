set terminal post eps color enhanced
set output "power-rrpaa.eps"
set title "Average transmit power (AP to STA) vs time"
set xlabel "Time (seconds)"
set ylabel "Power (mW)"
plot "-"  title "Average Transmit Power" with lines
5 7.3685
15 6.69169
25 29.1606
35 31.7883
45 33.1384
e
