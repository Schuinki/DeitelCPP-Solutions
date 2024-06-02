// Exercício 9.2
/*
    A bicicleta pode herdar da classe Rodas, por exemplo, pois todas as funcionalidades de Rodas estão em bicicleta.
    A classe Rodas pode herdar funções de uma classe Circulo e de uma outra classe Pneus, por exemplo.
    A classe Bicicleta, tendo as funções de Rodas, pode criar uma função como Pedal.
*/

// Exercício 9.3
/*
    Herança é uma forma de reutilização de software na qual novas classes são criadas a partir de classes existentes.
    Herança múltipla é quando várias classes são utilizadas para criar uma nova classe. Exemplo: classe ProfessorPesquisador herda funcionalidades
    da classe Professor e da classe Pesquisador.
    Classe base é a classe que possui as funções que serão herdadas.
    Classe derivada é a classe que recebe as funcionalidades por herança.
    No exemplo anterior, a classe ProfessorPesquisador é classe derivada, enquanto as outras duas são classes base.
*/

// Exercício 9.4
/*
    Seja a classe Cachorro herdada de classe Animal.
    Um ponteiro Animal* ao ser convertido para um ponteiro Cachorro*, caso eu não tenha certeza que esse meu objeto Animal é realmente um Cachorro,
    pode buscar na memória as funcionalidades esperadas de Cachorro e não encontrar.
*/

// Exercício 9.5
/*
    A herança simples possui apenas uma classe base, enquanto a múltipla possui duas ou mais.
*/

// Exercício 9.6
/*
    Verdadeiro.
    Mesmo que Cachorro tenha funcionalidades que não estão em Animal, todo Cachorro continua estando em Animal.
    Logo, a classe Cachorro realmente é menor do que Animal.
    Realmente se chama subclasse, apesar de não ser comum em C++, segundo o livro.
*/

// Exercício 9.7
/*
    Conforme mencionado anteriormente, isso é verdade. Eu posso tratar um Cachoro como um Animal, desde que não cobre desse Animal as
    funcionalidades que defini apenas para Cachorro.
*/

// Exercício 9.8
/*
    Dados mantidos como private não podem ser herdados, dificultando a reutilização de código.
    Ele rompe o encapsulamento pois uma alteração nesse protected pode gerar alterações em todos as classes herdadas que utilizam de protected.
*/

// Exercício 9.9
/*
    Tornando uma questão puramente teórica, visto que na Questão 9.10 teremos a prática,
    Herança é um conceito em que uma classe pode herdar atributos e métodos de outra classe.
    Composição é um conceito em que uma classe é composta de objetos de outras classes como membros.
    Em vez de herdar comportamentos e atributos, a classe (em composição) usa objetos de outras classes para fornecer funcionalidade.
    A composição permite modelar sistemas "tem um". Exemplo: classe Carro com um objeto Motor.
*/

// Exercício 9.10
// Por herança
/*
#include <iostream>
#include <iomanip> // Adicionado para uso de setiosflags e setprecision

using std::ios;
using std::setiosflags;
using std::setprecision;
using std::ostream; // Adicionado para uso de ostream


class Point{
    friend std::ostream &operator<<(std::ostream &, const Point &); // Correção: std::ostream
public:
    Point(int = 0, int = 0);
    void setPoint(int, int);
    int getX() const {return x;}
    int getY() const {return y;}
protected:
    int x, y;
};

Point::Point(int a, int b){ setPoint(a, b); }

void Point::setPoint(int a, int b){
    x = a;
    y = b;
}

std::ostream &operator<<(std::ostream &output, const Point &p){ // Correção: std::ostream
    output << '[' << p.x << ", " << p.y << ']';
    return output;
}

class Square : public Point{
    friend std::ostream &operator<<(std::ostream &, const Square &); // Correção: std::ostream
public:
    Square(double s = 0.0, int x = 0, int y = 0);
    void setSide(double);
    double getSide() const;
    double area() const;
protected:
    double side;
};

Square::Square(double s, int x, int y) : Point(x, y){
    setSide(s);
}

void Square::setSide(double s){
    side = ( s >= 0 ? s : 0);
}

double Square::getSide() const { return side; }

double Square::area() const{
    return side*side;
}

std::ostream &operator<<(std::ostream &output, const Square &s){ // Correção: std::ostream
    output << "Centro = " << static_cast<Point>(s)
           << "; Lado = " << setiosflags(ios::fixed | ios::showpoint) << setprecision(2) << s.side;
    return output;
}

class Cube : public Square{
    friend std::ostream &operator<<(std::ostream &, const Cube &);
public:
    Cube(double s = 0.0); // Correção: falta ponto e vírgula
    void setSide(double);
    double volume() const;
    double area() const;
};

Cube::Cube(double s) : Square(s, 0, 0){ // Correção: inicialização da base
    setSide(s);
}

void Cube::setSide(double s){
    side = ( s >= 0 ? s : 0);
}

double Cube::area() const{ // Correção: método constante
    return 6 * side * side; // Correção: uso de 'side' em vez de 's'
}

double Cube::volume() const{ // Correção: método constante
    return side * side * side; // Correção: uso de 'side' em vez de 's'
}

std::ostream &operator<<(std::ostream &output, const Cube &c){ // Correção: std::ostream
    output << static_cast<Square>(c) << "; Lado = " << c.side;
    return output;
}

int main(){
    Square s(2.5, 37, 43);
    std::cout << "A coordenada X eh " << s.getX();
    std::cout << "\nA coordenada Y eh " << s.getY();
    std::cout << "\nO lado eh " << s.getSide(); // Corrigido o erro de digitação de "laod" para "lado"

    s.setSide(4.25);
    s.setPoint(2, 2);
    std::cout << "\n\nA nova posicao e o lado sao: " << s << "\nArea " << s.area() << "\n";

    Point &pRef = s;
    std::cout << "\nSquare impresso como um Point eh: " << pRef << std::endl;

    Cube cube(2);
    std::cout << "Volume eh " << cube.volume();
    return 0;
}
*/

// Exercício 9.10 por Composição
#include <iostream>
#include <iomanip> // Adicionado para uso de setiosflags e setprecision

using std::ios;
using std::setiosflags;
using std::setprecision;
using std::ostream; // Adicionado para uso de ostream

class Point {
    friend std::ostream &operator<<(std::ostream &, const Point &);
public:
    Point(int = 0, int = 0);
    void setPoint(int, int);
    int getX() const { return x; }
    int getY() const { return y; }
protected:
    int x, y;
};

Point::Point(int a, int b) { setPoint(a, b); }

void Point::setPoint(int a, int b) {
    x = a;
    y = b;
}

std::ostream &operator<<(std::ostream &output, const Point &p) {
    output << '[' << p.x << ", " << p.y << ']';
    return output;
}

class Square {
    friend std::ostream &operator<<(std::ostream &, const Square &);
public:
    Square(double s = 0.0, int x = 0, int y = 0);
    void setSide(double);
    double getSide() const;
    double area() const;
    void setPoint(int, int);
    int getX() const;
    int getY() const;
private:
    Point center;
    double side;
};

Square::Square(double s, int x, int y) : center(x, y) {
    setSide(s);
}

void Square::setSide(double s) {
    side = (s >= 0 ? s : 0);
}

double Square::getSide() const { return side; }

double Square::area() const {
    return side * side;
}

void Square::setPoint(int x, int y) {
    center.setPoint(x, y);
}

int Square::getX() const { return center.getX(); }

int Square::getY() const { return center.getY(); }

std::ostream &operator<<(std::ostream &output, const Square &s) {
    output << "Centro = " << s.center
           << "; Lado = " << setiosflags(ios::fixed | ios::showpoint) << setprecision(2) << s.side;
    return output;
}

class Cube {
    friend std::ostream &operator<<(std::ostream &, const Cube &);
public:
    Cube(double s = 0.0);
    void setSide(double);
    double volume() const;
    double area() const;
private:
    Square base;
};

Cube::Cube(double s) : base(s) {
    setSide(s);
}

void Cube::setSide(double s) {
    base.setSide(s);
}

double Cube::area() const {
    return 6 * base.getSide() * base.getSide();
}

double Cube::volume() const {
    double side = base.getSide();
    return side * side * side;
}

std::ostream &operator<<(std::ostream &output, const Cube &c) {
    output << c.base << "; Lado = " << c.base.getSide();
    return output;
}

int main() {
    Square s(2.5, 37, 43);
    std::cout << "A coordenada X eh " << s.getX();
    std::cout << "\nA coordenada Y eh " << s.getY();
    std::cout << "\nO lado eh " << s.getSide(); 

    s.setSide(4.25);
    s.setPoint(2, 2);
    std::cout << "\n\nA nova posicao e o lado sao: " << s << "\nArea " << s.area() << "\n";

    std::cout << "\nSquare impresso: " << s << std::endl;

    Cube cube(2);
    std::cout << "Volume eh " << cube.volume() << std::endl;
    std::cout << "Area eh " << cube.area() << std::endl;
    std::cout << "Cube impresso: " << cube << std::endl;

    return 0;
}



// Exercício 9.11
/*
    De maneira bem resumida:
    Pense que uma classe possui uma função X que retorne um inteiro.
    Essa classe serve como classe base para uma outra função, que precisa que a função X retorne um char.
    Isso pode gerar incompatibilidades, de forma que um objeto da classe derivada não seja um objeto da classe base.
*/

// Exercício 9.12
/*
    MembroDaComunidade é classe base de Empregado, Estudante e Graduado
    Empregado é classe base de Docente e Funcionario
    Docente é classe base de Administrador e Professor
    Administrador e Professor são classes bases de herança múltipla para ProfessorAdministrador

    Podemos pensar em adicionar uma nova classe que herde de Docente, chamada Pesquisador.
    Dessa forma, podemos adicionar uma classe que herde (herança múltipla) de Professor e Pesquisador, chamada ProfessorPesquisador.
    Por fim, podemos adicionar uma classe que herde de ProfessorPesquisador e ProfessorAdministrador, chamada ProfessorAdministradorPesquisador.
*/

/*
// Exercício 9.13
// Código extremamente simplificado. 
#include <iostream>
#include <cmath>

class Quadrilatero {
public:
    Quadrilatero();
    void setPosicoes();
protected:
    double* getPosicoes() { return &posicoes[0][0]; } // Método protegido para acesso às posições
private:
    double posicoes[4][2];
};

Quadrilatero::Quadrilatero() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            posicoes[i][j] = 0;
        }
    }
}

void Quadrilatero::setPosicoes() {
    double x, y;
    for(int i = 0; i < 4; i++) {
        std::cout << "Digite as coordenadas do ponto " << i + 1 << ":" << std::endl;
        std::cin >> x >> y;
        posicoes[i][0] = x;
        posicoes[i][1] = y;
    }
}

class Trapezoide : public Quadrilatero {
public:
    Trapezoide();
    bool isTrapezoide();
};

Trapezoide::Trapezoide() {}

bool Trapezoide::isTrapezoide() {
    // Obtendo as coordenadas dos pontos
    double* coords = getPosicoes();

    // Verificar se pelo menos um par de lados é paralelo
    double slope1 = (coords[3] - coords[1]) / (coords[2] - coords[0]);
    double slope2 = (coords[7] - coords[5]) / (coords[6] - coords[4]);
    if(std::abs(slope1 - slope2) < 1e-6) {
        return true; // Primeiro e último lado são paralelos
    }
    slope1 = (coords[5] - coords[3]) / (coords[4] - coords[2]);
    slope2 = (coords[1] - coords[7]) / (coords[0] - coords[6]);
    if(std::abs(slope1 - slope2) < 1e-6) {
        return true; // Lados opostos são paralelos
    }
    return false; // Nenhum par de lados é paralelo
}

int main() {
    Trapezoide t;
    t.setPosicoes();
    if(t.isTrapezoide()) {
        std::cout << "Eh um trapezio." << std::endl;
    } else {
        std::cout << "Nao eh um trapezio." << std::endl;
    }
    return 0;
}
*/


// Exercício 9.14
/*
    Forma é classe base de FormaBidimensional e FormaTridimensional
    FormaBidimensional pode ter como classe derivada Quadrilatero e Triangulo, e dessas podem derivar TrianguloIsosceles, Quadrado etc
    FormaTridimensional pode ter como classe derivada a classe de poliedros de platao, e assim sucessivamente.
*/


