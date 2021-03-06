
// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Laade da Costa Lima Modesto
//  email: laade09@gmail.com
//  Matrícula: 2019116023
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y){
  int soma = 0;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes
  int fat = 1;
  return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */

int q1(char *data){

    char dia[3], mes[3], ano[5];
    int idia, imes, iano, i, j;
    int datavalida = 1;

    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);

    //QUEBRA DE STRING DATA
	for(i=0; data[i] != '/'; i++)
		dia[i] = data[i];
	for(i=i+1, j=0; data[i] != '/'; i++, j++)
		mes[j] = data[i];
	for(i=i+1, j=0; data[i] != '\0'; i++, j++)
		ano[j] = data[i];

	//Converte CHAR PARA INTEIRO
		idia= atoi(dia);
		imes= atoi(mes);
		iano= atoi(ano);

   if(iano>0000  && iano<=9999)   {
        if(imes>0 && imes<13)
            switch(imes){
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                if(idia<1||idia>31 && imes==1 || imes==3 || imes==5 || imes==7 || imes==8 || imes==0 || imes==12)
                    datavalida = 0;
                break;
                case 4:
                case 6:
                case 9:
                case 11:
                if(idia<1||idia>30 && imes == 4 || imes == 6 || imes == 9 || imes == 11)
                    datavalida = 0;
                break;

                case 2:
                if(!(iano % 400)||(!(iano % 4)&&(iano % 100))){
                    if(idia<1 || idia>29)
                        datavalida=0;
                } else
                if(idia<1 || idia>28)
                    datavalida=0;
                break;
        }
        else datavalida = 0;
    }//else datavalida = 0;
    if (datavalida)
        return 1;
    else
        return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */

int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    int nDias, nMeses, nAnos;
    int diainicial,mesinicial,anoinicial;
    int diafinal,mesfinal,anofinal;
    char sDia[3], sMes[3], sAno[5];
    int i, j, contM = 0, contA = 0;
    int retorno = 1;

    if(q1(datainicial)==0)
        retorno=2;
    if(q1(datafinal)==0)
        retorno=3;

    	sscanf(datainicial, "%d/%d/%d", &diainicial, &mesinicial, &anoinicial);
    	sscanf(datafinal, "%d/%d/%d", &diafinal, &mesfinal, &anofinal);

    	// Capturando Valores da Data Inicial

    for (i = 0; datainicial[i] != '/'; i++)
        sDia[i] = datainicial[i];

    sDia[i] = '\0';
    i++;

    for (j = i, contM = 0; datainicial[j] != '/'; j++, contM++)
        sMes[contM] = datainicial[j];

    sMes[j] = '\0';
    j++;

    for (i = j, contA = 0; i < strlen(datainicial); i++, contA++)
       sAno[contA] = datainicial[i];

    sAno[contA] = '\0';

   // Convertendo String em Inteiro
    diainicial = atoi(sDia);
    mesinicial = atoi(sMes);
    anoinicial = atoi(sAno);

    // Capturando Valores da Data Final

    for (i = 0; datafinal[i] != '/'; i++)
        sDia[i] = datafinal[i];

    sDia[i] = '\0';
    i++;
    for (j = i, contM = 0; datafinal[j] != '/'; j++, contM++)
        sMes[contM] = datafinal[j];

    sMes[j] = '\0';
    j++;

    for (i = j, contA = 0; i < strlen(datafinal); i++, contA++)
       sAno[contA] = datafinal[i];

    sAno[contA] = '\0';

    // Convertendo String em Inteiro
    diafinal = atoi(sDia);
    mesfinal = atoi(sMes);
    anofinal = atoi(sAno);

    nDias = diafinal - diainicial;
    nMeses = mesfinal - mesinicial;
    nAnos = anofinal - anoinicial;

        if (nAnos<0) retorno=4;
        else if (nMeses<0 && nAnos<1) retorno=4;
        else if (nDias<0 && nMeses<1 && nAnos<1) retorno=4;
        if(nDias<0){
            nDias+=30;
            nMeses--;

        }
        if(nMeses<0) {
            nMeses+=12;
            nAnos--;

			 return 0;
        }
     /*mantenha o código abaixo, para salvar os dados em
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */

int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = 0;
    int i;

    for(i=0; texto[i]!='\0'; i++){
        if(isCaseSensitive==1){
            if(texto[i]== c)
                qtdOcorrencias++;
        }else if(isCaseSensitive!=1){
            if(texto[i]== c || texto[i]== c+32 || texto[i]==c-32)
                qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */

int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = 0;
    int i, j, p=0;

    for(i=0; strTexto[i]!='\0'; i++){
        int j=0, ini;
        if(strTexto[i] == strBusca[j])
        ini = i+1;
        while(strTexto[i+1] == strBusca[j+1] && strBusca[j+1]!='\0'){
        i++;
        j++;
}
if(strBusca[j+1]=='\0'){
posicoes[p] = ini;
p++;
posicoes[p] = i+1;
p++;
qtdOcorrencias++;
}
    }

    return qtdOcorrencias;
}


/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){

    int num_invertido=num%10;
    num/=10;

    while(num>0){
        num_invertido*=10;
        num_invertido+=num%10;
        num/=10;
    }
    return num_invertido;
}


/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */


int q6(int numerobase, int numerobusca){
    int qtdOcorrencias, qtd, aux;

for(aux=numerobusca, qtd = 0;aux>0; aux/=10)
qtd++;

    qtd = pow(10,qtd);

    while (numerobase>0){
aux=numerobase%qtd;
numerobase=numerobase/10;
if (numerobusca==aux)
qtdOcorrencias++;
    }

    return qtdOcorrencias;
}
