#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //lib validacao
#include <string.h>
#include <locale.h> //acentuacao

int N, x, cont=0;
float sal_bruto, soma,soma2,soma3;
int op,mes,ano;
float ref2,sal,hor_extra,hor2;
float inss,liquido;
int xx;

int main(int argc, char *argv[])
{
	static int linha;
	do{
		setlocale(LC_ALL, "Portuguese"); //acentuacao

		int tipo,hor,numero,ref,jor;
		float media;
		char nome,NUMERO;


		printf("Empresas Master Kalote S/A\n");
		printf("Emissao da Folha de Pagamento\n ");
		printf("----------------------------------------\n");
		printf("Por favor, entre com os dados iniciais:\n\n");

		//1
		//ANO ------------------------------------------------------------------------
		printf("Ano de Referencia [2010 a 2099]:\n", ano);
		fflush(stdin);
		tipo = scanf("%d", &ano);    						//validacao
		if(tipo == 0) {
			printf("tipo de dado incorreto");
		}
        else {
	    //printf("tipo de dado correto - numérico");
	    	if( ano >= 2010 &&  ano <= 2099){
			//printf("- OK \n");
			}
			else{
			printf ("\nporem c/ valor invalido\n\n");
			//printf("numero: %4d",ano);
			exit(0);
			}
		}

    
		//MES------------------------------------------------------------------------
		//2
		printf("\nMês de Referencia [1 a 12]:\n", mes);
		//scanf("%d",&mes);
		fflush(stdin);
		tipo = scanf("%d", &mes);    						//validacao
		if(tipo == 0) {
			printf("tipo de dado incorreto");
		}
        else {
	   //printf("tipo de dado correto - numérico");
	   		if( mes >= 1 &&  mes <= 12){
			//printf("- OK \n");
			}
		else{
			printf ("\nporem c/ valor invalido\n\n");
			exit(0);
		}
	}

		printf("Serão emitidos os contracheques referentes a %d/%d", mes,ano);
		printf("\n-----------------------------------------------------------");
		printf("\nPor favor, entre com os dados do funcionário:\n\n");
		//3
		//NUMERO------------------------------------------------------------------------
		printf("\nDigite o Número do Funcionário [1000 a 9999]:\n", numero);
		fflush(stdin);
		tipo = scanf("%d", &numero);    						//validacao
		if(tipo == 0) {
		printf("tipo de dado incorreto");
		}
        else {
	   //printf("tipo de dado correto - numérico");
	    	if( numero >= 1000 &&  numero <= 9999){
			//printf("- OK \n");
			}
		else{
			printf ("\nporem c/ valor invalido\n\n");
			exit(0);
		}
	}

		//validacao palavra
		void alfabetico(char variavel);
		char palavra[40];
		printf("\nDigite o nome do funcionário como consta no RG: [5 a 40 caracteres]\n ");
		gets(palavra);
		scanf("%[^\n]", palavra);

		int i = 0;
		while(palavra[i] != '\0'){
			alfabetico(palavra[i]);
			//printf("%c", palavra[i]);
			++i;
			if (palavra[5] == NULL ){      //2 validacao anti Buffer Overflow
				printf ("\nPorém o mínimo requerido do campo não foi atingido\n\n");
    		}
    		else{
    			//printf("%s ", palavra);
			}
		}





		printf("\nReferência: 1 ou 2 ou 4 ou 6 ou 8 ou 9 :\n", ref);
		fflush(stdin);
		tipo = scanf("%d", &ref);    						//validacao
		if(tipo == 0) {
			printf("tipo de dado incorreto");
		}
       	else {
	   		//printf("tipo de dado correto - numérico");
	   		if( ref == 1 ||  ref ==2 || ref ==4 || ref==6 || ref ==8 || ref ==9){
			//printf("- OK \n");
		}
		else{
			printf ("\nporem c/ valor invalido\n\n");
			exit(0);
		}
	}


		printf("\nJornada Semanal: [16 a 44] :\n", jor);
		fflush(stdin);
		tipo = scanf("%d", &jor);    						//validacao
		if(tipo == 0) {
			printf("tipo de dado incorreto");
		}
        else {
	   		//printf("tipo de dado correto - numérico");
	   		if( jor >=16 && jor <=44){
			//printf("- OK \n");
			}
		else{
			printf ("\nporem c/ valor invalido\n\n");
			exit(0);
		}
	}


		printf("\nHoras-Extras: [0 ou 16 a 44] :\n", hor);
		fflush(stdin);
		tipo = scanf("%d", &hor);    						//validacao
		if(tipo == 0) {
			printf("tipo de dado incorreto");
		}
       else {
	   //printf("tipo de dado correto - numérico");
	   if( hor == 0 || hor >=16 || hor <=44){
			//printf("- OK \n");
			//printf("\nhorasss:  %d", hor);
		}
		else{
			printf ("\nporem c/ valor invalido\n\n");
			exit(0);
		}
	}


		printf("\nO contracheque do Funcionário %d será emitido a seguir.\n");


		//-------------------------------------------------------------
		//CALCULO Salario BASE-1

		printf("referencia %d",ref);
		if( ref == 1 ){
			ref2 = 3.9;
		}
		else if( ref == 2 ){
			ref2 = 5.4;
		}
		else if( ref == 4 ){
			ref2 = 6.3;
		}
		else if( ref == 6 ){
			ref2 = 9.9;
		}
		else if( ref == 8 ){
			ref2 = 13.5;
		}
		else if( ref == 9 ){
			ref2 = 18.5;
		}

		sal= ref2*jor;

		//printf("\nRemuneração Semanal do empregado: %f", sal);
		//printf("\nRemuneração Salário Base Mensal do empregado: %f", sal*4.5);

		//-------------------------------------------------------------
		//CALCULO HORAS EXTRAS-2
		//-------------------------------------------------------------
		printf("\nhorasss:  %d", hor);
		hor_extra = ref2*1.5;
		//printf ("\nvalor da hora extra trabalhada %f", hor_extra);
		hor2 = hor_extra*hor;
		//printf ("\nValor das horas extras Trabalhadas %f", hor2);

		//CALCULO SALARIO-BRUTO-3
		//-------------------------------------------------------------
		float sal_bruto = (sal*4.5)+hor2; 
		printf ("\nValor do Salário Bruto %f", sal_bruto);
		soma += sal_bruto;                                   //incremental rel_final
		//printf("hhhhhh %f", soma);

		//DESCONTO-INSS_E_SALARIO_LIQUIDO = 4 e 5
		//-------------------------------------------------------------

		//printf("referencia %d",ref);
		if( sal_bruto <= 1000 ){
			xx =8;	
			inss = (sal_bruto*8)/100;
			liquido = (sal_bruto*92)/100;
			printf("\nDesconto de 8% = %f", inss);
			soma2 += inss;
			printf("\nSalário Líquido no valor de: %f", liquido);
			soma3 += liquido;
		}
		else if( sal_bruto > 1000 || sal_bruto <= 1300 ){
			xx=9;
			inss = (sal_bruto*9)/100;
			liquido = (sal_bruto*91)/100;
			printf("\nDesconto de 9% = %f", inss);
			soma2 += inss;
			printf("\nSalário Líquido no valor de: %f\n", liquido);
			soma3 += liquido;
		}
		else if( sal_bruto > 1300 ){
		inss = (sal_bruto*11)/100;
		xx=11;
		liquido = (sal_bruto*89)/100;
		printf("\nDesconto de 11% = %f", inss);
		soma2 += inss;
		printf("\nSalário Líquido no valor de: %f \n", liquido);
		soma3 += liquido;
		}

		//SAIDA
		printf("\n\n\n*--------------------------------------------------------------------*");
		printf("\n* EMPRESAS KALOTE MASTER S/A      CNPJ 01.171.171/0001-71          *");
		printf("\n*------------------------------------------------------------------*");
		printf("\n* NOME: %s     NUMERO: %d                     *", palavra, numero);
		printf("\n* REFERENCIA: %d   JORNADA: %d       %d/%d                        *",ref, jor,mes,ano);
		printf("\n*--------------------------------------------------------------------*");
		printf("\n* DESCRICAO           QUANT *           PROVENTOS*            DESCONTOS*");
		printf("\n*--------------------------------------------------------------------*");
		printf("\n* SALARIO BASE              *               %f            *       ",sal*4.5);
		printf("\n* VALOR HORAS-EXTRAS        %d *            %f   			*",hor,hor2);
		printf("\n* CONTRIBICAO INSS          %d *            %f   			*",xx,inss);
		printf("\n* SALARIO BRUTO             *               %f            *",sal_bruto);
		printf("\n*--------------------------------------------------------------------*");
		printf("\n* SALARIO LIQUIDO           *               %f            *",liquido);
		printf("\n*--------------------------------------------------------------------*");

		printf("\nDigite 1 para adicionar mais valores ou\n");
		printf("\nDigite outro valor para gerar relatório final\n");
		scanf("%d", &op);
		linha++;
		}while(op==1);
	
		printf("\n\n\n*--------------------------------------------------------------------*");
		printf("\n* EMPRESAS KALOTE MASTER S/A      CNPJ 01.171.171/0001-71          *");
		printf("\n*------------------------------------------------------------------*");
		printf("\n* RELATORIO FINAL DA FOLHA DE PAGAMENTO      %d / %d",mes,ano);
		printf("\n*------------------------------------------------------------------*");
		printf("\nTOTAL DE FUNCIONÁRIOS: %d", linha);
		printf("\n TOTAL DE VALORES DE SALARIO BRUTO    : R$ %f", soma);
		printf("\n TOTAL DE VALORES DE DESCONTOS        : R$ %f", soma2);
		printf("\n TOTAL DE VALORES DE SALARIO LIQUIDO  : R$ %f", soma3);
		printf("\n MEDIA SALARIAL DA EMPRESA            : R$ %f\n\n", soma/linha);    //media slarial bruta/pela qtd de pessoas


system("pause");//pausa da tela somente para Windows
return 0;//retorno da função main  





}



//validacao palavra
void alfabetico(char variavel){
	if((variavel >= 'a' && variavel <= 'z') || (variavel >= 'A' && variavel <= 'Z') ||  (variavel == '-' ) ||  (variavel == '\'' ) || (variavel == '\b' ) || (variavel =! '\0' ) ){
	   //printf("%c", variavel);
	}
	 else {
	   printf("tipo de dado incorreto\n");
	}
}
