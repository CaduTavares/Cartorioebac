#include <stdio.h> //biblioteca responsavel de comunicação de usuario 
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de textp por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar usuários
{
	// inicio da criação de variários / strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
		// final  da criação de variários / strings
	
	printf("Digite o CPF a ser cadastrado: "); // cpletando informação de usuário
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
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
		printf("Não foi possível abrir o arquivo. Arquivo não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	 
}

int deletar()
{
	char cpf[40];

	printf("Digite o CPF do usuário a ser deletado:");
	scanf(" %s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
    
	if(file == NULL)
	{
		printf("O usuário foi deletado com sucesso.\n");
		system("pause");
	} 



}
int main()
{
	int opcao = 0; // definindo variável
	int laco = 1;
	
	for(laco = 1; laco = 1;)
	{
	    
	    
		setlocale(LC_ALL, "Portuguese"); // definindo linguagem
    
		system("cls"); //Limpar a mensagem da tela anterior antes de reexibir o menu
	
		printf("##### Cartório da EBAC #####\n\n"); // inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); // final do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usuario
	
		system("cls"); // limpar a tela após a escolha para evitar poluição visual para  o usuário
		
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
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
			
		
			// final da seleção
		}
	
	} 
	
}

