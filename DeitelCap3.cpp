// Sem os exercícios 3.42 e 3.44, que envolve Torre de Hanói, upados em separado!

/*
// Exercício 3.11
#include <iostream>
#include <cmath>
int main(){
    std::cout << fabs(7.5) << std::endl;
    std::cout << floor(7.5) << std::endl;
    std::cout << fabs(0.0) << std::endl;
    std::cout << ceil(0.0) << std::endl;
    std::cout << fabs(-6.4) << std::endl;
    std::cout << ceil(-6.4) << std::endl;
    std::cout << ceil(-fabs(-8+floor(-5.5))) << std::endl;
    return 0;
}
*/

/*
// Exercício 3.12
#include <iostream>
// Do jeito que ele mostrou o output, parece que digita o numero de carros e executa. 
// Pensei que seria melhor fazer sem saber o numero de carros. Digita quando for fechar o caixa.

// Declarando variáveis globais e protótipo da função
void calculateCharges(float);
float horaTotal = 0;
float valorTotal = 0;

int main(){
    int opt = 1;
    float hour;
    std::cout << "Iniciando..." << std::endl;
    std::cout << "Digite o numero de horas, sendo menor que 24: " << std::endl;
    std::cin >> hour;
    calculateCharges(hour);
    while (opt == 1){
        std::cout << "Deseja continuar? (0/1) " << std::endl;
        std::cin >> opt;
        if(opt == 0) break;
        else{
            std::cout << "Digite o numero de horas, sendo menor que 24: " << std::endl;
            std::cin >> hour;
            horaTotal += hour;
            calculateCharges(hour);
        }
    }
    std::cout << "Horas Totais\tTaxas Totais" << std::endl;
    std::cout << horaTotal << "\t\t\t" << valorTotal << std::endl;
    return 0;

}

void calculateCharges(float horas){
    static int counter = 1; // classe de armazenamento static (é local mas mantém salvo nas outras iterações)
    float valor;
    if(horas <= 3) valor = 2;
    if(horas > 3)  valor = (2+(horas-3)*0.5);
    valorTotal += valor;
    std::cout << "Carro\tHoras\tTaxa" << std::endl;
    std::cout << counter << "\t" << horas << "\t" << valor << std::endl;
    counter++;
}
*/

/*
// Exercício 3.13
#include <iostream>
#include <cmath>

int main(){
    float valor;
    while(true){
    std::cout << "Digite um numero float: " << std::endl;
    std::cin >> valor;
    std::cout << "Valor digitado: " << valor << std::endl
            << "Valor mais proximo: " << floor(valor + .5) << std::endl; // Fórmula para achar o inteiro mais próximo
    }
    return 0;
}
*/

/*
// Exercício 3.14
#include <iostream>
#include <cmath>

// Definindo os protótipos das funções a serem utilizadas
double roundToInteger(double);
double roundToTenths(double);
double roundToHundredths(double);
double roundToThousandths(double);

int main(){
    double valor;
    while(true){
        std::cout << "Digite um numero da forma 1.2345: " << std::endl;
        std::cin >> valor;
        std::cout << "Valor\tInteiro\tDecimo\tCentesimo\tMilesimo" << std::endl;
        std::cout << valor << "\t" << roundToInteger(valor) << "\t" << roundToTenths(valor) << "\t" << 
                    roundToHundredths(valor) << "\t\t" << roundToThousandths(valor) << std::endl;
    }
    return 0;
}

double roundToInteger(double x){
    return floor(x + .5);
}
double roundToTenths(double x){
    return floor(x*10 + .5)/10;
}
double roundToHundredths(double x){
    return floor(x*100 + .5)/100;
}
double roundToThousandths(double x){
    return floor(x*1000 + .5)/1000;
}
*/

/*
// Exercício 3.16 (Sortear inteiros)
#include <iostream>
#include <cstdlib>
#include <chrono> // chrono e thread usou para, de algum jeito, pausar o programa.
#include <thread>

void sorteio(int, int); // Protótipo

int main(){
    for(int count = 0; count < 5; count++){
        sorteio(2, 1); // 1 <= x <= 2
    }
    for(int count = 0; count < 5; count++){
        sorteio(100, 1); // 1 <= x <= 100
    }
    for(int count = 0; count < 5; count++){
        sorteio(10, 0); // 0 <= x <= 9
    }
    for(int count = 0; count < 5; count++){
        sorteio(113, 1000); // 1000 <= x <= 1112
    }
    for(int count = 0; count < 5; count++){
        sorteio(3, -1); // -1 <= x <= 1
    }
    for(int count = 0; count < 5; count++){
        sorteio(15, 3); // -3 <= x <= 1
    }
    return 0;
} 

// Definindo a função que vou usar
void sorteio(int a, int b){
    srand(time(0));
    int aleatorio = rand() % a + b; 
    std::cout << aleatorio << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // vem de chrono e thread
}
*/

/*
// Exercício 3.17
#include <iostream>
#include <cstdlib>
#include <chrono> // chrono e thread usou para pausar o programa.
#include <thread>

int sorteio(int, int); // Protótipo

int main(){
    std::cout << 2 * sorteio(6, 1) << std::endl;
    std::cout << 2 * sorteio(6, 1) + 1 << std::endl;
    std::cout << 4 * sorteio(5, 1) + 2 << std::endl;
    return 0;
}

int sorteio(int a, int b){
    srand(time(0));
    int aleatorio = rand() % a + b; 
    std::this_thread::sleep_for(std::chrono::seconds(1)); // vem de chrono e thread
    return aleatorio;
}
*/

/*
// Exercício 3.18
#include <iostream>

int integerPower(int, int);

int main(){
    int base, expoente;
    std::cout << "Digite o valor da base: " << std::endl;
    std::cin >> base;
    std::cout << "Digite o valor do expoente: " << std::endl;
    std::cin >> expoente;
    std::cout << integerPower(base, expoente);
    return 0;
}

int integerPower(int b, int e){
    int result = b;
    for(int linha = 1; linha < e; linha++){
        result *= b;
    }
    return result;
}
*/

/*
// Exercício 3.19
#include <iostream>
#include <cmath>

double hypotenuse(double, double);

int main(){
    double a, b;
    std::cout << "Digite o primeiro lado: " << std::endl;
    std::cin >> a;
    std::cout << "Digite o segundo lado: " << std::endl;
    std::cin >> b;
    std::cout << "Hipotenusa: " << hypotenuse(a, b) << std::endl;
    return 0;
}

double hypotenuse(double lado1, double lado2){
    return sqrt(lado1*lado1 + lado2*lado2);
}
*/

/*
// Exercício 3.20
#include <iostream>

bool multiple(int, int);

int main(){
    int a, b;
    std::cout << "Digite o primeiro termo: " << std::endl;
    std::cin >> a;
    std::cout << "Digite o segundo termo: " << std::endl;
    std::cin >> b;
    std::cout << "Eh multiplo: " << multiple(a, b) << std::endl;
    return 0;
}

bool multiple(int termo1, int termo2){
    if (termo2 % termo1 == 0) return true;
    else return false;
}
*/

/*
// Exercício 3.21
#include <iostream>

bool par(int);

int main(){
    int numero;
    while(true){
        std::cout << "Digite o numero a verificar: " << std::endl;
        std::cin >> numero;
        std::cout << "Eh par: " << par(numero) << std::endl;
    }
    return 0;
}

bool par(int a){
    if (a % 2 == 0) return true;
    else return false;
}
*/

/*
// Exercício 3.24 (inclui 3.22 e 3.23)
#include <iostream>

void quadrado(int, char);
void triangulo(int, char);

int main(){
    int lado, opt, altura;
    char caractere;
    std::cout << "Digite 0 para triangulo e 1 para quadrado: " << std::endl; 
    std::cin >> opt;
    if(opt == 1){
        std::cout << "Digite o lado do quadrado: " << std::endl;
        std::cin >> lado;
        std::cout << "Digite o caractere: " << std::endl;
        std::cin >> caractere;
        quadrado(lado, caractere);
    }
    if(opt == 0){
        std::cout << "Digite a altura do triangulo: " << std::endl;
        std::cin >> altura;
        std::cout << "Digite o caractere: " << std::endl;
        std::cin >> caractere;
        triangulo(altura,caractere);
    }
    return 0;
}

void quadrado(int a, char letra){
    std::cout << "\n";
    for(int linha = 1; linha <= a; linha++){
        for(int coluna = 1; coluna <= a; coluna++){
            std::cout << letra;
        }
        std::cout << std::endl;
    }
}

void triangulo(int a, char letra){
    std::cout << "\n";
    for(int linha = 1; linha <= a; linha++){
        for(int numero = 1; numero <= linha; numero++){
            std::cout << letra;
        }
        std::cout << std::endl;
    }
}
*/

/*
// Exercício 3.25
#include <iostream>
#include <cstdlib>

int inteiroQuociente(int, int);
int inteiroResto(int, int);
void imprimir(int);

int main(){
    int a, b;
    int numero = rand() % 32767 + 1;
    std::cout << "Digite os dois valores para dividir o primeiro pelo segundo: " << std::endl;
    std::cin >> a >> b;
    std::cout << inteiroQuociente(a, b) << std::endl;
    std::cout << inteiroResto(a, b) << std::endl;
    std::cout << "Sorteando um inteiro... " << std::endl;
    std::cout << "Numero sorteado: " << numero << std::endl;
    std::cout << "Imprimindo no formato desejado: " << std::endl;
    imprimir(numero);
    return 0;
}

int inteiroQuociente(int x, int y){
    return x/y;
}

int inteiroResto(int x, int y){
    return x - (x/y)*y; // Não dá 0 pois ocorre truncamento no x/y
}

void imprimir(int x){
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    a = inteiroResto(x, 10);
    b = inteiroResto(inteiroQuociente(x, 10), 10);
    c = inteiroResto(inteiroQuociente(x, 100), 10);
    d = inteiroResto(inteiroQuociente(x, 1000), 10);
    e = inteiroResto(inteiroQuociente(x, 10000), 10);
    std::cout << e << "\t" << d << "\t" << c << "\t" << b << "\t" << a;

}
*/

/*
// Exercício 3.26
#include <iostream>

int diferencaHora(int, int, int);

int main(){
    int hora, minuto, segundo;
    std::cout << "Digite a hora atual: " << std::endl;
    std::cin >> hora;
    std::cout << "Digite o minuto atual: " << std::endl;
    std::cin >> minuto;
    std::cout << "Digite o segundo atual: " << std::endl;
    std::cin >> segundo;
    std::cout << "Segundos passados desde 12h: " << diferencaHora(hora, minuto, segundo) << std::endl;
    return 0;
}

int diferencaHora(int h, int m, int s){
    if(h >= 12){
        return ((h-12)*3600+m*60+s);
    }else{
        return (86000 - (12-h)*3600 + 60*m - s);
    }
}
*/

/*
// Exercício 3.27
#include <iostream>

double fahrenheit(double);
double celsius(double);
void tabela(void);

int main(){
    double fah, cel;
    std::cout << "Digite a temperatura em Celsius: " << std::endl;
    std::cin >> cel;
    std::cout << "Temperatura em Fahrenheit: " << fahrenheit(cel) << std::endl;
    std::cout << "Digite a temperatura em Fahrenheit: " << std::endl;
    std::cin >> fah;
    std::cout << "Temperatura em Celsius: " << celsius(fah) << std::endl;
    std::cout << "Tabela completa de conversao: " << std::endl;
    tabela();
    return 0;
}

double fahrenheit(double x){
    return (x*9/5 + 32);
}

double celsius(double x){
    return (x-32)*5/9;
}
void tabela(void){
    for(int cel = 0; cel <= 100; cel++){
        std::cout << "Celsius: " << cel << "\tFahrenheit: " << fahrenheit(cel) << std::endl;
    }
}
*/

/*
// Exercício 3.28
#include <iostream>

double menor(double, double, double);

int main(){
    double a, b, c;
    std::cout << "Digite tres valores double: " << std::endl;
    std::cin >> a >> b >> c;
    std::cout << "Menor deles eh: " << menor(a, b, c) << std::endl;
    return 0;
}

double menor(double x, double y, double z){
    double min = x;
    if(min > y) min = y;
    if(min > z) min = z;
    return min;
}
*/

/*
// Exercício 3.29
#include <iostream>

int perfect(int);

int main(){
    int numero, contador;
    std::cout << "Digite o numero para testar: " << std::endl;
    std::cin >> numero;
    if(perfect(numero) == 0){
        
    }else{
        std::cout << "Numero perfeito: " << perfect(numero) << std::endl;
    }
    std::cout << "Numero perfeitos entre 1 e 1000:" << std::endl;
    for(contador = 1; contador <= 1000; contador++){
       if(perfect(contador) == 0){
        
        }else{
        std::cout << "Numero perfeito: " << perfect(contador) << std::endl;
        } 
    }
    return 0;
}

int perfect(int x){
    int soma = 0;
    int contador;
    for(contador = 1; contador < x; contador++){
        if(x % contador == 0) soma += contador;
    }
    if(soma == x) return x;
    else return 0;
}
*/

/*
// Exercício 3.30
#include <iostream>
#include <cmath>

int isPrime(int);

int main(){
    for(int contador = 1; contador <= 100; contador++){ // Diminui para ficar melhor o output
        if(isPrime(contador) == 0);
        if(isPrime(contador) != 0){
            std::cout << contador << " eh primo!" << std::endl;
        }
    }
}

int isPrime(int x){
    int soma = 0;
    for(int contador = 2; contador <= static_cast<int>(sqrt(x)) ; contador++ ){
        // So precisa ir ate a raiz quadrada pois os termos superiores a ela ja foram testados antes. Ex.: 2*50 = 100 testa tanto 2 quanto 50
        // Reduz a complexidade
        if(x % contador == 0) soma += 1;
    }
    if(soma != 0) return 0;
    else return 1;
}
*/

/*
// Exercício 3.31
#include <iostream>

void inverter(int);

int main(){
    int numero;
    std::cout << "Digite o numero para inverter: ";
    std::cin >> numero;
    inverter(numero);
    return 0;
}

void inverter(int x){
    int numero;
    while(x != 0){
        numero = x%10;
        x = (x - numero)/10;
        std::cout << numero;
    }
}
*/

/*
// Exercício 3.32
#include <iostream>

int mdc(int, int);

int main(){
    int a, b;
    std::cout << "Digite dois números para achar MDC: " << std::endl;
    std::cin >> a >> b;
    std::cout << "MDC: " << mdc(a, b) << std::endl;
    return 0;
}

int mdc(int x, int y){
    int max = 1;
    if(x >= y){
        for(int contador = 1; contador <= y; contador++){
            if(x % contador == 0 && y % contador == 0 && contador > max) max = contador;
        }
    }
    else{
        for(int contador = 1; contador <= x; contador++){
            if(x % contador == 0 && y % contador == 0 && contador > max) max = contador;
        }
    }
    return max;
}
*/

/*
// Exercício 3.33
#include <iostream>

int pontosDeQualificacao(double);

int main(){
    double media;
    std::cout << "Digite a media do aluno:" << std::endl;
    std::cin >> media;
    std::cout << "Convertido: " << pontosDeQualificacao(media);
    return 0;
}

int pontosDeQualificacao(double x){
    if(x >= 90) return 4;
    if(x >= 80) return 3;
    if(x >= 70) return 2;
    if(x >= 60) return 1;
    else return 0;
}
*/

/*
// Exercício 3.34 (usando operador unário de escopo)
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

int resultado = 0;

bool flip(void){
    srand(time(0));
    int resultado = rand() % 2;
    if(resultado == 1){
        ::resultado += 1;
        return true;
    }
    else return false;
}

int main(){
    for(int contador = 1; contador <= 30; contador++){ // Reduzi pra ficar melhor o resultado final
        std::cout << "Lancamento" << contador << "\tResultado:" << flip() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // vem de chrono e thread, serve pra dar tempo de atualizar resultado
    }
    std::cout << "Numero de caras: " << resultado;
    std::cout << "Numero de coroas " << 30 - resultado;
    return 0;
}
*/

/*
// Exercício 3.37 (inclui 3.35 e 3.36)
#include <iostream>
#include <cstdlib>

void respostaCerta(void);
void respostaErrada(void);

int main(){
    int resposta, contador = 0, certa = 0;
    while(true){
        contador += 1;
        int x = rand() % 8 + 1;
        int y = rand() % 8 + 1;
        std::cout << "Quanto vale " << x << " x " << y << "?" << std::endl;
        while(resposta != x*y){
            std::cin >> resposta;
            if(resposta == x*y){
                respostaCerta();
            }
            else{
                respostaErrada();
            }
        }
        // if(contador == 10){
            //Essa parte muda a lógica da questão! 
            //Antes só parava de perguntar se acertasse.
            // Agora se errar, supostamente é pra passar pra próxima, pra fechar a porcentagem que ele pediu.
            // if (CRITERIO){
                // std::cout << "Solicite ajuda extra ao professor" << std::endl;
                // break; 
            // }
            // else{
                //contador = 0;
                // certa = 0;
            // } 
        // }
    }
    return 0;
}

void respostaCerta(void){
    int sorteio = rand() % 4; // Ele pediu de 1 a 4, mas também funciona, mais fácil, de 0 a 3.
    switch(sorteio){
        case 0:
            std::cout << "Muito bem!" << std::endl;
            break;
        case 1:
            std::cout << "Excelente!" << std::endl;
            break;
        case 2:
            std::cout << "Bom trabalho!" << std::endl;
            break;
        case 3:
            std::cout << "Certo! Continue assim!" << std::endl;
            break;
    }
}

void respostaErrada(void){
    int sorteio = rand() % 4;
    switch(sorteio){
        case 0:
            std::cout << "Nao. Tente novamente!" << std::endl;
            break;
        case 1:
            std::cout << "Errado. Tente outra vez." << std::endl;
            break;
        case 2:
            std::cout << "Nao desista." << std::endl;
            break;
        case 3:
            std::cout << "Nao. Continue tentando." << std::endl;
            break;
    }
}
*/

/*
// Exercício 3.39 (inclui 3.38)
// Explicação teórica pedida: funcionamento da busca binária. Escolhe o do meio e verifica se é maior ou menor, e vai dividindo na metade.
#include <iostream>
#include <cstdlib>
int main(){
    enum Status { ON, OFF };
    Status gameStatus = ON;
    while(gameStatus == ON){
        int sorteado = rand() % 1000 + 1;
        int chute, contador = 1, opt;
        std::cout << "Tenho um numero entre 1 e 1000.\nVoce pode adivinhar meu numero?" << std::endl;
        while(sorteado != chute){
            std::cout << "Digite seu palpite numero " << contador << ":" << std::endl;
            std::cin >> chute;
            if(chute > sorteado){
                std::cout << "Muito alto!" << std::endl;
            }
            if(chute < sorteado){
                std::cout << "Muito baixo!" << std::endl;
            }
            contador++;
        }
        if(sorteado == chute){
            std::cout << "Excelente!" << std::endl;
            if(contador <= 10){
                std::cout << "Voce precisou de apenas " << contador << " tentativas! Deve ter o segredo." << std::endl;
            }
            else{
                std::cout << "Voce precisou de " << contador << " tentativas. Melhore!" << std::endl;
            }
            std::cout << "Deseja jogar novamente? (0/1)" << std::endl;
            std::cin >> opt;
            if(opt == 0) gameStatus = OFF;
            if(opt == 1) gameStatus = ON;
        }
    }
    return 0;
}
*/

/*
// Exercício 3.40
#include <iostream>

int potencia(int, int);

int main(){
    int base, expoente;
    std::cout << "Digite a base: " << std::endl;
    std::cin >> base;
    std::cout << "Digite o expoente: " << std::endl;
    std::cin >> expoente;
    std::cout << potencia(base, expoente);
    return 0;
}

int potencia(int x, int y){
    if(y > 0){
        return (x*potencia(x, y-1));
    }
    else{
        return 1;
    }
}
*/

/*
// Exercício 3.41
#include <iostream>

int fibonacci(int);

int main(){
    int ordem;
    std::cout << "Fibonacci: O0 - 1 \t O1 - 1 \t O2 - 2 \t O3 - 3 \t O4 - 5" << std::endl;
    std::cout << "Digite a ordem: " << std::endl;
    std::cin >> ordem;
    std::cout << "Termo de ordem " << ordem << ": " << fibonacci(ordem) << std::endl;
    return 0;
}

int fibonacci(int a){
    if (a == 0 || a == 1) return 1;
    else{
        return fibonacci(a-1) + fibonacci(a-2);
    }
}
*/

// Exercício 3.42 (Torre de Hanói recursiva)

// Exercício 3.43 (Torre de Hanói iterativa)

/*
// Exercício 3.44
#include <iostream>

int factorial(int);

int main(){
    int termo;
    std::cout << "Digite o termo pra calcular fatorial:" << std::endl;
    std::cin >> termo;
    std::cout << "Resultado: " << factorial(termo) << std::endl;
    return 0;
}

int factorial(int x){
    if(x > 1){
        return (x*factorial(x-1));
    }
    if(x == 1){
        return 1;
    }
}
*/

/*
// Exercício 3.45
#include <iostream>

int mdc(int, int);

int main(){
    int a, b;
    std::cout << "Digite dois valores: " << std::endl;
    std::cin >> a >> b;
    if(a > b) std::cout << "MDC =" << mdc(a, b);
    else std::cout << "MDC = " << mdc(b, a);
    return 0;
}

int mdc(int x, int y){
    if(y==0){
        return x;
    }
    else{
        return mdc(y, x % y);
    }
}
*/

/*
// Exercício 3.46
#include <iostream>
int main(){
    static int contador = 1;
    std::cout << contador << std::endl;
    contador++;
    main(); // Função main PODE ser chamada recursivamente!!
}
*/

/*
// Exercício 3.47
#include <iostream>
#include <cstdlib>

void respostaCerta(void);
void respostaErrada(void);

int main(){
    int resposta, contador = 0, certa = 0;
    int nivel, x, y, opt;
    while(true){
        contador += 1;
        std::cout << "Digite o nivel (1/2/3)" << std::endl;
        std::cin >> nivel;
        if(nivel == 1){
            x = rand() % 8 + 1;
            y = rand() % 8 + 1;
        }
        if(nivel == 2){
            x = rand() % 99 + 1;
            y = rand() % 99 + 1;
        }
        if(nivel == 3){
            x = rand() % 999 + 1;
            y = rand() % 999 + 1;
        }
        std::cout << "Digite 1 para multiplicacao e 2 para soma:  " << std::endl;
        std::cin >> opt;
        if(opt == 1){
            std::cout << "Quanto vale " << x << " x " << y << "?" << std::endl;
            while(resposta != x*y){
                std::cin >> resposta;
                if(resposta == x*y){
                    respostaCerta();
                }
                else{
                    respostaErrada();
                }
            }
        }
        else{
            std::cout << "Quanto vale " << x << "+" << y << "?" << std::endl;
            while(resposta != x+y){
                std::cin >> resposta;
                if(resposta == x+y){
                    respostaCerta();
                }else{
                    respostaErrada();
                }
            }
        }
        // if(contador == 10){
            //Essa parte muda a lógica da questão! 
            //Antes só parava de perguntar se acertasse.
            // Agora se errar, supostamente é pra passar pra próxima, pra fechar a porcentagem que ele pediu.
            // if (CRITERIO){
                // std::cout << "Solicite ajuda extra ao professor" << std::endl;
                // break; 
            // }
            // else{
                //contador = 0;
                // certa = 0;
            // } 
        // }
    }
    return 0;
}

void respostaCerta(void){
    int sorteio = rand() % 4; // Ele pediu de 1 a 4, mas também funciona, mais fácil, de 0 a 3.
    switch(sorteio){
        case 0:
            std::cout << "Muito bem!" << std::endl;
            break;
        case 1:
            std::cout << "Excelente!" << std::endl;
            break;
        case 2:
            std::cout << "Bom trabalho!" << std::endl;
            break;
        case 3:
            std::cout << "Certo! Continue assim!" << std::endl;
            break;
    }
}

void respostaErrada(void){
    int sorteio = rand() % 4;
    switch(sorteio){
        case 0:
            std::cout << "Nao. Tente novamente!" << std::endl;
            break;
        case 1:
            std::cout << "Errado. Tente outra vez." << std::endl;
            break;
        case 2:
            std::cout << "Nao desista." << std::endl;
            break;
        case 3:
            std::cout << "Nao. Continue tentando." << std::endl;
            break;
    }
}
*/

/*
// Exercício 3.48
#include <iostream>
#include <cmath>

double distance(double, double, double, double);

int main(){
    double x1, x2, y2, y1;
    std::cout << "Digite as coordenadas do primeiro ponto:" << std::endl;
    std::cin >> x1 >> y2;
    std::cout << "Digite as coordenadas do segundo ponto:" << std::endl;
    std::cin >> x2 >> y2;
    std::cout << "Distancia: " << distance(x1, y1, x2, y2) << std::endl;
}

double distance(double x, double y, double a, double b){
    return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}
*/

/*
// Exercício 3.54 (Jogo "CRAPS" bem simplificado. Não explicou com qual precisão queria na questão.)
// Várias definições distintas de craps na internet. Treinei um pouco, mas essa solução não está 100% certa.
// Faltaram definições.
#include <iostream>
#include <cstdlib>
#include <ctime>

enum Status { WIN, LOSE };

Status craps(void); // Definindo a função que vai retornar WIN ou LOSE.

int main(){
    std::srand(std::time(nullptr)); // Inicializa a semente do gerador de números aleatórios
    std::cout << "JOGO DE CRAPS!" << std::endl;
    int wager, bankBalance = 1000;
    while (bankBalance > 0){
        std::cout << "Saldo atual: " << bankBalance << std::endl;
        std::cout << "Digite sua aposta: " << std::endl;
        std::cin >> wager;
        while(wager > bankBalance || wager <= 0){ // Garante que a aposta seja válida
            std::cout << "Aposta inválida. Digite novamente: ";
            std::cin >> wager;
        }
        Status resultado = craps();
        if(resultado == WIN) bankBalance += wager;
        else bankBalance -= wager;
    }
    if(bankBalance == 0){
        std::cout << "Voce esta arruinado!" << std::endl;
    }
}

Status craps(void){
    int dadoSorteado1, dadoSorteado2;
    dadoSorteado1 = rand() % 6 + 1;
    dadoSorteado2 = rand() % 6 + 1;
    int somaDados = dadoSorteado1 + dadoSorteado2;
    if(somaDados == 7 || somaDados == 11){
        return WIN;
    }
    else if(somaDados == 2 || somaDados == 3 || somaDados == 12){
        return LOSE;
    }
    else{
        int segundoDadoSorteado1, segundoDadoSorteado2;
        segundoDadoSorteado1 = rand() % 6 + 1;
        segundoDadoSorteado2 = rand() % 6 + 1;
        int segundaSomaDados = segundoDadoSorteado1 + segundoDadoSorteado2;
        if(segundaSomaDados == somaDados){
            return WIN;
        }
        else if(segundaSomaDados == 7){
            return LOSE;
        }
    }
}
*/


/*
// Exercício 3.55
#include <iostream>

const double PI = 3.1415;

inline double areaDoCirculo(double raio) {return raio*raio*PI;}

int main(){
    std::cout << "Digite o raio:" << std::endl;
    int r;
    std::cin >> r;
    std::cout << areaDoCirculo(r);
    return 0;
}
*/

/*
// Exercício 3.56 (Passagem de parâmetro por valor e por referência) - Conteúdo diferente!
#include <iostream>

int triplaChamadaPorValor(int);
int triplaChamadaPorReferencia(int &);

int main(){
    int contador = 3, &y = contador;
    std::cout << "Triplicando por valor: " << triplaChamadaPorValor(contador) << std::endl;
    std::cout << contador << std::endl;
    std::cout << "Triplicando por referencia: " << triplaChamadaPorReferencia(y) << std::endl;
    std::cout << y << std::endl;  
    return 0;
}

int triplaChamadaPorValor(int x){
    return 3*x;
}

int triplaChamadaPorReferencia(int &y){
    y *= 3; // Triplica o valor referenciado por y
    return y;
}
*/



/*
// Exercício 3.58 (Função gabarito, já misturado com o 3.59)
#include <iostream>

template <class T> // Definindo gabarito de função.
T min(T num1, T num2, T num3){
    T min = num1;
    if(num2 < min) min = num2;
    if(num3 < min) min = num3;
    return min;
}

int main(){
    int a, b, c;
    char d, e, f;
    std::cout << "Digite tres inteiros:" << std::endl;
    std::cin >> a >> b >> c;
    std::cout << "Menor: " << min(a, b, c) << std::endl;
    std::cout << "Digite os tres char:" << std::endl;
    std::cin >> d >> e >> f;
    std::cout << "Menor: " << min(d, e, f) << std::endl; 
    return 0;
}
*/