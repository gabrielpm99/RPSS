#include "../include/Game.hpp"

Game::Game() {
    window.create(sf::VideoMode(sf::Vector2u(1440, 960)), "Jankenpo");
    window.setFramerateLimit(60);
    estadoAtual = EstadoJogo::Menu;

    if (fonte.openFromFile("../assets/arial.ttf")) {

        sf::Vector2u tamanhoJanela = window.getSize();

        textoOponente.setCharacterSize(50);
        textoResultado.setCharacterSize(55);
        
        textoTempo.setCharacterSize(50);
        textoTempo.setFillColor(sf::Color(255, 100, 100));

        textoPlacar.setCharacterSize(45);
        textoVidas.setCharacterSize(45);
        textoVidas.setFillColor(sf::Color::Green);
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
    if(texturaLogoMenu.loadFromFile("../assets/rockpaperscissor.png")) {
        spriteLogoMenu.setTexture(texturaLogoMenu, true);
        spriteLogoMenu.setPosition(sf::Vector2f(0.0f, 150.0f));
    }
    if(texturaScribbled01Menu.loadFromFile("../assets/scribbled001.png") && texturaScribbled02Menu.loadFromFile("../assets/scribbled002.png")) {
        spriteScribbledMenu.setTexture(texturaScribbled01Menu, true);
        sf::Vector2u tamanhoScribbled = texturaScribbled01Menu.getSize();
        spriteScribbledMenu.setOrigin(sf::Vector2f(tamanhoScribbled.x / 2.0f, tamanhoScribbled.y / 2.0f));
        spriteScribbledMenu.setPosition(sf::Vector2f(720.0f, 650.0f));
    }
    if(texturaSetaMenu.loadFromFile("../assets/arrow001.png")) {
        spriteSetaMenu.setTexture(texturaSetaMenu, true);
        sf::Vector2u tamanhoSeta = texturaSetaMenu.getSize();
        spriteSetaMenu.setOrigin(sf::Vector2f(tamanhoSeta.x / 2.0f, tamanhoSeta.y / 2.0f));
        spriteSetaMenu.setPosition(sf::Vector2f(625.0f, 800.0f));
    }
    if(texturaStartMenu.loadFromFile("../assets/start001.png")) {
        spriteStartMenu.setTexture(texturaStartMenu, true);
        sf::Vector2u tamanhoStart = texturaStartMenu.getSize();
        spriteStartMenu.setOrigin(sf::Vector2f(0, tamanhoStart.y / 2.0f));
        spriteStartMenu.setPosition(sf::Vector2f(700.0f, 800.0f));
    }
    if(texturaTutorialMenu.loadFromFile("../assets/tutorial001.png")) {
        spriteTutorialMenu.setTexture(texturaTutorialMenu, true);
        sf::Vector2u tamanhoTutorial = texturaTutorialMenu.getSize();
        spriteTutorialMenu.setOrigin(sf::Vector2f(0, tamanhoTutorial.y / 2.0f));
        spriteTutorialMenu.setPosition(sf::Vector2f(600.0f, 900.0f));
    }
    if(texturaMaoIntermediaria01.loadFromFile("../assets/handint001.png") &&
        texturaMaoIntermediaria02.loadFromFile("../assets/handint002.png") &&
        texturaMaoPapel.loadFromFile("../assets/handpaper001.png") &&
        texturaMaoTesoura.loadFromFile("../assets/handscissor001.png") &&
        texturaMaoPedra.loadFromFile("../assets/handrock001.png") &&
        texturaMaoCima.loadFromFile("../assets/handup001.png") &&
        texturaMaoDireita.loadFromFile("../assets/handright001.png") &&
        texturaMaoEsquerda.loadFromFile("../assets/handleft001.png") &&
        texturaMaoBaixo.loadFromFile("../assets/handdown001.png")) 
    {
        spriteMaoJogador.setTexture(texturaMaoIntermediaria01, true);
        sf::Vector2u tamanhoMao = texturaMaoIntermediaria01.getSize();
        spriteMaoJogador.setOrigin(sf::Vector2f(tamanhoMao.x, tamanhoMao.y));
        spriteMaoJogador.setPosition(sf::Vector2f(1440.0f, 960.0f));
    }
}


// ========================================================
// NOVA FUNÇÃO: Prepara a mesa antes do tempo começar
// ========================================================
void Game::iniciarRound(EstadoJogo novoEstado) {
    estadoAtual = novoEstado;
    escolhaJogador = 0; // Zera a sua escolha
    jogadaFinalizada = false; // Avisa que o tempo tá rolando
    
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
        sf::Vector2u tamanhoJanela = window.getSize();

        // Arrays de vocabulário para facilitar
        sf::Texture* opcoesJankenpoJogador[] = {&texturaMaoPapel, &texturaMaoTesoura, &texturaMaoPedra};
        sf::Texture* opcoesDirecaoJogador[] = {&texturaMaoCima, &texturaMaoDireita, &texturaMaoEsquerda, &texturaMaoBaixo};
        string opcoesJankenpo[] = {"", "Papel", "Tesoura", "Pedra"};
        string opcoesDirecao[] = {"", "Cima", "Direita", "Esquerda", "Baixo"};

        // ========================================================
        // 1. O TEMPO ESTÁ ROLANDO (A MESA ESTÁ ABERTA)
        // ========================================================
        if(!jogadaFinalizada) {
            float tempoRestante = tempoLimite - clockPrincipal.getElapsedTime().asSeconds();
            float tempoPassado = clockPrincipal.getElapsedTime().asSeconds();
            float tempoPorFrame = tempoLimite / 5.0f;

            // Mostra o cronômetro descendo na tela
            if(tempoRestante > 0.0f) {
                textoTempo.setString(L"Tempo: " + std::to_wstring(tempoRestante).substr(0, 3) + L"s");

                // Mostra o que você selecionou até agora
                if (estadoAtual == EstadoJogo::Round1) {
                    if(tempoPassado > tempoPorFrame * 4) spriteMaoJogador.setTexture(texturaMaoIntermediaria02, true);
                    else if(tempoPassado > tempoPorFrame * 3) spriteMaoJogador.setTexture(texturaMaoIntermediaria01, true);
                    else if(tempoPassado > tempoPorFrame * 2) spriteMaoJogador.setTexture(texturaMaoIntermediaria02, true);
                    else if(tempoPassado > 0.0f) spriteMaoJogador.setTexture(texturaMaoIntermediaria01, true);
                    
                    // INDÍCIOS DO ROUND 1 (Oponente se preparando)
                    string indicios[] = {"", "[Oponente relaxa a mao...]", "[Oponente levanta 2 dedos...]", "[Oponente fecha a mao...]"};
                    textoOponente.setString(indicios[escolhaOponente]);
                    textoOponente.setFillColor(sf::Color(150, 150, 150)); // Cinza pra parecer uma dica
                } 
                else if (estadoAtual == EstadoJogo::Round2) {
                    if(tempoPassado > tempoPorFrame * 3) spriteMaoJogador.setTexture(texturaMaoIntermediaria02, true);
                    else if(tempoPassado > 0.0f) spriteMaoJogador.setTexture(texturaMaoIntermediaria01, true);

                    // No Round 2, o NPC olha primeiro e fica assim durante o tempo todo
                    textoOponente.setString("NPC OLHA para: " + opcoesDirecao[escolhaOponente]);
                    textoOponente.setFillColor(sf::Color::White);
                } 
                else if (estadoAtual == EstadoJogo::Round3) {
                    if(tempoPassado > tempoPorFrame * 3) spriteMaoJogador.setTexture(texturaMaoIntermediaria02, true);
                    else if(tempoPassado > 0.0f) spriteMaoJogador.setTexture(texturaMaoIntermediaria01, true);

                    // No Round 3, o NPC aponta primeiro e fica assim durante o tempo todo
                    textoOponente.setString("NPC APONTA para: " + opcoesDirecao[escolhaOponente]);
                    textoOponente.setFillColor(sf::Color::White);
                }
            } 
            // O TEMPO ACABOU! TRAVA A JOGADA.
            else {
                if (escolhaJogador == 0) escolhaJogador = -1; // Se não escolheu nada, perdeu por tempo
                jogadaFinalizada = true;
                clockJogadaFinalizada.restart();
            }

            textoPlacar.setString(L"Pontos: " + std::to_wstring(pontuacao));
            textoVidas.setString(L"Vidas: " + std::to_wstring(vidas));
        } 
        
        // ========================================================
        // 2. O TEMPO ACABOU (MOSTRA O RESULTADO)
        // ========================================================
        else {
            textoTempo.setString("TEMPO ESGOTADO!");

            // Roda as regras de ganho só uma vez quando o texto de resultado ainda está vazio
            if (textoResultado.getString().isEmpty()) { 
                
                textoOponente.setFillColor(sf::Color::White); // Tira o cinza do indício

                if (estadoAtual == EstadoJogo::Round1) {
                    if (escolhaJogador != -1) {
                        spriteMaoJogador.setTexture(*opcoesJankenpoJogador[escolhaJogador - 1], true);
                    }
                    textoOponente.setString("Oponente jogou: " + opcoesJankenpo[escolhaOponente]);
                } else {
                    if (escolhaJogador != -1) {
                        spriteMaoJogador.setTexture(*opcoesDirecaoJogador[escolhaJogador - 1], true);
                    }
                    textoOponente.setString("Oponente jogou: " + opcoesDirecao[escolhaOponente]);
                }

                // REGRAS DO ROUND 1
                if (estadoAtual == EstadoJogo::Round1) {
                    if (escolhaJogador == -1) {
                        textoResultado.setString("Derrota por tempo");
                        textoResultado.setFillColor(sf::Color::Red);
                        proximoEstado = EstadoJogo::Round1; 
                    } 
                    else if (escolhaJogador == escolhaOponente) {
                        textoResultado.setString("Empate");
                        textoResultado.setFillColor(sf::Color::Yellow);
                        proximoEstado = EstadoJogo::Round1; 
                    }
                    else if((escolhaJogador == 1 && escolhaOponente == 3) || 
                            (escolhaJogador == 2 && escolhaOponente == 1) || 
                            (escolhaJogador == 3 && escolhaOponente == 2))   
                    {
                        textoResultado.setString("Vitoria! Round 2...");
                        textoResultado.setFillColor(sf::Color::Green);
                        proximoEstado = EstadoJogo::Round2; 
                    } 
                    else {
                        textoResultado.setString("Derrota");
                        textoResultado.setFillColor(sf::Color::Red);
                        proximoEstado = EstadoJogo::Round1; 
                    }
                }
                
                // REGRAS DO ROUND 2
                else if (estadoAtual == EstadoJogo::Round2) {
                    if (escolhaJogador == escolhaOponente && escolhaJogador != -1) {
                        pontuacao++; 
                        textoResultado.setString("Vitoria! Round 3...");
                        textoResultado.setFillColor(sf::Color::Green);
                        
                        if (tempoLimite > tempoLimite - 0.5f) {
                            tempoLimite -= 0.1f; 
                        }
                        proximoEstado = EstadoJogo::Round3; 

                    } else {
                        textoResultado.setString("Derrota");
                        textoResultado.setFillColor(sf::Color::Red);
                        proximoEstado = EstadoJogo::Round1; 
                    }
                }

                // REGRAS DO ROUND 3
                else if (estadoAtual == EstadoJogo::Round3) {
                    if (escolhaJogador != escolhaOponente && escolhaJogador != -1) {
                        textoResultado.setString("Vitoria!");
                        textoResultado.setFillColor(sf::Color::Green);
                        proximoEstado = EstadoJogo::Round1; 
                    } else {
                        textoResultado.setString("Derrota");
                        textoResultado.setFillColor(sf::Color::Red);
                        
                        vidas--; 
                        if (vidas <= 0) {
                            proximoEstado = EstadoJogo::Menu;
                        } else {
                            proximoEstado = EstadoJogo::Round1; 
                        }
                    }
                }
            }
        }

        // ========================================================
        // 3. TRANSIÇÃO DE TELAS (O RESET APÓS 3 SEGUNDOS)
        // ========================================================
        if(jogadaFinalizada) {
            if(clockJogadaFinalizada.getElapsedTime().asSeconds() >= tempoLimite) { 
                textoOponente.setString("");
                textoResultado.setString("");

                // Pula para a tela seguinte sorteando o oponente de novo!
                iniciarRound(proximoEstado); 
            }
        }

        // ALINHAMENTOS NA TELA (Inalterado)
        textoTempo.setOrigin(sf::Vector2f(textoTempo.getLocalBounds().size.x / 2.f, textoTempo.getLocalBounds().size.y / 2.f));
        textoTempo.setPosition(sf::Vector2f(tamanhoJanela.x * 0.5f, tamanhoJanela.y * 0.1f));

        textoVidas.setOrigin(sf::Vector2f(textoVidas.getLocalBounds().size.x / 2.f, textoVidas.getLocalBounds().size.y / 2.f));
        textoVidas.setPosition(sf::Vector2f(tamanhoJanela.x * 0.2f, tamanhoJanela.y * 0.1f));

        textoPlacar.setOrigin(sf::Vector2f(textoPlacar.getLocalBounds().size.x / 2.f, textoPlacar.getLocalBounds().size.y / 2.f));
        textoPlacar.setPosition(sf::Vector2f(tamanhoJanela.x * 0.8f, tamanhoJanela.y * 0.1f));

        textoOponente.setOrigin(sf::Vector2f(textoOponente.getLocalBounds().size.x / 2.f, textoOponente.getLocalBounds().size.y / 2.f));
        textoOponente.setPosition(sf::Vector2f(tamanhoJanela.x * 0.5f, tamanhoJanela.y * 0.3f)); 

        textoResultado.setOrigin(sf::Vector2f(textoResultado.getLocalBounds().size.x / 2.f, textoResultado.getLocalBounds().size.y / 2.f));
        textoResultado.setPosition(sf::Vector2f(tamanhoJanela.x * 0.5f, tamanhoJanela.y * 0.5f)); 
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
        window.draw(textoTempo);
        window.draw(textoVidas);
        window.draw(textoPlacar);
        window.draw(spriteMaoJogador);
        window.draw(textoOponente);
        window.draw(textoResultado);
    }

    window.display();
}