#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar daas string

int registro()//Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40]; //char vari�vel que representa do tipo texto
    char cpf[40];//char vari�vel que representa do tipo texto
    char nome[40];//char vari�vel que representa do tipo texto
	char sobrenome[40]; //char vari�vel que representa do tipo texto
    char cargo[40];//char vari�vel que representa do tipo texto
	//final cria��o de vari�veis/string
	
    printf("Digite o CPF a ser cadastrado: "); //coletando inform��es dos usu�rios
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf);//Responsavel por copiar os valores da string
    
	FILE *file;//Cria o arquivo
    file =  fopen(arquivo, "w");//Cria o arquivo  e o "w" siguinifica escrever
    fprintf(file,cpf); //Salvo o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");//busca o arquivo "a" abre o arquivo
    fprintf(file,",");//salva o valor da vari�vel
    fclose(file);//fecha o arquivo
    
    
    printf("Digite o nome a ser cadastrado: ");//coletando infor��es do usu�rio
    scanf("%s",nome);//%s referese-se a string
    
    file = fopen(arquivo, "a");//busca o arquivo "a" abre o arquivo
    fprintf(file, nome);//salva o valor da vari�vel
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a"); //busca o arquivo "a" abre o arquivo
    fprintf(file,","); //salva o valor da vari�vel
    fclose(file);//fecha o arquivo
    
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//busca o arquivo "a" abre o arquivo
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//busca o arquivo "a" abre o arquivo
    fprintf(file,",");//salva o valor da vari�vel
    fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a" );//busca o arquivo "a" abre o arquivo
	fprintf(file,cargo);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	system("pause");//faz uma pausa tela
   
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
     char cpf[40];//char vari�vel que representa do tipo texto
     char conteudo[200];//char vari�vel que representa do tipo texto
     
     printf("Digite o CPF a ser consultado: ");//coletando informa��es da vari�vel
     scanf("%s",cpf);//%s responsavel pela string
     
     FILE *file;//cria o arquivo
     file = fopen(cpf,"r");//abre o arquivo "r" abre o arquivo no modo leitura 
     
     if(file == NULL) //n�o existe a informa��o pesquisada
     {
     	printf ("N�o foi possivel abrir o arquivo, n�o localizado!.\n");//passando a informa��o para a vari�vel
     }
     
     while(fgets(conteudo, 200, file) != NULL) // ler o caracteres de um arquivo 
     {
     	printf("\nEssas s�o as informa��es do usu�rio: ");//mostrando as isnforma��es ao usu�rio
     	printf("%s", conteudo);//%s respons�vel pela string, mostrando o resultado do conte�do
     	printf("\n\n");// "\n\n" pular linhas
	 }
     
       system("pause"); //uma pausa na tela para o usu�rio poder ler 


}

int deletar()
{
       char cpf[40];//char vari�vel que representa do tipo texto 
      
       printf("Digite o CPF do usu�rio a ser deletado: ");//coletando informa�o do usu�rio
       scanf("%s",cpf);//%s respons�vel pela string, pedindo para digitar o usu�rio a ser deletado
      
       remove(cpf);//fun��o de delete rapido
       
       FILE *file;//cria um arquivo
       file = fopen(cpf,"r");//abreo o arquivo "r" fun��o leitura
       
       if(file == NULL) //n�o existe o arquivo 
       {
       
	   	printf("O usu�rio n�o se encontra no sistema!. \n");//passa inform��o ao usu�rio
       
	   	system("pause");//uma pausa na tela
	   
	   }
      
}



int main ()
{
  	   int opcao=0; //Definindo as vari�ves
  	   int laco=1; //var�vel de repeti��o
  	   char senhadigitada[]="a";
  	   int comparacao;
  	   
  	   printf("###Cart�rio da Ebac ###\n\n");
  	   printf("Login de administrador!\n\nDigite a sua senha:");
  	   scanf("%s",senhadigitada);
  	   
  	   comparacao = strcmp(senhadigitada, "admin");
  	   
  	   if(comparacao == 0)
       {
		system ("cls");
    	for(laco=1;laco=1;)//torna possivel repet��o 
      {

       system ("cls"); //responsavel por limpar a tela
				  
  	    setlocale(LC_ALL, "Portuguese"); //Definindo as linguagens
  	   
  	    printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
        printf("Escolha a op��o desejada do menu:\n\n"); //informa��o ao usu�rio
        printf("\t1 - Registrar nomes\n");//informa��o ao usu�rio
        printf("\t2 - Consultar nomes\n");//informa��o ao usu�rio
        printf("\t3 - Deletar nomes\n\n"); //informa��o ao usu�rio
	    printf("\t4 - Sair do sistema\n\n");//para sair do sistema
		printf("Op��o: "); //Fim do menu
		
  	    scanf("%d", &opcao); //comando para scaniar o que o usuario coloca, armazenando a escolha do usuario.
  	    
  	    system("cls"); //responsavel por limpar a tela
  	    
  	    switch(opcao) //inicio da sele��o do menu 
      {
  	    case 1:
  	   	registro (); //chamada de fun��es
  	   	break;//volta ao inicio  
  	   	  
  	    case 2:
  	    consulta();//chamada de func�es
  	   	break;//volta ao inicio
  	   	  
  	   	case 3:
        deletar(); //chamada de fun��es
  	   	break;//volta ao inicio
  	   	
  	   	case 4:
  	   	printf("obrigado por utilizar o sistema!\n");//passa a informa��o ao usu�rio
  	   	return 0;//fecha o sistema 
  	   	break;//volta ai inicio 
  	   	
  	   	  
  	   	default:
  	   	printf("Essa op��o n�o est� disponivel!\n");//informa��o ao usu�rio 
  	   	system("pause");//uma pausa na tela 
  	   	break;//volta ao inicio
	   }
  	    
   
     } 
  }
  
   else 
       printf("Senha incoreta!");
}
