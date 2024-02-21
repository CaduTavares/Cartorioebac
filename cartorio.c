#include <stdio.h> //biblioteca responsavel de comunica��o de usuario 
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de textp por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar usu�rios
{
	// inicio da cria��o de vari�rios / strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
		// final  da cria��o de vari�rios / strings
	
	printf("Digite o CPF a ser cadastrado: "); // cpletando informa��o de usu�rio
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // Criar arquivo
	file = fopen(arquivo, "w"); // Criar o nome do  arquivo
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf( "Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // definindo linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo. Arquivo n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	 
}

int deletar()
{
	char cpf[40];

	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf(" %s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
    
	if(file == NULL)
	{
		printf("O usu�rio foi deletado com sucesso.\n");
		system("pause");
	} 



}
int main()
{
	int opcao = 0; // definindo vari�vel
	int laco = 1;
	
	for(laco = 1; laco = 1;)
	{
	    
	    
		setlocale(LC_ALL, "Portuguese"); // definindo linguagem
    
		system("cls"); //Limpar a mensagem da tela anterior antes de reexibir o menu
	
		printf("##### Cart�rio da EBAC #####\n\n"); // inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); // final do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usuario
	
		system("cls"); // limpar a tela ap�s a escolha para evitar polui��o visual para  o usu�rio
		
		switch (opcao)
		{	
			case 1:
			registro();
			break;
		
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Esta op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
		
			// final da sele��o
		}
	
	} 
	
}

