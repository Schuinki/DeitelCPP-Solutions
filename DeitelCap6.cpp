/*
// Exercício 6.5
#include <iostream>
#include <ctime>

class Time { // Não precisa de parênteses.
public:
    Time();
    void displayTime();
private:
    int hour;
    int minute;
    int second;
}; // Precisa de ponto e vírgula.

int main() {
    Time tempoatual;
    tempoatual.displayTime();
    return 0;
}

// Construtor da classe Time
Time::Time() { // Para definir as funções dentro da classe, tem que usar Time::
    std::time_t now = std::time(0); // Número de segundos desde 1 de janeiro de 1970
    std::tm *ltm = std::localtime(&now); // Converte para a hora local

    // Inicializa os membros da classe com a hora atual
    hour = ltm->tm_hour; // Acessa a hora local (0-23)
    minute = ltm->tm_min; // Acessa os minutos (0-59)
    second = ltm->tm_sec; // Acessa os segundos (0-59)
}

// Método para exibir a hora atual
void Time::displayTime() {
    std::cout << "Hora atual: "
              << (hour < 10 ? "0" : "") << hour << ":"
              << (minute < 10 ? "0" : "") << minute << ":"
              << (second < 10 ? "0" : "") << second
              << std::endl;
}
*/

/*
// Exercício 6.6
#include <iostream>

class Complexos {
public:
    // Construtor e inicialização com valores padrão
    Complexos(double real = 0, double imag = 0) : parteReal(real), parteImaginaria(imag) {} // Já com a "lista de inicialização", que é depois do :

    // Função que retorna objeto da classe Complexos
    Complexos adicao(const Complexos& outro) const {
        return Complexos(parteReal + outro.parteReal, parteImaginaria + outro.parteImaginaria);
    }

    // Subtrai dois números complexos
    Complexos subtracao(const Complexos& outro) const {
        return Complexos(parteReal - outro.parteReal, parteImaginaria - outro.parteImaginaria);
    }

    // Imprime o número complexo
    void imprimir() const {
        std::cout << "(" << parteReal << " , " << parteImaginaria << ")" << std::endl;
    }

private:
    double parteReal;
    double parteImaginaria;
};

int main() {
    Complexos numero1(1, 2); // Primeiro número complexo
    Complexos numero2(3, 4); // Segundo número complexo

    // Soma e imprime
    Complexos soma = numero1.adicao(numero2); // Igualando objeto a outro objeto
    std::cout << "Soma: ";
    soma.imprimir(); // soma é objeto, conforme definição acima

    // Subtração e imprime
    Complexos subtracao = numero1.subtracao(numero2); // Está igualando um objeto a outro objeto (retorno de subtracao é objeto)
    std::cout << "Subtracao: ";
    subtracao.imprimir();

    return 0;
}
*/

/*
// Exercício 6.7
#include <iostream>

class Racional{
public:
    // Construtor já com inicialização
    Racional(int num = 0, int den = 1) : numerador(num), denominador(den) {
        // Verifica se a fração está reduzida
        if (num != 0) {
            int gcd = gcdEuclidiano(abs(num), abs(den)); /// Vai puxar do private.
            numerador /= gcd;
            denominador /= gcd;
        } else {
            denominador = 1; // Se o numerador for 0, o denominador deve ser 1
        }
    }

    // Funções solicitadas
    Racional adicao(const Racional&);
    Racional subtracao(const Racional&);
    Racional multiplicacao(const Racional&);
    Racional divisao(const Racional&);
    Racional simplificar();
    void imprimirAB();
    void imprimirPF();

private:
    int numerador;
    int denominador;

    int gcdEuclidiano(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

};

int main(){
    Racional numero1(1, 5);
    Racional numero2(5, 5);

    Racional soma = numero1.adicao(numero2);
    soma.simplificar();
    soma.imprimirAB();
    soma.imprimirPF();

    Racional subtracao = numero1.subtracao(numero2);
    subtracao.simplificar();
    subtracao.imprimirAB();
    subtracao.imprimirPF();

    Racional multiplicacao = numero1.multiplicacao(numero2);
    multiplicacao.simplificar();
    multiplicacao.imprimirAB();
    multiplicacao.imprimirPF();

    Racional divisao = numero1.divisao(numero2);
    divisao.simplificar();
    divisao.imprimirAB();
    divisao.imprimirPF();

    return 0;
}

Racional Racional::adicao(const Racional& outro){
    return Racional(numerador * outro.denominador + outro.numerador * denominador, denominador * outro.denominador);
}

Racional Racional::subtracao(const Racional& outro){
    return Racional(numerador * outro.denominador - outro.numerador * denominador, denominador * outro.denominador);
}

Racional Racional::multiplicacao(const Racional& outro){
    return Racional(numerador * outro.numerador, denominador * outro.denominador);
}

Racional Racional::divisao(const Racional& outro){
    return Racional(numerador * outro.denominador, denominador * outro.numerador);
}

Racional Racional::simplificar() {
    int mdc = gcdEuclidiano(abs(numerador), abs(denominador)); // Calcula o MDC
    if (mdc > 1) { // Se o MDC for maior que 1, a fração pode ser simplificada
        return Racional(numerador / mdc, denominador / mdc); // Simplifica a fração
    } else {
        return *this; // Retorna a própria fração se não puder ser simplificada
    }
}


void Racional::imprimirAB(){
    std::cout << numerador << "/" << denominador << std::endl;
}

void Racional::imprimirPF(){
    double den = denominador;
    std::cout << static_cast<double>(numerador/den) << std::endl;
}
*/

/*
// Exercício 6.8
// Copiando a tal figura 6.10 (que é imensa)
#include <iostream>

class Time {
public:
    Time(int = 0, int = 0, int = 0); // Constructor with default values

    // Initialization functions
    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    // Get functions
    int getHour();
    int getMinute();
    int getSecond();

    void printMilitary();
    void printStandard();
    void tick();

private:
    int hour;
    int minute;
    int second;
};

int main() {
    Time tempo(11, 59, 57);
    for (int contador = 0; contador < 20; contador++) {
        tempo.tick();
        tempo.printStandard();
        std::cout << std::endl;
    }
}

Time::Time(int hr, int min, int sec) {
    setTime(hr, min, sec);
}

void Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Time::setHour(int h) {
    hour = ((h >= 0 && h < 24) ? h : 0);
}

void Time::setMinute(int m) {
    minute = ((m >= 0 && m < 60) ? m : 0);
}

void Time::setSecond(int s) {
    second = ((s >= 0 && s < 60) ? s : 0);
}

int Time::getHour() { return hour; }
int Time::getMinute() { return minute; }
int Time::getSecond() { return second; }

void Time::printMilitary() {
    std::cout << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute;
}

void Time::printStandard() {
    std::cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << (minute < 10 ? "0" : "") << minute << ":";
    std::cout << (second < 10 ? "0" : "") << second << (hour < 12 ? " da manha" : " da tarde");
}

void Time::tick() {
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
            }
        }
    }
}
*/

/*
// Exercício 6.9
// Copiando a figura 6.12
#include <iostream>

using std::cout;
using std::endl;

class Date{
public:
    Date(int = 1, int = 1, int = 1990); // Construtor com default
    void print();
    void nextDay();
private:
    int month;
    int day;
    int year;
};

int main(){
    Date diaAtual(12, 19, 2024);
    for(int contador = 0; contador < 20; contador++){
        diaAtual.nextDay();
        diaAtual.print();
        cout << endl;
    }
}

Date::Date(int m, int d, int y){
    if(m < 13 && m > 0){month = m;}
    if(d < 31 && d > 0){day = d;}
    if(y > 0){year = y;}
}

void Date::print(){
    cout << day << "/" << month << "/" << year;
}

void Date::nextDay(){
    day++;
    if(day == 31){
        day = 1;
        month++;
        if(month == 13){
            month = 1;
            year++;
        }
    }
}
*/

/*
// Exercício 6.10 e 6.11
// Unindo as classes dos exercícios acima sem usar herança
#include <iostream>

class Date{
public:
    Date(int = 1, int = 1, int = 1990); // Construtor com default
    void print() const;
    void nextDay();
private:
    int month;
    int day;
    int year;
};

class Time {
public:
    Time(int = 0, int = 0, int = 0);


    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    // Get functions
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void printMilitary() const;
    void printStandard() const;
    void tick(Date&); 

private:
    int hour;
    int minute;
    int second;
};

int main() {
    Time tempo(31, 64, 62);
    Date data(12, 31, 2012);
    for (int contador = 0; contador < 20; contador++) {
        tempo.tick(data); 
        tempo.printStandard();
        std::cout << std::endl;
    }
}

Time::Time(int hr, int min, int sec) {
    setTime(hr, min, sec);
}

void Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Time::setHour(int h) {
    if(h >= 0 && h < 24){
        hour = h;
    }else{
        std::cout << "O input de hour esta errado. Atualizando para o padrao hr = 3." << std::endl;
        hour = 3;
    }
}

void Time::setMinute(int m) {
    if(m >= 0 && m < 60){
        minute = m;
    }else{
        std::cout << "O input de minute esta errado. Atualizando para o padrao min = 0." << std::endl;
        minute = 0;
    }
}

void Time::setSecond(int s) {
    if(s >= 0 && s < 60){
        second = s;
    }else{
        std::cout << "O input de second esta errado. Atualizando para o padrao seg = 0." << std::endl;
        second = 0;
    }
}

int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }

void Time::printMilitary() const {
    std::cout << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute;
}

void Time::printStandard() const {
    std::cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << (minute < 10 ? "0" : "") << minute << ":";
    std::cout << (second < 10 ? "0" : "") << second << (hour < 12 ? " da manha" : " da tarde");
}

void Time::tick(Date& dia) {
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
                dia.nextDay(); 
                dia.print();
                std::cout << std::endl;
            }
        }
    }
}

Date::Date(int m, int d, int y) : month(m), day(d), year(y) {
    if(m < 1 || m > 12) month = 1;
    if(d < 1 || d > 31) day = 1;
    if(y < 1) year = 1990;
}

void Date::print() const {
    std::cout <<  "Agora eh dia: " << day << "/" << month << "/" << year;
}

void Date::nextDay() {
    day++;
    if(day > 31) { // This is a simple increment, no month-specific logic
        day = 1;
        month++;
        if(month > 12) {
            month = 1;
            year++;
        }
    }
}
*/

/*
// Exercício 6.12
#include <iostream>

class Retangulo{
public:
    Retangulo(float, float);
    void perimetro();
    void area();
    void getLados();
private:
    float comprimento;
    float largura;
};

int main(){
    Retangulo teste(3, 5);
    Retangulo teste2(3, 21);
    Retangulo teste3(42, 54);

    teste.perimetro();
    teste.area();

    teste2.perimetro();
    teste2.area();

    teste3.perimetro();
    teste3.area();
}

Retangulo::Retangulo(float a, float b){
    if(a > 0 && a < 20){
        comprimento = a;
    }else{
        std::cout << "Fora do padrao o primeiro termo. Por padrao coloco 1." << std::endl;
        comprimento = 1;
    }
    if(b > 0 && b < 20){
        largura = b;
    }else{
        std::cout << "Fora do padrao o segundo termo. Por padrao coloco 1." << std::endl;
        largura = 1;
    }
}

void Retangulo::getLados(){
    std::cout << "Largura eh " << largura << std::endl << "Comprimento eh " << comprimento << std::endl;
}

void Retangulo::area(){
    std::cout << "A area do referido retangulo eh " << comprimento*largura << std::endl;
}

void Retangulo::perimetro(){
    std::cout << "O perimetro do referido retangulo eh " << 2*comprimento + 2*largura << std::endl;
}
*/

/*
// Exercício 6.13 e 6.14
#include <iostream>
#include <cmath>

class Retangulo{
public:
    Retangulo();
    void setCantos();
    float comprimento();
    float largura();
    void area();
    void perimetro();
    bool quadrado();
    void desenharRetangulo();
    void escalamaior();
private:
    float array[4][2];
    float distancias[6];
};

int main(){
    Retangulo quadrilatero;
    quadrilatero.area();
    quadrilatero.perimetro();
    std::cout << "Eh quadrado? " << std::boolalpha << quadrilatero.quadrado() << std::endl;
    quadrilatero.desenharRetangulo();
}

void Retangulo::setCantos(){
    float x, y;
    for(int contador = 0; contador < 4; contador++){
        std::cout << "Digite o par cartesiano em float: " << std::endl;
        std::cin >> x >> y;
        while(x < 0 || y < 0 || x > 20.0 || y > 20.0){
            std::cout << "Digite o par cartesiano em float valido, entre 0 e 20.0: " << std::endl;
            std::cin >> x >> y;
        }
        array[contador][0] = x;
        array[contador][1] = y;
    }

    // Verificação se é de fato um retângulo
    int index = 0;
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 4; j++){
            distancias[index++] = sqrt(pow(array[i][0] - array[j][0], 2) + pow(array[i][1] - array[j][1], 2));
        }
    }

    // Bubble sort para ordenar as distâncias
    for (int i = 0; i < 6 - 1; ++i) {
        for (int j = 0; j < 6 - i - 1; ++j) {
            if (distancias[j] > distancias[j + 1]) {
                // Troca os elementos se estiverem fora de ordem
                float temp = distancias[j];
                distancias[j] = distancias[j + 1];
                distancias[j + 1] = temp;
            }
        }
    }
}

Retangulo::Retangulo(){
    setCantos();
}

float Retangulo::comprimento(){
    // O comprimento é a maior distância sem ser as diagonais
    return distancias[3];
}

float Retangulo::largura(){
    return distancias[0];
}

void Retangulo::area(){
    std::cout << "Area: " << largura()*comprimento() << std::endl;
}

void Retangulo::perimetro(){
    std::cout << "Perimetro: " << 2*(largura()+comprimento()) << std::endl;
}

bool Retangulo::quadrado(){
    // Um retângulo é um quadrado se e somente se o comprimento for igual à largura
    return comprimento() == largura();
}

void Retangulo::desenharRetangulo(){
    char fundo[25][25];
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 25; j++){
            fundo[i][j] = '.';
        }
    }

    // Conectar os cantos do retângulo
    // Conectar os lados horizontais
    for(int j = static_cast<int>(array[0][0]); j <= static_cast<int>(array[1][0]); j++){
        fundo[static_cast<int>(array[0][1])][j] = '*'; // Conectar lado superior
        fundo[static_cast<int>(array[2][1])][j] = '*'; // Conectar lado inferior
    }
    // Conectar os lados verticais
    for(int i = static_cast<int>(array[0][1]); i <= static_cast<int>(array[2][1]); i++){
        fundo[i][static_cast<int>(array[0][0])] = '*'; // Conectar lado esquerdo
        fundo[i][static_cast<int>(array[1][0])] = '*'; // Conectar lado direito
    }

    // Desenhar os cantos do retângulo
    fundo[static_cast<int>(array[0][1])][static_cast<int>(array[0][0])] = '*'; // Canto superior esquerdo
    fundo[static_cast<int>(array[1][1])][static_cast<int>(array[1][0])] = '*'; // Canto superior direito
    fundo[static_cast<int>(array[2][1])][static_cast<int>(array[2][0])] = '*'; // Canto inferior esquerdo
    fundo[static_cast<int>(array[3][1])][static_cast<int>(array[3][0])] = '*'; // Canto inferior direito

    // Imprimir o retângulo
    for(int i = 24; i >= 0; i--){
        for(int j = 0; j < 25; j++){
            std::cout << fundo[i][j];
        }
        std::cout << std::endl;
    }
}
*/


/*
// Exercício 6.15
#include <iostream>
#include <cstring>

class InteiroGigante{
public:
    InteiroGigante();
    void setInteiroGigante(); // Imagino que é a leia que ele pediu
    void imprimirInteiroGigante();

    // Funções predicado solicitadas
    bool eIgualA(InteiroGigante &);
    bool eMaiorQue(InteiroGigante &);
    bool naoEIgualA(InteiroGigante &);
    bool eMenorQue(InteiroGigante &);
    bool eMaiorQueOuIgualA(InteiroGigante &);
    bool eMenorQueOuIgualA(InteiroGigante &);
    bool eZero();

private:
    int arrayGigante[40];
};

int main(){
    InteiroGigante numero1, numero2;
    numero1.setInteiroGigante();
    numero1.imprimirInteiroGigante();
    numero2.setInteiroGigante();
    numero2.imprimirInteiroGigante();

    std::cout << "Eh igual: " << numero1.eIgualA(numero2) << std::endl;
    std::cout << "Nao eh igual: " << numero1.naoEIgualA(numero2) << std::endl;
    std::cout << "O primeiro eh maior que o segundo: " << numero1.eMaiorQue(numero2) << std::endl;
    std::cout << "O primeiro eh maior ou igual que o segundo: " << numero1.eMaiorQueOuIgualA(numero2) << std::endl;
    std::cout << "O primeiro numero eh zero: " << numero1.eZero() << std::endl;
    std::cout << "O segundo numero eh zero: " << numero2.eZero() << std::endl;
    std::cout << "O primeiro eh menor que o segundo: " << numero1.eMenorQue(numero2) << std::endl;
    std::cout << "O primeiro eh menor ou igual que o segundo: " << numero1.eMenorQueOuIgualA(numero2) << std::endl;

}

InteiroGigante::InteiroGigante(){
    std::cout << "Inicializado: ";
    for(int i = 0; i < 40; i++){
        arrayGigante[i] = 0;
        std::cout << arrayGigante[i];
    }
    std::cout << std::endl;
}

void InteiroGigante::setInteiroGigante() {
    char entrada[41]; // Criar um array de caracteres para armazenar temporariamente a entrada, com espaço para o caractere nulo
    std::cout << "Digite um número de até 40 dígitos: ";
    std::cin.getline(entrada, 41); // Ler a entrada do usuário

    int tamanho = strlen(entrada); // Obter o tamanho da entrada

    // Armazenar os dígitos na ordem correta no arrayGigante
    for (int i = 0; i < tamanho; ++i) {
        arrayGigante[40 - tamanho + i] = entrada[i] - '0';
    }
}


void InteiroGigante::imprimirInteiroGigante(){
    std::cout << "Imprimindo: ";
    for(int contador = 0; contador < 40; contador++){
        std::cout << arrayGigante[contador];
    }
    std::cout << std::endl;
}

bool InteiroGigante::eIgualA(InteiroGigante& outro){
    for(int contador = 0; contador < 40; contador++){
        if(arrayGigante[contador] != outro.arrayGigante[contador]){
            return false;
        }
    }
    return true;
}

bool InteiroGigante::naoEIgualA(InteiroGigante& outro){
    for(int contador = 0; contador < 40; contador++){
        if(arrayGigante[contador] != outro.arrayGigante[contador]){
            return true;
        }
    }
    return false;   
}

bool InteiroGigante::eMaiorQue(InteiroGigante& outro) {
    for (int i = 0; i < 40; ++i) {
        if (arrayGigante[i] > outro.arrayGigante[i]) {
            return true;
        } else if (arrayGigante[i] < outro.arrayGigante[i]) {
            return false;
        }
    }
    // Se chegou aqui, os números são iguais
    return false;
}

bool InteiroGigante::eMaiorQueOuIgualA(InteiroGigante& outro){
    for (int i = 0; i < 40; ++i) {
        if (arrayGigante[i] > outro.arrayGigante[i]) {
            return true;
        } else if (arrayGigante[i] < outro.arrayGigante[i]) {
            return false;
        }
    }
    // Se chegou aqui, os números são iguais
    return true;  
}

bool InteiroGigante::eZero(){
    int soma = 0;
    for(int contador = 0; contador < 40; contador++){
        if(arrayGigante[contador] == 0){
            soma++;
        }
    }
    if(soma == 40){
        return true;
    }else{
        return false;
    }
}

bool InteiroGigante::eMenorQue(InteiroGigante& outro){
    for (int i = 0; i < 40; i++) {
        if (arrayGigante[i] < outro.arrayGigante[i]) {
            return true;
        } else if (arrayGigante[i] > outro.arrayGigante[i]) {
            return false;
        }
    }
    // Se chegou aqui, os números são iguais
    return false;     
}

bool InteiroGigante::eMenorQueOuIgualA(InteiroGigante& outro){
    for (int i = 0; i < 40; i++) {
        if (arrayGigante[i] < outro.arrayGigante[i]) {
            return true;
        } else if (arrayGigante[i] > outro.arrayGigante[i]) {
            return false;
        }
    }
    // Se chegou aqui, os números são iguais
    return true;     
}
*/

// Exercício 6.16 (Jogo da Velha)
#include <iostream>

class JogoDaVelha{
public:
    JogoDaVelha();
    void imprimirTabuleiro();
    void jogada();
    bool verificarVitoria(char);
private:
    char tabuleiro[3][3];
};

int main(){
    std::cout << "Iniciando jogo da velha jogador x jogador" << std::endl;
    JogoDaVelha jogo;
    jogo.imprimirTabuleiro();
    std::cout << "Jogador 1 eh X e jogador 2 eh O!!" << std::endl;
    jogo.jogada();

}

JogoDaVelha::JogoDaVelha(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = '.';
        }
    }
}

void JogoDaVelha::imprimirTabuleiro(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << tabuleiro[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void JogoDaVelha::jogada(){
    int vez = 1, espaco;
    int a, b;
    bool space = true;
    while (space){
        if(vez == 1 || vez == 2){
            char jogador = (vez == 1) ? 'X' : 'O';
            std::cout << "Digite sua jogada no formato A B: " << std::endl;
            std::cin >> a >> b;
            while(a < 0 || a > 2 || b < 0 || b > 2 || tabuleiro[a][b] != '.'){
                std::cout << std::endl << "Jogada invalida! Essa casa ja foi marcada ou esta fora dos limites!" << std::endl;
                std::cout << "Digite sua jogada no formato A B: " << std::endl;
                std::cin >> a >> b;
            }
            tabuleiro[a][b] = jogador;
            vez = (vez == 1) ? 2 : 1;
        }
        imprimirTabuleiro();
        espaco = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(tabuleiro[i][j] == '.'){
                    espaco++;
                }
            }
        }
        // Verifica se há um vencedor
        if(verificarVitoria('X')){
            std::cout << "Jogador X venceu!" << std::endl;
            break;
        }
        if(verificarVitoria('O')){
            std::cout << "Jogador O venceu!" << std::endl;
            break;
        }
        if(espaco == 0){
            std::cout << "Empate!" << std::endl;
            space = false;
        }
    }
}

bool JogoDaVelha::verificarVitoria(char jogador){
    // Verifica linhas
    for(int i = 0; i < 3; i++){
        if(tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador){
            return true;
        }
    }
    // Verifica colunas
    for(int j = 0; j < 3; j++){
        if(tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador){
            return true;
        }
    }
    // Verifica diagonais
    if(tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador){
        return true;
    }
    if(tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador){
        return true;
    }
    return false;
}
