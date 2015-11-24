set terminal png
set output 'posicoes.png'

set xlabel "Posicao"

set autoscale

set ylabel "Tempo"
set format y "%s"

set title "Simulacao de Posicoes"
set key reverse Left outside
set grid

set style data linespoints

plot "graph" using 1:2 title "Posicao"

