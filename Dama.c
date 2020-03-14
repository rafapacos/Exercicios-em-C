#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DAMA 'R'
#define VISAO '*'
#define CHEGADA 'E'

char szTabuleiro[8][8];

void vIniciaTabuleiro(void){

  int i;
  int j;

  for (i=0; i<8; i++)
      for (j=0; j<8; j++)
        szTabuleiro[i][j] = ' ';

}

void vPrintTabuleiro(char szTabuleiro[8][8]){

  int i;
  int j;

  for (i=0; i<8; i++){

    for (j=0; j<8; j++){
    printf("[%c] ", szTabuleiro[i][j]);
    }

    printf("\n");
  }
  printf("====================================================\n");  
}
void vPosicionaDama (int iLinha, int iColuna){

  szTabuleiro[iLinha-1][iColuna-1] = DAMA;

}

void vCriaLinhaVisao (int iLinha, int iColuna){

  int i;
  int j;


  for (i=iLinha; i<8; i++)
    szTabuleiro[i][iColuna-1] = VISAO;

  for (i=(iLinha-2); i>=0; i--)
    szTabuleiro[i][iColuna-1] = VISAO; 
  
  for (j=iColuna; j<8; j++)
    szTabuleiro[iLinha-1][j] = VISAO;

  for (j=iColuna-2; j>=0; j--)
    szTabuleiro[iLinha-1][j] = VISAO;
  
  for (i=iLinha, j=iColuna; i<8 && j<8; i++, j++){
    szTabuleiro[i][j] = VISAO;
  }

  for (i=iLinha-2, j=iColuna-2; i>=0 && j>=0; i--, j--){
    szTabuleiro[i][j] = VISAO;
  }

  for (i=iLinha, j=iColuna-2; i<8 && j>=0; i++, j--){
    szTabuleiro[i][j] = VISAO;
  }

  for (i=iLinha-2, j=iColuna; i>=0 && j<8; i--, j++){
    szTabuleiro[i][j] = VISAO;
  }
}

int iPosicionarChegada (int iLinha, int iColuna, int iLinDestino, int iColDestino){

  if(iLinha == iLinDestino && iColuna == iColDestino){
    printf("0\n");
    return 0;
  }

  szTabuleiro[iLinDestino-1][iColDestino-1] = CHEGADA;

  return 1;
}

int iChecarLinhaVisao (int iLinha, int iColuna){

  int i;
  int j;


  for (i=iLinha; i<8; i++)
    if(szTabuleiro[i][iColuna-1] == CHEGADA)
      return 1; 

  for (i=(iLinha-2); i>=0; i--)
    if(szTabuleiro[i][iColuna-1] == CHEGADA)
      return 1;

  for (j=iColuna; j<8; j++)
    if(szTabuleiro[iLinha-1][j] == CHEGADA)
      return 1;

  for (j=iColuna-2; j>=0; j--)
    if(szTabuleiro[iLinha-1][j] == CHEGADA)
      return 1;

  for (i=iLinha, j=iColuna; i<8 && j<8; i++, j++)
    if(szTabuleiro[i][j] == CHEGADA)
      return 1;

  for (i=iLinha-2, j=iColuna-2; i>=0 && j>=0; i--, j--)
    if(szTabuleiro[i][j] == CHEGADA)
      return 1;

  for (i=iLinha, j=iColuna-2; i<8 && j>=0; i++, j--)
    if(szTabuleiro[i][j] == CHEGADA)
      return 1;

  for (i=iLinha-2, j=iColuna; i>=0 && j<8; i--, j++)
    if(szTabuleiro[i][j] == CHEGADA)
      return 1;

  return 2;
}


int main(int argc, char *argv[]){

  int i;
  int j;
  int iColuna;
  int iLinha;
  int iColDestino;
  int iLinDestino;
  //int iDama;

  while(1){

    scanf("%d %d %d %d", &iLinha, &iColuna, &iLinDestino, &iColDestino);

    if(iLinha == 0 && iColuna  == 0 && iLinDestino == 0 && iColDestino == 0){
      break ;
    }
 
    vIniciaTabuleiro();

    //vPrintTabuleiro(szTabuleiro);
    //vPosicionaDama(iLinha, iColuna);
    //vPrintTabuleiro(szTabuleiro);
    //vCriaLinhaVisao(iLinha, iColuna);
    //vPrintTabuleiro(szTabuleiro);

    if( iPosicionarChegada(iLinha, iColuna, iLinDestino, iColDestino) == 0 ){
      continue;
    }

    //vPrintTabuleiro(szTabuleiro);

    printf("%d\n", iChecarLinhaVisao(iLinha, iColuna));

  }   

	return 0;
}