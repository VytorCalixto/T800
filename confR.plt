set terminal png
set output 'velDir.png'

set xlabel "Velocidade/Direcao"

set autoscale

set ylabel "Tempo"
set format y "%s"

set title "Simulacao de Velocidade e Direcao"
set key reverse Left outside
set grid

set style data linespoints

plot "velo" using 1:2 title "Velocidade", \
	"dir" using 1:2 title "Direcao"

