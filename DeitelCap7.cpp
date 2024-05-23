/*

// Exercício 7.3 (Comparar new/delete e malloc/free)
    ==== Principais Diferenças
    1. Tipo de Dados Retornado: new retorna um ponteiro do tipo específico do objeto alocado, enquanto malloc retorna um ponteiro void*, 
    que precisa ser convertido explicitamente.
    2. Inicialização e Destruição: new chama construtores e destrutores apropriados, enquanto malloc e free não realizam 
    nenhuma inicialização ou destruição.
    3. Sintaxe: A sintaxe para usar new e delete é mais direta e limpa em C++ do que a combinação de malloc e free em C.
    4. Sobrecarga de Operador: new pode ser sobrecarregado para personalizar a alocação de memória, o que não é possível com malloc.

    ==== Conclusão
    1. new e delete são mais seguros e convenientes em C++ devido à chamada automática de construtores e destrutores.
    2. malloc e free são mais flexíveis em C e são usados quando não é necessário suporte para construtores e destrutores, 
    ou quando se deseja interoperabilidade com código C.
    3. Para código C++, é preferível usar new e delete, enquanto em código C, malloc e free são as opções padrão para alocação de memória dinâmica.
    Destaca-se que memória alocada por new não é deletada por free e vice-versa (malloc/delete).

*/

/*

// Exercício 7.4 (Explicar friend e aspectos negativos)
    Em resumo, dada uma classe com membros do tipo public, private e protected, eu posso declarar uma função ou uma classe como
    friend dessa primeira classe, de forma que minha classe/função friend terá acesso aos membros private e protected da primeira classe.
    Usar estas classes friends melhora o desempenho, mas algumas pessoas consideram que a noção de friend corrompe a ocultação de 
    informações e enfraquece o valor da abordagem de projeto orientado a objetos.
    Apenas como revisão, para declarar basta algo do tipo:
    class A{
        friend class B; (classe B é friend de A, e portanto tem acesso aos seus membros private)
    public:

    private:

    }

*/

/*

// Exercício 7.5 (Sobrecarga de Construtor)
    Sim! Pode incluir os dois construtores, sendo um deles esperando parâmetro e o outro sem esperar parâmetro.
    Isso permite que eu crie objetos nas formas: Time t1(8, 2, 1) e Time t2.
    Isso se chama sobrecarga do construtor!
    "Quando você cria um objeto da classe, o compilador determina qual construtor usar com base nos argumentos fornecidos na chamada do construtor."
    Isso não ocorre para destruidores!! São únicos na classe.

*/

/*

// Exercício 7.6
    Dá erro de compilação.
    Construtor e destruidor não podem ter tipo de retorno, e nem posso tentar retornar algo deles.
    Destruidor também não pode ter parâmetro.    

*/


/*
// Exercício 7.7

#include <iostream>
#include <ctime>
#include <string>

class Date {
public:
    // Usando sobrecarga de construtor. Lembrando que isso não é possível com destruidor.
    Date(int d, int m, int a) : dia(d), mes(m), ano(a) {} // Permite entrada curta
    Date(int d, std::string mesStr, int a); // Permite entrada longa
    Date(); // Pega do ctime
    void imprimirSimples();
    void imprimirLongo();
private:
    int dia;
    int mes;
    int ano;
    int getMesFromString(const std::string& mesStr); // Função auxiliar
};

Date::Date(int d, std::string mesStr, int a) : dia(d), ano(a) {
    mes = getMesFromString(mesStr);
}

Date::Date() {
    time_t t = time(0);
    tm* now = localtime(&t);
    dia = now->tm_mday;
    mes = now->tm_mon + 1;
    ano = now->tm_year + 1900;
}

void Date::imprimirSimples() {
    std::cout << (dia < 10 ? "0" : "") << dia << "/"
              << (mes < 10 ? "0" : "") << mes << "/"
              << ano << std::endl;
}

void Date::imprimirLongo() {
    const char* meses[] = { "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", 
                            "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" };
    std::cout << (dia < 10 ? "0" : "") << dia << " de " << meses[mes - 1] << " de " << ano << std::endl;
}

int Date::getMesFromString(const std::string& mesStr) {
    const char* meses[] = { "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", 
                            "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" };
    for (int i = 0; i < 12; ++i) {
        if (mesStr == meses[i]) {
            return i + 1;
        }
    }
    return 0; // Retornar 0 para indicar erro
}

int main() {
    Date dataCurta(25, 12, 2022);
    Date dataLonga(25, "Dezembro", 2022);
    Date dataAtual;

    std::cout << "Data curta em formato simples: ";
    dataCurta.imprimirSimples();
    std::cout << "Data curta em formato longo: ";
    dataCurta.imprimirLongo();

    std::cout << "Data longa em formato simples: ";
    dataLonga.imprimirSimples();
    std::cout << "Data longa em formato longo: ";
    dataLonga.imprimirLongo();

    std::cout << "Data atual em formato simples: ";
    dataAtual.imprimirSimples();
    std::cout << "Data atual em formato longo: ";
    dataAtual.imprimirLongo();

    return 0;
}

*/

/*
// Exercício 7.8

#include <iostream>

class ContaDePoupanca{
public:
    ContaDePoupanca(float);
    static void modifiqueTaxaDeJuros(float);
    void calculeRendimentoMensal();
    float imprimirSaldo();
private:
    static float taxaDeJurosAnual;
    float saldoDaPoupanca;
};

// Relembrando: Definir um membro como static em uma classe em C++ significa que este membro é compartilhado por todos os objetos 
// daquela classe, em vez de cada objeto ter sua própria cópia desse membro.

int main(){
    ContaDePoupanca poupador1(2000), poupador2(3000);
    ContaDePoupanca::modifiqueTaxaDeJuros(6); // Note que por ser static eu não uso a estrutura objeto.funcao() e sim Classe::Funcao()
    poupador1.calculeRendimentoMensal();
    poupador2.calculeRendimentoMensal();
    std::cout << "Rendimento do poupador 1: " << poupador1.imprimirSaldo() << std::endl;
    std::cout << "Rendimento do poupador 2: " << poupador2.imprimirSaldo() << std::endl;
    ContaDePoupanca::modifiqueTaxaDeJuros(8);
    poupador1.calculeRendimentoMensal();
    poupador2.calculeRendimentoMensal();
    std::cout << "Rendimento do poupador 1: " << poupador1.imprimirSaldo() << std::endl;
    std::cout << "Rendimento do poupador 2: " << poupador2.imprimirSaldo() << std::endl;
}

ContaDePoupanca::ContaDePoupanca(float a){
    saldoDaPoupanca = a;
    std::cout << "Poupanca de " << saldoDaPoupanca << std::endl;
}

void ContaDePoupanca::calculeRendimentoMensal(){
    saldoDaPoupanca += ((saldoDaPoupanca*taxaDeJurosAnual)/12);
}

float ContaDePoupanca::imprimirSaldo(){
    return saldoDaPoupanca;
}

float ContaDePoupanca::taxaDeJurosAnual = 0; // PRECISA TER ISSO. ISSO É INICIALIZAÇÃO ESTÁTICA. ESTÁ NO LIVRO. 
// Essa linha acima, o ChatGPT 3.5 diz que pode remover, mas se remover ele NÃO COMPILA. Veja a página 476 do Livro, Fig. 7.9.

void ContaDePoupanca::modifiqueTaxaDeJuros(float a){
    taxaDeJurosAnual = (a/100);
}
*/

/*
// Exercício 7.9
#include <iostream>

class ConjuntoDeInteiros{
public:
    ConjuntoDeInteiros(int = -1, int = -1, int = -1, int = -1, int = -1);
    ConjuntoDeInteiros uniao(ConjuntoDeInteiros &);
    ConjuntoDeInteiros intersecao(ConjuntoDeInteiros &);
    void inserirMembro(int);
    void retirarMembro(int);
    void imprimaConjunto();
    bool ehIgualA(ConjuntoDeInteiros &);

private:
    int array[100];
};

int main(){
    ConjuntoDeInteiros conj1, resultado, resultado2;
    ConjuntoDeInteiros conj2(1, 2, 3, 4);
    conj1.inserirMembro(10);
    conj1.imprimaConjunto();
    conj2.imprimaConjunto();
    resultado =conj1.uniao(conj2);
    resultado.imprimaConjunto();
    resultado2 = resultado.intersecao(conj2);
    resultado2.imprimaConjunto();
    std::cout << "Eh igual: " << 
    resultado2.ehIgualA(conj2);
    
    return 0;
}

ConjuntoDeInteiros::ConjuntoDeInteiros(int a, int b, int c, int d, int e){
    for(int contador = 0; contador < 100; contador++){
        array[contador] = 0;
    }
    
    for(int contador = 0; contador < 100; contador++){
        if(contador + 1 == a) {array[contador] = 1;}
        if(contador + 1 == b) {array[contador] = 1;}
        if(contador + 1 == c) {array[contador] = 1;}
        if(contador + 1 == d) {array[contador] = 1;}
        if(contador + 1 == e) {array[contador] = 1;}
    }   
}

ConjuntoDeInteiros ConjuntoDeInteiros::uniao(ConjuntoDeInteiros & outroConjunto){
    ConjuntoDeInteiros resultado;
    for(int contador = 0; contador < 100; contador++){
        if(array[contador] == 1 || outroConjunto.array[contador] == 1) {
            resultado.array[contador] = 1;
        }
    }
    return resultado;
}

ConjuntoDeInteiros ConjuntoDeInteiros::intersecao(ConjuntoDeInteiros & outroConjunto){
    ConjuntoDeInteiros resultado;
    for(int contador = 0; contador < 100; contador++){
        if(array[contador] == 1 && outroConjunto.array[contador] == 1) {
            resultado.array[contador] = 1;
        }
    }
    return resultado;
}

void ConjuntoDeInteiros::inserirMembro(int a){
    array[a-1] = 1;
}

void ConjuntoDeInteiros::imprimaConjunto(){
    for(int contador = 0; contador < 100; contador++){
        if(array[contador] == 1){
            std::cout << contador+1 << "\t";
        }
    }
    std::cout << std::endl;
}

void ConjuntoDeInteiros::retirarMembro(int a){
    array[a-1] = 0;
}

bool ConjuntoDeInteiros::ehIgualA(ConjuntoDeInteiros & outroConjunto){
    for(int contador = 0; contador < 100; contador++){
        if(array[contador] != outroConjunto.array[contador]){
            return false;
        }
    }
    return true;
}
*/


// Exercício 7.10 
// Precisa copiar o código da Figura 7.8 pág 470
// Muda a parte private apenas para segundos, e nas implementações das funções públicas, por exemplo:
// setHour deve adicionar x*60*60 nesse int private
// Sucessivamente.
// Código extremamente grande para copiar no momento.


