/*
// Exercício 2.16
#include <iostream>
int main(){
    using std::cout;
    using std::cin;
    using std::endl;
    double litros, km;
    do{
        cout << "Digite o numero de litros (-1 para parar): ";
        cin >> litros;
        if (litros + 1 > 0.1){
            cout << "Digite o numero de km: ";
            cin >> km;
            cout << "Media para esse tanque: " << km/litros << endl;
        }
    }while(litros + 1 > 0);
    return 0;
}
*/

/*
// Exercício 2.18
#include <iostream>
int main(){
    double vendaSemana;
    while(true){
        std::cout << "Digita vendas em dólares: (-1 para encerrar): ";
        std::cin >> vendaSemana;
        if(vendaSemana + 1 > 0.1){
            std::cout << "Salario é: " << 200 + 0.09*vendaSemana << std::endl;
        }else{
            break;
        }
    }
    return 0;
}
*/

/*
// Exercício 2.18
#include <iostream>
int main(){
    double salarioHora, hora;
    while(true){
        std::cout << "Digite as horas trabalhadas (-1 para encerrar):  ";
        std::cin >> hora;
        if(hora + 1 > 0.1){
            std::cout << "Digite o salario hora do trabalhador: ";
            std::cin >> salarioHora;
            if(hora > 40){
                std::cout << "Salario eh: $" << (hora - 40)*1.5*salarioHora + 40*salarioHora;
            }else{
                std::cout << "Salario eh: $" << hora*salarioHora;
            }
        }else{
            break;
        }
    }
    return 0;
}
*/

/*
// Exercício 2.20
#include <iostream>
int main(){
    int counter, number, largest;
    for(counter = 1; counter <= 10; counter++){
        std::cout << "Numero: ";
        std::cin >> number;
        if(counter == 1){
            largest = number;
        }else{
            if(number > largest){
                largest = number;
            }
        }
    }
    std::cout << largest;
    return 0;
}
*/

/*
// Exercício 2.21
#include <iostream>
int main(){
    int count;
    for(count = 1; count <= 5; count++){
        std::cout << count << "\t" << 10*count << "\t" << 100*count << "\t" << 1000*count << std::endl;
    }
    return 0;
}
*/

/*
// Exercício 2.22
#include <iostream>
int main(){
    int count, number, largest1, largest2;
    for(count = 1; count <= 10; count++){
        std::cout << "Numero: ";
        std::cin >> number;
        if(count == 1){
            largest1 = number;
        }
        if(count == 2){
            largest2 = number;
        }
        else{
            if(number > largest1 && number < largest2) largest1 = number;
            if(number > largest2 && number < largest1) largest2 = number;
            if(number > largest1 && number > largest2 && largest1 > largest2) largest2 = number;
            if(number > largest1 && number > largest2 && largest2 > largest1) largest1 = number;
        }
    }
    std::cout << largest1 << std::endl;
    std::cout << largest2 << std::endl;
    return 0;
}
*/

/*
// Exercício 2.28
#include <iostream>
int main(){
    int lado, counter, imp;
    std::cout << "Digite o tamanho: ";
    std::cin >> lado;
    for(counter = 1; counter <= lado; counter++){
        imp = 1;
        if(counter == 1 || counter == lado){
            for(imp = 1; imp <= lado; imp++){
                std::cout << "*";
            } 
        }else{
            for(imp = 1; imp <= lado; imp++){
                if(imp == 1 || imp == lado){
                    std::cout << "*";
                }else{
                    std::cout << " ";
                }
            }
        }
        std::cout << "\n";
    }
    return 0;
}
*/

/*
// Exercício 2.29
#include <iostream>
int main(){
    int number;
    std::cout << "Digite o numero de cinco digitos:";
    std::cin >> number;
    int a = number%10;
    int novoNumero = (number - a)/10;
    int b = (novoNumero)%10;
    novoNumero = (novoNumero - b)/10;
    int c = (novoNumero)%10;
    novoNumero = (novoNumero - c)/10;
    int d = (novoNumero)%10;
    novoNumero = (novoNumero - d)/10;
    if(novoNumero == a && d == b) std::cout << "Eh palindromo";
    else std::cout << "Nao eh";
    return 0;
}
*/

/*
// Exercício 2.30
#include <iostream>
#include <math.h>
int main(){
    int number, soma = 0, count = 0, digito;
    std::cout << "Digite o numero binario: ";
    std::cin >> number;
    while(!(number == 0)){
        digito = number % 2;
        soma += digito * pow(2, count);
        count++;
        number = (number-digito)/10;
    }
    std::cout << soma;
    return 0;
}
*/

/*
// Exercício 2.31
#include <iostream>
int main(){
    int row, column;
    for(row = 1; row <= 8; row++){
        if(row % 2 == 0){
            std::cout << " ";
        }
        for(column = 1; column <= 16; column += 2){
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    return 0;
}
*/

/*
// Exercício 2.35
#include <iostream>
int main(){
    double a, b, c;
    std::cout << "Digite o primeiro: ";
    std::cin >> a;
    std::cout << "Digite o segundo: ";
    std::cin >> b;
    std::cout << "Digite o terceiro: ";
    std::cin >> c;
    if(a <= b+c && b <= a+c && c <= a+b && a >= abs(b-c) && b >= abs(a-c) && c >= abs(a-b)) std::cout << "Eh triangulo"; 
    return 0;
}
*/

/*
// Exercício 2.36
#include <iostream>
int main(){
    int a, b, c;
    std::cout << "Digite o primeiro: ";
    std::cin >> a;
    std::cout << "Digite o segundo: ";
    std::cin >> b;
    std::cout << "Digite o terceiro: ";
    std::cin >> c;
    if(a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b) std::cout << "Eh triangulo retangulo";
    return 0;
}
*/

/*
// Exercício 2.37
#include <iostream>
int main(){
    int number;
    std::cout << "Digite o numero de quatro digitos: ";
    std::cin >> number;
    int a = number%10;
    number = (number-a)/10;
    int b = number%10;
    number = (number-b)/10;
    int c = number%10;
    int d = (number-c)/10;
    a = (a+7) % 10;
    b = (b+7) % 10;
    c = (c+7) % 10;
    d = (d+7) % 10;
    std::cout << b << a << d << c;
    return 0;
}
*/

/*
// Exercício 2.38
#include <iostream>
#include <math.h>
int main(){
    // Resolvendo a Letra C, que já engloba as outras alternativas.
    int x, count, f, contador;
    double soma = 1;
    std::cout << "Digite o valor de x:";
    std::cin >> x;
    for(count = 1; count <= 10; count++){ // Vou fazer 20 iterações na equação, parece ser razoável
        // Em cada iteração vou precisar do fatorial do número da iteração;
        f = 1;
        for(contador = 1; contador <= count; contador++){
            f *= contador;
        }
        soma += static_cast<double>(pow(x, count)/f);
    }
    std::cout << soma << std::endl;
    return 0;
}
*/

/*
// Exercício 2.41
#include <iostream>
int main(){
    using std::cin;
    int a, contador = 0, soma = 0;
    std::cout << "Digite o numero:";
    do{
        std::cin >> a;
        if(a != 9999){
            soma += static_cast<int>(a);
            contador += 1;
        }
    }while(a != 9999);
    std::cout << "Media eh: " << static_cast<double>(soma/contador);
    return 0;
}
*/

/*
// Exercício 2.43
#include <iostream>
int main(){
    int counter = 0, numero, termos, menor;
    std::cout << "Digite uma sequencia: ";
    do{
        std::cin >> numero;
        if(counter == 0) termos = numero;
        else if(counter == 1) menor = numero;
        if(menor > numero) menor = numero;
        counter++;
    }while(counter <= termos);
    std::cout << menor << std::endl;
    return 0;
}
*/

/*
// Exercício 2.47
#include <iostream>
int main(){
    int count, count2;
    for(count = 1; count <= 10; count++){
        for(count2 = 1; count2 <= count; count2++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for(count = 10; count >= 1; count--){
        for(count2 = 1; count2 <= count; count2++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for(count = 10; count >= 1; count--){
        for(count2 = 1; count2 <= 10; count2++){
            if(count2 <= 10-count) std::cout << " ";
            else std::cout << "*";
        }
        std::cout << std::endl;
    }
    for(count = 10; count >= 0; count--){
        for(count2 = 1; count2 <= 10; count2++){
            if(count2 <= count) std::cout << " ";
            else std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}
*/

/*
// Exercício 2.53 (Difícil para a lista #1)
#include <iostream>
int main(){
    long long numero;
    int a, b, c, d, e, f, g, h, i;
    int j, k, l;
    std::cout << "Decimal\t\tBinario\t\tOctal\t\tHexadecimal\n";
    for(numero = 1; numero <= 256; numero++){
        std::cout << std::dec << numero << "\t";
        // Transformando para binário (precisei pesquisar essa parte)
        i = numero & 1; // É uma operação entre o número decimal "numero" e o digito binário 1.
        h = (numero >> 1) & 1; // Transforma automaticamente numero para binario e compara com a representação binaria de 1.
        g = (numero >> 2) & 1; // Ex.: 1 & 1 = 1, 10 (em binário) & 1 = 10. É uma "porta lógica AND"
        f = (numero >> 3) & 1; // A parte numero >> 3 significa que estou pegando meu binário de "número" e deslocando 3 casas pra direita.
        e = (numero >> 4) & 1; // Ex.: 1001 >> 2 = 0010 (01 somem)
        d = (numero >> 5) & 1; // Basicamente transformei numero para binario e estou salvando em cada variável se é 0 ou 1 no último digito
        c = (numero >> 6) & 1; // e dai vou deslocando, ate acabar e transformar tudo em 0000000000
        b = (numero >> 7) & 1;
        a = (numero >> 8) & 1;
        std::cout << a << b << c << d << e << f << g << h << i << "\t";
        // Transformando para octal

        std::cout << std::oct << numero << "\t"; // A outra forma é pegar de 3 em 3 os números binários e ir transformando

        // Transformando para hexadecimal
        
        std::cout << std::hex << numero << "\t"; // A outra forma é pegar de 4 em 4 os números binários e ir transformando

        std::cout << std::endl;
    }
}
*/

/*
// Exercício 2.54
#include <iostream>
#include <math.h>
int main(){
    int contador;
    double soma = 0;
    for(contador = 1; contador <= 100; contador++){
        soma += static_cast<double>(pow(-1, contador+1)*4/(2*contador-1));
        std::cout << "Aproximacao com " << contador << " termos: " << soma << std::endl;
    }
    return 0;
}
*/

/*
// Exercício 2.55
#include <iostream>
int main(){
    int a, b, c, contador = 0;
    for(a = 1; a <= 500; a++){
        for(b = 1; b <= 500; b++){
            for(c = 1; c <= b; c++){
                if(a*a == b*b + c*c){
                    contador += 1;
                    std::cout << "Tripla numero " << contador << ": ";
                    std::cout<< a << "\t" << b << "\t" << c << std::endl;
                }
            }
        }
    }
    return 0;
}
*/

/*
// Exercício 2.56
#include <iostream>
int main(){
    char answ = 's';
    int opt, hours, value, vendaSemanal, produtos; 
    while (answ == 's'){
        std::cout << "Deseja verificar outro funcionario? (s/n)";
        std::cin >> answ;
        if(answ == 's'){
            std::cout << "Digite o numero do funcionario, sendo: 1 - gerente, 2 - horista, 3 - comissionado, 4 - tarefeiros:";
            std::cin >> opt;
            switch(opt){
                case 1:
                    std::cout << "Possui salario fixo!";
                    break;
                case 2:
                    std::cout << "Digite o numero de horas trabalhadas: ";
                    std::cin >> hours;
                    std::cout << "Digite o valor da hora: ";
                    std::cin >> value;
                    if(hours >= 40) std::cout << "Salario eh: $" << 40*value + (hours-40)*1.5*value;
                    else std::cout << "Salario eh: $" << hours*value;
                    break;
                case 3:
                    std::cout << "Digite o valor da venda semanal bruta: ";
                    std::cin >> vendaSemanal;
                    std::cout << "Salario eh: $" << static_cast<double>(250 + vendaSemanal*0.057);
                    break;
                case 4:
                    std::cout << "Numero de itens produzidos: ";
                    std::cin >> produtos;
                    std::cout << "Valor de cada produto que vai pro tarefeiro: ";
                    std::cin >> value;
                    std::cout << "Salario eh: $" << produtos*value;
                    break;
                default:
                    std::cout << "Numero invalido." << std::endl;
            }
        }else{
            std::cout << "Encerrando..." << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
*/


/*
// Exercício 2.59 (2.58 incluido). (Difícil para a lista #2)
#include <iostream>
int main(){
    int numero, contador, cont;
    std::cout << "Digite o numero impar de linhas: ";
    std::cin >> numero;
    for(contador = 1; contador <= numero; contador++){ // Número de linhas. Da linha 1 até linha numero.
        if(contador < (numero+1)/2){ // Se vem antes do maior trecho
            for(cont = 1; cont < (numero+1)/2 - contador + 1; cont++){
                std::cout << " ";
            }
            for(cont = (numero+1)/2 - contador + 2; cont <= (numero+1)/2 + contador; cont++){
                std::cout << "*";
            }
        }else if(contador == (numero+1)/2){ // Se é o maior trecho
            for(cont = 1; cont <= numero; cont++){
                std::cout << "*";
            }
        }else{ // Se vem depois do maior trecho
            for(cont = 1; cont < - (numero+1)/2 + contador + 1; cont++){
                std::cout << " ";
            }
            for(cont = 1; cont <= 2 *(numero-contador)+1; ++cont){
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
*/
