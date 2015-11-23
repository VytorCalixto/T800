#include <stdio.h>

#define L 0.15
// L = Distancia centro da roda - eixo em cm

typedef struct {
    /**
     * (x, y) indicam a posição do espaço discreto
     * t em milisegundos indica o tempo
     */
    int x, y, t;
} Tuple;

typedef struct {
    int x, y;
    double theta;
} Robot;

double menorDistancia (int xa, int ya, int xb,int yb){
  return (sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya)));
}

int main(int argc, char const *argv[]) {
  int t_size;
  Tuple *tuplas;
  Robot r = {0, 0, 0};
  puts("Quantos pontos há na lista? Mínimo de 10 elementos.");
  scanf("%d", &t_size);
  if(t_size < 10) {
      puts("A lista deve ter no mínimo 10 elementos.");
      exit(1);
  }
  tuplas = malloc(t_size*sizeof(Tuple));
  if(!tuplas) {
      puts("Ocorreu um erro ao alocar a lista de tuplas.");
      exit(1);
  }
  puts("Por favor insira as coordenadas na qual o robô deverá passar e seu tempo em milissegundos.");
  puts("(Ex: x1 y1 tempo1\n   x2 y2 tempo2\n ...\n xN yN tempoN)");
  for(int i=0; i < t_size; ++i) {
      scanf("%d %d %d", &tuplas[i].x, &tuplas[i].y, &tuplas[i].t);
  }

  // calcular velocidade das rodas entre cada coordenada
  for(int i=0; i < t_size; ++i) {
      // pega o ângulo entre a posição do robô e o próximo ponto
      // gira o robô
      // calcula a velocidade para as rodas
  }
  // gerar tabela e grafico

  return 0;
}
