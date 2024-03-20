 #include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

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
	
	setlocale(LC_ALL, "Portuguese"); //Defini��o de linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s" ,cpf);
	
	FILE * file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		 printf("CPF n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		 printf("\nEssas s�o as informa��es encontradas: ");
		 printf("%s" ,conteudo);
		 printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	printf("Voc� escolheu deletar nomes\n");
	system("pause");
}


int main()
    {
	int opcao=0; //defini��o de vari�veis
	int lapis=1;
	
	for(lapis=1;lapis=1;)
    {	
     
     system("cls");
     
	 setlocale(LC_ALL, "Portuguese"); //Defini��o de linguagem
	
    	printf("=== Cart�rio da EBAC ===\n\n"); //inicio do menu
        printf("Escolha uma op��o do menu:\n\n");
    	printf("\t1 - Registro de nomes\n");
        printf("\t2 - Consulta de nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
        printf("Op��o: "); //fim do menu
	
	
     scanf("%d" , &opcao); //armazenamento do usu�rio
	
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
     printf("Op��o inexistente\n");
     system("pause");
     break;
     	
	 } //fim da pesquisa
    
    
    
  }
  
}
