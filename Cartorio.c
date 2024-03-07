#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

 int registro() //função reesponsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //final da criação de variáveis/strings
	
	printf("Digite o CPF para cadastro: "); //coleta de dados do usuário
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

int consulta() //consulta os cadastros já feitos
{
	
	setlocale(LC_ALL, "Portuguese"); //Definição de linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //pede para o cliente escrever o cpf que deseja consultar
	scanf("%s" ,cpf); 
	
	FILE * file; 
	file = fopen(cpf, "r"); //abre e procura no arquivo o cpf digitado para pesquisa
	
	if(file == NULL)
	{
		 printf("CPF não localizado!.\n"); //mensagem para cpf não encontrado no banco de dados
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		 printf("\nEssas são as informações encontradas: "); //mensagem para quando encontra um cpf e em seguida é fornecido as informções do cadastro ao cliente
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
    	printf("Usuário não encontrado!. \n");
    	system("pause");
	}
	
	else if(file != NULL)
	{
		printf("usuário deletado com sucesso!. \n");
		system("pause");
		
		remove(cpf);
	}
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
	
     system("cls"); //responsável por limpar a tela
     
     switch(opcao) //inicio da seleção do menu
     {
     case 1:
     registro(); //chamada de funções
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
     printf("Opção inexistente\n");
     system("pause");
     break;
     	
	 } //fim da pesquisa
    
    
    
  }
  
}
