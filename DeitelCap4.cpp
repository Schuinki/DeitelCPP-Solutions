/*
// Exercício 4.8
#include <iostream>

int main(){
    int f[8] = {0};
    std::cout << "O setimo elemento eh: " << f[6] << std::endl;
    
    float b[10] = {0};
    std::cout << "Digite um valor para o elemento 4 do array b[10]: " << std::endl;
    std::cin >> b[4];

    int g[5] = {8, 8, 8, 8, 8};

    float c[100] = {1}, soma = 0;
    int n = 0;
    while(n < 100){
        soma += c[n];
        n++;
    }
    std::cout << soma << std::endl;

    double a[11] = {1, 2, 3, 4}, d[34] = {0};
    n = 0;
    while(n < 11){
        d[n] = a[n];
        n++;
    }
    for(int contador = 0; contador < 34; contador++){
        std::cout << d[contador] << " ";
    }
    std::cout << "\n";
    float w[99] = {1, 2, 3};
    n = 0;
    float max = w[0];
    for(n = 0; n < 99; n++){
        if(w[n] > max) max = w[n];
    }
    std::cout << max;
}
*/

/*
// Exercício 4.10
#include <iostream>

enum Status { ON, OFF };
Status gameStatus = ON;
int array[9] = {0};

int main(){
    int bruta, opt;
    while(gameStatus == ON){
        std::cout << "Deseja adicionar salario? (0/1) " << std::endl;
        std::cin >> opt;
        if(opt == 0){
            for(int contador = 0; contador < 9; contador++){
                std::cout << 200 + contador*100 << " - " << 299 + 100*contador << "\t" << array[contador] << std::endl;
            }
        }else{
            std::cout << "Digite o total de venda bruta: " << std::endl;
            std::cin >> bruta;
            int salario = 200+bruta*0.09;
            if(salario >= 200 && salario <= 299) array[0] += 1;
            if(salario >= 300 && salario <= 399) array[1] += 1;
            if(salario >= 400 && salario <= 499) array[2] += 1;
            if(salario >= 500 && salario <= 599) array[3] += 1;
            if(salario >= 600 && salario <= 699) array[4] += 1;
            if(salario >= 700 && salario <= 799) array[5] += 1;
            if(salario >= 800 && salario <= 899) array[6] += 1;
            if(salario >= 900 && salario <= 999) array[7] += 1;
            if(salario >= 1000) array[8] += 1;
        }
    }
}
*/

/*
// Exercício 4.11 (Alteração no Bubble Sort. Ele vai colocando os maiores já no final aos poucos)
#include <iostream>
#include <cstdlib>

int main(){
    srand(time(0));
    int array[40];
    int passagens = 0, guardarIndice;
    std::cout << "Array original sorteado: ";
    for(int contador = 0; contador < 40; contador++){
        array[contador] = rand() % 100 + 1;
        std::cout << array[contador] << " ";
    }
    // Ordenando esse array aleatório (Bubble sort modificado):
    std::cout << std::endl;
    int n = 1;
    while(n != 0){
        n = 0;
        int max = 0;
        int contador = 0;
        for(contador = 0; contador <= 39-passagens; contador++){
            max = 0;
            if(array[contador] >= max){
                max = array[contador];
                guardarIndice = contador;
            }
            if(array[contador] > array[contador+1]){
                int auxiliar;
                auxiliar = array[contador];
                array[contador] = array[contador+1];
                array[contador+1] = auxiliar;
                n++; // Se ele passar uma vez e não fizer troca, já vai parar.
            }
        }
        array[guardarIndice] = array[39-passagens];
        array[39-passagens] = max;
        std::cout << std::endl;
        std::cout << "Array ordenado (Bubble Sort): " << contador << std::endl;
        for(int contador = 0; contador < 40; contador++){
            std::cout << array[contador] << " ";
        }
        passagens++;
    }
    std::cout << std::endl << "Passagens: " << passagens << std::endl;
}
*/

/*
// Exercício 4.17
#include <iostream>
#include <cstdlib>

int main(){
    srand(time(0));
    int array[11] = {0};
    for(int i = 0; i < 34000; i++){
        int dado1 = rand() % 6 + 1;
        int dado2 = rand() % 6 + 1;
        if(dado1 + dado2 == 2) array[0] += 1;
        if(dado1 + dado2 == 3) array[1] += 1;
        if(dado1 + dado2 == 4) array[2] += 1;
        if(dado1 + dado2 == 5) array[3] += 1;
        if(dado1 + dado2 == 6) array[4] += 1;
        if(dado1 + dado2 == 7) array[5] += 1;
        if(dado1 + dado2 == 8) array[6] += 1;
        if(dado1 + dado2 == 9) array[7] += 1;
        if(dado1 + dado2 == 10) array[8] += 1;
        if(dado1 + dado2 == 11) array[9] += 1;
        if(dado1 + dado2 == 12) array[10] += 1;
    }
    for(int i = 0; i < 11; i++){
        std::cout << "Resultado " << i+2 << ": " << array[i] << " ocorrencias." << std::endl;
    }
}
*/

/*
// Exercício 4.19 (1000 JOGOS DE CRAPS)
#include <iostream>
#include <cstdlib>
// Vou fazer uma versão bem simplificada. 
// Seja uma função void para jogar Craps. Uma vez encerrada, ganhando ou perdendo, ela deve somar 1 ao array[x], onde x é a jogada.
// Ganhou na primeira: soma 1 no vitoria[0]
// Ganhou na 24823: soma 1 no vitoria[19]

void jogarCraps(int[], int[]);

int main(){
    int vitoria[20] = {0};
    int derrota[20] = {0};
    for(int contador = 0; contador < 1000; contador++){
        jogarCraps(vitoria, derrota);
    }
    for(int contador = 0; contador < 20; contador++){
        std::cout << "Vitoria na rodada " << contador + 1 << ": " << vitoria[contador] << std::endl;
        std::cout << "Derrota na rodada " << contador + 1 << ": " << derrota[contador] << std::endl;
    }

}

void jogarCraps(int ganhou[], int perdeu[]){
    // Falta programar o jogo em si, com lançamento de dados e já feito no capítulo anterior.
}
*/

/*
// Exercício 4.20
#include <iostream>

void reservarClasseEconomica(int[]);
void reservarPrimeiraClasse(int[]);

enum Status { ON, OFF };
Status programStatus = ON;

int main(){
    int array[10] = {0};
    while(programStatus == ON){
        int opcao = 0, opcao2 = 0;
        while(opcao != 1 && opcao != 2){
            std::cout << "Favor digitar 1 para Primeira Classe e 2 para Classe Economica: ";
            std::cin >> opcao;
            if(opcao == 1){
                if(array[0] == 1 && array[1] == 1 && array[2] == 1 && array[3] == 1 && array[4] == 1){
                    std::cout << "Todos os assentos primeira classe estao ocupados. Aceita economico? (0/1) ";
                    std::cin >> opcao2;
                    if(opcao2 == 0){
                        std::cout << "Proximo voo sai em 3 horas" << std::endl;
                        programStatus = OFF;
                    }
                    else{
                        if(array[5] == 1 && array[6] == 1 && array[7] == 1 && array[8] == 1 && array[9] == 1){
                            std::cout << "Todos os assentos economicos estao ocupados";
                            programStatus = OFF;
                        }
                        reservarClasseEconomica(array);
                    }
                }
                reservarPrimeiraClasse(array);   
            }
            else if(opcao == 2){
                if(array[5] == 1 && array[6] == 1 && array[7] == 1 && array[8] == 1 && array[9] == 1){
                    std::cout << "Todos os assentos economicos estao ocupados. Aceita primeira classe? (0/1) ";
                    std::cin >> opcao2;
                    if(opcao2 == 0){
                        std::cout << "Proximo voo sai em 3 horas" << std::endl;
                        programStatus = OFF;
                    }
                    else{
                        if(array[0] == 1 && array[1] == 1 && array[2] == 1 && array[3] == 1 && array[4] == 1){
                            std::cout << "Todos os acentos de primeira classe estão ocupados!";
                            programStatus = OFF;
                        }
                        reservarPrimeiraClasse(array);
                    }
                }
                reservarClasseEconomica(array);
            }else{
                std::cout << "Entrada invalida, repita!!!";
            }
        }
    }
    return 0;
}

void reservarClasseEconomica(int array[]){
    for(int contador = 5; contador < 10; contador++){
        if(array[contador] == 0){
            array[contador] = 1;
            std::cout << "Reservada Classe Economica!!!" << std::endl;
            std::cout << "Seu assento eh o " << contador+1 << " na classe economica!!";
            return;
        }
    }
}

void reservarPrimeiraClasse(int array[]){
    for(int contador = 0; contador < 5; contador++){
        if(array[contador] == 0){
            array[contador] = 1;
            std::cout << "Reservada Primeira Classe!!!" << std::endl;
            std::cout << "Seu assento eh o " << contador+1 << " na primeira classe!!";  
            return;  
        }
    }
}
*/

/*
// Exercício 4.22 (Ficou faltando os valores em si, mas a tabela do jeito que o cara pediu esta feita)
#include <iostream>

int soma0 = 0, soma1 = 0, soma2 = 0, soma3 = 0, soma4 = 0;
int somaVendedor[4] = {0};
int somaProduto[5] = {0};

int someVendedor(int indice, int array[][5]){
    for(int contador = 0; contador < 5; contador++){
        somaVendedor[indice] += array[indice][contador];
    }
    return somaVendedor[indice];
}

int someProduto(int indice, int array[][5]){
    for(int contador = 0; contador < 4; contador++){
        somaProduto[indice] += array[contador][indice];
    }
    return somaProduto[indice];
}

int main(){
    // Inicializando o array bidimensional solicitado
    int vendas[4][5] ={0};
    // Imprimindo uma tabela
    // Cabeçalho
    std::cout << "1\t2\t3\t4\t       Total" << std::endl;
    // Vendas do item 1
    std::cout << vendas[0][0] << "\t" << vendas[1][0] << "\t" << vendas[2][0] << "\t" << vendas[3][0] << "\t\t" << someProduto(0, vendas) << std::endl;
    // Análogo
    std::cout << vendas[0][1] << "\t" << vendas[1][1] << "\t" << vendas[2][1] << "\t" << vendas[3][1] << "\t\t" << someProduto(1, vendas) << std::endl;
    std::cout << vendas[0][2] << "\t" << vendas[1][2] << "\t" << vendas[2][2] << "\t" << vendas[3][2] << "\t\t" << someProduto(2, vendas) << std::endl;
    std::cout << vendas[0][3] << "\t" << vendas[1][3] << "\t" << vendas[2][3] << "\t" << vendas[3][3] << "\t\t" << someProduto(3, vendas) << std::endl;
    std::cout << vendas[0][4] << "\t" << vendas[1][4] << "\t" << vendas[2][4] << "\t" << vendas[3][4] << "\t\t" << someProduto(4, vendas) << std::endl;
    std::cout << std::endl;
    std::cout << someVendedor(0, vendas) << "\t" << someVendedor(1, vendas) << "\t" << someVendedor(2, vendas) << "\t" << someVendedor(3, vendas);
}
*/

/*
// Exercício 4.23 (TURTLE GRAPHICS NO C++)
#include <iostream>
#include <limits>

enum Status { CIMA, BAIXO };
Status canetaStatus = CIMA;

int main(){
    int array[20][20] = {{0}};
    int opt = 10;
    int xAtual = 0, yAtual = 0;
    int anguloAtual = 0;
    int casas = 0;
    std::cout << "Digite as opcoes: " << std::endl;
    while(opt != 9){
        std::cin >> opt;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer de entrada
        switch(opt){ // Se definir variável aqui dentro, vai dar erro!!!
            case 1: // Caneta para cima
                canetaStatus = CIMA;
                break;
            case 2: // Caneta para baixo
                canetaStatus = BAIXO;
                break;
            case 3: // Giro para a direita
                anguloAtual -= 90;
                break;
            case 4: // Giro para a esquerda
                anguloAtual += 90;
                break;
            case 5: // Movimento para frente
                casas = 0;
                std::cout << "Digite o numero de casas do movimento: ";
                std::cin >> casas;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer de entrada
                if(canetaStatus == CIMA){
                    // Não vai fazer nada!
                }else{
                    if(anguloAtual % 360 == 0 || anguloAtual == -360){
                        for(int contador = 0; contador < casas; contador++){
                            array[xAtual][yAtual+contador] = 1;
                        }
                        yAtual = yAtual + casas - 1;
                    }
                    if(anguloAtual % 360 == 90 || anguloAtual == -270){
                        for(int contador = 0; contador < casas; contador++){
                            array[xAtual-contador][yAtual] = 1;
                        }
                        xAtual = xAtual - casas - 1;
                    }
                    if(anguloAtual % 360 == 180 || anguloAtual == -180){
                        for(int contador = 0; contador < casas; contador++){
                            array[xAtual][yAtual-contador] = 1;
                        }
                        yAtual = yAtual - casas + 1;
                    }
                    if(anguloAtual % 360 == 270 || anguloAtual == -90){
                        for(int contador = 0; contador < casas; contador++){
                            array[xAtual+contador][yAtual] = 1;
                        }
                        xAtual = xAtual + casas + 1;
                    }
                }
                break;
            case 6: // Imprimir o array 20 por 20
                for(int i = 0; i < 20; i++){
                    for(int j = 0; j < 20; j++){
                        std::cout << array[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                break;
            case 9:
                break;
            default:
                std::cout << "Numero desconhecido!!!" << std::endl;
        }
    }
    return 0;
}
*/

/*
// Exercício 4.29 (CRIVO DE ERATÓSTENES)
#include <iostream>

int main(){
    // Definindo e inicializando o Array com todos os termos 1.
    int array[1000];
    for(int contador = 0; contador < 1000; contador++){
        array[contador] = 1;
    }
    // Fazendo o Crivo de Eratóstenes
    // Partindo de 2, faz com que todos os múltiplos de 2 virem 0. 
    // Aí, todos os múltiplos de 3 viram 0.
    // Aí, todos os múltiplos de 5 viram 0.
    // No fim soma o número de 1 que sobrou no array.
    for(int contador = 2; contador < 1000; contador++){
        if(array[contador] == 1){
            for(int contador2 = 2; contador2 <= 1000/contador; contador2++){
                if((contador*contador2) < 1000){
                    array[contador*contador2] = 0;
                }
            }
        }
    }
    // Somando o valor final
    int soma = 0;
    for(int contador = 2; contador < 1000; contador++){ // Não conta nem o 0 nem o 1!!
        soma += array[contador];
    }
    std::cout << "Existem: " << soma << " primos nesse intervalo!!!" << std::endl;
}
*/

/*
// Exercício 4.30 (CLASSIFICAÇÃO COM BUCKET SORT)
// Técnica de ordenação com desempenho melhor que o Bubble Sort, mas exige capacidade de armazenamento muito maior.
#include <iostream>
#include <cstdlib>

void bucketSort(int[], int);

int main() {
    int array[20];

    // Preencher array com números aleatórios entre 1 e 80
    for(int contador = 0; contador < 20; contador++) {
        array[contador] = rand() % 80 + 1;
    }

    // Exibir array original
    std::cout << "Array original:\n";
    for(int contador = 0; contador < 20; contador++) {
        std::cout << array[contador] << " ";
    }

    // Ordenar o array usando Bucket Sort
    bucketSort(array, 20);

    // Exibir array ordenado
    std::cout << "\n\nArray ordenado:\n";
    for(int contador = 0; contador < 20; contador++) {
        std::cout << array[contador] << " ";
    }

    return 0;
}

void bucketSort(int array[], int tamanho) { // Unica necessidade real é o array. O parâmetro tamanho pode ser inserido manualmente.
    const int numBuckets = 10; // Para estabelecer o sistema de restos
    int buckets[numBuckets][20] = {0}; // Inicializando a matriz do Bucket Sort

    // Encontrando o maior número do Array 
    int max_num = 0;
    for (int i = 0; i < tamanho; ++i) {
        if (array[i] > max_num) {
            max_num = array[i];
        }
    }

    // Encontrando o número de casas decimais do maior número a ser classificado
    int max_digit_count = 0;
    while (max_num > 0) {
        max_num /= 10;
        ++max_digit_count;
    }

    // Classificação em Bucket Sort. Vai classificar esperando o max_digit_count do maior termo
    // Ideia do Bucket Sort: 
    // Pega os termos, faz % 10 e classifica entre linhas de 0 a 9.
    // Repassa para o array original lendo as linhas (primeiro passa os de resto 0, depois os de resto 1, depois os de resto 2...)
    // Isso significa passar primeiro os termos da linha 0, depois os termos da linha 1 e assim sucessivamente
    // Durante a próxima classificação, divide os termos por 10 e pega o % 10, classificando novamente os termos originais nas linhas.
    // Assim sucessivamente até todo mundo ser classificado
    int divisor = 1; // Para funcionar o sistema dos restos, isso precisa ser *= 10 toda iteração grande.
    for (int digit_place = 0; digit_place < max_digit_count; ++digit_place) {
        // Distribuir elementos nos buckets com base nos dígitos na posição atual
        for(int i = 0; i < tamanho; i++) {
            int indice = (array[i] / divisor) % 10; // Determinar o índice do bucket
            for(int j = 0; j < 20; j++) {
                if(buckets[indice][j] == 0) {
                    buckets[indice][j] = array[i];
                    break;
                }
            }
        }

        // Copiar os valores dos buckets de volta para o array original
        int index = 0;
        for(int i = 0; i < numBuckets; i++) {
            for(int j = 0; j < 20; j++) { // Está lendo como COLUNA, dai muda a LINHA. Ex.: primeiro pega os resto 0, depois os resto 1
                if(buckets[i][j] != 0) {
                    array[index++] = buckets[i][j]; // Nesse index++ ele vai copiar o bucket e já na proxima iteração esta o proximo index
                }
            }
        }

        // Limpar os buckets, agora com o array ordenado pela passagem anterior
        for(int i = 0; i < numBuckets; i++) {
            for(int j = 0; j < 20; j++) {
                buckets[i][j] = 0;
            }
        }

        divisor *= 10;
    }
}
*/

/*
// Exercício 4.31 (ALGORITMO DO SELECTION SORT)
#include <iostream>
#include <cstdlib>

void  selectionSort(int [], int);

int main(){
    int array[40];
    for(int contador = 0; contador < 40; contador++){
        array[contador] = rand() % 100 + 1;
        std::cout << array[contador] << " ";
    }
    selectionSort(array, 40);
    std::cout << std::endl;
    for(int contador = 0; contador < 40; contador++){
        std::cout << array[contador] << " ";
    }
    return 0;
}

void selectionSort(int vetor[], int tamanho){
    int passagens = 0, min, guardarIndice, guardarValor;
    while(passagens <= tamanho - 1){ // O último termo é automaticamente ordenado
        min = vetor[passagens];
        guardarIndice = passagens; // Inicializar a variável guardarIndice, que é o índice do menor termo. No começo, supõe que é o primeiro.
        for(int i = passagens; i < tamanho; i++){
            if(vetor[i] < min){
                min = vetor[i];
                guardarIndice = i;
            }
        }
        guardarValor = vetor[passagens];
        vetor[passagens] = min;
        vetor[guardarIndice] = guardarValor;
        passagens++;
    }
}
*/

/*
// Exercício 4.32
#include <iostream>
#include <string>

int palindromo(std::string);

int main(){
    std::string frase; // Declarando duas variáveis do tipo std::string, da biblioteca string.
    // Com std::string não preciso declarar o tamanho, como seria com char.
    std::cout << "Digite a frase desejada:";
    std::getline(std::cin, frase); // Se usar só o cin, ele só pega até o primeiro espaço!
    std::cout << "Eh palindromo: " << palindromo(frase) << std::endl;
}

int palindromo(std::string fraseTeste){
    std::string semEspacos;
    int tamanho = 0;
    for (char c : fraseTeste) {
        if (c != ' ') {
            semEspacos += c; // Adiciona letra por letra em semEspacos, sem adicionar os espaços
            tamanho += 1;
        }
    }
    for(int contador = 0; contador < tamanho; contador++){
        if(semEspacos[contador] == semEspacos[tamanho-contador-1]){

        }
        else{
            return 0;
        }
    }
    return 1;
}
*/

/*
// Exercício 4.33 (ALGORITMO DE PESQUISA LINEAR);
#include <iostream>
#include <cstdlib>

int buscaLinear(int [], int, int);

int main(){
    int array[30], termo;
    for(int contador = 0; contador < 30; contador++){
        array[contador] = rand() % 100 + 1;
        std::cout << array[contador] << " ";
    }
    std::cout << std::endl;
    std::cout << "Digite o termo a ser buscado: " << std::endl;
    std::cin >> termo;
    std::cout << "Achou (posicao) ou nao (-1): " << buscaLinear(array, 30, termo) << std::endl;
    return 0;
}

int buscaLinear(int vetor[], int tamanho, int buscado){
    for(int contador = 0; contador < tamanho; contador++){
        if(vetor[contador] == buscado){
            return contador;
        }
    }
    return -1;
}
*/

/*
// Exercício 4.34 (ALGORITMO DE PESQUISA BINÁRIA)
#include <iostream>
#include <cstdlib>

int buscaBinaria(int[], int, int);
void ordenar(int[], int);
enum Status { NO, YES };

int main(){
    int array[30], buscado;
    for(int contador = 0; contador < 30; contador++){
        array[contador] = rand() % 100 + 1;
        std::cout << array[contador] << " ";
    }
    std::cout << std::endl;
    std::cout << "Digite o valor buscado: " << std::endl;
    std::cin >> buscado;
    std::cout << std::endl;
    ordenar(array, 30);
    for(int contador = 0; contador < 30; contador++){
        std::cout << array[contador] << " ";
    }
    std::cout << std::endl;
    std::cout << "Achou (posicao) ou nao (-1): " << buscaBinaria(array, 30, buscado);
    return 0;
}

void ordenar(int vetor[], int tamanho){ // Aplicação do Bubble Sort
    int n = 1;
    while(n != 0){
        n = 0;
        for(int contador = 0; contador < tamanho - 1; contador++){
            if(vetor[contador] > vetor[contador+1]){
                int guardar = vetor[contador+1];
                vetor[contador+1] = vetor[contador];
                vetor[contador] = guardar;
                n++;
            }
        }
    }
}

int buscaBinaria(int vetor[], int tamanho, int procurado) {
    int inicio = 0;
    int fim = tamanho - 1;

    // Enquanto o intervalo de busca for válido
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        // Se encontrarmos o valor procurado no meio do intervalo
        if (vetor[meio] == procurado) {
            return meio; // Retornar o índice do elemento encontrado
        } else if (vetor[meio] < procurado) {
            inicio = meio + 1; // Descartar a metade inferior do array
        } else {
            fim = meio - 1; // Descartar a metade superior do array
        }
    }

    return -1; // Retornar -1 se o elemento não for encontrado
}
*/

/*
// Exercício 4.36 (Imprime caractere por caractere de um Array. Não foi especificado o tipo do Array)
// Preciso fazer, então, um gabarito de função (RECURSIVO) que funcione para um array de char e um array de int.
#include <iostream>

// Gabarito de função genérico para imprimir um array recursivamente
template <typename T, size_t N>
void imprimirArrayRecursivo(const T (&array)[N], size_t index = 0) { // size_t index tem valor padrão, que vai sendo modificado na recursao
    // const diz que a função não vai modificar o array de tipo T
    // o próprio compilador consegue identificar o tamanho N do array
    // o entendimento total da passagem const T (&array)[N] é assunto do próximo capítulo!
    // Base case: se index alcançou o tamanho do array, encerra a recursão
    if (index == N) {
        std::cout << std::endl;
        return;
    }

    // Imprime o elemento atual e chama recursivamente para o próximo elemento
    std::cout << array[index] << " ";
    imprimirArrayRecursivo(array, index + 1);
}

int main() {
    // Exemplo de uso com array de caracteres
    char charArray[] = "Hello";
    std::cout << "Array de caracteres: ";
    imprimirArrayRecursivo(charArray);

    // Exemplo de uso com array de inteiros
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Array de inteiros: ";
    imprimirArrayRecursivo(intArray);

    return 0;
}
*/

/*
// Exercício 4.37 (Semelhante ao anterior, vou copiar e mudar só a imprimirArray)
#include <iostream>

// Gabarito de função genérico para imprimir um array recursivamente
template <typename T, size_t N>
void imprimirArrayRecursivo(const T (&array)[N], size_t index = 0) { // size_t index tem valor padrão, que vai sendo modificado na recursao
    // const diz que a função não vai modificar o array de tipo T
    // o próprio compilador consegue identificar o tamanho N do array
    // o entendimento total da passagem const T (&array)[N] é assunto do próximo capítulo!
    // Base case: se index alcançou o tamanho do array, encerra a recursão
    if (index == N) {
        std::cout << std::endl;
        return;
    }

    // Imprime o elemento atual e chama recursivamente para o próximo elemento
    std::cout << array[N-1-(index)]; // Única diferença para a questão anterior.
    imprimirArrayRecursivo(array, index + 1);
}

int main() {
    // Exemplo de uso com array de caracteres
    char charArray[] = "Hello";
    std::cout << "Array de caracteres: ";
    imprimirArrayRecursivo(charArray);

    // Exemplo de uso com array de inteiros
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Array de inteiros: ";
    imprimirArrayRecursivo(intArray);

    return 0;
}
*/

/*
// Exercício 4.38
#include <iostream>
#include <cstdlib>

int minimo(const int array[], int indice = 0){
    static int min;
    if(indice == 0){
        min = array[0];
    }
    if(indice == 30){ // Garante que o último elemento também seja candidato a minimo
        return min;
    }
    else{
        if(array[indice] < min){
            min = array[indice];
        }
        return minimo(array, indice+1);
    }
}

int main(){
    int array[30];
    for(int contador = 0; contador < 30; contador++){
        array[contador] = rand() % 100 + 1;
        std::cout << array[contador] << " ";
    }
    std::cout << std::endl << "Valor minimo: " << minimo(array) << std::endl;
}
*/

/*
    Exercícios 4.24, 4.25 e 4.28 (sobre Passeio do Cavalo)
    e
    Exercícios 4.26, 2.27 e 4.35 (sobre Oito Rainhas)
    serão postados em outro arquivo, em momento oportuno.
*/