#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espaco em  mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro()  //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e "W" significa escrever
	fprintf(file, "\nCPF: ");
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" � de atualiza��o
	fprintf(file, ", \nNome: "); //inclui a "," entre os dados digitados
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //� frase que aparecer� para o usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" � de atualiza��o
	fprintf(file, nome); // neste caso est� salvando o nome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" � de atualiza��o
	fprintf(file, ", \nSobrenome: "); //inclui a "," entre os dados digitados
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //� frase que aparecer� para o usu�rio
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo e o "a" � de atualiza��o
	fprintf(file, sobrenome); // neste caso est� salvando o sobrenome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e o "a" � de atualiza��o
	fprintf(file, ", \nCargo: "); //inclui a "," entre os dados digitados
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //� frase que aparecer� para o usu�rio
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" � de atualiza��o
	fprintf(file, cargo); // neste caso est� salvando o cargo no arquivo
	fprintf(file, "\n\n");
	fclose(file); //fecha o arquivo
		
	system("pause"); // Pausa entre uma fun��o e outra
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n"); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	printf("\n");
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //consulta o arquivo e "R" significa ler
	
	if(file == NULL) //condicional se caso n�o encontrar a op��o digitada
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");	
	}

	printf("\nEssas s�o as informa��es do usu�rio: \n");


	while(fgets(conteudo, 200, file) != NULL) //fun��o para busca // while - enquanto
	{
	
		printf("%s", conteudo);

	}
	fclose(file);
	system("pause"); // Pausa entre uma fun��o e outra
	
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF do usu�rio a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("O usu�rio n�o se encontra no sistema!.\n");
			system("pause");
		}
		
		fclose(file);
}


int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a"; //string
	int comparacao;
	
	printf("### Cart�rio da EBAC ###");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //compara senha
	
	if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)
		
		{
			
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
			printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
			printf ("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do Sistema\n"); 
			printf("Op��o: "); //fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
			system("cls"); //respons�vel por limpar a tela
		
			switch(opcao) //in[icio da sele��o do menu
			{
				case 1:
				registro(); //chamada de fun��es
				break; //informa quando acaba o case
			
				case 2:
				consultar();//chamada de fun��es
				break; //informa quando acaba o case
			
				case 3:
				deletar();//chamada de fun��es
				break; //informa quando acaba o case
			
				case 4:
				printf ("Obrigado por utilizar o sistema!\n");
				return 0; //para sair do sistema
				break;
		
			
				default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break; //informa quando acaba o case
			}//fim da sele��o
		}
    }
	
	else
		printf("Senha incorreta");
			
}
