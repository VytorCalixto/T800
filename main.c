#include <stdio.h>

#define L 0.15
// L = Distancia centro da roda - eixo em cm

int menorDistancia (xa,ya,xb,yb){
  return (sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya)));
}

int main(int argc, char const *argv[]) {
  /* code */
  int i = 0, dist;
  int tuplas[10][3]; // Vetor de coordenadas x, y e tempo
  puts("Por favor insira as coordenadas na qual o robô deverá passar e seu tempo");
  puts("(Ex: x1 y1 tempo1\n   x2 y2 tempo2\n ...\n xn yn tempon)");
  while (i < 10){
    scanf("%d %d %d",&tuplas[i][0],&tuplas[i][1],&tuplas[i][2]);
    ++i;
  }

  // Fiz uma função que calcula a menor distância entre pontos, não sei se é útil
  for (i=0; i<10; ++i){
    dist = menorDistancia(tuplas[i][0],tuplas[i][1],tuplas[i+1][0],tuplas[i+1][1]);
  }

  // calcular velocidade das rodas entre cada coordenada
  // gerar tabela e grafico

  return 0;
}
