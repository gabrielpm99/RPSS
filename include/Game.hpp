#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

#define TEMPO_INICIAL 1.5f
#define TEMPO_MINIMO 1.0f

enum class EstadoJogo {
    Menu,
    Round1, 
    Round2, 
    Round3, 
    FimDeJogo
};

class Game {
private:
    sf::RenderWindow window;
    EstadoJogo estadoAtual;
    EstadoJogo proximoEstado;

    sf::Font fonte;

    // Texturas e sprites do background
    sf::Texture texturaBackground;
    sf::Sprite spriteBackground{texturaBackground};

    int opcaoMenu = 1;

    // Texturas e sprites do menu
    sf::Texture texturaLogoMenu;
    sf::Sprite spriteLogoMenu{texturaLogoMenu};
    sf::Texture texturaScribbled01Menu;
    sf::Texture texturaScribbled02Menu;
    sf::Sprite spriteScribbledMenu{texturaScribbled01Menu};
    sf::Texture texturaSetaMenu;
    sf::Sprite spriteSetaMenu{texturaSetaMenu};
    sf::Texture texturaStartMenu;
    sf::Sprite spriteStartMenu{texturaStartMenu};
    sf::Texture texturaTutorialMenu;
    sf::Sprite spriteTutorialMenu{texturaTutorialMenu};

    // Textura UI do jogo
    sf::Texture UIJogo;
    sf::Sprite spriteUIJogo{UIJogo};

    // Texturas e sprites do jogador
    sf::Texture texturaMaoInt01;
    sf::Texture texturaMaoInt02;
    sf::Texture texturaMaoPapel;
    sf::Texture texturaMaoTesoura;
    sf::Texture texturaMaoPedra;
    sf::Texture texturaMaoCima;
    sf::Texture texturaMaoDireita;
    sf::Texture texturaMaoEsquerda;
    sf::Texture texturaMaoBaixo;
    sf::Sprite spriteMaoJogador{texturaMaoInt01};

    // Texturas e sprites do oponente
    sf::Texture texturaOponenteInt01;
    sf::Texture texturaOponenteInt02;
    sf::Texture texturaOponentePapel;
    sf::Texture texturaOponenteTesoura;
    sf::Texture texturaOponentePedra;
    sf::Texture texturaOponenteCimaFase02;
    sf::Texture texturaOponenteDireitaFase02;
    sf::Texture texturaOponenteEsquerdaFase02;
    sf::Texture texturaOponenteBaixoFase02;
    sf::Texture texturaOponenteCimaFase03;
    sf::Texture texturaOponenteDireitaFase03;
    sf::Texture texturaOponenteEsquerdaFase03;
    sf::Texture texturaOponenteBaixoFase03;
    sf::Texture texturaOponenteVitoria01;
    sf::Texture texturaOponenteVitoria02;
    sf::Texture texturaOponenteDerrota;
    sf::Texture texturaOponenteOlhosCima;
    sf::Texture texturaOponenteOlhosDireita;
    sf::Texture texturaOponenteOlhosEsquerda;
    sf::Texture texturaOponenteOlhosBaixo;

    sf::Texture texturaFinalRodada;

    sf::Sprite spriteOponente{texturaOponenteInt01};

    sf::Text textoPlacar{fonte};

    int escolhaJogador = 0;
    int escolhaOponente = 0;

    sf::Clock clockJogadaFinalizada;
    bool jogadaFinalizada = false;

    sf::Clock clockPrincipal;
    float tempoLimite = TEMPO_INICIAL;

    sf::Clock clockAnimacaoScribbled;
    bool ehFrameScribbled01 = true;

    sf::Clock clockAnimacaoMaoIntermediaria;
    bool ehFrameMao01 = true;

    sf::Clock clockAnimacaoVida;
    bool ehFrameVida01 = true;

    int pontuacao = 0;

    sf::Texture texturaVidaCheia;
    sf::Texture texturaVidaVazia;
    sf::Sprite spriteVida001{texturaVidaCheia};
    sf::Sprite spriteVida002{texturaVidaCheia};
    sf::Sprite spriteVida003{texturaVidaCheia};

    int vidas = 3; 

    bool resultadoCalculado = false;

    void processarEventos();
    void atualizar();
    void renderizar();
    
    // NOVO: Função para organizar o começo de cada round
    void iniciarRound(EstadoJogo novoEstado);

    void carregarTexturas();

public:
    Game();
    ~Game();

    void run();
};
