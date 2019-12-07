#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

/* 
	-Autor: Raul Andrade de Oliveira Fernandes
	-Curso: Sistemas de Informação
	-2° Semestre
	-Instituição: Centro Universiário e Faculdade Projeção
	
	-Algoritmo para reserva de uma fileira de cadeiras do cinema.
*/

void umdez( int *op ); //Função com passagem por referência para que o valor da variável 'op' seja alterado na main

void umdez( int *op )
{
	while( *op <= 0 || *op > 10 )  //while utilizado para que o usuário selecione apenas as opções disponíveis(1 a 10)
	{
		printf( "APENAS NÚMEROS ENTRE 1 E 10: " );
		scanf( "%d", &*op );
	}
}

main() {
	setlocale( LC_ALL, "Portuguese" );
	
	int i;
	int op;
	int vet[10] = { };
	int vet2[10] = { };
	int cont = 0;
	
	char resp;
	
	do
	{	
		puts( "==============================" );
		puts( "FILEIRA LETRA 'B' SELECIONADA!" );
		puts( "==============================" );
		
		//Imprime as posições das cadeiras
		
		puts( "----------------------------------------------------" );
		
		for( i = 0;i < 10; i++ )
		{
			if( vet2[i] == vet[i] )
			{
				printf ( " [B%d]", i + 1 );	
			}
			else
			{
				printf( " [--]" );
			}
		}
		putchar( '\n' );
		
		puts( "----------------------------------------------------" );
		
		putchar( '\n' );
		
		if( cont == 10 ) //if utilizado para caso o cont seja igual a 10, isso significa que as 10 cadeiras foram reservadas
		{
			puts( "TODAS AS CADEIRAS FORAM RESERVADAS." );
			puts( "SAINDO..." );
			exit( 0 );
		}
		
		//Usuário seleciona posições("cadeiras")
		
		printf( "INFORME O NÚMERO DA CADEIRA: B" );
		scanf( "%d", &op );
		
		umdez( &op );
		
		for( i = 0;i < 10;i++ ) //O for irá percorrer o vetor e o while irá comparar todas as posições com a opção que o usuário digitou
		{
			while( op == vet2[i] )
			{
				puts( "ESTA CADEIRA JÁ FOI ESCOLHIDA!" );
				puts( "------------------------------" );
				printf( "INFORME OUTRA CADEIRA: B" );
				scanf( "%d", &op );
				
				umdez( &op );
				
				i = -1; //Esta atribuição serve para fazer com que o for percorra o vetor desde o início para comparar novamente a opção com todos os índices
			}
		}
		
		vet2[op - 1] = op; //Esta atribuição servirá para colocar a opção do usuário dentro do seu respectivo índice de vetor.(Ex: op = 1 então vet2[0] = 1;)
		
		printf( "CADEIRA B%d RESERVADA.\n", op );
		puts( "--------------------------------" );
		
		//Opção para o usuário selecionar outra ou não
		
		printf( "QUER RESERVAR OUTRA? [S/N]: " );
		scanf( " %c", &resp );
		resp = toupper( resp );
		
		while( resp != 'S' && resp != 'N' ) //while utilizado para restringir o usuário a digitar apenas 'S' ou 'N'
		{
			printf( "APENAS 'S' OU 'N': " );
			scanf( " %c", &resp );
			resp = toupper( resp );
		}
		cont++; //Esse contador vai ser utilizado para contar quantas cadeiras foram reservadas
		system( "cls" );
		
	}while( resp != 'N' && resp == 'S' );
	
	puts( "--------------------------------" );
	puts( "BOM FILME!" );
	printf( "SAINDO..." );
	
}
