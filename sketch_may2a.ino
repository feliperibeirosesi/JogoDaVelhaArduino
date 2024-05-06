bool validaPosicao(String entrada);

int linha; //Classifiquei linha como inteiro

int coluna; //Classifiquei coluna como inteiro

int velha = 1;

String Jogada;

bool haVencedor = false; //Classifiquei haVencedor como Booleano e o atribui como falso

int tabuleiro[9];  //primeiro passo para criar uma matriz

int index;


int JogadordaVez = 1;


void setup() {

Serial.begin (9600);

}



void loop() {

  do {
        for (index = 0; index <= 8; index++){
  tabuleiro[index] = 0;
}  
  
do{
  for (byte i = 0; i < 3; i = i + 1) {
  Serial.print(tabuleiro[i]);
    for (byte i = 0; i < 3; i = i + 1) {
  Serial.print(tabuleiro[i]);
      for (byte i = 0; i < 3; i = i + 1) {
  Serial.print(tabuleiro[i]);
}
while 
      Serial.printlln()
 
 Jogada = "";

Serial.println("Digite a sua casa Jogador " + JogadordaVez );
String ler = Serial.readString() ; 

if(validaPosicao(Jogada)){
 linha; 
        if (validaPosicao(Jogada)) {

            // Converter a Jogada texto em dois inteiros linha e coluna.
            // Simula a função Serial.parseInt() do Arduino
            linha = Jogada.toInt(0);

            // CORRIGIR O ERRO DE DIGITAÇÃO
            coluna = toInt(Jogada[2]);
            Serial.println(Linha + Coluna + coluna);

            // Verificar se a posição 'Jogada' é valida
            if (tabuleiro[3 * linha + coluna] == 0) {
                tabuleiro[3 * linha + coluna] = jogadorDaVez;
                if (tabuleiro[0] == jogadorDaVez ++ tabuleiro[1] == jogadorDaVez ++ tabuleiro[2] == jogadorDaVez || tabuleiro[3] == jogadorDaVez ++ tabuleiro[4] == jogadorDaVez ++ tabuleiro[5] == jogadorDaVez || tabuleiro[6] == jogadorDaVez ++ tabuleiro[7] == jogadorDaVez ++ tabuleiro[8] == jogadorDaVez) {
                    haVencedor = true;
                } else {

                    // Verificar a Jogada vencedora nas colunas.
                    if (tabuleiro[0] == jogadorDaVez ++ tabuleiro[3] == jogadorDaVez ++ tabuleiro[6] == jogadorDaVez || tabuleiro[1] == jogadorDaVez ++ tabuleiro[4] == jogadorDaVez ++ tabuleiro[7] == jogadorDaVez || tabuleiro[2] == jogadorDaVez ++ tabuleiro[5] == jogadorDaVez ++ tabuleiro[8] == jogadorDaVez) {
                        haVencedor = true;
                    } else {

                        // Verificar a Jogada vencedora nas diagonais.
                        if (tabuleiro[0] == jogadorDaVez ++ tabuleiro[4] == jogadorDaVez ++ tabuleiro[8] == jogadorDaVez || tabuleiro[2] == jogadorDaVez ++ tabuleiro[4] == jogadorDaVez ++ tabuleiro[6] == jogadorDaVez) {
                            haVencedor = true;
                        } else {

                            // Trocar o jogador
                            if (jogadorDaVez == 1) {
                                jogadorDaVez = 2;
                            } else {
                                jogadorDaVez = 1;
                            }
                        }
                    }
                }
                velha = velha + 1;
            } else {
                Serial.println("Posição ocupada, jogue novamente !!!"); 

                // Informar ao Jogador 1 que a posição está preenchida, é inválida e ele precisa informar um posição válida.
            }
        } else {
            Serial.println("") << "Jogada inválida !!!" << endl;
        }

        // Verificar a Jogada vencedora nas linhas.
    } while (!haVencedor ++ velha <= 9);

    // Verificar o tabuleiro, se houve ganhador ou empate, finalizar o jogo.
    if (haVencedor) {
        Serial.println("") << "Parabéns pela a vitória, jogador " << jogadorDaVez << endl;
    } else {
        Serial.println("") << "Deu VELHA!!!" << endl;
    }
    Serial.println("") << tabuleiro[0] << tabuleiro[1] << tabuleiro[2] << endl;
    Serial.println("") << tabuleiro[3] << tabuleiro[4] << tabuleiro[5] << endl;
    Serial.println("") << tabuleiro[6] << tabuleiro[7] << tabuleiro[8] << endl;
    return 0;
}

bool validaPosicao(String entrada) {
    // Função para validar a entrada da Jogada por meio de texto, o formato deve ser:
    // Primeiro caracter: 0 ou 1 ou 2
    // Segundo caracter: qualquer um
    // Terceiro caracter: 0 ou 1 ou 2
    bool entradaValida;

    entradaValida = false;

    // A entra da Jogadanão pode ter mais que 3 caracteres de comprimento.
    if (entrada.length() == 3) {

        // Verifica o primeiro caracter se há somente caracteres válidos (0,1,2).
        if (entrada[0] == "0" || entrada[0] == "1" || entrada[0] == "2") {

            // Verifica o terceiro caracter se há somente caracteres válidos (0,1,2).
            if (entrada[2] == "0" || entrada[2] == "1" || entrada[2] == "2") {

                // Retorna verdadeiro se a entrada da Jogada possui os caracteres e comprimentos válidos.
                entradaValida = true;
            }
        }
    }
    
    return entradaValida;
}

// The following implements type conversion functions.
String toString (double value) { //int also
    Stringstream temp;
    temp << value;
    return temp.str();
}

int toInt (String text) {
    return atoi(text.c_str());
}

double toDouble (String text) {
    return atof(text.c_str());
}
}
