﻿function main() {
    var haVencedor;

    haVencedor = false;
    var jogada;

    // Criar o tabuleiro e os jogadores, zerar as variaveis
    // 0: posição vazia
    // 1: Jogada na posição do jogador 1
    // 2: Jogada na posição do jogador 2
    var linha;
    var coluna;
    var tabuleiro = createArray(9);

    // Limpar/zerar o tabuleiro
    var índice;

    for (índice = 0; índice <= 8; índice++) {
        tabuleiro[índice] = 0;
    }
    var jogadordavez;

    jogadordavez = 1;
    var tabuleiroValido;

    // inciar o jogo, definir quem joga primeiro
    var velha;

    velha = 1;
    do {
        var validar;

        window.alert(tabuleiro[0].ToString() + tabuleiro[1] + tabuleiro[2]);
        window.alert(tabuleiro[3].ToString() + tabuleiro[4] + tabuleiro[5]);
        window.alert(tabuleiro[6].ToString() + tabuleiro[7] + tabuleiro[8]);
        jogada = "";

        // anotar a jogada do primeiro jogador
        window.alert("Digite a posição da sua peça JOGADOR" + jogadordavez);
        jogada = window.prompt('Enter a value for jogada');
        validar = posicaoValida(jogada);
        if (validar) {
            if (jogada.length() == 3) {
                linha = parseInt(jogada.charAt(0));
                coluna = parseInt(jogada.charAt(2));
            } else {
                linha = parseInt(jogada.charAt(0));
                coluna = parseInt(jogada.charAt(1));
            }
            window.alert("Linha " + linha + ";Coluna " + coluna);
            if (tabuleiro[3 * linha + coluna] == 0) {
                tabuleiro[3 * linha + coluna] = jogadordavez;
                tabuleiroValido = validarTabuleiro(jogadordavez, tabuleiro);
                velha = velha + 1;
                if (tabuleiroValido != 2) {
                    if (jogadordavez == 1) {
                        jogadordavez = 2;
                    } else {
                        jogadordavez = 1;
                    }
                }
            } else {
                window.alert("posição ocupada, jogue novamente");

                // Informar ao jogador 1 que a posição está preenchida, é invalida e ela precisa informar uma posição valida
            }

            // converter a jogada texto em dois inteiros linha e coluna
        } else {
            window.alert("Entrada inválida !!!");
        }

        // verificar se a posição jogada é valida
    } while (tabuleiroValido == 0);
    if (tabuleiroValido < 9) {
        window.alert("Jogador " + jogadordavez + "; GANHOU!!!");
    } else {
        window.alert("Velha, ambos empataram.");
    }
    window.alert(tabuleiro[0].ToString() + tabuleiro[1] + tabuleiro[2]);
    window.alert(tabuleiro[3].ToString() + tabuleiro[4] + tabuleiro[5]);
    window.alert(tabuleiro[6].ToString() + tabuleiro[7] + tabuleiro[8]);

    // verificar o tabuleiro Se ouve ganhador ou empate, finalizar o jogo
    // Verificar jogada vencedora nas linhas
    // Verificar jogada vencedora nas colunas
    // Verificar jogada vencedora nas diagonais
    // anotar e registrar a jogada do segundo jogador
    // anotar e registrar a jogada do segundo jogador
    // Se ouve ganhador ou empate, finalizar o jogo
}

function posicaoValida(entrada) {
    var retorno;

    retorno = false;
    window.alert(entrada.length());
    if (entrada.length() == 3) {
        if (entrada.charAt(0) == "0" || entrada.charAt(0) == "1" || entrada.charAt(0) == "2") {
            if (entrada.charAt(2) == "0" || entrada.charAt(2) == "1" || entrada.charAt(2) == "2") {
                retorno = true;
            }
        }
    } else {
        if (entrada.length() == 2) {
            if (entrada.charAt(0) == "0" || entrada.charAt(0) == "1" || entrada.charAt(0) == "2") {
                if (entrada.charAt(1) == "0" || entrada.charAt(1) == "1" || entrada.charAt(1) == "2") {
                    retorno = true;
                }
            }
        }
    }
    
    return retorno;
}

function validarTabuleiro(jogadorDaVez, tabuleiro) {
    var resultado;

    resultado = 0;
    if (tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez || tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez || tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
        resultado = 2;
    } else {
        if (tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez || tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
            resultado = 2;
        } else {
            if (tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) {
                resultado = 2;
            }
        }
    }
    
    return resultado;
}
