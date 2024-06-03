/*
Exercício 10.2
    Funções virtuais permitem que uma função definida na classe base seja substituída (ou "sobrescrita") por uma função com a mesma assinatura em 
    uma classe derivada. Isso é essencial para a implementação de polimorfismo, que permite que objetos de diferentes classes derivadas
    sejam tratados de forma uniforme através de ponteiros ou referências à classe base.
    Exemplo: declaração de classe abstrata Shape para posterior implementação de funções concretas de geometria, como Square e Rectangle.
*/

/*
Exercício 10.3
    Nessa questão ele pede para encontrar alguma coisa que funcione semelhante a construtores virtuais.
    Por pesquisa, encontramos: "é possível um comportamento semelhante com métodos de fábrica (factory methods) e polimorfismo"
    Um método de fábrica é uma função que cria instâncias de classes derivadas, permitindo que a lógica de criação seja encapsulada e reutilizada.
*/

/*
Exercício 10.4
    O polimorfismo melhora a extensibilidade do meu programa, pois ele permite que eu trate aspectos do programa de forma genérica.
    Exemplo: o polimorfismo permite definir uma classe base abstrata Shape, que fornece funções que serão usadas e algumas redefinidas em
    subclasses derivadas, como Square, Rectangle, Circle e semelhantes.
    Esse tratamento mais genérico permite que novos tipos de objetos sejam adicionados sem muita modificação, desde que 
    respeitando a hierarquia do polimorfismo.
*/

/*
Exercício 10.5
    Em comparação com o switch, o uso de funções virtual e polimorfismo tornam os programas de aparência mais simples, com menos
    ramificações lógicas, favorecendo o emprego de código sequêncial mais simples. Facilita o teste, a depuração e a manutenção de programas e evita
    erros.
    A ideia da lógica de programação com o switch é que é possível lidar com objetos de tipos diferentes por meio de comando switch para executar 
    a ação apropriada sobre cada objeto, com base no tipo do objeto.
*/

/*
Exercício 10.6
    "Diferencia vinculação estática e vinculação dinâmica. Explique uso de funçao virtual e da vtable na vinculação dinâmica."

    Vinculação estática: significa que todas as decisões sobre quais funções serão chamadas são feitas antes da execução do programa.
    É o padrão!
    Vinculação dinâmica: ligação entre a chamada de uma função e sua implementação é determinada durante a execução do programa.
    Quando uma função é declarada como virtual, ela permite que uma subclasse forneça uma implementação específica, e essa implementação
    pode ser chamada mesmo que o objeto seja referenciado através de um ponteiro ou referência da classe base.
    É fruto de polimorfismo!

    "A vtable é uma tabela de ponteiros para funções virtuais de uma classe. Cada classe que possui funções virtuais tem uma vtable, 
    e cada objeto de uma classe que possui funções virtuais tem um ponteiro para a vtable da classe correspondente. Quando uma função
    virtual é chamada, o sistema usa o ponteiro para a vtable do objeto para encontrar o ponteiro correto da função e invocá-la.
    Isso permite que a implementação correta da função virtual seja chamada, com base no tipo real do objeto em tempo de execução,
    facilitando o polimorfismo."
*/

/*
Exercício 10.7
    Herdar a interface: significa basicamente o que ocorre entre classe abstrata e classe concreta.
    Herdar a implementação: herda tudo certinho e adiciona novas coisas. Basicamente reutilização de código.
    A primeira é o clássico do polimorfismo, enquanto a segunda foi o Capítulo 9 de Herança.
    
*/

/*
Exercício 10.8
    Uma função virtual pura é uma função virtual que possui inicializador 0, conforme resumo do capítulo.
*/

/*
Exercício 10.9
    Falso! Para ser uma classe abstrata basta que uma das funções virtuais seja declarada como virtual pura.
*/

/*
Exercício 10.10
    Uma classe abstrata para a classe abstrata Shape poderia ser algo mais genérico, como Geometry, com as propriedades da Geometria.
    Uma classe ainda mais abstrata poderia ser a classe Math em si. 
    Classes para as quais não faz sentido instanciar um objeto.
*/

/*
Exercício 10.11
    O polimorfismo promove extensibilidade ao permitir que sistemas sejam desenvolvidos com componentes modulares e intercambiáveis.
    Isso facilita a adição de novas funcionalidades, a manutenção do código existente e a evolução do sistema sem a necessidade de 
    modificações significativas. Ao depender de abstrações e usar o polimorfismo, os desenvolvedores podem criar sistemas flexíveis 
    e adaptáveis às mudanças, que são características fundamentais de software extensível e robusto.
*/

/*
Exercício 10.12
    Um simulador de vôo parece ser um sistema consideravelmente complexo. Improvável ser realizado em programação procedural, então
    vamos para OOP.
    A programação polimórfica poderia ser utilizada, por exemplo, na definição de uma classe abstrata Avião, base para classes concretas
    de modelos de avião. 
    Além dos motivos claros da programação polimórfica ser bem utilizada para programas extensíveis.
*/

// Exercício 10.13

// Exercício 10.14

// Exercício 10.15