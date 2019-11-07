set terminal png
set output "gnuplot-helper-example.png"
set title "Emitter Count vs. Time \n\nTrace Source Path: /Names/Emitter/Counter"
set xlabel "Time (Seconds)"
set ylabel "Emitter Count"

set key inside
set datafile missing "-nan"
plot "gnuplot-helper-example.dat" index 0 title "Emitter Count" with linespoints
