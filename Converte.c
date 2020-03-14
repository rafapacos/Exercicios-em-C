#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<ctype.h>

void vPrintVetor(char *pszBinario, int iNBits ){

	int i;
	char *pszWork;

	pszWork = pszBinario;

	for(i=0; i<iNBits; i++){
		printf("[%c] [%d]", *pszWork, *pszWork);
		pszWork++;
	}

	printf("\n");

}
char *szRepresentacao[16] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

char *szBinarios[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"}; 

enum HexasBinarios{

	Zero = 0,
	  Um,
	Dois,
	Tres,
  Quatro,
   Cinco,
    Seis,
    Sete,
    Oito,
    Nove,
     Dez,
    Onze,
    Doze,
   Treze,
Quatorze,
  Quinze,
Dezesseis,
};

int main(int argc, char *argv[]){

	int iCase;
	int iNBits;
	int iAux;
	char *pszBinario;
	char *pszWork;
	char szA[32];
	int iResult;
	int i;
	int iResultConversao = 0;


	printf("+++++++++++++++++++++++++++++++++++ PROGRAMAÇO DE CONVERSÃO LINDUU +++++++++++++++++++++++++++++++++++++++++++\n\n");
	
	do{

		printf("Digite 1 para Conversão de Binario\n");
		printf("Digite 2 para Conversão de Decimal\n");

		scanf("%d", &iCase);

	}while(iCase < 1 || iCase >  2);

	switch(iCase){

		case 1: 
			printf("Declare o Numero de bits: \n");

			scanf("%d", &iNBits);

			fgets(szA, 2, stdin);

			pszBinario = (char *) malloc(sizeof(char)*iNBits+1);

			pszWork = pszBinario;
	
			fgets(pszWork, iNBits+1, stdin); strtok(pszWork, "\n");
						
			//vPrintVetor(pszBinario, iNBits);

			iAux = iNBits;

			for(i=0; i<iNBits; i++, iAux--){

				iResultConversao += (pszBinario[i]-48)*pow(2, iAux-1);

				//printf("%d\n", iResultConversao );
			}

			printf("Em decimal: %d\n", iResultConversao );
			printf("Em Octal: %o\n", iResultConversao );
			printf("Em Hexadecimal: %x\n", iResultConversao );

			break;
		
		case 2:

			printf("Declare o Numero: \n");

			scanf("%d", &iNBits);

			sprintf(szA, "%x", iNBits);

			//printf("%s\n", szA);

			for(pszWork = szA; *pszWork; pszWork++){
				for(i = Zero; i<Dezesseis; i=i+Um){
					if(szRepresentacao[i][0] == toupper(*pszWork)){
						printf("Em Binario: %s", szBinarios[i]);
					}
				}

			}
			printf("\n");
			printf("Em Octal: %o\n", iNBits);
			printf("Em Hexadecimal: %x\n", iNBits);
			break;			
	}	

	
return 0 ;

	
}