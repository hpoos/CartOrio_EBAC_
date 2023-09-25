#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //respons�vel por aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das stings


int registrar() //fun��o de cadastro
{
	setlocale(LC_ALL, "Portuguese"); //selecionando a linguagem
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF do usu�rio a ser cadatrado: ");
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das stings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //W cria novo arquivo
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //A atualiza o arquivo W
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome do usu�rio a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome do usu�rio a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo do usu�rio a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}


int consultar() //fun��o de consulta
{
	setlocale(LC_ALL, "Portuguese"); //selecionando a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usu�rio a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nOps! Parece que n�o foi poss�vel localizar as informa��es desse usu�rio.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o as informa��es encontradas sobre usu�rio informado: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
}

int deletar() //fun��o de exclus�o
{
	
    char cpf[40];
	
	printf("Digite o CPF a que deseja deletar: ");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r"); //R representa read/ler
	
	if(file == NULL) //mensagem quando o usu�rio n�o � encontrado ou j� foi deletado
	{
		fclose(file);
		printf("\nOps! Parece que esse usu�rio n�o est� resgistrado no sistema ou j� foi deletado.\n\n");
		system("pause");
	}
	
	else if (file !=NULL) //mensagem quando o usu�rio for deletado corretamente
	{
		fclose(file);
		printf("\nO usu�rio foi deletado com sucesso!\n\n");
		system("pause");
		remove (cpf);
	}
	
}



int main() //fun��o principal

{
	int opcao=0; //vari�vel
	int x=1; //x=la�o
	
	
	for(x=1;x=1;)
	{
	
	
	system("cls"); //"limpar" a tela


	setlocale(LC_ALL, "Portuguese"); //selecionando a linguagem 
	
	
	//in�cio do menu
	printf(" ## Cart�rio de usu�rios EBAC ##\n\n"); 
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1- Registrar usu�rios\n");
	printf("\t2- Consultar usu�rios\n");
    printf("\t3- Deletar usu�rios\n\n"); 
	printf("Op��o: "); 
	//fim do menu

    
	scanf("%d", &opcao); //armazenando a escolha do usu�rio
    
    
    system("cls"); //"limpar" a tela
    
    
    //in�cio da sele��o do usu�rio
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
	        printf("Ops! Parece que essa op��o n�o est� dispon�vel.\n\n");
            system("pause");    
			break;	
    }
    //fim da sele��o do usu�rio
    
}
}
