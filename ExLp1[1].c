#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vPrintVetor(int *iVetor, int TamVetor){
  int i;

  for(i=0; i<TamVetor; i++){
    printf("[%d] -----> %d\n", i, iVetor[i]);
  }

}

int iPosicaoNoVetor(int *iVetor, int iNum){
  int *iptr;
  int i;
  int j = 0;

  for(iptr = iVetor, i=0; *iptr; iptr++, i++){
    if(*iptr == iNum){
      j = 1;
      return i;
    }
  }
  if (j == 0)
    return -1;
}

void vMudarVetor(int *iVetor, int iTamVetor){
  int i;
  int *iptr;

  for(iptr = iVetor, i=0; i < iTamVetor; iptr++, i++){
    if(i == 0){
      continue;
    }
    else
      *iptr = *iptr + iVetor[i-1];
  }


}


int main(int argc, char **argv){

  int iVetor[7];
  int i, iNum;

  for(i=0; i<7; i++){

    scanf("%d", &iVetor[i]);
  }

  vPrintVetor(iVetor, 7);

  printf("Digite um Numero para saber a posição no vetor: ");
  scanf("%d", &iNum);

  printf("[%d]\n", iPosicaoNoVetor(iVetor, iNum));

  vMudarVetor(iVetor, 7);

  vPrintVetor(iVetor, 7);

 
  return 0;

}

