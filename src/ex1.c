#include <stdio.h>

#define MAX_ARR 1024 // Não modifique esse valor!!

/* 
 * Protótipos das funções - NÃO MODIFIQUE 
 *
 */

// le_vetor deve ler um vetor até receber o valor -100 ou chegar em MAX_ARR.
// O retorno da função deve ser o tamanho do vetor lido.
int le_vetor(int vetor[MAX_ARR]);

// busca_linear deve receber um vetor, seu tamanho e uma chave a ser buscada.
// A função deve implementar o algoritmo de busca linear.
// Seu retorno deve ser o índice onde a chave for encontrada ou,
// caso não tenha encontrado nada, -1.
int busca_linear(int vetor[MAX_ARR], int tam_vetor, int chave);

// Ganharam essa de brinde. =)
void exibe_vetor(int vetor[MAX_ARR], int tam_vetor);

int main (int argc, char *argv[])
{
  int vetor[MAX_ARR],chave,a,b;
  a = le_vetor(vetor);
  printf("Chave a ser buscada: ");
  scanf("%i",&chave);
  b = busca_linear(vetor,a,chave);
  exibe_vetor(vetor,a);
  if(b==-1){
    printf("Chave %i não foi encontrada.",chave);
    return 0;
  }
  printf("Chave %i encontrada na posição %i.",chave,b);
  return 0;
}

int busca_linear(int vetor[MAX_ARR], int tam_vetor, int chave) {
  int i;
  for(i=0;i<tam_vetor;i++){
    if(chave==vetor[i]){
      return i;
    }
  }
  return -1;
}

int le_vetor(int vetor[MAX_ARR]) {
  int i, a;
  printf("Digite o vetor: ");
  for(i=0;i<MAX_ARR;i++){
    scanf("%i",&a);
    if(a==-100){
      break;
    } 
    vetor[i] = a;
  }
  /* do
  {
    scanf("%i", &a);
    if (a == -100)
    {
      break;
    }
    vetor[i] = a;
    i += 1;
  } while (i < MAX_ARR); */
  return i;
}

void exibe_vetor(int vetor[MAX_ARR], int tam_vetor) {
  printf("[");
  for (int i = 0; i < tam_vetor; i++) {
    printf("%i", vetor[i]);
    if ( i < tam_vetor - 1 ) printf(", ");
  }
  printf("]\n");
}
