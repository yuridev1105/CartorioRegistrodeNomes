#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos string

 int registro() //Função responsável por cadastrar os usuários no sistema
 {
 	//inicio de criação de variáveis/srintg
 	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando informação do usuário
	scanf("%s", cpf); // ''%s'' Refere-se as strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo e o ''w'' significa escrever
	fprintf(file,cpf); //Salvo o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo
	fprintf(file, ","); //Salvar o valor da variável
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //Para pausar ou fixar o texto para o cliente ver.
 }

 int consulta()
 { 
   setlocale(LC_ALL, "Portuguese"); //Definindo o idioma da região
   char cpf[40];
   char conteudo[200];

   printf("Digite o CPF para ser consultado:");
   scanf("%s",cpf);
   

    FILE *file;
    file = fopen(cpf,"r");
   
    if(file == NULL)
    {
      printf("Arquivo não localizado, insira os dados corretamente e faça uma nova consulta.\n\n");
	}
	
    while(fgets(conteudo, 200, file) != NULL)
   {
   	     printf("\nInformações obtidas do usuário: ");
   	     printf("%s", conteudo);
     	 printf("\n\n");
   }
    fclose(file);
	system("pause");
	
 }

 int deletar()
 {
   char cpf[40];
   
   printf("Digite o CPF do usuário a qual você deseja deletar: ");
   scanf("%s",cpf);// ''%s" é por causa das strings
   
   remove(cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   fclose(file);
   
   if(file == NULL)
    {
   	  printf("\nO usuário não foi identificado no sistema!\n\n");
      system("pause");
    }
 }

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
    	system("cls"); //É responsavel por limpar a tela
    	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
        printf("~~~ Cartório da EBAC ~~~\n\n"); //Início do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
     	printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
     	printf("Opção: ");//Fim do menu
	
    	scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls"); //Resposável por limpar a tela
	    
	        switch(opcao) //Inicio da seleção do menu
	        {
	         case 1: //Chamada de funções
		     registro();
	         break;//Serve para fechar o comando 
	   	
	    	 case 2:
	         consulta();
	         break;//Serve para fechar o comando 
	    
	         case 3:
	         deletar();
	         break;//Serve para fechar o comando 
	        
	         case 4:
	         printf("Obrigado por utilizar o nosso sistema!\n");
	         return 0;
	         break;
	        
	         default:
	         printf("Essa opção não está disponível!\n");
	         printf("Tente novamente escolhendo as opções disponíveis, obrigado!\n");
	         system("pause");
	         break;//Serve para fechar o comando 
         	}//Fim da seleção
    }
}
