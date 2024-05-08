#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar daas string

int registro()//Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40]; //char variável que representa do tipo texto
    char cpf[40];//char variável que representa do tipo texto
    char nome[40];//char variável que representa do tipo texto
	char sobrenome[40]; //char variável que representa do tipo texto
    char cargo[40];//char variável que representa do tipo texto
	//final criação de variáveis/string
	
    printf("Digite o CPF a ser cadastrado: "); //coletando informções dos usuários
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf);//Responsavel por copiar os valores da string
    
	FILE *file;//Cria o arquivo
    file =  fopen(arquivo, "w");//Cria o arquivo  e o "w" siguinifica escrever
    fprintf(file,cpf); //Salvo o valor da variável
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");//busca o arquivo "a" abre o arquivo
    fprintf(file,",");//salva o valor da variável
    fclose(file);//fecha o arquivo
    
    
    printf("Digite o nome a ser cadastrado: ");//coletando inforções do usuário
    scanf("%s",nome);//%s referese-se a string
    
    file = fopen(arquivo, "a");//busca o arquivo "a" abre o arquivo
    fprintf(file, nome);//salva o valor da variável
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a"); //busca o arquivo "a" abre o arquivo
    fprintf(file,","); //salva o valor da variável
    fclose(file);//fecha o arquivo
    
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//busca o arquivo "a" abre o arquivo
	fprintf(file,sobrenome); //salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//busca o arquivo "a" abre o arquivo
    fprintf(file,",");//salva o valor da variável
    fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a" );//busca o arquivo "a" abre o arquivo
	fprintf(file,cargo);//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	system("pause");//faz uma pausa tela
   
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
     char cpf[40];//char variável que representa do tipo texto
     char conteudo[200];//char variável que representa do tipo texto
     
     printf("Digite o CPF a ser consultado: ");//coletando informações da variável
     scanf("%s",cpf);//%s responsavel pela string
     
     FILE *file;//cria o arquivo
     file = fopen(cpf,"r");//abre o arquivo "r" abre o arquivo no modo leitura 
     
     if(file == NULL) //não existe a informação pesquisada
     {
     	printf ("Não foi possivel abrir o arquivo, não localizado!.\n");//passando a informação para a variável
     }
     
     while(fgets(conteudo, 200, file) != NULL) // ler o caracteres de um arquivo 
     {
     	printf("\nEssas são as informações do usuário: ");//mostrando as isnformações ao usuário
     	printf("%s", conteudo);//%s responsável pela string, mostrando o resultado do conteúdo
     	printf("\n\n");// "\n\n" pular linhas
	 }
     
       system("pause"); //uma pausa na tela para o usuário poder ler 


}

int deletar()
{
       char cpf[40];//char variável que representa do tipo texto 
      
       printf("Digite o CPF do usuário a ser deletado: ");//coletando informaão do usuário
       scanf("%s",cpf);//%s responsável pela string, pedindo para digitar o usuário a ser deletado
      
       remove(cpf);//função de delete rapido
       
       FILE *file;//cria um arquivo
       file = fopen(cpf,"r");//abreo o arquivo "r" função leitura
       
       if(file == NULL) //não existe o arquivo 
       {
       
	   	printf("O usuário não se encontra no sistema!. \n");//passa informção ao usuário
       
	   	system("pause");//uma pausa na tela
	   
	   }
      
}



int main ()
{
  	   int opcao=0; //Definindo as variáves
  	   int laco=1; //varável de repetição
  	    
    	for(laco=1;laco=1;)//torna possivel repetção 
    {

       system ("cls"); //responsavel por limpar a tela
				  
  	    setlocale(LC_ALL, "Portuguese"); //Definindo as linguagens
  	   
  	    printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
        printf("Escolha a opção desejada do menu:\n\n"); //informação ao usuário
        printf("\t1 - Registrar nomes\n");//informação ao usuário
        printf("\t2 - Consultar nomes\n");//informação ao usuário
        printf("\t3 - Deletar nomes\n\n"); //informação ao usuário
	    printf("Opção: "); //Fim do menu
		
  	    scanf("%d", &opcao); //comando para scaniar o que o usuario coloca, armazenando a escolha do usuario.
  	    
  	    system("cls"); //responsavel por limpar a tela
  	    
  	    switch(opcao) //inicio da seleção do menu 
      {
  	    case 1:
  	   	registro (); //chamada de funções
  	   	break;//volta ao inicio  
  	   	  
  	    case 2:
  	    consulta();//chamada de funcões
  	   	break;//volta ao inicio
  	   	  
  	   	case 3:
        deletar(); //chamada de funções
  	   	break;//volta ao inicio
  	   	
  	   	  
  	   	default:
  	   	printf("Essa opção não está disponivel!\n");//informação ao usuário 
  	   	system("pause");//uma pausa na tela 
  	   	break;//volta ao inicio
	   }
  	    
    }
}
