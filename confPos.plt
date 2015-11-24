set terminal png
set output 'posicoes.png'

set xlabel "x"

set autoscale

set ylabel "y"
set format y "%s"
set zlabel "Time"

set title "Simulacao de Posicoes"
set key reverse Left outside
set grid

set style data linespoints

splot "graph" using 1:2:3 title "Posicao"

