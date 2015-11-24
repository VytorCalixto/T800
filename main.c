#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265
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

double velocity(double dist, double tempo){
  return (dist / (tempo/1000));
}

double distance(int xa, int ya, int xb,int yb){
  return (sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya)));
}

// Retorna o ângulo em relação a origem (0,0)
double angleFromOrigin(int x, int y) {
    /**
     * Y
     * ^
     * |--*
     * | /|
     * |/ |
     * +----------> X
     * |
     * 1. Sabendo os valores de x e y, calculamos a hipotenusa
     * 2. Com o valor de X e da Hip, temos o seno do ângulo formado entre a hipotenusa e o eixo X
     * 3. Fazemos a função arco cosseno para pegar o valor do ângulo (em graus)
     */
    double hip = sqrt(x*x + y*y);
    return acos(x/hip) * 180/PI;
}

double angleFromPoint(int ox, int oy, int x, int y) {
    //ox e oy são os pontos da nova referência
    double hip = distance(ox, oy, x, y);
    return acos((ox-x)/hip) * 180/PI;
}

void moverRobo(Robot *r, int x, int y){
  /* Deveríamos "acionar os motores"
  *  e realmente movimentar o robô
  *	 Contudo estamos só simulando esse movimento
  */
  r->x = x;
  r->y = y;
}

int main(int argc, char const *argv[]) {
  int t_size;
  double velocidade, distancia;
  Tuple *tuplas;
  Robot r = {0, 0, 0};
  FILE *graph = fopen("./graph", "w");
  FILE *out = fopen("./table", "w");
  if(graph == NULL || out == NULL) {
      puts("Erro ao criar arquivos de saída.");
      exit(1);
  }
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

  int frame = 0;

  for(int i=0; i < t_size; ++i) {
      // Pega o ângulo entre a posição do robô e o próximo ponto
      frame += tuplas[i].t;
      double angle = angleFromPoint(r.x, r.y, tuplas[i].x, tuplas[i].y);
      double turn = angle - r.theta; // angulo para girar o robo
      //printf("DEBUG: %f %f\n", angle, r.theta);
      fprintf(graph, "%d %d %d\n", tuplas[i].x, tuplas[i].y, frame);
      // Gira o robô
      r.theta += turn;
      // calcula a velocidade para as rodas
      distancia = distance(r.x, r.y, tuplas[i].x, tuplas[i].y);
      velocidade = velocity(distancia, tuplas[i].t);
      fprintf(out, "%f %f %d\n", velocidade, r.theta, frame);
      moverRobo(&r,tuplas[i].x,tuplas[i].y);
  }

  fclose(graph);
  fclose(out);

  return 0;
}
