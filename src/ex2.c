#include <stdio.h>

#define TAM_L 3 // NÃO MODIFIQUE
#define TAM_C 6 // NÃO MODIFIQUE

/* 
 * Protótipos das funções - NÃO MODIFIQUE 
 *
 */

// le_matriz deve ler uma matriz de tamanho [TAM_L, TAM_C] linha por linha.
void le_matriz(int matriz[TAM_L][TAM_C]);

// busca_linear deve implementar o algoritmo de busca linear para vetores
// do tamanho [TAM_C]. Recebe como parâmetros o vetor e a chave a ser buscada.
// Retorna -1 se não encontrar nada e o índice da chave se ela for encontrada.
int busca_linear(int vetor[TAM_C], int chave);

// busca_binaria deve implementar o algoritmo de busca binária para vetores
// do tamanho [TAM_C]. Recebe como parâmetros o vetor e a chave a ser buscada.
// Retorna -1 se não encontrar nada e o índice da chave se ela for encontrada.
int busca_binaria(int vetor[TAM_C], int chave);

// verifica_ordenacao deve verificar se um vetor de tamanho [TAM_C] 
// está ordenado em ordem crescente. Se estiver, a função retorna 1.
// Se não estiver, a função retorna 0. Recebe como parâmetro o vetor.
int verifica_ordenacao(int vetor[TAM_C]);

// Outro brinde =)
void exibe_matriz(int matriz[TAM_L][TAM_C]);

int main (int argc, char *argv[])
{
  int matriz[TAM_L][TAM_C],chave,i,a,l;
  le_matriz(matriz);
  printf("Valor a ser buscado: ");
  scanf("%i", &chave);
  exibe_matriz(matriz);
  for(i=0;i<TAM_L;i++){
    a = verifica_ordenacao(matriz[i]);
    if(a==0){
      printf("Linha %i desordenada. Verificando por busca linear.\n",i);
      l = busca_linear(matriz[i],chave);
      if(l!=-1){
        printf("Chave %i encontrada em [%i, %i].",chave,i,l);
        return 0;
      }      
    }
    if(a==1){
      printf("Linha %i ordenada. Verificando por busca binária.\n",i);
      l = busca_binaria(matriz[i],chave);
      if(l!=-1){
        printf("Chave %i encontrada em [%i, %i].",chave,i,l);
        return 0;
      }
    }
  }
  if(l==-1){
    printf("Chave %i não foi encontrada.",chave);
    
  }
  return 0;
}

int busca_binaria(int vetor[TAM_C], int chave){
  int i,pos_ini,pos_fim;
  pos_ini = 0;
  pos_fim = TAM_C-1;
  while(pos_ini<pos_fim){
    i = pos_ini + (pos_fim-pos_ini)/2;
    if(vetor[i]==chave){
      return i;
    }
    if(vetor[i]<chave){
      pos_ini = i+1;
    }
    if(vetor[i]>chave){
      pos_fim = i-1;
    }
  }
  return -1;

}

int verifica_ordenacao(int vetor[TAM_C]) {
  int i,ordem;
  for(i=0;i<TAM_C;i++){
    if(vetor[i]<vetor[i+1]){
      ordem = 1;
    }
    else{
      return 0;
    }
  }
  if(ordem==1){
    return 1;
  }
  return 0;
}

int busca_linear(int vetor[TAM_C], int chave){
  int i;
  for(i=0;i<TAM_C;i++){
    if(chave==vetor[i]){
      return i;
    }
  }
  return -1;
}

void le_matriz(int matriz[TAM_L][TAM_C]){
  int i, j, a;
  for(i=0;i<TAM_L;i++){
    printf("Digite a linha %i: ",i);
    for(j=0;j<TAM_C;j++){
      scanf("%i",&a);
      matriz[i][j] = a;
    }
  }
}

void exibe_matriz(int matriz[TAM_L][TAM_C]){
  printf("[");
  for (int i = 0; i < TAM_L; ++i){ 
    printf("[");
    for (int j = 0; j < TAM_C; ++j){
      printf("%i", matriz[i][j]);
      if( j < TAM_C - 1) printf(", ");
    }
    printf("]");
    if( i < TAM_L - 1 ) printf(",\n");
  }
  printf("]\n");
}
