/*
    A aplicação desse capítulo depende bastante do Capítuo 5!!!
    Praticamente tudo : ponteiro!
*/

// Exercício 8.6
/*
    A sobrecarga dos operatores de C++ serve para que
    seja possível manipular tipos de dados definidos
    pelo usuário. Pode ser feita explicitamente ou
    implicitamente. 
    Sobrecarga explícita: : o que foi estudado no 
    capítulo. Define-se uma função com "operator"
    dentro ou fora da classe.
    Sobrecarga implícita: normalmente faz referência
    ao uso de construtor de conversão. 

*/

// Exercício 8.7
/*
    Conforme a teoria apresentada, os operatores
    de C++ que não podem ser sobrecarregados são
    .
    .*
    ::
    ?:   (o único operator ternário de C++)
    sizeof

*/

/*
// Exercício 8.8
// Pede para sobrecarregar o operator + para fazer união de strings.
#include <iostream>
#include <cstring> // Para std::strlen e std::strcpy

class String {
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend String operator+(const String &, const String &);

public:
    String(const char* = "");
    String(const String &);
    ~String();
    String &operator=(const String &);

private:
    int length;
    char *sPtr;
};

// Construtor
String::String(const char *str) {
    length = std::strlen(str);
    sPtr = new char[length + 1];
    std::strcpy(sPtr, str);
}

// Construtor de cópia
String::String(const String &copy) : length(copy.length) {
    sPtr = new char[length + 1];
    std::strcpy(sPtr, copy.sPtr);
}

// Destrutor
String::~String() {
    delete[] sPtr;
}

// operator de atribuição
String &String::operator=(const String &right) {
    if (&right != this) { // evitar auto-atribuição
        delete[] sPtr;
        length = right.length;
        sPtr = new char[length + 1];
        std::strcpy(sPtr, right.sPtr);
    }
    return *this;
}

// operator de soma
String operator+(const String &left, const String &right) {
    String temp;
    temp.length = left.length + right.length;
    temp.sPtr = new char[temp.length + 1];
    std::strcpy(temp.sPtr, left.sPtr);
    std::strcat(temp.sPtr, right.sPtr);
    return temp;
}

// operator de inserção (<<)
std::ostream &operator<<(std::ostream &output, const String &str) {
    output << str.sPtr;
    return output;
}

// Função principal
int main() {
    String s1("feliz"), s2(" aniversario"), s3;
    s3 = s1 + s2; // Preciso sobrecarregar + e =
    std::cout << s3; // Preciso sobrecarregar <<
}
*/


// Exercício 8.9
/*
    operatores que podem ser sobrecarregados. Seja, por exemplo, uma classe Array (de inteiros):
    + (Ex.: Somar item a item); - (Ex.: Subtrair item a item); * (Ex.: Multiplicar item a item); / (Ex.: Dividir item a item)
    % (Ex.: Resto item a item); ^ (Ex.: : usado para operação de bits, mas poderia ser usado para exponenciação termo a termo)
    & (Ex.: Retornar o endereço do elemento do meio do Array); | (Ex.: Tamb:m usado para operação de bits (OR). Poderia ser sobrecarregado
    para verificar se um elemento pode ser escrito como soma de potências de dois (?)).
    Outros operatores sobrecarregáveis:
    ~ ! = > < += -= *= /= %= ^= &= |= << >> >>= <<= == != <= >= && || ++ -- ->* , -> [] () new delete new[] delete[]
    Questão muito grande.

*/

// Exercício 8.10
/*
    Mesma ideia do anterior.
*/

// Exercício 8.11
/*
    Essa edição parece ter sido lançada no início dos anos 00 (basta ver as referências. A maioria : da d:cada de 80 e 90)
    Desde então, novos operatores foram adicionados.
    Um possível operator novo seria algo que fizesse a potenciação normalmente. Exemplo: ** (Potência) do Python.

*/

/*
// Exercício 8.12
// Sobrecarregar o operator () para permitir entrada do tipo array(a,b) no lugar de array[a][b]
#include <iostream>

class tabuleiroDeXadrez{
public:
    tabuleiroDeXadrez();
    int operator()(const int, const int);
private:
    int array[8][8];
};

tabuleiroDeXadrez::tabuleiroDeXadrez(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i+j % 2 == 1){
                array[i][j] = 1; // Se a soma : ímpar, a casa : PRETA!
            }else{
                array[i][j] = 0; // Se a soma : par, a casa : BRANCA!
            }
        }
    }
}


int tabuleiroDeXadrez::operator()(const int a, const int b){
    if(array[a][b] == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    tabuleiroDeXadrez t1;
    if(t1(1, 1) == 0){
        std::cout << "Eh quadrado branco!!";
    }else{
        std::cout << "Eh quadrado preto!!";
    }
}
*/

/*
// Exercício 8.13
// : para sobrecarregar: == != = << >> ()
#include <iostream>

class ArrayBidimensional {
    friend std::ostream& operator<<(std::ostream&, const ArrayBidimensional&);
    friend std::istream& operator>>(std::istream&, ArrayBidimensional&);
public:
    ArrayBidimensional(int, int); // Construtor.
    ~ArrayBidimensional(); // Destruidor
    int& operator()(int, int); // Sobrecarregando () como ele pediu, retornando int&
    const int& operator()(int, int) const; // Sobrecarregando () retornando const int &
    bool operator==(const ArrayBidimensional&) const;
    bool operator!=(const ArrayBidimensional&) const;
    ArrayBidimensional& operator=(const ArrayBidimensional&);
private:
    int** data; // Para conseguir fazer uma alocação dinâmica de um array bidimensional.
    int linhas;
    int colunas;
};

ArrayBidimensional::ArrayBidimensional(int a, int b): linhas(a), colunas(b) {
    // Alocar espaço para o array bidimensional
    data = new int*[linhas];
    for (int i = 0; i < linhas; ++i) {
        data[i] = new int[colunas];
    }
    // Inicializar todos os elementos como 0
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            data[i][j] = 0;
        }
    }
}

ArrayBidimensional::~ArrayBidimensional() {
    // Liberar memória alocada
    for (int i = 0; i < linhas; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

int& ArrayBidimensional::operator()(int i, int j) {
    return data[i][j];
}

const int& ArrayBidimensional::operator()(int i, int j) const {
    return data[i][j];
}

bool ArrayBidimensional::operator==(const ArrayBidimensional &other) const {
    if (linhas != other.linhas || colunas != other.colunas) {
        return false;
    }
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool ArrayBidimensional::operator!=(const ArrayBidimensional &other) const {
    return !(*this == other);
}

ArrayBidimensional& ArrayBidimensional::operator=(const ArrayBidimensional &other) {
    if (this != &other) {
        // Liberar memória alocada
        for (int i = 0; i < linhas; ++i) {
            delete[] data[i];
        }
        delete[] data;
        // Realocar e copiar dados
        linhas = other.linhas;
        colunas = other.colunas;
        data = new int*[linhas];
        for (int i = 0; i < linhas; ++i) {
            data[i] = new int[colunas];
            for (int j = 0; j < colunas; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ArrayBidimensional& arr) {
    for (int i = 0; i < arr.linhas; ++i) {
        for (int j = 0; j < arr.colunas; ++j) {
            os << arr(i, j) << ' ';
        }
        os << '\n';
    }
    return os;
}

std::istream& operator>>(std::istream& is, ArrayBidimensional& arr) {
    for (int i = 0; i < arr.linhas; ++i) {
        for (int j = 0; j < arr.colunas; ++j) {
            is >> arr(i, j);
        }
    }
    return is;
}

int main() {
    // Exemplo de uso
    ArrayBidimensional arr(3, 3); // Cria um array 3x3
    std::cin >> arr; // Preenche o array com dados do usuário
    std::cout << arr; // Exibe o array
    return 0;
}
*/

/*
// Exercício 8.14
#include <iostream>
#include <cstdlib>

class Array{
public:
    Array();
    void printArray();
    int operator[](const int);
private:
    int array[10];
};

int main(){
    Array a1;
    a1.printArray();
    std::cout << "O terceiro maior elemento eh " << a1[3]; // Aqui está o resultado da sobrecarga!
}

Array::Array(){
    for(int contador = 0; contador < 10; contador++){
        array[contador] = rand() % 50 + 1;
    }

}

void Array::printArray(){
    for(int contador = 0; contador < 10 ; contador++ ){
        std::cout << array[contador] << " ";
    }
}

int Array::operator[](const int a){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9-i; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return array[10-a];
}
*/

/*
// Exercício 8.15
// Primeiro, copiando o código:
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

class Complex {
public:
    Complex(double = 0.0, double = 0.0);
    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    Complex operator*(const Complex &) const;
    const Complex &operator=(const Complex &);
    bool operator==(const Complex &) const;
    bool operator!=(const Complex &) const;

    friend std::ostream& operator<<(std::ostream&, const Complex&);
    friend std::istream& operator>>(std::istream&, Complex&);

private:
    double real;
    double imaginary;
};

Complex::Complex(double r, double i) : real(r), imaginary(i) {}

Complex Complex::operator+(const Complex &operand2) const {
    return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

Complex Complex::operator-(const Complex &operand2) const {
    return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

Complex Complex::operator*(const Complex &operand2) const {
    return Complex(real * operand2.real - imaginary * operand2.imaginary,
                   real * operand2.imaginary + imaginary * operand2.real);
}

const Complex& Complex::operator=(const Complex &right) {
    if (this != &right) {
        real = right.real;
        imaginary = right.imaginary;
    }
    return *this;
}

bool Complex::operator==(const Complex &other) const {
    double epsilon = 0.0000000000001;
    return (std::fabs(real - other.real) < epsilon) && (std::fabs(imaginary - other.imaginary) < epsilon);
}

bool Complex::operator!=(const Complex &other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Complex& arr) {
    os << arr.real << " + i" << arr.imaginary;
    return os;
}

std::istream& operator>>(std::istream& is, Complex& arr) {
    is >> arr.real >> arr.imaginary;
    return is;
}

int main() {
    Complex x, y(4, 8), z(3.3, 1.1);
    cout << "x: ";
    cin >> x;
    cout << "\ny: " << y;
    cout << "\nz: " << z;

    
    cout << "\n\nVerificando igualdade e desigualdade:\n";
    cout << "x == y: " << (x == y) << endl;
    cout << "x != y: " << (x != z) << endl;

    x = y + z;
    cout << "\n\nx = y + z : \n";
    cout << x << " = " << y << " + " << z;

    x = y - z;
    cout << "\n\nx = y - z : \n";
    cout << x << " = " << y << " - " << z;
    cout << endl;

    x = y * z;
    cout << "\n\nx = y * z : \n";
    cout << x << " = (" << y << ") * (" << z << ")";
    cout << endl;

    return 0;
}
*/

/*
// Exercício 8.16
// Primeiro, copiando o código
/*
    Resposta da Letra B: uma restrição da classe : ela realizar apenas operação de adição.
    Isso será resolvido nas letras C, D e E.

#include <iostream>
#include <cstring>

using std::ostream;
using std::endl;
using std::cout;

class HugeInt{
    friend ostream &operator<<(ostream &, const HugeInt &);
public:
    HugeInt(long = 0); // Aceita uma entrada da forma long int (exemplo: HugeInt a(890123))
    HugeInt(const char *); // Aceita uma entrada passada na forma de string (exemplo: HugeInt b("98048921398141"))
    // Salva como integer[30].
    // Sobrecarrega os operatores para poder operar.
    HugeInt operator+(const HugeInt &) ;
    HugeInt operator+(int) ;
    HugeInt operator+(const char *) ;

    HugeInt operator-(const HugeInt &) ;
    HugeInt operator-(int) ;
    HugeInt operator-(const char *) ;

    HugeInt operator*(const HugeInt &) ;
    HugeInt operator*(int) ;
    HugeInt operator*(const char *) ;

    bool operator>(const HugeInt &) ;
    bool operator>(int) ;
    bool operator>(const char *) ;

    bool operator<(const HugeInt &) ;
    bool operator<(int) ;
    bool operator<(const char *) ;

    bool operator>=(const HugeInt &) ;
    bool operator>=(int) ;
    bool operator>=(const char *) ;

    bool operator==(const HugeInt &) ;
    bool operator==(int) ;
    bool operator==(const char *) ;

    bool operator!=(const HugeInt &) ;
    bool operator!=(int) ;
    bool operator!=(const char *) ;

    // Isso aqui é mais complicado.
    // Não consegui fazer nesse momento.
    HugeInt operator/(const HugeInt &) ;
    HugeInt operator/(int) ;
    HugeInt operator/(const char *) ;

private:
    short integer[30];
};

// Funções definidas pelo ENUNCIADO
HugeInt::HugeInt(long val){ // Inicializa integer[30] como 0 e depois vai posicionando digito a digito de val como um array[30]
    int i;
    for(i = 0; i <= 29; i++){
        integer[i] = 0;
    }
    for(i = 29; val != 0 && i >= 0; i--){
        integer[i] = val % 10;
        val /= 10;
    }
}

HugeInt::HugeInt(const char *string){
    int i, j;
    for(i = 0; i <= 29; i++){
        integer[i] = 0; // Inicializa integer como 0 igual o codigo acima
    }
    for(i = 30-strlen(string), j = 0; i <= 29; i++, j++){
        if(isdigit(string[j])) integer[i] = string[j] - '0'; // ao fazer - '0' ele transforma o caractere numerico em int
        // Dessa forma, independente da entrada, esta salvo como short int integer[30]
    }
}

HugeInt HugeInt::operator+(const HugeInt &op2){  // : a definição base do operator +
    // Recebe um objeto da classe HugeInt e efetua a soma na forma de array[30]
    HugeInt temp;
    int carry = 0;
    for(int i = 29; i >= 0; i--){ 
        temp.integer[i] = integer[i] + op2.integer[i] + carry;
        if(temp.integer[i] > 9){
            temp.integer[i] %= 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
    }
    return temp; // Retorna outro objeto da classe HugeInt
}

HugeInt HugeInt::operator+(int op2){ 
    return *this + HugeInt(op2); //  Reutiliza o + anterior, só que agora para uma entrada do tipo inteira, e não string de caractere
}

HugeInt HugeInt::operator+(const char *op2){
    return *this + HugeInt(op2); // Converte uma string de caracteres denominada op2 para HugeInt e reutiliza o + anterior
}

HugeInt HugeInt::operator-(const HugeInt &op2) {
    HugeInt result;
    int borrow = 0;
    for (int i = 29; i >= 0; i--) {
        int diff = integer[i] - op2.integer[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.integer[i] = diff;
    }
    return result;
}

HugeInt HugeInt::operator-(int op2) {
    return *this - HugeInt(op2);
}

HugeInt HugeInt::operator-(const char *op2) {
    return *this - HugeInt(op2);
}

bool HugeInt::operator>=(const HugeInt &op2) {
    return (*this > op2) || (*this == op2);
}

bool HugeInt::operator>=(int op2) {
    HugeInt temp(op2);
    return *this >= temp;
}

bool HugeInt::operator>=(const char *op2) {
    HugeInt temp(op2);
    return *this >= temp;
}


ostream& operator<<(ostream &output, const HugeInt &num){ // Sobrecarga de << serve para imprimir o array integer de um objeto chamado num
    int i;
    for(i = 0; (num.integer[i] == 0) && (i <= 29); i++);
    if(i == 30){
        output << 0;
    }
    else{
        for(; i <= 29; i++){
            output << num.integer[i];
        }
    }
    return output; // retorna para o cout
}

// Definindo operatores de multiplicação

HugeInt HugeInt::operator*(const HugeInt &op2) {
    HugeInt temp; // Inicializa a variável para armazenar o resultado
    for(int i = 29; i >= 0; i--) { // Itera sobre cada dígito do primeiro número
        int carry = 0; // Inicializa o carry para a multiplicação deste dígito
        for(int j = 29; j >= 0; j--) { // Itera sobre cada dígito do segundo número
            int k = i + j - 29; // Calcula a posição correta no array de resultado
            if (k >= 0) { // Verifica se a posição está dentro dos limites do array
                temp.integer[k] += integer[i] * op2.integer[j] + carry;
                carry = temp.integer[k] / 10; // Calcula o novo carry
                temp.integer[k] %= 10; // Ajusta o valor para um único dígito
            }
        }
        if (i - 30 >= 0) { // Adiciona qualquer carry restante fora do array de resultado
            temp.integer[i - 30] += carry;
        }
    }
    return temp;
}
HugeInt HugeInt::operator*(int op2){
    return *this * HugeInt(op2);
}
HugeInt HugeInt::operator*(const char *op2){
    return *this * HugeInt(op2);
}

bool HugeInt::operator>(const HugeInt &op2) {
    for (int i = 0; i < 30; ++i) {
        if (integer[i] > op2.integer[i])
            return true;
        else if (integer[i] < op2.integer[i])
            return false;
    }
    return false; // Se forem iguais
}

bool HugeInt::operator>(int op2) {
    HugeInt temp(op2);
    return *this > temp;
}

bool HugeInt::operator>(const char *op2) {
    HugeInt temp(op2);
    return *this > temp;
}

bool HugeInt::operator<(const HugeInt &op2) {
    return !(*this > op2) && !(*this == op2);
}

bool HugeInt::operator<(int op2) {
    HugeInt temp(op2);
    return *this < temp;
}

bool HugeInt::operator<(const char *op2) {
    HugeInt temp(op2);
    return *this < temp;
}

bool HugeInt::operator==(const HugeInt &op2) {
    for (int i = 0; i < 30; ++i) {
        if (integer[i] != op2.integer[i])
            return false;
    }
    return true; // Se todos os dígitos forem iguais
}

bool HugeInt::operator==(int op2) {
    HugeInt temp(op2);
    return *this == temp;
}

bool HugeInt::operator==(const char *op2) {
    HugeInt temp(op2);
    return *this == temp;
}

bool HugeInt::operator!=(const HugeInt &op2) {
    return !(*this == op2);
}

bool HugeInt::operator!=(int op2) {
    HugeInt temp(op2);
    return *this != temp;
}

bool HugeInt::operator!=(const char *op2) {
    HugeInt temp(op2);
    return *this != temp;
}

HugeInt HugeInt::operator/(const HugeInt &op2) { // funcional, mas ruim.
    HugeInt quotient; // Inicializa o quociente como zero
    HugeInt remainder(*this); // Inicializa o resto como o dividendo

    // Enquanto o resto for maior ou igual ao divisor
    while (remainder >= op2) {
        HugeInt subtractor(op2); // Cria um objeto subtractor como o divisor
        HugeInt temp(1); // Cria um objeto temp para contar o número de vezes que o divisor é subtraído do resto

        // Enquanto o subtractor for menor ou igual ao resto, subtraia o subtractor do resto
        while (remainder >= subtractor) {
            remainder = remainder - subtractor; // Subtrai o subtractor do resto
            quotient = quotient + temp; // Incrementa o quociente
            subtractor = subtractor + op2; // Adiciona o divisor ao subtractor para próxima subtração
            temp = temp + 1; // Incrementa o contador de subtrações
        }
    }

    return quotient; // Retorna o quociente
}

HugeInt HugeInt::operator/(int op2) {
    return *this / HugeInt(op2);
}

HugeInt HugeInt::operator/(const char *op2) {
    return *this / HugeInt(op2);
}


int main() {
    // Testando a criação de objetos HugeInt
    HugeInt n1(7654321), n2(7891234), n3("999999999999999999999"), n4("1"), n5;
    
    cout << "n1: " << n1 << "\nn2 : " << n2 << "\nn3 : " << n3 << "\nn4 : " << n4 << "\nn5 : " << n5 << endl;

    // Testando os operatores de comparação
    cout << "Comparacao:" << endl;
    cout << "n1 > n2: " << (n1 > n2) << endl;
    cout << "n1 >= n2: " << (n1 >= n2) << endl;
    cout << "n1 > n3: " << (n1 > n3) << endl;
    cout << "n3 < n4: " << (n3 < n4) << endl;
    cout << "n3 == n4: " << (n3 == n4) << endl;
    cout << "n1 != n2: " << (n1 != n2) << endl;
    cout << "n2 != 7891234: " << (n2 != 7891234) << endl;
    cout << "n2 != \"7891234\": " << (n2 != "7891234") << endl;

    // Testando os operatores de adição
    n5 = n1 + n2;
    cout << n1 << " + " << n2 << " = " << n5 << endl;
    cout << n3 << " + " << n4 << " = " << n3 + n4 << endl;
    n5 = n1 + 9;
    cout << n1 << " + " << 9 << " = " << n5 << endl;
    n5 = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << n5 << endl;

    // Testando os operatores de subtração
    n5 = n1 - n2;
    cout << n1 << " - " << n2 << " = " << n5 << endl;
    cout << n3 << " - " << n4 << " = " << n3 - n4 << endl;
    n5 = n1 - 9;
    cout << n1 << " - " << 9 << " = " << n5 << endl;
    n5 = n2 - "10000";
    cout << n2 << " - " << "10000" << " = " << n5 << endl;

    // Testando os operatores de multiplicação
    HugeInt n6(10), n7("100");
    cout << n6 << " * " << n7 << " = " << n6 * n7 << endl;

    // Testando o operator de divisão
    HugeInt n8("1000"), n9("10");
    cout << n8 << " / " << n9 << " = " << n8 / n9 << endl;

    return 0;
}
*/

/*
// Exercício 8.17 (implementar uma classe NumeroRacional)
// Funcionalidades: construtor, sobrecarga de + - * /, sobrecarga > < ==
#include <iostream>

using std::cout;
using std::endl;

class NumeroRacional {
    friend std::ostream &operator<<(std::ostream &, const NumeroRacional &);
public:
    NumeroRacional(int = 0, int = 1);
    NumeroRacional operator+(const NumeroRacional &) const;
    NumeroRacional operator-(const NumeroRacional &) const;
    NumeroRacional operator*(const NumeroRacional &) const;
    NumeroRacional operator/(const NumeroRacional &) const;

    bool operator>(const NumeroRacional &) const;
    bool operator<(const NumeroRacional &) const;
    bool operator==(const NumeroRacional &) const;
private:
    int array[2];
};

NumeroRacional::NumeroRacional(int a, int b) {
    array[0] = a;
    if (b != 0) {
        array[1] = b;
    } else {
        cout << "Tentou divisão por zero! Padronizando 1." << endl;
        array[1] = 1;
    }
}

NumeroRacional NumeroRacional::operator+(const NumeroRacional &op2) const {
    NumeroRacional result;
    result.array[0] = array[0] * op2.array[1] + array[1] * op2.array[0];
    result.array[1] = array[1] * op2.array[1];
    return result;
}

NumeroRacional NumeroRacional::operator-(const NumeroRacional &op2) const {
    NumeroRacional result;
    result.array[0] = array[0] * op2.array[1] - array[1] * op2.array[0];
    result.array[1] = array[1] * op2.array[1];
    return result;
}

NumeroRacional NumeroRacional::operator*(const NumeroRacional &op2) const {
    NumeroRacional result;
    result.array[0] = array[0] * op2.array[0];
    result.array[1] = array[1] * op2.array[1];
    return result;
}

NumeroRacional NumeroRacional::operator/(const NumeroRacional &op2) const {
    NumeroRacional result;
    result.array[0] = array[0] * op2.array[1];
    result.array[1] = array[1] * op2.array[0];
    return result;
}

bool NumeroRacional::operator>(const NumeroRacional &op2) const {
    NumeroRacional result = *this - op2;
    return result.array[0] > 0;
}

bool NumeroRacional::operator<(const NumeroRacional &op2) const {
    NumeroRacional result = *this - op2;
    return result.array[0] < 0;
}

bool NumeroRacional::operator==(const NumeroRacional &op2) const {
    NumeroRacional result = *this - op2;
    return result.array[0] == 0;
}

std::ostream& operator<<(std::ostream &output, const NumeroRacional &num) {
    output << num.array[0] << "/" << num.array[1];
    return output;
}

int main() {
    NumeroRacional t1(1, 2), t2(3, 4);
    cout << t1 + t2 << endl;
    cout << t1 - t2 << endl;
    cout << t1 * t2 << endl;
    cout << t2 / t1 << endl;
    cout << (t1 > t2) << endl;
    cout << (t1 < t2) << endl;
    cout << (t1 == t2) << endl;
}
*/

/*
// Exercício 8.18
/*
    Vou usar a biblioteca <string> para fazer algumas manipulações de texto. 
    Não vou adicionar em Classe String.

#include <iostream>
#include <string>

int main(){
    std::string str1 = "Hello, World!";
    std::string str2("Hello, World!");
    std::string str3(10, 'A'); // "AAAAAAAAAA"
    std::cout << str1 << "\n" << str2 << "\n" << str3 << std::endl;

    std::string str4 = "Hello";
    std::string str5 = "World";
    std::string str6 = str4 + ", " + str5 + "!"; // Concatenação de string usando um operator + sobrecarregado
    std::cout << str4 << "\n" << str5 << "\n" << str6 << std::endl;

    std::string str7 = "Hello";
    char ch = str7[1]; // 'e'. Note sobrecarga de operator.
    str7[1] = 'a'; // "Hallo"
    std::cout << str7

    std::string str = "Hello";
    size_t len = str.size(); // 5. Note definição de private da classe.
    size_t capacity = str.capacity(); // Note definição de private da classe.

    // Outras possibilidades:
    // erase -> apaga um pedaço da string
    // find -> acha algo na string
    // insert -> adiciona algo na string
    // substr -> pega uma substring
}
*/

/*
// Exercício 8.19
#include <iostream>
#include <algorithm> // Para std::max

class Polinomio {
public:
    Polinomio(size_t size); // Para precisar de destruidor
    ~Polinomio();
    void setCoef(size_t index, int value);
    void print() const;

    Polinomio operator+(const Polinomio &op2) const;
    Polinomio operator-(const Polinomio &op2) const;
    Polinomio& operator=(const Polinomio &op2);
    Polinomio operator*(const Polinomio &op2) const;
    Polinomio& operator+=(const Polinomio &op2);
    Polinomio& operator-=(const Polinomio &op2);
    Polinomio& operator*=(const Polinomio &op2);

private:
    int* coef;
    size_t size;
};

Polinomio::Polinomio(size_t size) : size(size) {
    coef = new int[size];
    for (size_t i = 0; i < size; ++i) {
        coef[i] = 0;
    }
}

Polinomio::~Polinomio() {
    delete[] coef;
}

void Polinomio::setCoef(size_t index, int value) {
    if (index < size) {
        coef[index] = value;
    }
}

void Polinomio::print() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << coef[i] << " ";
    }
    std::cout << std::endl;
}

Polinomio Polinomio::operator+(const Polinomio &op2) const {
    size_t newSize = std::max(size, op2.size);
    Polinomio result(newSize);

    for (size_t i = 0; i < newSize; ++i) {
        if (i < size) {
            result.coef[i] += coef[i];
        }
        if (i < op2.size) {
            result.coef[i] += op2.coef[i];
        }
    }
    return result;
}

Polinomio Polinomio::operator-(const Polinomio &op2) const {
    size_t newSize = std::max(size, op2.size);
    Polinomio result(newSize);

    for (size_t i = 0; i < newSize; ++i) {
        if (i < size) {
            result.coef[i] += coef[i];
        }
        if (i < op2.size) {
            result.coef[i] -= op2.coef[i];
        }
    }
    return result;
}

Polinomio& Polinomio::operator+=(const Polinomio &op2) {
    size_t newSize = std::max(size, op2.size);

    // Realiza a adição dos coeficientes
    for (size_t i = 0; i < newSize; ++i) {
        if (i < size) {
            coef[i] += op2.coef[i];
        } else {
            // Se o tamanho de op2 for maior que o tamanho de this,
            // precisamos expandir o array de coeficientes de this
            int* temp = new int[i + 1];
            std::copy(coef, coef + size, temp);
            delete[] coef;
            coef = temp;
            size = i + 1;
            coef[i] = op2.coef[i];
        }
    }
    return *this;
}

Polinomio& Polinomio::operator-=(const Polinomio &op2) {
    size_t newSize = std::max(size, op2.size);

    // Realiza a adição dos coeficientes
    for (size_t i = 0; i < newSize; ++i) {
        if (i < size) {
            coef[i] -= op2.coef[i];
        } else {
            // Se o tamanho de op2 for maior que o tamanho de this,
            // precisamos expandir o array de coeficientes de this
            int* temp = new int[i + 1];
            std::copy(coef, coef + size, temp);
            delete[] coef;
            coef = temp;
            size = i + 1;
            coef[i] -= op2.coef[i];
        }
    }
    return *this;
}

Polinomio& Polinomio::operator=(const Polinomio &op2) {
    if (this != &op2) {  // Verifica se não estamos atribuindo a si mesmo
        delete[] coef;  // Libera a memória do array de coeficientes atual
        size = op2.size;  // Copia o tamanho do array
        coef = new int[size];  // Aloca memória para o novo array de coeficientes
        std::copy(op2.coef, op2.coef + size, coef);  // Copia os coeficientes
    }
    return *this;
}

Polinomio Polinomio::operator*(const Polinomio &op2) const {
    size_t newSize = size + op2.size - 1; // Tamanho do polinômio resultante
    Polinomio result(newSize); // Polinômio resultante

    // Inicializa todos os coeficientes do polinômio resultante com zero
    for (size_t i = 0; i < newSize; ++i) {
        result.coef[i] = 0;
    }

    // Realiza a multiplicação dos polinômios
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < op2.size; ++j) {
            result.coef[i + j] += coef[i] * op2.coef[j];
        }
    }

    return result;
}

Polinomio& Polinomio::operator*=(const Polinomio &op2) {
    *this = *this * op2; // Multiplica o polinômio atual pelo polinômio op2 e atribui o resultado de volta ao polinômio atual
    return *this; // Retorna uma referência para permitir encadeamento de operadores
}



int main() {
    Polinomio p1(4), p2(3);

    p1.print();
    p2.print();

    // Definindo o polinomio 1
    p1.setCoef(0, 1); // Vou considerar que isso é o termo independente, e vale 1
    p1.setCoef(1, 2); // Esse é o termo de grau 1, e vale 2. Sucessivamente.
    p1.setCoef(2, 3);
    p1.setCoef(3, 4);

    // Definindo o polinomio 2
    p2.setCoef(0, 2);
    p2.setCoef(1, 3);
    p2.setCoef(2, 4);

    p1.print();
    p2.print();

    Polinomio p3 = p1+p2, p4=p1-p2, p5(4);
    p3.print();
    p4.print();
    p5 += p1;
    p5.print();
    p4 -= p1;
    p4.print();
    Polinomio p6 = p1*p2;
    p6.print();
    p1 *= p2;
    p1.print();

    return 0;
}
*/

/*
// Exercício 8.20
// Exemplo:
#include <iostream>
#include <string>

class PhoneNumber {
public:
    PhoneNumber(std::string number) : number(number) {}

    // Sobrecarga do operador de inserção como função membro da classe PhoneNumber
    PhoneNumber& operator<<(std::ostream& os) {
        os << number;
        return *this;
    }

private:
    std::string number;
};

int main() {
    PhoneNumber somePhoneNumber("123-456-7890");
    
    // Usando a sintaxe somePhoneNumber << std::cout
    somePhoneNumber << std::cout;

    return 0;
}
*/

