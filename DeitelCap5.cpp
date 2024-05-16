/*
// Para comparação, copiando o código da Figura 5.24:
// Usado em 5.12, 5.13, 5.14 e 5.15.
// Programa de Embaralhamento e Retirada de Cartas
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::ios;
using std::setw;
using std::setiosflags;

void shuffle(int[][13]);
void deal(const int [][13], const char *[], const char *[]);

int main(){
    const char *suit[4] = {"Copas", "Ouros", "Paus", "Espadas"};
    const char *face[13] = {"Ás", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
    int deck[4][13] = {0};
    srand(time(0));
    shuffle(deck); // Embaralhar (O DECK COMPLETO)
    deal(deck, face, suit); // Dar carta (BASICAMENTE IMPRIME O NOME DAS COISAS EMBARALHADAS)
    return 0;
}

void shuffle(int wDeck[][13]){
    int row, column;
    for(int card = 1; card <= 52; card++){
        do{
            row = rand () % 4;
            column = rand() % 13;
        } while(wDeck[row][column] != 0);
        wDeck[row][column] = card;
    }
}

void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]){
    for(int card = 1; card <= 52; card++){
        for(int row = 0; row <= 3; row++){
            for(int column = 0; column <= 12; column++){
                if(wDeck[row][column] == card){
                    cout << setw(6) << setiosflags(ios::right) << wFace[column] << "de " << setw(7) << setiosflags(ios::left);
                    cout << wSuit[row] << (card % 2 == 0 ? '\n' : '\t');
                }
            }
        }
    }
}
*/

/*
// Exercício 5.12
// Sacando cartas 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::ios;
using std::endl;
using std::setw;
using std::setiosflags;

void shuffle(int[][13]);
void deal(const int [][13], const char *[], const char *[]);
void isEven(const int [][2]);

int main(){
    const char *suit[4] = {"Copas", "Ouros", "Paus", "Espadas"};
    const char *face[13] = {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
    int deck[4][13] = {{0}};
    srand(time(0));
    shuffle(deck); // Embaralhar (O DECK COMPLETO)
    deal(deck, face, suit); // Dar carta (BASICAMENTE IMPRIME O NOME DAS COISAS EMBARALHADAS)

    // Salvando as minhas cartas: vou fazer um linear search para achar onde estão salvas minhas cartas 1, 2, 3, 4 e 5, e vou salvá-las num array
    int arraySave[5][2] = {{0}};
    for(int k = 0; k < 5; k++){
        int cardNumber = k + 1; // Número da carta que queremos sacar
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 13; j++){
                if(deck[i][j] == cardNumber){ // Procura, por exemplo, onde em i e j está minha carta 1.
                    arraySave[k][0] = i; // Salva o naipe na coluna 0
                    arraySave[k][1] = j; // Salva o valor na coluna 1
                }
            }
        }
    }

    // Uma vez salvo no arraySave, vou verificar se existe par (Se é um par, dois pares, tripla ou quadra)
    cout << endl;
    isEven(arraySave);

    // Agora, verificar se é flush (todas as cartas são do mesmo naipe)
    if(arraySave[0][0] == arraySave[1][0] && arraySave[0][0] == arraySave[2][0] && arraySave[0][0] == arraySave[3][0] && arraySave[0][0] == arraySave[4][0] ){
        cout << "Eh flush de " << arraySave[0][0] << endl;
    }

    // Por fim, resta verificar se é uma sequência (Pode ser naipe diferente, mas tem que ser mesmo numero) 
    // Possível sequência: 1 3 2 4 5.
    // Vou começar procurando o menor.
    int min = 0;
    for(int contador = 0; contador < 5; contador++){
        if(arraySave[contador][1] < min){
            min = arraySave[contador][1];
        }
    }
    // Agora, preciso buscar o menor + 1.
    for(int contador = 0; contador < 5; contador++){
        if(arraySave[contador][1] == min+1){
            for(int contador = 0; contador < 5; contador++){
                if(arraySave[contador][1] == min+2){
                    for(int contador = 0; contador < 5; contador++){
                        if(arraySave[contador][1] == min+3){
                            for(int contador = 0; contador < 5; contador++){
                                if(arraySave[contador][1] == min+4){
                                    cout << "Eh sequencia!" << endl;
                                }else{}
                            }    
                        }else{}
                    }
                }else{}
            }
        }else{}
    }
        return 0;
}


void shuffle(int wDeck[][13]){
    int row, column;
    for(int card = 1; card <= 52; card++){
        do{
            row = rand () % 4; // Escolhe de 0 a 3, que são indices de suit
            column = rand() % 13; // Escolhe de 0 a 13, que são indices de face
        } while(wDeck[row][column] != 0);
        wDeck[row][column] = card; 
        // Explicando este código:
        // Ele tem uma matriz 4x13, que esgota todas as possibilidades de cartas.
        // Ele pega o card chamado 1, por exemplo, e sorteia em qual local nessa matriz ele vai ficar.
        // Se ele sortear e chegar em um wDeck[row][column] que não seja zero, sorteia novamente.
        // Se for zero, ele encontrou um lugar vazio e vai posicionar o numero da carta la.
    }
}

void isEven(const int arraySave[][2]) {
    // O algoritmo é o seguinte:
    // Tomando a carta 3, por exemplo, vou compará-la às cartas 4 e 5.
    // Caso a carta 3 seja igual a apenas mais uma carta, então vamos para a segunda verificação.
    // A segunda verificação consiste em verificar se a carta 3 não é igual nem a 1 e nem a 2.
    // Ele pede para verificar se existe um par. Logo, se existir dois, então está válido.
    int pares = 0;
    bool hasPair = false;
    for(int contador = 0; contador < 5; contador++){
        int soma = 1;
        for(int i = contador+1; i <= 5; i++){
            if(arraySave[contador][1] == arraySave[i][1]){
                soma++;
            }
        }
        if(soma == 2){
            int soma2 = 0;
            for(int i = contador-1; i >= 0; i--){
                if(arraySave[contador][1] == arraySave[i][1]){
                    soma2++;
                }
            }
            if(soma2 > 0){ // Trios não são pares!!!
                cout << "Existe algo maior do que par!!!" << endl;
                if(soma2 == 1){
                    cout << "Ha uma tripla." << endl; // Aqui já resolve as triplas (Letra C)
                }if(soma2 == 2){
                    cout << "Ha uma quadra" << endl; // Aqui já resolve as quadras (Letra D)
                }
            }
            else{
                cout << "Existe par de " <<  arraySave[contador][1] + 1 << endl;
                hasPair = true;
                pares++;
            }
        }
    }
    if(hasPair == false){
        cout << "Nao ha par" << endl;
    }
    if(pares == 2){ 
        cout << "Ha dois pares!!!" << endl; // Aqui já resolve a letra B
    }
}

void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]){
    for(int card = 1; card <= 5; card++){ // Alterando para sacar apenas cinco cartas
        for(int row = 0; row <= 3; row++){
            for(int column = 0; column <= 12; column++){
                if(wDeck[row][column] == card){
                    cout << wFace[column] << " de ";
                    cout << wSuit[row] << endl;
                }
            }
        }
    }
}
*/

/*
// Exercício 5.13
    Nessa questão vou precisar pegar a questão anterior e separar em mais funções.
    Essa questão foi testada um grande número de vezes e ainda possui um ou outro bug, mas no geral está funcionando.
    Preciso de funções para:
    1. Royal Flush (Sequência Real): Uma sequência de 10 a Ás, todas do mesmo naipe.
    2. Straight Flush (Sequência do Mesmo Naipe): Cinco cartas consecutivas do mesmo naipe.
    3. Four of a Kind (Quadra): Quatro cartas com o mesmo valor.
    4. Full House (Full House ou Trinca e Par): Três cartas de um valor e duas de outro valor.
    5. Flush (Cores): Cinco cartas do mesmo naipe, não necessariamente em sequência.
    6. Straight (Sequência): Cinco cartas consecutivas quaisquer.
    7. Three of a Kind (Trinca): Três cartas do mesmo valor e duas cartas não relacionadas.
    8. Two Pair (Dois Pares): Duas cartas de um valor, duas de outro valor e uma carta solta.
    9. One Pair (Um Par): Duas cartas do mesmo valor e três cartas não relacionadas.
    10. High Card (Carta Alta): Nenhuma das combinações acima. A mão é avaliada pela carta mais alta. Se duas mãos têm a mesma carta alta, 
    as próximas cartas mais altas são comparadas, e assim por diante.



#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::ios;
using std::setw;
using std::setiosflags;

void shuffle(int[][13]);
void deal(const int [][13], const char *[], const char *[]);

// Funções de pontuação da mão:
int royalFlush(int [][5][2], int);
int straightFlush(int [][5][2], int);
int fourofakind(int [][5][2], int);
int fullhouse(int [][5][2], int);
int flush(int [][5][2], int);
int straight(int [][5][2], int);
int threeofakind(int [][5][2], int);
int twopair(int [][5][2], int);
int onepair(int [][5][2], int);
void highcard(int [][5][2]);

int main(){
    const char *suit[4] = {"Copas", "Ouros", "Paus", "Espadas"};
    const char *face[13] = {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
    int deck[4][13] = {{0}};
    srand(time(0));
    shuffle(deck); // Está embaralhando as 52 cartas do deck.
    deal(deck, face, suit); // Está imprimindo as dez cartas removidas, sendo as cinco primeiras do jogador 1 e as outras do jogador 2.

    // ================================================================================================================
    
        Criando um Array de três dimensões que consiga salvar as mãos dos dois jogadores.
    
    // ================================================================================================================
    
    int arraySave[2][5][2] = {{{0}}};
    for(int k = 0; k < 2; k++){ // Iterando nos baralhos (baralho 0 e baralho 1)
        int startCard = (k == 0) ? 1 : 6; // Determina o número inicial da carta para este baralho
        for(int l = 0; l < 5; l++){ // Iterando nas cartas
            int cardNumber = startCard + l; // Número da carta que queremos sacar
            for(int i = 0; i < 4; i++){ // Iterando nos naipes
                for(int j = 0; j < 13; j++){ // Iterando nos valores das cartas
                    if(deck[i][j] == cardNumber){ // Procura onde em i e j está a carta com o número desejado
                        arraySave[k][l][0] = j; // Salva o valor da carta na coluna 0
                        arraySave[k][l][1] = i; // Salva o naipe da carta na coluna 1
                    }
                }
            }
        }
    }



    // Debug: imprimir o que esta sendo reconhecido como deck para cada jogador
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 2; k++){
                cout << arraySave[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }

    // ================================================================================================================
    
        Classificando cada um dos Arrays.
        Ideia: criar funções int para cada um dos 10 casos, de modo que se o caso for verdadeiro, retorne o numero dele.
        Exemplo: se o jogador 1 tem Royal Flush, ele vai receber um return 1 de uma função.
        No fim, se um dos jogadores possuir um número MENOR que o outro, este com o número menor vence.
        Uma lógica a parte terá que ser feita para o caso em que os dois jogadores tem 10.
        Qualquer outro caso de empate significa SPLIT POT. (Ou seja, empate mesmo)
    
    // ================================================================================================================

    int pontuacao[] = {0, 0};
    for(int j = 0; j < 2; j++) {
        if(royalFlush(arraySave, j) == 1) {
            pontuacao[j] = 1;
        } else if(straightFlush(arraySave, j) == 1 && pontuacao[j] == 0) {
            pontuacao[j] = 2;
        } else if(fourofakind(arraySave, j) == 1 && pontuacao[j] == 0) {
            pontuacao[j] = 3;
        } else if(fullhouse(arraySave, j) == 1 && pontuacao[j] == 0) {
            pontuacao[j] = 4;
        } else if(flush(arraySave, j) == 1 && pontuacao[j] == 0) {
            pontuacao[j] = 5;
        } else if(straight(arraySave, j) == 1 && pontuacao[j] == 0) {
            pontuacao[j] = 6;
        } else if(threeofakind(arraySave, j) == 1 && pontuacao[j] == 0) {
            pontuacao[j] = 7;
        } else if(twopair(arraySave, j) == 1 && pontuacao[j] == 0) {
            pontuacao[j] = 8;
        } else if(onepair(arraySave, j) == 1 && pontuacao[j] == 0) {
            pontuacao[j] = 9;
        } else {
            pontuacao[j] = 10;
        }
    }
    cout << pontuacao[0] << " " << pontuacao[1] << endl;

    // ================================================================================================================
    
        Uma vez que as duas mãos possuem pontuação, vejo o vencedor.
    
    // ================================================================================================================

    if(pontuacao[0] != 10 || pontuacao[1] != 10){
        if(pontuacao[0] < pontuacao[1]){
            cout << "Primeiro jogador venceu com pontuacao " << pontuacao[0] << endl;
        }else{
            if(pontuacao[0] > pontuacao[1]){
                cout << "Segundo jogador venceu com pontuacao " << pontuacao[1] << endl;
            }else{
                cout << "Empate! Split pot! Ambos com mao especial de pontuacao " << pontuacao[0] << endl;
            }
        }
    }else{ // Caso os dois tenham High Card, preciso de uma avaliação a parte, com base apenas no numero das cartas. (compara as maiores sucessivamente)
        highcard(arraySave);
    }

    return 0;
}

void shuffle(int wDeck[][13]){ 
    int row, column;
    for(int card = 1; card <= 52; card++){
        do{
            row = rand () % 4;
            column = rand() % 13;
        } while(wDeck[row][column] != 0);
        wDeck[row][column] = card;
    }
}

void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]){
    for(int card = 1; card <= 10; card++){
        for(int row = 0; row <= 3; row++){
            for(int column = 0; column <= 12; column++){
                if(wDeck[row][column] == card){
                    cout << wFace[column] << " de ";
                    cout << wSuit[row] << endl;
                }
            }
        }
        if(card == 5){
            cout << endl;
        }
    }
}

    // ================================================================================================================
    
        Definindo as funções de comparação
    
    // ================================================================================================================

int royalFlush(int arraySave[][5][2], int j){ // Sequência de mesmo naipe: ás, 10, dama, valete, rei.
    int min = 14;
    if(arraySave[j][0][1] == arraySave[j][1][1] && arraySave[j][0][1] == arraySave[j][2][1] && arraySave[j][0][1] == arraySave[j][3][1] && arraySave[j][0][1] == arraySave[j][4][1]){
        for(int contador = 0; contador < 5; contador++){
            if(arraySave[j][contador][0] < min){
                min = arraySave[j][contador][0];
            }
        }
        if(min == 1){ // Achou o Ás
            for(int contador = 0; contador < 5; contador++){
                if(arraySave[j][contador][0] == 10){
                    for(int contador2 = 0; contador2 < 5; contador2++){
                        if(arraySave[j][contador2][0] == 11){
                            for(int contador3 = 0; contador3 < 5; contador3++){
                                if(arraySave[j][contador3][0] == 12){
                                    for(int contador4 = 0; contador4 < 5; contador4++){
                                        if(arraySave[j][contador4][0] == 13){
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int straightFlush(int arraySave[][5][2], int j){
    if(arraySave[j][0][1] == arraySave[j][1][1] && arraySave[j][0][1] == arraySave[j][2][1] && arraySave[j][0][1] == arraySave[j][3][1] && arraySave[j][0][1] == arraySave[j][4][1]){ 
        int min = 14;
        for(int contador = 0; contador < 5; contador++){
            if(arraySave[j][contador][1] < min){
                min = arraySave[j][contador][1];
            }
        }
        for(int contador = 0; contador < 5; contador++){
            if(arraySave[j][contador][1] == min+1){
                for(int contador = 0; contador < 5; contador++){
                    if(arraySave[j][contador][1] == min+2){
                        for(int contador = 0; contador < 5; contador++){
                            if(arraySave[j][contador][1] == min+3){
                                for(int contador = 0; contador < 5; contador++){
                                    if(arraySave[j][contador][1] == min+4){
                                        return 1;
                                    }
                                }    
                            }
                        }
                    }
                }
            }
        }
    }
    return 0; // Aqui retorna 0 caso nenhum Straight Flush seja encontrado.
}

int fourofakind(int arraySave[][5][2], int j){ // Quatro cartas de mesmo numero
    // É impossível uma quadra sem ter nem o primeiro termo nem o segundo termo. Então é só conferir esses casos.
    int soma = 1;
    for(int contador = 1; contador < 5; contador++){
        if(arraySave[j][0][0] == arraySave[j][contador][0]){
            soma++;
        }
    }
    if(soma == 4){
        return 1;
    }else{
        soma = 1;
        if(arraySave[j][1][0] == arraySave[j][0][0]){
            soma++;
        }
        for(int contador = 2; contador < 5; contador++){
            if(arraySave[j][1][0] == arraySave[j][contador][0]){
                soma++;
            }
        }
        if(soma == 4){
            return 1;
        }
    }
    return 0;
}

int fullhouse(int arraySave[][5][2], int j) {
    bool temTripla = false;
    bool temPar = false;

    // Verifica se há uma trinca e um par
    for (int contador = 0; contador < 5; contador++) {
        int valor = arraySave[j][contador][0];
        int count_same = 0;
        for (int i = 0; i < 5; i++) {
            if (arraySave[j][i][0] == valor) {
                count_same++;
            }
        }
        if (count_same == 3) {
            temTripla = true;
        } else if (count_same == 2) {
            temPar = true;
        }
    }

    // Retorna 1 se há uma trinca e um par, caso contrário, retorna 0
    if (temTripla && temPar) {
        return 1;
    } else {
        return 0;
    }
}


int flush(int arraySave[][5][2], int j){ // Verifica se todos são do mesmo naipe
    if(arraySave[j][0][1] == arraySave[j][1][1] && arraySave[j][0][1] == arraySave[j][2][1]){
        if(arraySave[j][0][1] == arraySave[j][3][1] && arraySave[j][0][1] == arraySave[j][4][1]){
            return 1;
        }
    }else{
        return 0;
    }
}

int straight(int arraySave[][5][2], int j){ // Verifica a existência de sequência qualquer
    int min = 14;
    for(int contador = 0; contador < 5; contador++){ // Acha o termo mínimo
        if(arraySave[j][contador][1] < min){
            min = arraySave[j][contador][1];
        }
    }
    for(int contador = 0; contador < 5; contador++){ // Busca o mínimo + 1
        if(arraySave[j][contador][1] == min+1){
            for(int contador2 = 0; contador2 < 5; contador2++){ // Caso encontrado, busca o mínimo + 2. Assim sucessivamente.
                if(arraySave[j][contador2][1] == min+2){
                    for(int contador3 = 0; contador3 < 5; contador3++){
                        if(arraySave[j][contador3][1] == min+3){
                            for(int contador4 = 0; contador4 < 5; contador4++){
                                if(arraySave[j][contador4][1] == min+4){
                                    return 1;
                                }else{}
                            }    
                        }else{}
                    }
                }else{}
            }
        }else{}
    }
    return 0;
}

int threeofakind(int arraySave[][5][2], int j){ // Retorna 1 caso exista uma tripla e duas cartas distintas
    int contador;
    int count_triple = 0;
    int unique_values[5] = {0};
    for (contador = 0; contador < 5; contador++) {
        int valor = arraySave[j][contador][0];
        int count_same = 0;
        for (int i = 0; i < 5; i++) {
            if (arraySave[j][i][0] == valor) {
                count_same++;
            }
        }
        if (count_same == 3) {
            count_triple++;
        }
        unique_values[contador] = valor;
    }
    if (count_triple == 1) {
        int unique_count = 0;
        for (contador = 0; contador < 5; contador++) {
            int valor = unique_values[contador];
            int count_same = 0;
            for (int i = 0; i < 5; i++) {
                if (unique_values[i] == valor) {
                    count_same++;
                }
            }
            if (count_same == 1) {
                unique_count++;
            }
        }
        if (unique_count == 2) {
            return 1;
        }
    }
    return 0;
}

int twopair(int arraySave[][5][2], int j){ // Retorna 1 caso existam dois pares e uma carta distinta dos dois pares
    int contador;
    int count_pairs = 0;
    int unique_values[5] = {0};
    for (contador = 0; contador < 5; contador++) {
        int valor = arraySave[j][contador][0];
        int count_same = 0;
        for (int i = 0; i < 5; i++) {
            if (arraySave[j][i][0] == valor) {
                count_same++;
            }
        }
        if (count_same == 2) {
            int found = 0; // Evitando que o mesmo par seja contado mais de uma vez
            for (int k = 0; k < 5; k++) {
                if (unique_values[k] == valor) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                count_pairs++;
                unique_values[count_pairs - 1] = valor;
            }
        }
    }
    return (count_pairs == 2) ? 1 : 0;
}


int onepair(int arraySave[][5][2], int j){
    int contador;
    int count_pairs = 0;
    int unique_values[5] = {0};

    // Conta o número de pares distintos e armazena valores únicos
    for (contador = 0; contador < 5; contador++) {
        int valor = arraySave[j][contador][0];
        int count_same = 0;
        for (int i = 0; i < 5; i++) {
            if (arraySave[j][i][0] == valor) {
                count_same++;
            }
        }
        if (count_same == 2) { // Ajustado para verificar exatamente dois valores iguais
            int found = 0;
            for (int k = 0; k < 5; k++) {
                if (unique_values[k] == valor) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                count_pairs++;
                unique_values[count_pairs - 1] = valor;
            }
        }
    }

    // Se houver exatamente um par e os outros três valores são únicos, retorna 1
    if (count_pairs == 1) {
        int unique_count = 0;
        int pair_value = unique_values[0];
        for (contador = 0; contador < 5; contador++) {
            int valor = arraySave[j][contador][0];
            if (valor != pair_value) {
                unique_count++;
            }
        }
        if (unique_count == 3) {
            return 1;
        }
    }

    return 0;
}




void highcard(int arraySave[][5][2]){
    // Para não perder nenhum dado, vou copiar em dois novos arrays.
    int PrimeiroArray[5] = {arraySave[0][0][0], arraySave[0][1][0], arraySave[0][2][0], arraySave[0][3][0], arraySave[0][4][0]};
    int SegundoArray[5] = {arraySave[1][0][0], arraySave[1][1][0], arraySave[1][2][0], arraySave[1][3][0], arraySave[1][4][0]};

    // Vou ordenar os valores destes dois Arrays por meio de um Bubble Sort.
    for(int contador = 0; contador < 4; contador++){ // Ajuste na condição do loop
        if(PrimeiroArray[contador] < PrimeiroArray[contador+1]){ // Comparação ajustada para ordem decrescente
            int hold = PrimeiroArray[contador];
            PrimeiroArray[contador] = PrimeiroArray[contador+1];
            PrimeiroArray[contador+1] = hold;
        }
    }

    for(int contador = 0; contador < 4; contador++){ // Ajuste na condição do loop
        if(SegundoArray[contador] < SegundoArray[contador+1]){ // Comparação ajustada para ordem decrescente
            int hold = SegundoArray[contador];
            SegundoArray[contador] = SegundoArray[contador+1];
            SegundoArray[contador+1] = hold;
        }
    }

    // Comparando as cartas mais altas
    for(int i = 0; i < 5; i++){ // As comparações devem ser em ordem decrescente
        if(PrimeiroArray[i] > SegundoArray[i]){
            cout << "Jogador 1 venceu." << endl;
            return;
        } else if(PrimeiroArray[i] < SegundoArray[i]){
            cout << "Jogador 2 venceu." << endl;
            return;
        }
    }

    cout << "Empate!" << endl;
}

*/

// Exercício 5.14
/*
    Nesse exercício, pega o Exercício 5.13 e adiciona uma função para poder substituir cartas.
    Pelo o que entendi, caso eu tenha uma dupla simples, por exemplo, posso tentar sacar até mais três cartas em prol de melhorar minha mão.
    Ou seja: identifica a pontuação e as cartas úteis na pontuação, remove uma carta inutil e saca uma nova. Processo recursivo 3x.
*/

/*
// Exercício 5.31
#include <iostream>
#include <cstring>

int main(){
    char string1[100], string2[100];
    std::cin >> string1 >> string2;
    std::cout << std::endl;
    std::cout << strcmp(string1, string2); // Retorna numero > 0 se string1 for maior que string2, e análogos.

    return 0;
}
*/

/*
// Exercício 5.32
#include <iostream>
#include <cstring>

int main(){
    int numero;
    std::cin >> numero;
    char string1[numero], string2[numero];
    std::cin >> string1 >> string2;
    std::cout << strncmp(string1, string2, numero);
}
*/

/*
// Exercício 5.33
#include <iostream>
#include <cstdlib>
#include <cstring>

using std::cout;
using std::endl;

int main() {
    const char *artigos[] = {"o", "a", "um", "uma", "algum", "qualquer"};
    const char *substantivo[] = {"menino", "menina", "cachorro", "cidade", "carro"};
    const char *verbo[] = {"dirigiu", "pulou", "correu", "caminhou", "saltou"};
    const char *preposicao[] = {"para", "de", "acima de", "debaixo de", "sobre"};

    char arrayFrases[20][50]; // 20 áreas que esperam strings de até 50 caracteres

    for(int i = 0; i < 20; i++){
        strcpy(arrayFrases[i], artigos[rand() % 6]); // Copia a palavra para o array de frases
        strcat(arrayFrases[i], " "); // strcat  anexa a string s2 (nesse caso o espaço) à string s1 (arrayFrases)
        strcat(arrayFrases[i], substantivo[rand() % 5]);
        strcat(arrayFrases[i], " ");
        strcat(arrayFrases[i], verbo[rand() % 5]);
        strcat(arrayFrases[i], " ");
        strcat(arrayFrases[i], preposicao[rand() % 5]);
        strcat(arrayFrases[i], " ");
        strcat(arrayFrases[i], artigos[rand() % 6]);
        strcat(arrayFrases[i], " ");
        strcat(arrayFrases[i], substantivo[rand() % 5]);

        cout << arrayFrases[i] << endl; // Imprime a frase completa
    }

    return 0;
}
*/

/*
// Exercício 5.34 (Limericks, cinco frases sendo que 1 e 2 rimam com 5 e 3 e 4 rimam entre si)
#include <iostream>
#include <cstdlib>
#include <cstring>

using std::cout;
using std::endl;

int main() {
    const char *artigos[] = {"o", "a", "um", "uma", "algum", "qualquer"};
    const char *substantivo1[] = {"capaz", "trás", "paz", "satisfaz", "sagaz"};
    const char *substantivo2[] = {"amor", "flor", "cantor", "motor", "vapor"};

    char arrayFrases[20][50]; // 20 áreas que esperam strings de até 50 caracteres

    for(int i = 0; i < 5; i++){
        if(i == 0 || i == 1 || i == 4){
            strcpy(arrayFrases[i], artigos[rand() % 6]); // Copia a palavra para o array de frases
            strcat(arrayFrases[i], " "); // strcat  anexa a string s2 (nesse caso o espaço) à string s1 (arrayFrases)
            strcat(arrayFrases[i], substantivo1[rand() % 5]);    
        }
        else{
            strcpy(arrayFrases[i], artigos[rand() % 6]); // Copia a palavra para o array de frases
            strcat(arrayFrases[i], " "); // strcat  anexa a string s2 (nesse caso o espaço) à string s1 (arrayFrases)
            strcat(arrayFrases[i], substantivo2[rand() % 5]);
        }

        cout << arrayFrases[i] << endl; // Imprime a frase completa
    }

    return 0;
}
*/

/*
// Exercício 5.35 (Usando a biblioteca string, mais abrangente que a cstring)
#include <iostream>
#include <string> // Biblioteca mais atualizada do que cstring que o livro apresenta

void printLatinWord(std::string&); // Espera o endereço de uma string

int main() {
    std::string frase; // Novo tipo de dado:: std::string
    std::cout << "Digite a frase em ingles: ";
    std::getline(std::cin, frase); // Use getline para ler a linha inteira, pois o cin iria parar no primeiro espaço

    std::string palavra;
    std::size_t inicioPalavra = 0;
    std::size_t fimPalavra = frase.find(' ');
    while (fimPalavra != std::string::npos) { // 
        palavra = frase.substr(inicioPalavra, fimPalavra - inicioPalavra);
        printLatinWord(palavra);
        std::cout << palavra << " ";
        inicioPalavra = fimPalavra + 1;
        fimPalavra = frase.find(' ', inicioPalavra);
    }
    palavra = frase.substr(inicioPalavra);
    printLatinWord(palavra);
    std::cout << palavra;

    return 0;
}

void printLatinWord(std::string& palavra) {
    char primeiro = palavra[0];
    palavra.erase(0, 1); // Remove o primeiro caractere da palavra
    palavra += primeiro; // Adiciona o primeiro caractere ao final
    palavra += "ay"; // Adiciona "ay" ao final da palavra
}
*/

/*
// Exercício 5.36
#include <iostream>
#include <cstring>

int main(){
    // Primeiro obter o numero
    char numero[15];
    std::cin.getline(numero, 15, '\n');

    // Converter o numero para os tipos de dados pedidos:
    // Criando uma cópia da string original
    char input_copy[20];
    std::strcpy(input_copy, numero);

    // Removendo parênteses e traço da cópia da string original
    char *ptr = input_copy;
    while (*ptr) {
        if (*ptr == '(' || *ptr == ')' || *ptr == '-') {
            std::strcpy(ptr, ptr + 1); // Isso copia uma string em cima de outra. É como se eu copiasse a string que vem depois de ptr+1 em ptr, sumindo 1 caractere
        } else {
            ++ptr;
        }
    }

    // Convertendo a parte antes do traço para int
    char codigo_area_str[4];
    std::strncpy(codigo_area_str, input_copy, 3);
    codigo_area_str[3] = '\0';
    int codigo_area = std::atoi(codigo_area_str); // Transforma em int

    // Convertendo a parte depois do traço para long
    long numero_telefone = std::atol(input_copy + 3); // Transforma em long

    std::cout << "Codigo de area como int: " << codigo_area << std::endl;
    std::cout << "Numero de telefone como long: " << numero_telefone << std::endl;
    
    // Imprimir nas três partes separadas
    char *tokenPtr;
    tokenPtr = strtok(numero, " ");
    std::cout << "Codigo de area: " << tokenPtr << std::endl;
    
    tokenPtr = strtok(NULL, " ");
    std::cout << "Primeiros tres digitos: " << strtok(tokenPtr, "-") << std::endl;

    tokenPtr = strtok(NULL, " ");
    std::cout << "Ultimos quatro digitos: " << tokenPtr << std::endl;

}
*/

/*
// Exercício 5.37
#include <iostream>
#include <cstring>

int main() {
    // Recebendo a frase
    char frase[50];
    std::cin.getline(frase, 50, '\n');

    // Tokenizar a frase em palavras usando strtok
    char *ptr = std::strtok(frase, " "); // O ponteiro aponta para o primeiro token
    char *palavras[50]; // array para armazenar ponteiros para as palavras
    int count = 0;

    while (ptr != nullptr) {
        palavras[count++] = ptr; // Armazena token em palavras (salva o 0 caso seja primeira execução, e salva o abaixo aqui se for outra)
        ptr = std::strtok(nullptr, " "); // Esse nullptr significa que eu quero continuar a busca de onde tinha parado, já avança o ponteiro pro proximo token
    }

    // Imprimir as palavras em ordem inversa
    std::cout << "Palavras em ordem inversa:" << std::endl;
    for (int i = count - 1; i >= 0; --i) {
        std::cout << palavras[i] << std::endl;
    }

    return 0;
}
*/

/*
// Exercício 5.38
#include <iostream>
#include <cstring>

int main(){

    // Array de cidades do Brasil, fora de ordem alfabética.
    const char* cidades[10] = {
        "Sao Paulo",
        "Rio de Janeiro",
        "Salvador",
        "Brasília",
        "Fortaleza",
        "Belo Horizonte",
        "Manaus",
        "Curitiba",
        "Recife",
        "Porto Alegre"
    };

    for(int contador = 0; contador < 9; contador++){
        for(int contador2 = contador + 1; contador2 < 10; contador2++){
            if (std::strcmp(cidades[contador], cidades[contador2]) > 0) { // strcmp acha a primeira diferença e compara (DOCUMENTAÇÃO)
                // Trocar as cidades de posição se estiverem fora de ordem
                const char* temp = cidades[contador]; // Poderia guardar em string tambem, mas assim é melhor.
                cidades[contador] = cidades[contador2];
                cidades[contador2] = temp;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        std::cout << cidades[i] << std::endl;
    }

}
*/

// Ainda por fazer.
