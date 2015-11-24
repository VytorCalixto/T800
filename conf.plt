set terminal png
set output 'simulation.png'

set xlabel "x/velocidade"

set autoscale

set ylabel "y/angulo de deslocamento"
set format y "%s"
set zlabel "Time"

set title "Simulation"
set key reverse Left outside
set grid

set style data linespoints

splot "graph" using 1:2:3 title "Posicao", \
	"table" using 1:2:3 title "Angulo/Velocidade"

