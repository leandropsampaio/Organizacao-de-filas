/******************************************************************************* 
Autor: Leandro Pereira Sampaio
Componente Curricular: Algoritmos I
Concluido em: 27/07/2014
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum 
trecho de código de outro colega ou de outro autor, tais como provindos de livros e 
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código 
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte 
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação. 
******************************************************************************************/

// Declaração das bibliotecas utilizadas na execução do programa.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct estrutura celula; // Definindo um apelido chamado de (celula), para a estrutura.

struct estrutura // Definindo a estrutura.
{ 
// Membros da estrutura, onde as informações dos torcedores terão um determinado espaço na estrutura (celula).
	char nome[20];
	int categoria;
	int bloco;
	int assento;
	celula *proximo;
};

void dividir_filas(celula **, char [], int, int, int); /* Protótipo da função utilizada para dividir uma fila em três, utilizando como parâmetro um ponteiro 
de ponteiro do tipo (celula), um nome do tipo caracteres e as informações do torcedor como: categoria, bloco e assento do tipo inteiro. */
void removerfila(celula**); // Protótipo da função que remove um torcedor da fila, passando como parâmetro um ponteiro de ponteiro, do tipo (celula).

int main() // Iniciando a função principal.
{
	FILE *arq, *log, *vaimeufilho; // Declaração das arquivos necessários no programa.
	celula cel, *fila1 = NULL,*fila2 = NULL,*fila3 = NULL; // Declaração das variáveis do tipo estrutura (celula).
	int portao=0, portao1=0, portao2=0, portao3=0; // Declaração das variáveis inteiras.
// A variável (portão) irá salvar os portões existentes no arquivo de texto (vai_meu_filho).
// As variáveis portao1, portao2 e portao3, irá salvar a quantidade de torcedores que passam por aquele determinado portão.

	arq = fopen("fila.txt", "r"); // Nessa linha, o arquivo (fila.txt) será aberto para a leitura, apenas se o arquivo existir.
	if(arq == NULL) // Se o arquivo não existir, será mostrado uma mensagem na tela que não foi possivel abrir o arquivo.
			printf("\n ERRO, NAO FOI POSSIVEL ABRIR O ARQUIVO (fila.txt)! \n\n");
	else // Se o arquivo existir, o programa irá executar esse trecho de código.
	// O software irá ler os dados do arquivo, enquanto existirem dados.
		while( (fscanf(arq,"%s categoria %d bloco %d assento %d\n", cel.nome, &cel.categoria, &cel.bloco, &cel.assento))!=EOF )
		{
			
			if (cel.categoria == 1) // Se a categoria for igual a 1, o programa irá inserir os torcedores na primeira fila.
			{
			    	
			     dividir_filas(&fila1,cel.nome,cel.categoria, cel.bloco,cel.assento); // Função que armazena dinamicamente os torcedores da categoria 1, na primeira fila.
						
			}
			if (cel.categoria == 2) // Se a categoria for igual a 2, o programa irá inserir os torcedores na segunda fila. 
			{
				
			    	dividir_filas(&fila2,cel.nome,cel.categoria, cel.bloco,cel.assento); // Função que armazena dinamicamente os torcedores da categoria 2, na segunda fila.

			}
			if (cel.categoria == 3) // Se a categoria for igual a 3, o programa irá inserir os torcedores na terceira fila.
			{
			
			     dividir_filas(&fila3,cel.nome,cel.categoria, cel.bloco,cel.assento); // Função que armazena dinamicamente os torcedores da categoria 3, na terceira fila.
			     
			}
			
			
		}
fclose(arq); // Essa linha de código fecha o arquivo (fila.txt), aberto anteriormente.

vaimeufilho = fopen("vai_meu_filho.txt", "r"); // Nessa parte o arquivo (vai_meu_filho), será aberto para a leitura.
if(vaimeufilho == NULL) // Se o arquivo não existir, aparecerá a seguinte mensagem de erro.
{
	printf("\n ERRO, NAO FOI POSSIVEL ABRIR O ARQUIVO (vai_meu_filho)! \n\n");
	return 0;
}

else  // Se o arquivo (vai_meu_filho) existir, o software executará este trecho de código.
{
	log = fopen("log.txt", "w"); // Nessa linha, será criado um arquivo chamado: (log.txt), apenas para a escrita.
	fprintf(log, "Entrada\n"); // Tudo que estiver dentro do fprintf, será escrito dentro do arquivo aberto anteriormente: (log.txt).

while( (fscanf(vaimeufilho,"%d", &portao)) != EOF) // Enquanto existirem portões abertos no arquivo (vai_meu_filho), o laço de repetição continuará rodando.
{
	// Condição para o primeiro portão.
	if(portao==1) // Se o portão do arquivo (vai_meu_filho), for igual a 1, o software realizará as funções existentes dentro desse trecho de código.
	{
		portao1++; // Acrescentando um torcedor, ao primeiro portão.
		if(fila1!=NULL) // Havendo torcedores no primeira fila, o programa salvará suas informações no (log.txt).
		{
			// As informações do torcedor serão escritas no (log.txt).
    		fprintf(log,"portao %d categoria %d  %s bloco %d assento %d\n", portao, fila1->categoria, fila1->nome, fila1->bloco, fila1->assento);
        	removerfila(&fila1); // Chamada da função (removerfila), passando como argumento a primeira fila.
    	}
    	else if(fila3!=NULL) // Não possuindo torcedores na primeira fila, os torcedores que estão na terceira fila entrarão no primeiro portão.
    	{
    		// As informações do torcedor serão escritas no (log.txt).
 	   		fprintf(log,"portao %d categoria %d  %s bloco %d assento %d\n", portao, fila3->categoria, fila3->nome, fila3->bloco, fila3->assento);
        	removerfila(&fila3); // Chamada da função (removerfila), passando como argumento a terceira fila.
		}
    	else // Caso não passuam torcedores para entrarem no primeiro portão.
		{
			// Aparecerá no (log.txt) a seguinte frase.
    		fprintf(log,"portao %d none \n", portao);
    		// Esse comando diminuirá um torcedor do primeiro portão, pois anteriormente havia sido acrescentado uma unidade.
        	portao1--; // Como ninguém passou pelo primeiro portão, ele será reduzido em uma unidade.
    	}
	}  
              
	// Condição para o segundo portão.
	else if(portao==2) // Se o portão do arquivo (vai_meu_filho), for igual a 2, o software realizará as funções existentes dentro desse trecho.
	{
        portao2++; // Acrescentando um torcedor, ao segundo portão.
        if(fila2!=NULL) // Se ainda houver torcedores na segunda fila, suas informações serão salvas no (log.txt).
		{
			// As informações do torcedor serão escritas no (log.txt).
        	fprintf(log,"portao %d categoria %d  %s bloco %d assento %d\n", portao, fila2->categoria, fila2->nome, fila2->bloco, fila2->assento);
            removerfila(&fila2); // Chamada da função (removerfila), passando como argumento a segunda fila.
                  
        }
    	else if(fila3!=NULL) // Não possuindo torcedores na segunda fila, os torcedores que estão na terceira fila entrarão no segundo portão.
		{
			// As informações do torcedor serão escritas no (log.txt).
            fprintf(log,"portao %d categoria %d  %s bloco %d assento %d\n", portao, fila3->categoria, fila3->nome, fila3->bloco, fila3->assento);
            removerfila(&fila3); // Chamada da função (removerfila), passando como argumento a terceira fila.
		}  
        else // Caso não passuam torcedores para entrarem no segundo portão.
		{
			// Aparecerá no (log.txt) a seguinte frase.
        	fprintf(log,"portao %d none \n",portao);
        	// Esse comando diminuirá um torcedor do segundo portão, pois anteriormente havia sido acrescentado uma unidade.
            portao2--; // Como ninguém passou pelo segundo portão, ele será reduzido em uma unidade.
        }
    }
	
	// Condição para o terceiro portão.
    else if(portao==3) // Se o portao do arquivo (vai_meu_filho), for igual a 3, o software realizará as funções existentes dentro desse trecho.
	{
    	portao3++; // Acrescentando um torcedor, ao terceiro portão.
        if(fila3!=NULL) // Se houver torcedores na terceira fila, suas informações serão salvas no (log.txt).
		{
			// As informações do torcedor serão escrita no (log.txt).
        	fprintf(log,"portao %d categoria %d  %s bloco %d assento %d\n", portao, fila3->categoria, fila3->nome, fila3->bloco, fila3->assento);
            removerfila(&fila3); // Chamada da função (removerfila), passando como argumento a terceira fila.
        }
        else // Caso não passuam torcedores para entrarem no terceiro portão.
		{
			// Aparecerá no (log.txt) a seguinte frase.
        	fprintf(log,"portao %d none \n", portao);
        	// Esse comando diminuirá um torcedor do terceiro portão, pois anteriormente havia sido acrescentado uma unidade.
            portao3--; // Como ninguém passou pelo terceiro portão, ele será reduzido uma unidade.
        }
    } 
}
}

// Essas linhas de código serão escritas no arquivo (log.txt), exibindo o total de torcedores que cada portão recebeu.
fprintf(log, "Total\n");
fprintf(log, "portao 1  %d torcedor(es)\n",portao1);

fprintf(log, "portao 2  %d torcedor(es)\n",portao2);

fprintf(log, "portao 3  %d torcedor(es)\n",portao3);
fclose(vaimeufilho); // Fechando o arquivo de texto: (vai_meu_filho).  
fclose(log); // Fechando o arquivo de texto: (log.txt).
system("pause");
		
}

// Função que divide todos os torcedores existentes na (fila.txt), em apenas três filas.
void dividir_filas(celula **p, char nome [], int categoria, int bloco, int assento)
{
	celula *nova, *aux; // Declarando dois ponteiros do tipo (celula).
	if(*p == NULL) // Se na fila não possuir nenhum torcedor, o software executará esse trecho de código.
	{   
		*p= (celula *) malloc(sizeof (celula)); // Alocando dinamicamente a momória, e armazenando o endereço da memória, no ponteiro (p).
		strcpy ((*p)->nome, nome);
		// Salvando as informações dos torcedores na fila.
		(*p)->categoria = categoria;
		(*p)->bloco = bloco;
		(*p)->assento =assento;
		(*p)->proximo = NULL;
	}
	else // Caso a fila já possua torcedores.
	{
		nova = (celula *) malloc(sizeof (celula)); // Alocando dinamicamente um espaço de memória, e armazenando o endereço, no ponteiro (nova).
		strcpy ((nova)->nome, nome);
		// Salvando as informações dos torcedores na fila.
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

void removerfila(celula **fila) // Função necessária para remover da fila, os torcedores que já passaram pelos portões.
{
     celula *aux; // Criando um ponteiro auxiliar, do tipo (celula).
     aux = *fila; // Auxiliar, será igual ao primeiro torcedor existente na fila.
     *fila = (*fila)->proximo; // Fila apontará para o próximo torcedor.
     free(aux); // Função necessário para liberar o espaço de memória, anteriormente utilizada.
}
