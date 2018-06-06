/******************************************************************************* 
Autor: Leandro Pereira Sampaio
Componente Curricular: Algoritmos I
Concluido em: 27/07/2014
Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum 
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e 
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo 
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte 
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o. 
******************************************************************************************/

// Declara��o das bibliotecas utilizadas na execu��o do programa.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct estrutura celula; // Definindo um apelido chamado de (celula), para a estrutura.

struct estrutura // Definindo a estrutura.
{ 
// Membros da estrutura, onde as informa��es dos torcedores ter�o um determinado espa�o na estrutura (celula).
	char nome[20];
	int categoria;
	int bloco;
	int assento;
	celula *proximo;
};

void dividir_filas(celula **, char [], int, int, int); /* Prot�tipo da fun��o utilizada para dividir uma fila em tr�s, utilizando como par�metro um ponteiro 
de ponteiro do tipo (celula), um nome do tipo caracteres e as informa��es do torcedor como: categoria, bloco e assento do tipo inteiro. */
void removerfila(celula**); // Prot�tipo da fun��o que remove um torcedor da fila, passando como par�metro um ponteiro de ponteiro, do tipo (celula).

int main() // Iniciando a fun��o principal.
{
	FILE *arq, *log, *vaimeufilho; // Declara��o das arquivos necess�rios no programa.
	celula cel, *fila1 = NULL,*fila2 = NULL,*fila3 = NULL; // Declara��o das vari�veis do tipo estrutura (celula).
	int portao=0, portao1=0, portao2=0, portao3=0; // Declara��o das vari�veis inteiras.
// A vari�vel (port�o) ir� salvar os port�es existentes no arquivo de texto (vai_meu_filho).
// As vari�veis portao1, portao2 e portao3, ir� salvar a quantidade de torcedores que passam por aquele determinado port�o.

	arq = fopen("fila.txt", "r"); // Nessa linha, o arquivo (fila.txt) ser� aberto para a leitura, apenas se o arquivo existir.
	if(arq == NULL) // Se o arquivo n�o existir, ser� mostrado uma mensagem na tela que n�o foi possivel abrir o arquivo.
			printf("\n ERRO, NAO FOI POSSIVEL ABRIR O ARQUIVO (fila.txt)! \n\n");
	else // Se o arquivo existir, o programa ir� executar esse trecho de c�digo.
	// O software ir� ler os dados do arquivo, enquanto existirem dados.
		while( (fscanf(arq,"%s categoria %d bloco %d assento %d\n", cel.nome, &cel.categoria, &cel.bloco, &cel.assento))!=EOF )
		{
			
			if (cel.categoria == 1) // Se a categoria for igual a 1, o programa ir� inserir os torcedores na primeira fila.
			{
			    	
			     dividir_filas(&fila1,cel.nome,cel.categoria, cel.bloco,cel.assento); // Fun��o que armazena dinamicamente os torcedores da categoria 1, na primeira fila.
						
			}
			if (cel.categoria == 2) // Se a categoria for igual a 2, o programa ir� inserir os torcedores na segunda fila. 
			{
				
			    	dividir_filas(&fila2,cel.nome,cel.categoria, cel.bloco,cel.assento); // Fun��o que armazena dinamicamente os torcedores da categoria 2, na segunda fila.

			}
			if (cel.categoria == 3) // Se a categoria for igual a 3, o programa ir� inserir os torcedores na terceira fila.
			{
			
			     dividir_filas(&fila3,cel.nome,cel.categoria, cel.bloco,cel.assento); // Fun��o que armazena dinamicamente os torcedores da categoria 3, na terceira fila.
			     
			}
			
			
		}
fclose(arq); // Essa linha de c�digo fecha o arquivo (fila.txt), aberto anteriormente.

vaimeufilho = fopen("vai_meu_filho.txt", "r"); // Nessa parte o arquivo (vai_meu_filho), ser� aberto para a leitura.
if(vaimeufilho == NULL) // Se o arquivo n�o existir, aparecer� a seguinte mensagem de erro.
{
	printf("\n ERRO, NAO FOI POSSIVEL ABRIR O ARQUIVO (vai_meu_filho)! \n\n");
	return 0;
}

else  // Se o arquivo (vai_meu_filho) existir, o software executar� este trecho de c�digo.
{
	log = fopen("log.txt", "w"); // Nessa linha, ser� criado um arquivo chamado: (log.txt), apenas para a escrita.
	fprintf(log, "Entrada\n"); // Tudo que estiver dentro do fprintf, ser� escrito dentro do arquivo aberto anteriormente: (log.txt).

while( (fscanf(vaimeufilho,"%d", &portao)) != EOF) // Enquanto existirem port�es abertos no arquivo (vai_meu_filho), o la�o de repeti��o continuar� rodando.
{
	// Condi��o para o primeiro port�o.
	if(portao==1) // Se o port�o do arquivo (vai_meu_filho), for igual a 1, o software realizar� as fun��es existentes dentro desse trecho de c�digo.
	{
		portao1++; // Acrescentando um torcedor, ao primeiro port�o.
		if(fila1!=NULL) // Havendo torcedores no primeira fila, o programa salvar� suas informa��es no (log.txt).
		{
			// As informa��es do torcedor ser�o escritas no (log.txt).
    		fprintf(log,"portao %d categoria %d  %s bloco %d assento %d\n", portao, fila1->categoria, fila1->nome, fila1->bloco, fila1->assento);
        	removerfila(&fila1); // Chamada da fun��o (removerfila), passando como argumento a primeira fila.
    	}
    	else if(fila3!=NULL) // N�o possuindo torcedores na primeira fila, os torcedores que est�o na terceira fila entrar�o no primeiro port�o.
    	{
    		// As informa��es do torcedor ser�o escritas no (log.txt).
 	   		fprintf(log,"portao %d categoria %d  %s bloco %d assento %d\n", portao, fila3->categoria, fila3->nome, fila3->bloco, fila3->assento);
        	removerfila(&fila3); // Chamada da fun��o (removerfila), passando como argumento a terceira fila.
		}
    	else // Caso n�o passuam torcedores para entrarem no primeiro port�o.
		{
			// Aparecer� no (log.txt) a seguinte frase.
    		fprintf(log,"portao %d none \n", portao);
    		// Esse comando diminuir� um torcedor do primeiro port�o, pois anteriormente havia sido acrescentado uma unidade.
        	portao1--; // Como ningu�m passou pelo primeiro port�o, ele ser� reduzido em uma unidade.
    	}
	}  
              
	// Condi��o para o segundo port�o.
	else if(portao==2) // Se o port�o do arquivo (vai_meu_filho), for igual a 2, o software realizar� as fun��es existentes dentro desse trecho.
	{
        portao2++; // Acrescentando um torcedor, ao segundo port�o.
        if(fila2!=NULL) // Se ainda houver torcedores na segunda fila, suas informa��es ser�o salvas no (log.txt).
		{
			// As informa��es do torcedor ser�o escritas no (log.txt).
        	fprintf(log,"portao %d categoria %d  %s bloco %d assento %d\n", portao, fila2->categoria, fila2->nome, fila2->bloco, fila2->assento);
            removerfila(&fila2); // Chamada da fun��o (removerfila), passando como argumento a segunda fila.
                  
        }
    	else if(fila3!=NULL) // N�o possuindo torcedores na segunda fila, os torcedores que est�o na terceira fila entrar�o no segundo port�o.
		{
			// As informa��es do torcedor ser�o escritas no (log.txt).
            fprintf(log,"portao %d categoria %d  %s bloco %d assento %d\n", portao, fila3->categoria, fila3->nome, fila3->bloco, fila3->assento);
            removerfila(&fila3); // Chamada da fun��o (removerfila), passando como argumento a terceira fila.
		}  
        else // Caso n�o passuam torcedores para entrarem no segundo port�o.
		{
			// Aparecer� no (log.txt) a seguinte frase.
        	fprintf(log,"portao %d none \n",portao);
        	// Esse comando diminuir� um torcedor do segundo port�o, pois anteriormente havia sido acrescentado uma unidade.
            portao2--; // Como ningu�m passou pelo segundo port�o, ele ser� reduzido em uma unidade.
        }
    }
	
	// Condi��o para o terceiro port�o.
    else if(portao==3) // Se o portao do arquivo (vai_meu_filho), for igual a 3, o software realizar� as fun��es existentes dentro desse trecho.
	{
    	portao3++; // Acrescentando um torcedor, ao terceiro port�o.
        if(fila3!=NULL) // Se houver torcedores na terceira fila, suas informa��es ser�o salvas no (log.txt).
		{
			// As informa��es do torcedor ser�o escrita no (log.txt).
        	fprintf(log,"portao %d categoria %d  %s bloco %d assento %d\n", portao, fila3->categoria, fila3->nome, fila3->bloco, fila3->assento);
            removerfila(&fila3); // Chamada da fun��o (removerfila), passando como argumento a terceira fila.
        }
        else // Caso n�o passuam torcedores para entrarem no terceiro port�o.
		{
			// Aparecer� no (log.txt) a seguinte frase.
        	fprintf(log,"portao %d none \n", portao);
        	// Esse comando diminuir� um torcedor do terceiro port�o, pois anteriormente havia sido acrescentado uma unidade.
            portao3--; // Como ningu�m passou pelo terceiro port�o, ele ser� reduzido uma unidade.
        }
    } 
}
}

// Essas linhas de c�digo ser�o escritas no arquivo (log.txt), exibindo o total de torcedores que cada port�o recebeu.
fprintf(log, "Total\n");
fprintf(log, "portao 1  %d torcedor(es)\n",portao1);

fprintf(log, "portao 2  %d torcedor(es)\n",portao2);

fprintf(log, "portao 3  %d torcedor(es)\n",portao3);
fclose(vaimeufilho); // Fechando o arquivo de texto: (vai_meu_filho).  
fclose(log); // Fechando o arquivo de texto: (log.txt).
system("pause");
		
}

// Fun��o que divide todos os torcedores existentes na (fila.txt), em apenas tr�s filas.
void dividir_filas(celula **p, char nome [], int categoria, int bloco, int assento)
{
	celula *nova, *aux; // Declarando dois ponteiros do tipo (celula).
	if(*p == NULL) // Se na fila n�o possuir nenhum torcedor, o software executar� esse trecho de c�digo.
	{   
		*p= (celula *) malloc(sizeof (celula)); // Alocando dinamicamente a mom�ria, e armazenando o endere�o da mem�ria, no ponteiro (p).
		strcpy ((*p)->nome, nome);
		// Salvando as informa��es dos torcedores na fila.
		(*p)->categoria = categoria;
		(*p)->bloco = bloco;
		(*p)->assento =assento;
		(*p)->proximo = NULL;
	}
	else // Caso a fila j� possua torcedores.
	{
		nova = (celula *) malloc(sizeof (celula)); // Alocando dinamicamente um espa�o de mem�ria, e armazenando o endere�o, no ponteiro (nova).
		strcpy ((nova)->nome, nome);
		// Salvando as informa��es dos torcedores na fila.
		nova->categoria = categoria;
		nova->bloco = bloco;
		nova->assento =assento;
		nova->proximo=NULL;
		aux=*p;
		
		while (aux->proximo != NULL)
			aux=aux->proximo;
		aux->proximo= nova;	
	}
}

void removerfila(celula **fila) // Fun��o necess�ria para remover da fila, os torcedores que j� passaram pelos port�es.
{
     celula *aux; // Criando um ponteiro auxiliar, do tipo (celula).
     aux = *fila; // Auxiliar, ser� igual ao primeiro torcedor existente na fila.
     *fila = (*fila)->proximo; // Fila apontar� para o pr�ximo torcedor.
     free(aux); // Fun��o necess�rio para liberar o espa�o de mem�ria, anteriormente utilizada.
}
