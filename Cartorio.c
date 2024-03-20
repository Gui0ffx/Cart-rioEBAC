 #include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

 int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF para cadastro: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome para cadastro: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome para cadastro: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definição de linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s" ,cpf);
	
	FILE * file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		 printf("CPF não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		 printf("\nEssas são as informações encontradas: ");
		 printf("%s" ,conteudo);
		 printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	printf("Você escolheu deletar nomes\n");
	system("pause");
}


int main()
    {
	int opcao=0; //definição de variáveis
	int lapis=1;
	
	for(lapis=1;lapis=1;)
    {	
     
     system("cls");
     
	 setlocale(LC_ALL, "Portuguese"); //Definição de linguagem
	
    	printf("=== Cartório da EBAC ===\n\n"); //inicio do menu
        printf("Escolha uma opção do menu:\n\n");
    	printf("\t1 - Registro de nomes\n");
        printf("\t2 - Consulta de nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
        printf("Opção: "); //fim do menu
	
	
     scanf("%d" , &opcao); //armazenamento do usuário
	
     system("cls");
     
     switch(opcao)
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
     
     case 4:
     printf("Obrigado por utilizar o sistema!\n");
     return 0;
     break;
     
     default:
     printf("Opção inexistente\n");
     system("pause");
     break;
     	
	 } //fim da pesquisa
    
    
    
  }
  
}
