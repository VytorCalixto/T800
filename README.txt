----------------------------------------------------------
------- Leandro Bertazzo Rodrigues - GRR20143009 ---------
----------- Victor Luis Perszel - GRR20144615 ------------
----- Vytor dos Santos Bezerra Calixto - GRR20144434 -----
----------------------------------------------------------



Trabalho 1 da disciplina de Tópicos em Sistemas Imbutidos - Intrudução à Robótica Móvel (CI321)

A. Cinemática

Desenvolver aplicação para simulação de movimento de robô com duas rodas, com motores independentes, e com uma terceira
roda castor de apoio, conforme esquema a seguir:


               |

         ||----x----||
            L  p  L


A distância entre o centro de cada roda e o centro do eixo que as une, ponto p, é L.
O grupo pode definir L fixo com valor razoável para um robô real.

A aplicação deverá realizar o seguinte:

1. Permitir configurar dimensões do espaço de trabalho

2. Ler lista de tuplas com coordenadas x, y referenciadas ao espaço de trabalho, e informação temporal referente a cada ponto (x,y) especificado, definindo uma trajetória. A lista deve possuir ao menos 10 tuplas.

3. Realizar simulação, partindo do ponto inicial, tendo sucessivamente os pontos da lista como próximos objetivos. Definir velocidades das rodas ao longo do tempo para atingir cada ponto intermediário.

4. Mostrar graficamente (nao precisa necessariamente desenvolver sw para isto, pode um outro sw livre qualquer ler dados para serem visualizados) a trajetória do robô, indicando x, y e orientação (ângulo, relativo ao eixo x do espaço de trabalho)
e velocidades das rodas (relativas ao frame do robô).

5. Gerar tabela em arquivo com os dados mostrados no item 4.

Atenção: este problema envolve o conntrole do robô, você terá que investigar um pouco sobre isto, leia, por exemplo, no livro do Siegwart (particularmente sessão 3.6.2.4).
