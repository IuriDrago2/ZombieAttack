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
  loadImage("desafio", "https://media.discordapp.net/attachments/845462939951169546/848356033340506132/3FASE.png");
  loadImage("regras", "https://cdn.discordapp.com/attachments/845462939951169546/848354840068489246/regras-new_1.png");
  waitUntilResourcesLoad();
  delay(300);
  drawImage("regras", 0, 0);
  delay(10000);
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

    drawRect(obj1X, obj1Y, tamanhoHumano, tamanhoHumano, "red"); //Desenha um quadrado com linhas vermelhas em volta do humano
    drawRect(coordX, coordY, tamanhoZumbi, tamanhoZumbi, "green"); //Desenha um quadrado com linhas vermelhas em volta do zumbi

    drawRect(hunter1X, hunter1Y, tamanhoMatador, tamanhoMatador, "yellow"); //Desenha um quadrado com linhas vermelhas em volta do matador de zumbi
    drawRect(hunter2X, hunter2Y, tamanhoMatador, tamanhoMatador, "yellow"); //Desenha um quadrado com linhas vermelhas em volta do matador de zumbi
    delay(30);

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

  } //fim do For
}

void segundaFase(){
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
      drawImage("desafio", 0, 0);
      delay(1000);
      break;
    }

    if (vida < 0){
      gameOver();
    }

    contagem ++;

    alteraPosicaoCacadorNivel2();

  } //fim do For
}


// ------------------------------------------------------------
// |||||||||||||||||||| FUNÇÕES |||||||||||||||||||||||||||
// ------------------------------------------------------------

void colisaoHumano(){
  if (sqrt((obj1X - coordX) * (obj1X - coordX) + ((obj1Y - coordY) * (obj1Y - coordY))) < (tamanhoHumano + tamanhoZumbi) / 2)
  {
    cout << "CoordenadaX igual a obj1X" << endl;
    obj1X = rand() % 600;
    obj1Y = rand() % 310;
    hunter1X = rand() % 500 + 0;
    hunter1Y = rand() % 300 + 20;
    hunter2X = rand() % 450;
    hunter2Y = rand() % 240;
    ganhaPontos();
    cout << "Pontos: " << pontos << endl;
  }
}

void colisaoHunter1(){
  if (sqrt((hunter1X - coordX) * (hunter1X - coordX) + ((hunter1Y - coordY) * (hunter1Y - coordY))) < (tamanhoZumbi + tamanhoMatador) / 2)
  {
    hunter1X = rand() % 560;
    hunter1Y = rand() % 280;
    perdeVida();
    cout << "vida: " << vida << endl;
  }
}

void colisaoHunter2(){
  if (sqrt((hunter2X - coordX) * (hunter2X - coordX) + ((hunter2Y - coordY) * (hunter2Y - coordY))) < (tamanhoZumbi + tamanhoMatador) / 2)
  {
    hunter2X = rand() % 560;
    hunter2Y = rand() % 280;
    perdeVida();
    cout << "vida: " << vida << endl;
  }
}

void colisaoHunter3(){
  if (sqrt((hunter3X - coordX) * (hunter3X - coordX) + ((hunter3Y - coordY) * (hunter3Y - coordY))) < (tamanhoZumbi + tamanhoMatador) / 2)
  {
    hunter3X = rand() % 560;
    hunter3Y = rand() % 280;
    perdeVida();
    cout << "vida: " << vida << endl;
  }
}

void perdeVida(){
  vida -= 1;
}

void ganhaPontos(){
  pontos += 10;
}

void gameOver()
{
  clear("black");
  drawImage("gameOver", 0, 0);
//   drawText("Game Over!", 200, 140, 40, "white");
  drawText("Pontuação final: ", 50, 290, 40, "white");
  drawText(pontos, 350, 290, 40, "yellow");
  delay(10000);
  break;
}

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