## Conversão n2m

#O programa é composto por três estruturas.

#A primeira é o arquivo n2m.c que contém a função main() que recebe 3 parâmetros quando é chamado o programa, caso não tenha esse três parâmetros(excluindo-se a própria chamada da função que é o n2m), o programa executa o exit com o parametro 1, mostrando que algo não está certo. Ainda neste arquivo e na função main, dentro dela só existe uma chamada de função que é o newBase(), que deve receber os mesmos parâmetros que foram passados na chamada da função, caso esteja dentro dos conformes, o programa "linka" com o outro arquivo, o lib.c.


#No arquivo lib.c ja na primeira linha é chamada a biblioteca lib.h(será explicado mais tarde). Dentro do lib.c existe todas as funções que o programa usa para gerar o número na base desejada. Primeiramente existe a função verify(), que é onde se verifica para ver se os parâmetros estão na ordem e dentro das configurações a ser seguida, como por exemplo, o terceiro e o quarto parâmetros são as bases, as bases devem estar entre 2 e 36, fora desse intervalo o programa não executará nenhum calculo e retornará um no exit(). 
#Existe também uma função de auxilio que é o potency(), que recebe 2 inteiros e retorna a potencia do primeiro inteiro pelo segundo, para não precisar usar uma biblioteca extra.
#Agora partindo para a o calculo de mudança de base, primeiramente é chamada a função toBase10() que transforma o numero passado como segundo parametro para a base 10, seja qual for a base ele fará as contas. Caso o numero utrapasse a potencia de 2 por 32, o exit(1) será acionado. Ainda nessa função, caso o numero tenha caracteres incoerente com a base dita ser a dele o exit(1) também será acionado.
#Já com o numero na base 10, a função toAnyBase(), que recebe o número e a base desejada, o calculo é feito para transformar para a base passada como parâmetro. Seja qual for a base desejada o programa fará as contas de qualquer jeito. Ao fim desse processo o programa retornará uma String com o valor corresponde, vale ressaltar que mesmo sendo um conjunto de números somente, o valor retornado será no formato de String e não um número inteiro.
#Chegando no final exite a própria função newBase que contém todas as funções acima na ordem dos calculos.

#Agora explicando o lib.h, nele existe todos os includes que o lib.c necessita, dentro dela não existe função alguma, apenas includes do sistema.


