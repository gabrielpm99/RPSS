#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

#define TEMPO_LIMITE 1.0f

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

    // Texturas e sprites do jogador
    sf::Texture texturaMaoIntermediaria01;
    sf::Texture texturaMaoIntermediaria02;
    sf::Texture texturaMaoPapel;
    sf::Texture texturaMaoTesoura;
    sf::Texture texturaMaoPedra;
    sf::Texture texturaMaoCima;
    sf::Texture texturaMaoDireita;
    sf::Texture texturaMaoEsquerda;
    sf::Texture texturaMaoBaixo;
    sf::Sprite spriteMaoJogador{texturaMaoIntermediaria01};

    sf::Text textoOponente{fonte};

    sf::Text textoResultado{fonte};
    sf::Text textoPlacar{fonte};
    sf::Text textoTempo{fonte};
    sf::Text textoVidas{fonte}; 

    int escolhaJogador = 0;
    int escolhaOponente = 0;

    sf::Clock clockJogadaFinalizada;
    bool jogadaFinalizada = false;

    sf::Clock clockPrincipal;
    float tempoLimite = TEMPO_LIMITE;

    sf::Clock clockAnimacaoScribbled;
    bool ehFrameScribbled01 = true;

    sf::Clock clockAnimacaoMaoIntermediaria;
    bool ehFrameMao01 = true;

    int pontuacao = 0;
    int vidas = 3; 

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
