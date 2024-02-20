#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaco em  memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro()  //Função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e "W" significa escrever
	fprintf(file, "\nCPF: ");
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" é de atualização
	fprintf(file, ", \nNome: "); //inclui a "," entre os dados digitados
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //é frase que aparecerá para o usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" é de atualização
	fprintf(file, nome); // neste caso está salvando o nome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" é de atualização
	fprintf(file, ", \nSobrenome: "); //inclui a "," entre os dados digitados
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //é frase que aparecerá para o usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo e o "a" é de atualização
	fprintf(file, sobrenome); // neste caso está salvando o sobrenome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e o "a" é de atualização
	fprintf(file, ", \nCargo: "); //inclui a "," entre os dados digitados
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //é frase que aparecerá para o usuário
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" é de atualização
	fprintf(file, cargo); // neste caso está salvando o cargo no arquivo
	fprintf(file, "\n\n");
	fclose(file); //fecha o arquivo
		
	system("pause"); // Pausa entre uma função e outra
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n"); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	printf("\n");
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //consulta o arquivo e "R" significa ler
	
	if(file == NULL) //condicional se caso não encontrar a opção digitada
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n");	
	}

	printf("\nEssas são as informações do usuário: \n");


	while(fgets(conteudo, 200, file) != NULL) //função para busca // while - enquanto
	{
	
		printf("%s", conteudo);

	}
	fclose(file);
	system("pause"); // Pausa entre uma função e outra
	
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF do usuário a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("O usuário não se encontra no sistema!.\n");
			system("pause");
		}
		
		fclose(file);
}


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[10]="a"; //string
	int comparacao;
	
	printf("### Cartório da EBAC ###");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //compara senha
	
	if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)
		
		{
			
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf ("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do Sistema\n"); 
			printf("Opção: "); //fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usuário
	
			system("cls"); //responsável por limpar a tela
		
			switch(opcao) //in[icio da seleção do menu
			{
				case 1:
				registro(); //chamada de funções
				break; //informa quando acaba o case
			
				case 2:
				consultar();//chamada de funções
				break; //informa quando acaba o case
			
				case 3:
				deletar();//chamada de funções
				break; //informa quando acaba o case
			
				case 4:
				printf ("Obrigado por utilizar o sistema!\n");
				return 0; //para sair do sistema
				break;
		
			
				default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break; //informa quando acaba o case
			}//fim da seleção
		}
    }
	
	else
		printf("Senha incorreta");
			
}
