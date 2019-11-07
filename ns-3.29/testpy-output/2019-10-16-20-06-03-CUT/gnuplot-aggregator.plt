set terminal png
set output "gnuplot-aggregator.png"
set title "Gnuplot Aggregator Plot"
set xlabel "Time (seconds)"
set ylabel "Double Values"

set datafile missing "-nan"
plot "gnuplot-aggregator.dat" index 0 title "Data Values" with lines
