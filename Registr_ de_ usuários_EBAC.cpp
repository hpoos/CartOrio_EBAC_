#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //responsável por alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das stings


int registrar() //função de cadastro
{
	setlocale(LC_ALL, "Portuguese"); //selecionando a linguagem
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF do usuário a ser cadatrado: ");
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das stings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //W cria novo arquivo
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //A atualiza o arquivo W
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome do usuário a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome do usuário a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo do usuário a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}


int consultar() //função de consulta
{
	setlocale(LC_ALL, "Portuguese"); //selecionando a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usuário a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nOps! Parece que não foi possível localizar as informações desse usuário.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações encontradas sobre usuário informado: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
}

int deletar() //função de exclusão
{
	
    char cpf[40];
	
	printf("Digite o CPF a que deseja deletar: ");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r"); //R representa read/ler
	
	if(file == NULL) //mensagem quando o usuário não é encontrado ou já foi deletado
	{
		fclose(file);
		printf("\nOps! Parece que esse usuário não está resgistrado no sistema ou já foi deletado.\n\n");
		system("pause");
	}
	
	else if (file !=NULL) //mensagem quando o usuário for deletado corretamente
	{
		fclose(file);
		printf("\nO usuário foi deletado com sucesso!\n\n");
		system("pause");
		remove (cpf);
	}
	
}



int main() //função principal

{
	int opcao=0; //variável
	int x=1; //x=laço
	
	
	for(x=1;x=1;)
	{
	
	
	system("cls"); //"limpar" a tela


	setlocale(LC_ALL, "Portuguese"); //selecionando a linguagem 
	
	
	//início do menu
	printf(" ## Cartório de usuários EBAC ##\n\n"); 
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1- Registrar usuários\n");
	printf("\t2- Consultar usuários\n");
    printf("\t3- Deletar usuários\n\n"); 
	printf("Opção: "); 
	//fim do menu

    
	scanf("%d", &opcao); //armazenando a escolha do usuário
    
    
    system("cls"); //"limpar" a tela
    
    
    //início da seleção do usuário
    switch(opcao)
    {
    	case 1:
    		registrar();
        	break;
        	
        case 2:
        	consultar();
	        break;
	    
	    case 3:
	    	deletar();
	        break;
	        
	    default:
	        printf("Ops! Parece que essa opção não está disponível.\n\n");
            system("pause");    
			break;	
    }
    //fim da seleção do usuário
    
}
}
