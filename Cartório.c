#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos string

 int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
 {
 	//inicio de cria��o de vari�veis/srintg
 	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando informa��o do usu�rio
	scanf("%s", cpf); // ''%s'' Refere-se as strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo e o ''w'' significa escrever
	fprintf(file,cpf); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo
	fprintf(file, ","); //Salvar o valor da vari�vel
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
   setlocale(LC_ALL, "Portuguese"); //Definindo o idioma da regi�o
   char cpf[40];
   char conteudo[200];

   printf("Digite o CPF para ser consultado:");
   scanf("%s",cpf);
   

    FILE *file;
    file = fopen(cpf,"r");
   
    if(file == NULL)
    {
      printf("Arquivo n�o localizado, insira os dados corretamente e fa�a uma nova consulta.\n\n");
	}
	
    while(fgets(conteudo, 200, file) != NULL)
   {
   	     printf("\nInforma��es obtidas do usu�rio: ");
   	     printf("%s", conteudo);
     	 printf("\n\n");
   }
    fclose(file);
	system("pause");
	
 }

 int deletar()
 {
   char cpf[40];
   
   printf("Digite o CPF do usu�rio a qual voc� deseja deletar: ");
   scanf("%s",cpf);// ''%s" � por causa das strings
   
   remove(cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   fclose(file);
   
   if(file == NULL)
    {
   	  printf("\nO usu�rio n�o foi identificado no sistema!\n\n");
      system("pause");
    }
 }

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
    	system("cls"); //� responsavel por limpar a tela
    	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
        printf("~~~ Cart�rio da EBAC ~~~\n\n"); //In�cio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
     	printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
     	printf("Op��o: ");//Fim do menu
	
    	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls"); //Respos�vel por limpar a tela
	    
	        switch(opcao) //Inicio da sele��o do menu
	        {
	         case 1: //Chamada de fun��es
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
	         printf("Essa op��o n�o est� dispon�vel!\n");
	         printf("Tente novamente escolhendo as op��es dispon�veis, obrigado!\n");
	         system("pause");
	         break;//Serve para fechar o comando 
         	}//Fim da sele��o
    }
}
