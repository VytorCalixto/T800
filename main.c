#include <stdio.h>

#define L 0.15
// L = Distancia centro da roda - eixo
// Não tenho ideia desse valor
// Ou da unidade (15 cm?)

int main(int argc, char const *argv[]) {
  /* code */
  int i = 0; // Contador
  int tuplas[10][3]; // Vetor de coordenadas x, y e tempo
  puts("Por favor insira as coordenadas na qual o robô deverá passar e seu tempo");
  puts("(Ex: x1 y1 tempo1\n   x2 y2 tempo2\n ...\n xn yn tempon)");
  while (i < 10){
    scanf("%d %d %d",&tuplas[i][0],&tuplas[i][1],&tuplas[i][2]);
    ++i;
  }

  // calcular velocidade dos pontos entre cada coordenada
  // gerar tabela e grafico

  return 0;
}
