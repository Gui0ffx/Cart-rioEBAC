#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

 int registro() //fun��o reespons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //final da cria��o de vari�veis/strings
	
	printf("Digite o CPF para cadastro: "); //coleta de dados do usu�rio
	scanf("%s", cpf); //%s = refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo "a" significa
	fprintf(file,","); //salva o valor da variavel
	fclose(file);
	
	printf("Digite o nome para cadastro: "); //Adiciona nome para cadastro
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");  //abre o arquivo "a"
	fprintf(file,nome); //adiciona uma variavel
	fclose(file); //fecha 
	
	file = fopen(arquivo, "a"); //abre o arquivo "a"
	fprintf(file,","); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome para cadastro: "); //adiciona sobrenome para cadastro
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo "a"
	fprintf(file,sobrenome); //adiciona uma variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre a arquivo "a"
	fprintf(file,","); //salva a avariavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //adiciona o cargo a ser cadastrado
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //abre a variavel "a"
	fprintf(file,cargo); //adiciona uma variavel
	fclose(file); //fecha o arquivo
	
    system("pause");

	
}

int consulta() //consulta os cadastros j� feitos
{
	
	setlocale(LC_ALL, "Portuguese"); //Defini��o de linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //pede para o cliente escrever o cpf que deseja consultar
	scanf("%s" ,cpf); 
	
	FILE * file; 
	file = fopen(cpf, "r"); //abre e procura no arquivo o cpf digitado para pesquisa
	
	if(file == NULL)
	{
		 printf("CPF n�o localizado!.\n"); //mensagem para cpf n�o encontrado no banco de dados
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		 printf("\nEssas s�o as informa��es encontradas: "); //mensagem para quando encontra um cpf e em seguida � fornecido as inform��es do cadastro ao cliente
		 printf("%s" ,conteudo);
		 printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //deleta o cadastro da escolha do cliente
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s" ,cpf);
	
	remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("Usu�rio n�o encontrado!. \n");
    	system("pause");
	}
	
	else if(file != NULL)
	{
		printf("usu�rio deletado com sucesso!. \n");
		system("pause");
		
		remove(cpf);
	}
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
	
     system("cls"); //respons�vel por limpar a tela
     
     switch(opcao) //inicio da sele��o do menu
     {
     case 1:
     registro(); //chamada de fun��es
	 break;
	 
	 case 2:
	 consulta();
     break;
     
     case 3:
     deletar();
     break;
     
     case 4:
     printf("obrigado por usar o sistema!\n");
     return 0;
     break;
     
       
     default:
     printf("Op��o inexistente\n");
     system("pause");
     break;
     	
	 } //fim da pesquisa
    
    
    
  }
  
}
