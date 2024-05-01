/*
// Programa de Adição
#include <iostream>
int main(){
    int integer1, integer2, sum;
    std::cout << "Digite o primeiro inteiro: ";
    std::cin >> integer1;
    std::cout << "Digite o segundo inteiro: ";
    std::cin >> integer2;
    sum = integer1 + integer2;
    std::cout << "A soma eh " << sum << std::endl;
    return 0;
}
*/

/*
// Exercício 1.5
#include <iostream>
int main(){
    int c, thisIsAVariable, q76354, number, age;
    std::cout << "Digite o numero inteiro: ";
    std::cin >> age;
    std::cout << "Esse é um programa em C++";
    std::cout << "Esse é um programa em C++\n";
    std::cout << "Esse\né\num\nprograma\nem\nC++\n";
    std::cout << "Esse\teh\tum\tprograma\tem\tC++";
}
*/

/*
// Exercício 1.6
#include <iostream>
int main(){
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "\n\nPrograma que calcule produto de 3 inteiros\n";
    int x, y, z, result;
    cout << "Digite o primeiro numero: ";
    cin >> x;
    cout << "Digite o segundo numero: ";
    cin >> y;
    cout << "Digite o terceiro numero: ";
    cin >> z;
    result = x * y * z;
    cout << "O produto eh " << result << endl;
    return 0;
}
*/

/*
// Exercício 1.16
#include <iostream>
int main(){
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "Digite o primeiro numero: \n";
    int a, b, c;
    cin >> b;
    cout << "Digite o segundo numero: \n";
    cin >> c;
    a = b * c;
    // Afirmar: Texto calcula folha de pagamento
    cout << "Digite o primeiro numero: \n";
    cin >> a;
    cout << "Digite o segundo numero: \n";
    cin >> b;
    cout << "Digite o terceiro numero: \n";
    cin >> c;
}
*/

/*
// Exercício 1.26
#include <iostream>
int main(){
    using std::cin;
    using std::cout;
    using std::endl;
    int a, b, c;
    cout << "Digite tres numeros: ";
    cin >> a >> b >> c;
    cout << "Soma: " << a + b + c << endl;
    cout << "Media: " << (a+b+c)/3 << endl;
    cout << "Produto: " << a*b*c << endl;
    if(a > b && b > c){
        cout << "Maior: " << a << "\nMenor: " << c;
    }
    if(a > c && c > b){
        cout << "Maior: " << a << "\nMenor: " << b;
    }
    if(b > a && a > c){
        cout << "Maior: " << b << "\nMenor: " << c;
    }
    if(b > c && c > a){
        cout << "Maior: " << b << "\nMenor: " << a;
    }
    if(c > a && a > b){
        cout << "Maior: " << c << "\nMenor: " << b;
    }
    if(c > b && b > a){
        cout << "Maior: " << c << "\nMenor: " << a;
    }
}
*/

/*
// Exercício 1.27
#include <iostream>
int main(){
    int r, par;
    using std::endl;
    std::cout << "Digite o raio: ";
    std::cin >> r;
    std::cout << "Diametro: " << 2*r << endl;
    std::cout << "Circunferencia: " << 3.14159 * r * 2 << endl;
    std::cout << "Area: " << r * r * 3.14159 << endl;
    std::cout << "*********" << endl;
    std::cout << "*\t*" << endl;
    std::cout << "*\t*" << endl;
    std::cout << "*\t*" << endl;
    std::cout << "*********";
    std::cout << "Digite um numero para verificar se eh par ou impar: " << endl;
    std::cin >> par;
    if(par % 2 == 0) std::cout << "Par";
    else std::cout << "Impar";
}
*/

/*
// Exercício 1.35
#include <iostream>
int main(){
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "A: " << static_cast<int>('A') << endl;
    cout << "B: " << static_cast<int>('B') << endl;
    cout << "C: " << static_cast<int>('C') << endl;
    cout << "a: " << static_cast<int>('a') << endl;
    cout << "b: " << static_cast<int>('b') << endl;
    cout << "c: " << static_cast<int>('c') << endl;
    cout << "0: " << static_cast<int>('0') << endl;
    cout << "1: " << static_cast<int>('1') << endl;
    cout << "2: " << static_cast<int>('2') << endl;
    cout << "$: " << static_cast<int>('$') << endl;
    cout << "*: " << static_cast<int>('*') << endl;
    cout << "+: " << static_cast<int>('+') << endl;
    cout << "/: " << static_cast<int>('/') << endl;
    cout << "Espaco: " << static_cast<int>(' ') << endl;
}
*/

/*
// Exercício 1.36
#include <iostream>
int main(){
    int numero;
    using std::cin; using std::cout; using std::endl;
    cout << "Digite um numero de cinco digitos: ";
    cin >> numero;
    int a, b, c, d, e, novo_numero;
    a = numero % 10;
    novo_numero = (numero - a)/10;
    b = novo_numero % 10;
    novo_numero = (novo_numero - b)/10;
    c = novo_numero % 10;
    novo_numero = (novo_numero - c)/10;
    d = novo_numero % 10;
    novo_numero = (novo_numero - d)/10;
    e = novo_numero % 10;
    cout << e <<  "\t" << d << "\t" << c << "\t" << b << "\t" << a;
}
*/

/*
// Exercício 1.37
#include <iostream>
int main(){
    using std::cout; using std::cin;; using std::endl;
    cout << "Numero\tQuadrado\tCubo" << endl;
    cout << "0\t0\t\t0" << endl;
    cout << "1\t1\t\t1" << endl;
    cout << "2\t4\t\t8" << endl;
    cout << "3\t9\t\t27" << endl;
}
*/