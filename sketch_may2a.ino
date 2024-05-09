bool validaPosicao(String entrada);

int linha;  //Classifiquei linha como inteiro

int coluna;  //Classifiquei coluna como inteiro

int velha = 1;

String Jogada;

bool haVencedor = false;  //Classifiquei haVencedor como Booleano e o atribui como falso

int tabuleiro[9];  //primeiro passo para criar uma matriz

int index;


int JogadordaVez = 1;


void setup() {

  Serial.begin(9600);
}


void loop() {
  for (index = 0; index <= 8; index++) {
    tabuleiro[index] = 0;
  }

  do {
    Serial.print(tabuleiro[0]);
    Serial.print(tabuleiro[1]);
    Serial.println(tabuleiro[2]);
    Serial.print(tabuleiro[3]);
    Serial.print(tabuleiro[4]);
    Serial.println(tabuleiro[5]);
    Serial.print(tabuleiro[6]);
    Serial.print(tabuleiro[7]);
    Serial.println(tabuleiro[8]);

    Jogada = "";
    Serial.print("Digite a sua casa Jogador ");
    Serial.println(JogadordaVez);
    while (!Serial.available())
      ;
 
    String Jogada = Serial.readString();

    // lê o dado recebido:
    //Jogada = Serial.read();

    if (validaPosicao(Jogada)) {

      // Converter a Jogada texto em dois inteiros linha e coluna.
      // Simula a função Serial.parseInt() do Arduino
      linha = int(Jogada[0]) - '0';

      // CORRIGIR O ERRO DE DIGITAÇÃO
      coluna = int(Jogada[2]) - '0';
      Serial.print("Linha: ");
      Serial.print(linha);
      Serial.print(", Coluna: ");
      Serial.println(coluna);

      // Verificar se a posição 'Jogada' é valida
      if (tabuleiro[3 * linha + coluna] == 0) {
        tabuleiro[3 * linha & coluna] = JogadordaVez;
        if (JogadordaVez && tabuleiro[0] == JogadordaVez && tabuleiro[1] == JogadordaVez && tabuleiro[2] == JogadordaVez || tabuleiro[3] == JogadordaVez && tabuleiro[4] == JogadordaVez && tabuleiro[5] == JogadordaVez || tabuleiro[6] == JogadordaVez && tabuleiro[7] == JogadordaVez && tabuleiro[8] == JogadordaVez) {
          haVencedor = true;
        } else {

          // Verificar a Jogada vencedora nas colunas.
          if (JogadordaVez && tabuleiro[0] == JogadordaVez && tabuleiro[3] == JogadordaVez && tabuleiro[6] == JogadordaVez || tabuleiro[1] == JogadordaVez && tabuleiro[4] == JogadordaVez && tabuleiro[7] == JogadordaVez || tabuleiro[2] == JogadordaVez && tabuleiro[5] == JogadordaVez && tabuleiro[8] == JogadordaVez) {
            haVencedor = true;
          } else {

            // Verificar a Jogada vencedora nas diagonais.
            if (JogadordaVez && tabuleiro[0] == JogadordaVez && tabuleiro[4] == JogadordaVez && tabuleiro[8] == JogadordaVez || tabuleiro[2] == JogadordaVez && tabuleiro[4] == JogadordaVez && tabuleiro[6] == JogadordaVez) {
              haVencedor = true;
            } else {

              // Trocar o jogador
              if (JogadordaVez == 1) {
                JogadordaVez = 2;
              } else {
                JogadordaVez = 1;
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
      Serial.println("Jogada inválida !!!");
    }

    // Verificar a Jogada vencedora nas linhas.


  } while (!haVencedor && velha <= 9);
  // Verificar o tabuleiro, se houve ganhador ou empate, finalizar o jogo.
  if (haVencedor) {
    Serial.println("Parabéns pela a vitória, jogador" + JogadordaVez);
  } else {
    Serial.println("Deu VELHA!!!");
  }
  Serial.print(tabuleiro[0]);
  Serial.print(tabuleiro[1]);
  Serial.println(tabuleiro[2]);
  Serial.print(tabuleiro[3]);
  Serial.print(tabuleiro[4]);
  Serial.println(tabuleiro[5]);
  Serial.print(tabuleiro[6]);
  Serial.print(tabuleiro[7]);
  Serial.println(tabuleiro[8]);
}


bool validaPosicao(String entrada) {
  // Função para validar a entrada da Jogada por meio de texto, o formato deve ser:
  // Primeiro caracter: 0 ou 1 ou 2
  // Segundo caracter: qualquer um
  // Terceiro caracter: 0 ou 1 ou 2
  bool entradaValida = false;

  // A entra da Jogadanão pode ter mais que 3 caracteres de comprimento.
  if (entrada.length() == 3) {

    // Verifica o primeiro caracter se há somente caracteres válidos (0,1,2).
    if (entrada[0] == '0' || entrada[0] == '1' || entrada[0] == '2') {

      // Verifica o terceiro caracter se há somente caracteres válidos (0,1,2).
      if (entrada[2] == '0' || entrada[2] == '1' || entrada[2] == '2') {

        // Retorna verdadeiro se a entrada da Jogada possui os caracteres e comprimentos válidos.
        entradaValida = true;
      }
    }
  }
  return entradaValida;
}
