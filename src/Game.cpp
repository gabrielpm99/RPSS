#include "../include/Game.hpp"

Game::Game() {
    window.create(sf::VideoMode(sf::Vector2u(1440, 960)), "Jankenpo");
    window.setFramerateLimit(60);
    estadoAtual = EstadoJogo::Menu;

    if (fonte.openFromFile("../assets/fonte.ttf")) {

        sf::Vector2u tamanhoJanela = window.getSize();

        textoPlacar.setCharacterSize(120);
        textoPlacar.setFillColor(sf::Color(167, 0, 0));
        textoPlacar.setLetterSpacing(12.0f);
    }

    carregarTexturas();
}

Game::~Game() {}


void Game::carregarTexturas() {
    if(texturaBackground.loadFromFile("../assets/fundo001.png")) {
        spriteBackground.setTexture(texturaBackground, true);
        sf::Vector2u tamanhoMenuBackground = texturaBackground.getSize();
        spriteBackground.setScale(sf::Vector2f(1440.0f / tamanhoMenuBackground.x, 960.0f / tamanhoMenuBackground.y));
        spriteBackground.setPosition(sf::Vector2f(0.0f, 0.0f));
    }
    if(texturaLogoMenu.loadFromFile("../assets/menu/rockpaperscissor.png")) {
        spriteLogoMenu.setTexture(texturaLogoMenu, true);
        spriteLogoMenu.setPosition(sf::Vector2f(0.0f, 150.0f));
    }
    if(texturaScribbled01Menu.loadFromFile("../assets/menu/scribbled001.png") && texturaScribbled02Menu.loadFromFile("../assets/menu/scribbled002.png")) {
        spriteScribbledMenu.setTexture(texturaScribbled01Menu, true);
        sf::Vector2u tamanhoScribbled = texturaScribbled01Menu.getSize();
        spriteScribbledMenu.setOrigin(sf::Vector2f(tamanhoScribbled.x / 2.0f, tamanhoScribbled.y / 2.0f));
        spriteScribbledMenu.setPosition(sf::Vector2f(720.0f, 650.0f));
    }
    if(texturaSetaMenu.loadFromFile("../assets/menu/arrow001.png")) {
        spriteSetaMenu.setTexture(texturaSetaMenu, true);
        sf::Vector2u tamanhoSeta = texturaSetaMenu.getSize();
        spriteSetaMenu.setOrigin(sf::Vector2f(tamanhoSeta.x / 2.0f, tamanhoSeta.y / 2.0f));
        spriteSetaMenu.setPosition(sf::Vector2f(625.0f, 800.0f));
    }
    if(texturaStartMenu.loadFromFile("../assets/menu/start001.png")) {
        spriteStartMenu.setTexture(texturaStartMenu, true);
        sf::Vector2u tamanhoStart = texturaStartMenu.getSize();
        spriteStartMenu.setOrigin(sf::Vector2f(0, tamanhoStart.y / 2.0f));
        spriteStartMenu.setPosition(sf::Vector2f(700.0f, 800.0f));
    }
    if(texturaTutorialMenu.loadFromFile("../assets/menu/tutorial001.png")) {
        spriteTutorialMenu.setTexture(texturaTutorialMenu, true);
        sf::Vector2u tamanhoTutorial = texturaTutorialMenu.getSize();
        spriteTutorialMenu.setOrigin(sf::Vector2f(0, tamanhoTutorial.y / 2.0f));
        spriteTutorialMenu.setPosition(sf::Vector2f(600.0f, 900.0f));
    }
    if(UIJogo.loadFromFile("../assets/uiplayerrpss/uiplayer001.png")) {
        spriteUIJogo.setTexture(UIJogo, true);
        spriteUIJogo.setPosition(sf::Vector2f(0.0f, 0.0f));
    }
    if(texturaMaoInt01.loadFromFile("../assets/jogador/handint001.png") &&
        texturaMaoInt02.loadFromFile("../assets/jogador/handint002.png") &&
        texturaMaoPapel.loadFromFile("../assets/jogador/handpaper001.png") &&
        texturaMaoTesoura.loadFromFile("../assets/jogador/handscissor001.png") &&
        texturaMaoPedra.loadFromFile("../assets/jogador/handrock001.png") &&
        texturaMaoCima.loadFromFile("../assets/jogador/handup001.png") &&
        texturaMaoDireita.loadFromFile("../assets/jogador/handright001.png") &&
        texturaMaoEsquerda.loadFromFile("../assets/jogador/handleft001.png") &&
        texturaMaoBaixo.loadFromFile("../assets/jogador/handdown001.png")) 
    {
        spriteMaoJogador.setTexture(texturaMaoInt01, true);
        sf::Vector2u tamanhoMao = texturaMaoInt01.getSize();
        spriteMaoJogador.setOrigin(sf::Vector2f(tamanhoMao.x, tamanhoMao.y));
        spriteMaoJogador.setPosition(sf::Vector2f(1440.0f, 960.0f));
    }

    if(texturaOponenteInt01.loadFromFile("../assets/oponente/girlint001.png") &&
        texturaOponenteInt02.loadFromFile("../assets/oponente/girlint002.png") &&
        texturaOponentePapel.loadFromFile("../assets/oponente/girlpaper001.png") &&
        texturaOponenteTesoura.loadFromFile("../assets/oponente/girlscissor001.png") &&
        texturaOponentePedra.loadFromFile("../assets/oponente/girlrock001.png") &&
        texturaOponenteCimaFase02.loadFromFile("../assets/oponente/girltype002up001.png") &&
        texturaOponenteDireitaFase02.loadFromFile("../assets/oponente/girltype002right001.png") &&
        texturaOponenteEsquerdaFase02.loadFromFile("../assets/oponente/girltype002left001.png") &&
        texturaOponenteBaixoFase02.loadFromFile("../assets/oponente/girltype002down001.png") &&
        texturaOponenteCimaFase03.loadFromFile("../assets/oponente/girltype003up001.png") &&
        texturaOponenteDireitaFase03.loadFromFile("../assets/oponente/girltype003right001.png") &&
        texturaOponenteEsquerdaFase03.loadFromFile("../assets/oponente/girltype003left001.png") &&
        texturaOponenteBaixoFase03.loadFromFile("../assets/oponente/girltype003down001.png") &&
        texturaOponenteVitoria01.loadFromFile("../assets/oponente/girlwin001.png") &&
        texturaOponenteVitoria02.loadFromFile("../assets/oponente/girlwin002.png") &&
        texturaOponenteDerrota.loadFromFile("../assets/oponente/girlloss001.png") &&
        texturaOponenteOlhosCima.loadFromFile("../assets/oponente/girleyesup001.png") &&
        texturaOponenteOlhosDireita.loadFromFile("../assets/oponente/girleyesright001.png") &&
        texturaOponenteOlhosEsquerda.loadFromFile("../assets/oponente/girleyesleft001.png") &&
        texturaOponenteOlhosBaixo.loadFromFile("../assets/oponente/girleyesdown001.png"))
    {
        spriteOponente.setTexture(texturaOponenteInt01, true);
        sf::Vector2u tamanhoOponente = texturaOponenteInt01.getSize();
        spriteOponente.setOrigin(sf::Vector2f(0, 0));
        spriteOponente.setPosition(sf::Vector2f(50.0f, 150.0f));
    }

    if(texturaVidaCheia.loadFromFile("../assets/uiplayerrpss/heartnew001.png") &&
        texturaVidaVazia.loadFromFile("../assets/uiplayerrpss/heartnew002.png")) 
    {
        spriteVida001.setTexture(texturaVidaCheia, true);
        spriteVida001.setPosition(sf::Vector2f(100.0f, -10.0f));
        spriteVida002.setTexture(texturaVidaCheia, true);
        spriteVida002.setPosition(sf::Vector2f(200.0f, -5.0f));
        spriteVida003.setTexture(texturaVidaCheia, true);
        spriteVida003.setPosition(sf::Vector2f(300.0f, 0.0f));
    }
}


// ========================================================
// NOVA FUNÇÃO: Prepara a mesa antes do tempo começar
// ========================================================
void Game::iniciarRound(EstadoJogo novoEstado) {
    estadoAtual = novoEstado;
    escolhaJogador = 0; // Zera a sua escolha
    jogadaFinalizada = false; // Avisa que o tempo tá rolando
    resultadoCalculado = false; // Avisa que o resultado ainda não foi calculado
    
    // O oponente já faz a escolha dele AQUI, no inicio da rodada
    if (estadoAtual == EstadoJogo::Round1) {
        escolhaOponente = (rand() % 3) + 1;
    } else {
        escolhaOponente = (rand() % 4) + 1;
    }
    
    clockPrincipal.restart(); // Dispara o cronômetro!
}

void Game::run() {
    while(window.isOpen()) {
        processarEventos();
        atualizar();
        renderizar();
    }
}

void Game::processarEventos() {
    while(const auto event = window.pollEvent()) {
        if(event->is<sf::Event::Closed>()) {
            window.close();
        } 

        const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();

        if(keyPressed) {
            if(estadoAtual == EstadoJogo::Menu) {
                if(keyPressed->code == sf::Keyboard::Key::Up) {
                    if(opcaoMenu == 2) {
                        opcaoMenu = 1;

                        spriteTutorialMenu.setPosition(sf::Vector2f(600.0f, 900.0f));
                        spriteStartMenu.setPosition(sf::Vector2f(700.0f, 800.0f));
                        spriteSetaMenu.setPosition(sf::Vector2f(625.0f, 800.0f));

                        window.draw(spriteTutorialMenu);
                        window.draw(spriteStartMenu);
                        window.draw(spriteSetaMenu);
                    }
                }
                if(keyPressed->code == sf::Keyboard::Key::Down) {
                    if(opcaoMenu == 1) {
                        opcaoMenu = 2;

                        spriteTutorialMenu.setPosition(sf::Vector2f(675.0f, 900.0f));
                        spriteStartMenu.setPosition(sf::Vector2f(600.0f, 800.0f));
                        spriteSetaMenu.setPosition(sf::Vector2f(625.0f, 900.0f));

                        window.draw(spriteTutorialMenu);
                        window.draw(spriteStartMenu);
                        window.draw(spriteSetaMenu);
                    }
                }
                if(keyPressed->code == sf::Keyboard::Key::Enter) {
                    if(opcaoMenu == 1) {
                        tempoLimite = TEMPO_INICIAL;
                        vidas = 3;
                        pontuacao = 0;
                        iniciarRound(EstadoJogo::Round1); // Chama a função nova
                    } else {
                    
                    }
                }
            }
            else if (estadoAtual == EstadoJogo::Round1 || estadoAtual == EstadoJogo::Round2 || estadoAtual == EstadoJogo::Round3) {
                
                // Enquanto o tempo não acabar, o jogador pode mudar de ideia à vontade!
                if(!jogadaFinalizada) {
                    if(keyPressed->code == sf::Keyboard::Key::Up) { escolhaJogador = 1; }
                    else if(keyPressed->code == sf::Keyboard::Key::Right) { escolhaJogador = 2; }
                    else if(keyPressed->code == sf::Keyboard::Key::Left) { escolhaJogador = 3; }
                    else if(keyPressed->code == sf::Keyboard::Key::Down) { 
                        if(estadoAtual != EstadoJogo::Round1) { escolhaJogador = 4; }
                    }
                }
            }
        }
    }
}

void Game::atualizar() {
    if(estadoAtual == EstadoJogo::Menu) {
        if(clockAnimacaoScribbled.getElapsedTime().asSeconds() >= 0.5f) {
            if(ehFrameScribbled01) {
                spriteScribbledMenu.setTexture(texturaScribbled02Menu, true);
                ehFrameScribbled01 = false;
            } else {
                spriteScribbledMenu.setTexture(texturaScribbled01Menu, true);
                ehFrameScribbled01 = true;
            }

            clockAnimacaoScribbled.restart();
        }
    }
    
    if(estadoAtual == EstadoJogo::Round1 || estadoAtual == EstadoJogo::Round2 || estadoAtual == EstadoJogo::Round3) {
        if (vidas >= 1) spriteVida001.setTexture(texturaVidaCheia, true);
        else spriteVida001.setTexture(texturaVidaVazia, true);

        if (vidas >= 2) spriteVida002.setTexture(texturaVidaCheia, true);
        else spriteVida002.setTexture(texturaVidaVazia, true);

        if (vidas >= 3) spriteVida003.setTexture(texturaVidaCheia, true);
        else spriteVida003.setTexture(texturaVidaVazia, true);

        sf::Vector2u tamanhoJanela = window.getSize();

        // Arrays de ponteiros para as texturas do jogador
        sf::Texture* opcoesJankenpoJogador[] = {&texturaMaoPapel, &texturaMaoTesoura, &texturaMaoPedra};
        sf::Texture* opcoesDirecaoJogador[] = {&texturaMaoCima, &texturaMaoDireita, &texturaMaoEsquerda, &texturaMaoBaixo};

        // Arrays de ponteiros para as texturas do oponente
        sf::Texture* opcoesJankenpoOponente[] = {&texturaOponentePapel, &texturaOponenteTesoura, &texturaOponentePedra};
        sf::Texture* opcoesDirecaoOponenteFase02[] = {&texturaOponenteCimaFase02, &texturaOponenteDireitaFase02, &texturaOponenteEsquerdaFase02, &texturaOponenteBaixoFase02};
        sf::Texture* opcoesDirecaoOponenteFase03[] = {&texturaOponenteCimaFase03, &texturaOponenteDireitaFase03, &texturaOponenteEsquerdaFase03, &texturaOponenteBaixoFase03};
        sf::Texture* opcoesDirecaoOponenteOlhos[] = {&texturaOponenteOlhosCima, &texturaOponenteOlhosDireita, &texturaOponenteOlhosEsquerda, &texturaOponenteOlhosBaixo};

        // ========================================================
        // 1. O TEMPO ESTÁ ROLANDO (A MESA ESTÁ ABERTA)
        // ========================================================
        if(!jogadaFinalizada) {
            float tempoRestante = tempoLimite - clockPrincipal.getElapsedTime().asSeconds();
            float tempoPassado = clockPrincipal.getElapsedTime().asSeconds();

            // Mostra o cronômetro descendo na tela
            if(tempoRestante > 0.0f) {
                // Mostra o que você selecionou até agora
                if (estadoAtual == EstadoJogo::Round1) {
                    if(tempoPassado > tempoLimite * 0.8f) {
                        spriteMaoJogador.setTexture(texturaMaoInt02, true);
                        spriteOponente.setTexture(texturaOponenteInt02, true);
                    }
                    else if(tempoPassado > tempoLimite * 0.6f) {
                        spriteMaoJogador.setTexture(texturaMaoInt01, true);
                        spriteOponente.setTexture(texturaOponenteInt01, true);
                    }
                    else if(tempoPassado > tempoLimite * 0.4f) {
                        spriteMaoJogador.setTexture(texturaMaoInt02, true);
                        spriteOponente.setTexture(texturaOponenteInt02, true);
                    }
                    else if(tempoPassado >= 0.0f) {
                        spriteMaoJogador.setTexture(texturaMaoInt01, true);
                        spriteOponente.setTexture(texturaOponenteInt01, true);
                    }
                } 
                else if (estadoAtual == EstadoJogo::Round2) {
                    if(tempoPassado > tempoLimite * 0.5f) {
                        spriteOponente.setTexture(*opcoesDirecaoOponenteOlhos[escolhaOponente - 1], true);
                    } else if(tempoPassado >= 0.0f) {
                        spriteOponente.setTexture(texturaOponenteInt01, true);
                    }

                    if(tempoPassado > tempoLimite * 0.8f) {
                        spriteMaoJogador.setTexture(texturaMaoInt02, true);
                    }
                    else if(tempoPassado >= 0.0f) {
                        spriteMaoJogador.setTexture(texturaMaoInt01, true);
                    }
                } 
                else if (estadoAtual == EstadoJogo::Round3) {
                    if(tempoPassado > tempoLimite * 0.5f) {
                        spriteOponente.setTexture(*opcoesDirecaoOponenteOlhos[escolhaOponente - 1], true);
                    } else if(tempoPassado >= 0.0f) {
                        spriteOponente.setTexture(texturaOponenteInt01, true);
                    }

                    if(tempoPassado > tempoLimite * 0.8f) {
                        spriteMaoJogador.setTexture(texturaMaoInt02, true);
                    }
                    else if(tempoPassado >= 0.0f) {
                        spriteMaoJogador.setTexture(texturaMaoInt01, true);
                    }
                }
            } 
            // O TEMPO ACABOU! TRAVA A JOGADA.
            else {
                if (escolhaJogador == 0) escolhaJogador = -1; // Se não escolheu nada, perdeu por tempo
                jogadaFinalizada = true;
                clockJogadaFinalizada.restart();
            }

            wstringstream ss;
            ss << setfill(L'0') << setw(4) << pontuacao;
            textoPlacar.setString(ss.str());
            //textoVidas.setString(L"Vidas: " + std::to_wstring(vidas));
        } 
        
        // ========================================================
        // 2. O TEMPO ACABOU (MOSTRA O RESULTADO)
        // ========================================================
        else {
            // Se o resultado ainda não foi calculado, calcula o resultado da rodada
            if (!resultadoCalculado) { 
                resultadoCalculado = true; // Marca que o resultado já foi calculado

                if (estadoAtual == EstadoJogo::Round1) {
                    if (escolhaJogador != -1) {
                        spriteMaoJogador.setTexture(*opcoesJankenpoJogador[escolhaJogador - 1], true);
                    }
                } else if (estadoAtual == EstadoJogo::Round2) {
                    if (escolhaJogador != -1) {
                        spriteMaoJogador.setTexture(*opcoesDirecaoJogador[escolhaJogador - 1], true);
                    }
                } else if (estadoAtual == EstadoJogo::Round3) {
                    if (escolhaJogador != -1) {
                        spriteMaoJogador.setTexture(*opcoesDirecaoJogador[escolhaJogador - 1], true);
                    }
                }

                // REGRAS DO ROUND 1
                if (estadoAtual == EstadoJogo::Round1) {
                    if (escolhaJogador == -1) {
                        texturaFinalRodada = texturaOponenteVitoria01;

                        proximoEstado = EstadoJogo::Round3;
                    } 
                    else if (escolhaJogador == escolhaOponente) {
                        proximoEstado = EstadoJogo::Round1;
                    }
                    // CONDICIONAL DE VITÓRIA
                    else if((escolhaJogador == 1 && escolhaOponente == 3) || 
                            (escolhaJogador == 2 && escolhaOponente == 1) || 
                            (escolhaJogador == 3 && escolhaOponente == 2))   
                    {
                        texturaFinalRodada = texturaOponenteDerrota;
                        proximoEstado = EstadoJogo::Round2; 
                    } 
                    // CONDICIONAL DE DERROTA
                    else {
                        texturaFinalRodada = texturaOponenteVitoria01;

                        proximoEstado = EstadoJogo::Round3; 
                    }
                }
                
                // REGRAS DO ROUND 2
                else if (estadoAtual == EstadoJogo::Round2) {
                    if (escolhaJogador == escolhaOponente && escolhaJogador != -1) {
                        pontuacao++; 
                        texturaFinalRodada = texturaOponenteDerrota;
                        proximoEstado = EstadoJogo::Round1; 

                    } else {
                        texturaFinalRodada = texturaOponenteVitoria01;
                        proximoEstado = EstadoJogo::Round1; 
                    }

                    if (tempoLimite > TEMPO_MINIMO) {
                        tempoLimite -= 0.1f; 
                    }
                }

                // REGRAS DO ROUND 3
                else if (estadoAtual == EstadoJogo::Round3) {
                    if (escolhaJogador != escolhaOponente && escolhaJogador != -1) {
                        texturaFinalRodada = texturaOponenteDerrota;
                        proximoEstado = EstadoJogo::Round1; 
                    } else {
                        texturaFinalRodada = texturaOponenteVitoria01;
                        vidas--; 
                        if (vidas <= 0) {
                            proximoEstado = EstadoJogo::Menu;
                        } else {
                            proximoEstado = EstadoJogo::Round1; 
                        }
                    }

                    if (tempoLimite > TEMPO_MINIMO) {
                        tempoLimite -= 0.1f; 
                    }
                }
            }
        }

        // ========================================================
        // 3. TRANSIÇÃO DE TELAS (O RESET APÓS 3 SEGUNDOS)
        // ========================================================
        if(jogadaFinalizada) {
            float tempoEspera = clockJogadaFinalizada.getElapsedTime().asSeconds();
            
            if(tempoEspera < tempoLimite * 0.7f) {
                if(estadoAtual == EstadoJogo::Round1) {
                    spriteOponente.setTexture(*opcoesJankenpoOponente[escolhaOponente - 1], true);
                }
                else if(estadoAtual == EstadoJogo::Round2) {
                    spriteOponente.setTexture(*opcoesDirecaoOponenteFase02[escolhaOponente - 1], true);
                }
                else if(estadoAtual == EstadoJogo::Round3) {
                    spriteOponente.setTexture(*opcoesDirecaoOponenteFase03[escolhaOponente - 1], true);
                }
            }
            else if(tempoEspera < tempoLimite * 1.4f) {
                spriteOponente.setTexture(texturaFinalRodada, true);
            }
            else {
                texturaFinalRodada = texturaOponenteInt01; // Reseta a textura do oponente para a próxima rodada
                spriteMaoJogador.setTexture(texturaMaoInt01, true);
                // Pula para a tela seguinte sorteando o oponente de novo!
                iniciarRound(proximoEstado); 
            }
        }

        // ALINHAMENTOS NA TELA (Inalterado)
        textoPlacar.setOrigin(sf::Vector2f(textoPlacar.getLocalBounds().size.x, 0.0f));
        textoPlacar.setPosition(sf::Vector2f(1200, -15));
    }
}

void Game::renderizar() {
    window.clear();

    window.draw(spriteBackground);

    if(estadoAtual == EstadoJogo::Menu) {
        window.draw(spriteLogoMenu);
        window.draw(spriteScribbledMenu);
        window.draw(spriteTutorialMenu);
        window.draw(spriteStartMenu);
        window.draw(spriteSetaMenu);
    }
    else if(estadoAtual == EstadoJogo::Round1 || estadoAtual == EstadoJogo::Round2 || estadoAtual == EstadoJogo::Round3) {
        window.draw(spriteUIJogo);
        window.draw(textoPlacar);
        window.draw(spriteMaoJogador);
        window.draw(spriteOponente);
        window.draw(spriteVida001);
        window.draw(spriteVida002);
        window.draw(spriteVida003);
    }

    window.display();
}