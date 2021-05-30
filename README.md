# Zombie Attack - Tutorial
- **Equipe:** Ana Carolina Cerqueira, Iuri Santos, Luís Fernando Guerra e Silas Cardoso.

- **Conhecimento Prévio Necessário:** Estrutura de seleção **if**; estruturas de repetição **for**; Conhecimento das funções da biblioteca **inge9**.

O jogo "Zombie Attack" foi desenvolvido utilizando a **linguagem de programação C++** e os recursos da biblioteca [**inge9**](https://rodrigorgs.github.io/inge9/), no contexto da disciplina "MATB22 - Laboratório de Informática na Educação", no semestre de 2021.1 sob orientação do professor Rodrigo Rocha.

## Sobre o jogo
![Imagem representativa do jogo](https://cdn.discordapp.com/attachments/845388670390370344/848340318428332052/cover_1.png)

O jogo Zombie Attack foi desenvolvido com a intenção de ser mais um recurso didático de apoio aos estudantes da disciplina de Introdução à Lógica de Programação (ILP) da UFBA. Desenvolvemos um jogo com uma implementação simples, e para que seja cumprido o objetivo de aprendizagem, será solicitado um exercício para evolução do jogo, que envolve um conceito abordados na disciplina. 

Zombie Attack se passa em um contexto de ataque zumbi, atualmente conta com duas fases implementadas e possui três tipos de personagem:

- O Zumbi;
- O humano;
- Os "Hunters".

## Regras

![Regras do jogo](https://cdn.discordapp.com/attachments/845388670390370344/848340487085359135/regras-new_1.png)

O jogo fuciona da seguinte forma:
* O **Zumbi** é o personagem principal, e se move quando as teclas direcionais do teclado são acionadas. O objetivo do zumbi é atacar o **Humano**. Entretanto, para chegar até o humano o zumbi precisa passar pelos **Hunters**. 
* O zumbi começa a partida com uma determinada quantidade de **vidas** e a cada colisão com um hunter uma vida é perdida. Caso a quantidade de vidas chegue a zero antes que o zumbi alcance a pontuação necessária para passar para a fase seguinte, ele perde o jogo.
* A cada vez que o zumbi colide com um humano, ele pontua, e é necessário obter uma pontuação mínima para que ele passe para a fase seguinte.


## Execução

Para executar o jogo basta inserir o código-fonte no playground da biblioteca inge9 (https://rodrigorgs.github.io/inge9/playground) e clicar em "Rodar".

## Código Fonte

Primeiramente realizamos a importação das bibliotecas do C++ utilizadas e criamos a tela inicial e regras do jogo, utilizando as funções de carregamento e exibição de imagens (_loadImage()_ e _drawImage()_). Utilizamos para exibição de texto a função (_drawText()_), e _readKey()_ para ler a entrada do teclado e dar início ao jogo. Acionamos algumas vezes a função _delay()_ para dar tempo suficiente para que o usuário visualize e compreenda os elementos do jogo. Feito isso, foi chamada a função primeiraFase().

```sh
#include <iostream>
#include <cmath>
#include <inge9>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;

void main() {

  srand(time(0));
  loadImage("home", "https://cdn.discordapp.com/attachments/845388670390370344/846377279571361822/zombieee.png");
  loadImage("gameOver", "https://media.discordapp.net/attachments/845462939951169546/846495765903573032/game-over.png");
  loadImage("win", "https://media.discordapp.net/attachments/845462939951169546/846497054067130388/win.png");
  loadImage("transition", "https://cdn.discordapp.com/attachments/845388670390370344/846384119533535252/transicao.png");
  waitUntilResourcesLoad();
  delay(300);
  drawImage("home", 0, 0);
  delay(1000);
  fillRect(130, 255, 380, 30, "#7F0000");
  delay(1000);
  drawText("PRESSIONE UMA TECLA PARA COMEÇAR!", 140, 277, 18, "white");
  readKey();
  clear("black");
  delay(500);
  drawImage("transition", 0, 0);
  delay(1000);
  clear("black");
  delay(500);

  loadImage("level1", "https://cdn.discordapp.com/attachments/845388670390370344/846383737699565568/fase1.png");
  waitUntilResourcesLoad();
  drawImage("level1", 0, 0);
  delay(3000);
  primeiraFase();
}
```
No início da função **primeiraFase()**, são carregadas as artes (imagens) do jogo utilizando novamente _loadImage()_ e são criadas as variáveis que guardam as informações sobre os personagens, e as variáveis de controle da pontuação, vidas, deslocamento e posições dos itens na tela. A utilização dos sufixos X e Y nas variáveis indicam a posição que elas representam, sendo que o X está relacionado ao eixo horizontal e Y ao vertical. A função _rand()_ gera um número aleatório dentro do limite declarado, fazendo com que os hunters se movam aleatoriamente na tela, criando a dificuldade do jogo.
```sh
void primeiraFase(){
  loadImage("background", "https://cdn.discordapp.com/attachments/845388670390370344/846394486288416789/bg-game.png");
  loadImage("zombie", "https://media.discordapp.net/attachments/845462939951169546/846455550634885130/zombie_walk.png");
  loadImage("human", "https://media.discordapp.net/attachments/845462939951169546/846455676762587187/human-idle2.png");
  loadImage("hunter", "https://media.discordapp.net/attachments/845462939951169546/846253310339842058/mata-zumbi.png");
  waitUntilResourcesLoad();

  double obj1X = rand() % 500 + 0;
  double obj1Y = rand() % 250 + 20;
  // -------------------
  double hunter1X = rand() % 500 + 0;
  double hunter1Y = rand() % 350 + 20;
  // -------------------
  double hunter2X = rand() % 450;
  double hunter2Y = rand() % 240;
  // -------------------

  double coordX = 20;
  double coordY = 20;
  double delta = 5;
  int pontos = 0;
  int vida = 3;
  int contagem = 0;
  int tamanhoHumano = 40;
  int tamanhoZumbi = 40;
  int tamanhoMatador = 40;

```
Na estrutura **for** abaixo estão definidas as regras da mecânica do jogo. Ele está sem as regras (de início, iteração e saída) pois a primeira fase sempre será executada. Primeiramente, é verificado se as teclas direcionais estão sendo pressionadas, utilizando o recurso _isKeyDown()_. No caso dos **if**s utilizados, eles verificam qual das teclas estão sendo pressionadas, e respeitando os limites da dimensão da tela, o zumbi se movimenta para a direção sinalizada na tecla. A variável **delta** controla a velocidade com que o zumbi se movimenta.
A direção do movimento é gerenciada pelas regras que estão dentro de cada if. Por exemplo, caso esteja sendo pressionada a tecla direcional para a esquerda (ArrowLeft), e o zumbi esteja sendo exibido dentro dos limites da dimensão do jogo, enquanto a tecla estiver pressionada, ele será movimentado na coordenada horizontal (variável **coordX**) no sentido negativo, para que se mova para a esquerda (coordX -= delta). Essas operações criam o movimento do zumbi.
```sh
 for (;;) {
    drawImage("background", 0, 0);
    if (isKeyDown("ArrowLeft") && (coordX != 0))
      coordX -= delta;
    if (isKeyDown("ArrowRight") && (coordX != 600))
      coordX += delta;
    if (isKeyDown("ArrowUp") && (coordY != 0))
      coordY -= delta;
    if (isKeyDown("ArrowDown") && (coordY != 320))
      coordY += delta;
    // cout<<coordY<<endl;

```
Nesse trecho de código, são desenhados na tela, alguns elementos que foram definidos anteriormente, como o display de vidas e pontuação com as suas respectivas posições na tela (a posição é controlada pelos parâmetros da função _drawText()_ do inge9). O mesmo é feito com os humanos, zumbis e hunters, que são exibidos nas posições anteriormente definidas nas variáveis.
```sh
    drawText("VIDAS:", 540, 20, 14, "white");
    drawText(vida, 590, 20, 14, "white");
    drawText("SCORE:", 540, 40, 14, "white");
    drawText(pontos, 600, 40, 14, "white");

    drawImage("human", obj1X, obj1Y);
    drawImage("zombie", coordX, coordY);
    drawImage("hunter", hunter1X, hunter1Y);
    drawImage("hunter", hunter2X, hunter2Y);

    drawRect(obj1X, obj1Y, tamanhoHumano, tamanhoHumano, "red"); //Desenha um quadrado com linhas vermelhas em volta do humano
    drawRect(coordX, coordY, tamanhoZumbi, tamanhoZumbi, "green"); //Desenha um quadrado com linhas vermelhas em volta do zumbi

    drawRect(hunter1X, hunter1Y, tamanhoMatador, tamanhoMatador, "yellow"); //Desenha um quadrado com linhas vermelhas em volta do matador de zumbi
    drawRect(hunter2X, hunter2Y, tamanhoMatador, tamanhoMatador, "yellow"); //Desenha um quadrado com linhas vermelhas em volta do matador de zumbi
    delay(30);
```
O trecho a seguir checa se existem colisões do zumbi com os humanos, ou com os hunters (funções _colisaoHumano()_, _colisaoHunter1()_ e _colisaoHunter2()_). A primeira condicional verifica se o jogador atingiu 50 pontos e em caso positivo, ele passa para a fase seguinte. A segunda condicional verifica se o jogador ainda possui vidas. Caso ele não possua, é chamada a função _gameOver()_, que indica que ele perdeu o jogo;.
```sh

    colisaoHumano();
    colisaoHunter1();
    colisaoHunter2();

    if (pontos == 50){
      delay(100);
      segundaFase();
      break;
    }

    if (vida < 0){
      gameOver();
    }

    contagem ++;

    alteraPosicaoCacadorNivel1();

  }
}
```
A função _segundaFase()_ utiliza os mesmos elementos já descritos com mais detalhes na Fase 1. São carregadas e exibidas as imagens nas suas respectivas posições, as colisões são verificadas e as vidas e pontuação são controladas da mesma maneira. Nesse nível é adicionado um terceiro hunter (hunter3) e a regra de pontuação para conclusão da fase é modificada .
```sh
void segundaFase(){
    loadImage("background", "https://cdn.discordapp.com/attachments/845388670390370344/846394486288416789/bg-game.png");
    loadImage("zombie", "https://media.discordapp.net/attachments/845462939951169546/846455550634885130/zombie_walk.png");
    loadImage("human", "https://media.discordapp.net/attachments/845462939951169546/846455676762587187/human-idle2.png");
    loadImage("hunter", "https://media.discordapp.net/attachments/845462939951169546/846253310339842058/mata-zumbi.png");
    loadImage("fase2", "https://cdn.discordapp.com/attachments/845388670390370344/846383763859832832/fase2.png");
    waitUntilResourcesLoad();

  double obj1X = rand() % 500 + 0;
  double obj1Y = rand() % 250 + 20;
  // -------------------
  double hunter1X = rand() % 500 + 0;
  double hunter1Y = rand() % 350 + 20;
  // -------------------
  double hunter2X = rand() % 450;
  double hunter2Y = rand() % 240;
  // -------------------
  double hunter3X = rand() % 300;
  double hunter3Y = rand() % 180;

  double coordX = 20;
  double coordY = 20;
  double delta = 5;
  int pontos = 0;
  int vida = 3;
  int contagem = 0;
  int tamanhoHumano = 40;
  int tamanhoZumbi = 40;
  int tamanhoMatador = 40;

  drawImage("win", 0, 0);
  delay(1200);
  drawImage("fase2", 0, 0);
  delay(1200);
  for (;;) {
    drawImage("background", 0, 0);
    if (isKeyDown("ArrowLeft") && (coordX != 0))
      coordX -= delta;
    if (isKeyDown("ArrowRight") && (coordX != 600))
      coordX += delta;
    if (isKeyDown("ArrowUp") && (coordY != 0))
      coordY -= delta;
    if (isKeyDown("ArrowDown") && (coordY != 320))
      coordY += delta;
    // cout<<coordY<<endl;

    drawText("VIDAS:", 540, 20, 14, "white");
    drawText(vida, 590, 20, 14, "white");
    drawText("SCORE:", 540, 40, 14, "white");
    drawText(pontos, 600, 40, 14, "white");

    drawImage("human", obj1X, obj1Y);
    drawImage("zombie", coordX, coordY);
    drawImage("hunter", hunter1X, hunter1Y);
    drawImage("hunter", hunter2X, hunter2Y);
    drawImage("hunter", hunter3X, hunter3Y);

    drawRect(obj1X, obj1Y, tamanhoHumano, tamanhoHumano, "red"); //Desenha um quadrado com linhas vermelhas em volta do humano
    drawRect(coordX, coordY, tamanhoZumbi, tamanhoZumbi, "green"); //Desenha um quadrado com linhas vermelhas em volta do zumbi

    drawRect(hunter1X, hunter1Y, tamanhoMatador, tamanhoMatador, "yellow"); //Desenha um quadrado com linhas vermelhas em volta do matador de zumbi
    drawRect(hunter2X, hunter2Y, tamanhoMatador, tamanhoMatador, "yellow"); //Desenha um quadrado com linhas vermelhas em volta do matador de zumbi
    delay(30);

    colisaoHumano();
    colisaoHunter1();
    colisaoHunter2();
    colisaoHunter3();

    if (pontos == 60)
    {
      clear("black");
      drawText("Parabéns, você passou da segunda fase!!", 40, 140, 26, "white");
      drawText("Desafio: ", 60, 220, 40, "white");
      drawText("Implemente a fase 3 do jogo.", 60, 280, 40, "red");
      delay(100);
      break;
    }

    if (vida < 0){
      gameOver();
    }

    contagem ++;

    alteraPosicaoCacadorNivel2();
  }
}

```
A função Colisaohunter3() verifica se houve colisão entre o zumbi e o hunter3. Caso ocorra a colisão uma vida do zumbi é subtraída, acionando a função perdeVida() e o hunter muda para outra posição aleatória na tela. Exemplificamos a dinâmica com o trecho de código do hunter3 abaixo, mas a mesma lógica é utilizada para os hunters 1 e 2.
```sh

void colisaoHunter3(){
  if (sqrt((hunter3X - coordX) * (hunter3X - coordX) + ((hunter3Y - coordY) * (hunter3Y - coordY))) < (tamanhoZumbi + tamanhoMatador) / 2)
  {
    hunter3X = rand() % 560;
    hunter3Y = rand() % 280;
    perdeVida();
    cout << "vida: " << vida << endl;
  }
}

```
As funções _perdeVida()_ e _ganhaPontos()_ decrementam 1 vida do zumbi a cada colisão com o matador, e aumentam o valor dos pontos (neste caso, 10 pontos) a cada colisão com um humano, respectivamente.
```sh
void perdeVida(){
  vida -= 1;
}

void ganhaPontos(){
  pontos += 10;
}

```

A função _gameOver()_ é acionada ao verificar que a vida do zumbi é menor que 0.
```sh
void gameOver()
{
  clear("black");
  drawImage("gameOver", 0, 0);
//   drawText("Game Over!", 200, 140, 40, "white");
  drawText("Pontuação final: ", 50, 290, 40, "white");
  drawText(pontos, 350, 290, 40, "yellow");
  delay(10000);
  break;

```

As funções _alteraPosicaoCacadorNivel1()_ e _alteraPosicaooCacadorNivel2()_ alteram, de forma aleatória, utilizando a função rand(), a posição dos matadores nas fases 1 e 2 do jogo, respectivamente.
```sh
void alteraPosicaoCacadorNivel1(){
  if (contagem > 80)
  {
    hunter1X = rand() % 560;
    hunter1Y = rand() % 280;
    hunter2X = rand() % 560;
    hunter2Y = rand() % 280;
    contagem = 0;
  }
}

void alteraPosicaoCacadorNivel2(){
  if (contagem > 40)
  {
    hunter1X = rand() % 560;
    hunter1Y = rand() % 280;
    hunter2X = rand() % 560;
    hunter2Y = rand() % 280;
    hunter3X = rand() % 560;
    hunter3Y = rand() % 280;
    contagem = 0;
  }
}

```
## Exercício proposto

* Implementar a terceira fase do jogo, alterando ao menos um dos seguintes elementos: controle de velocidade da nova fase (variável delta), pontuação necessária para conclusão de fase, quantidade de vidas disponíveis, quantidade de hunters exibidos, etc. 

### Podem usar a criatividade😊
\
**Formulário de avaliação do projeto:**
\
[JotForm](https://form.jotform.com/211486078485667) ✍️
