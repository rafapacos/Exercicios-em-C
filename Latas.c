#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14
#define METROS_POR_LITRO 3
#define TRUE 1
#define FALSE 0

typedef struct STRUCT_LATAS{
    char szMarca[64];
    int iLitros;
    double dValor;
    struct STRUCT_LATAS *pstproximo;
}STRUCT_LATAS;

int iInsereLata(STRUCT_LATAS **pstLatas){
    STRUCT_LATAS *pstWork;
    char szA[5];
    
    if((pstWork = (STRUCT_LATAS *) malloc(sizeof(STRUCT_LATAS))) == NULL){
        return FALSE;
    }
    printf("Digite o Nome da Marca: ");
    fgets(pstWork->szMarca, sizeof(char)*64, stdin); strtok(pstWork->szMarca, "\n");
    printf("Digite o Valor da Lata: ");
    scanf("%lf", &pstWork->dValor);
    printf("Digite a Quantidade de l da Lata: ");
    scanf("%d", &pstWork->iLitros);
    fgets(szA, 5, stdin);

    if(*pstLatas == NULL){
        *pstLatas = pstWork;
        (*pstLatas)->pstproximo = NULL;
    }
    else{
        pstWork->pstproximo = *pstLatas;
        *pstLatas = pstWork;
    }
    return TRUE;
}
void vRemoverLata(STRUCT_LATAS *pstLatas, char *szMarca, int iLitros){
    STRUCT_LATAS *pstWork;
    STRUCT_LATAS *pstUltimo = NULL;

    if(pstLatas == NULL){
        printf("Cadastro Vazio !\n");
        return;
    }
    for(pstWork = pstLatas; pstWork != NULL; pstWork = pstWork->pstproximo){
        if(strcmp(pstWork->szMarca, szMarca) == 0 && pstWork->iLitros == iLitros){
            if(pstUltimo == NULL){
                pstLatas = pstWork->pstproximo;
                if(pstLatas == NULL){
                    free(pstWork);
                    printf("Lata Deletada !\n");
                    printf("Cadastro Vazio !\n");
                    return;
                }
                free(pstWork);
                printf("Lata Deletada !\n");
                return;
            }
            pstUltimo->pstproximo = pstWork->pstproximo;
            free(pstWork);
            printf("Lata Deletada !\n");
            return;
        }
        pstUltimo = pstWork;    
    }
    printf("Lata Não Encontrada!\n");
    return;
}

void vLiberarLista(STRUCT_LATAS **pstLatas){
    STRUCT_LATAS *pstWork;
    STRUCT_LATAS *pstUltimo;

    for(pstWork = *pstLatas; pstWork != NULL;){
        pstUltimo = pstWork;
        pstWork = pstWork->pstproximo;
        free(pstUltimo);
    }
    *pstLatas = NULL;

}

void vPrintLista(STRUCT_LATAS *pstLatas){

    for(; pstLatas != NULL; pstLatas = pstLatas->pstproximo)
        printf("[%s] [%.2lf] [%d]\n", pstLatas->szMarca, pstLatas->dValor, pstLatas->iLitros);
}


int main() {
    
    float fAlt, fRaio, fAreaB, fAreaL, fAreaExt, fNumLatas, fValorTotal;
    STRUCT_LATAS *pstLatas = NULL;
    char szCaso[5], szMarca[64], szLitros[5];


    while(TRUE){
        printf("Selecione uma Opção\n");
        printf("1. Inserir Lata\n");
        printf("2. Remover Lata\n");
        printf("3. Sair\n");

        fgets(szCaso, sizeof(szCaso), stdin); strtok(szCaso, "\n");

        switch(atoi(szCaso)){
            case 1: 
                iInsereLata(&pstLatas);
                vPrintLista(pstLatas);
                break;
            case 2:
                fgets(szMarca, sizeof(szMarca), stdin); strtok(szMarca, "\n");
                fgets(szLitros, sizeof(szLitros), stdin); strtok(szLitros, "\n");
                vRemoverLata(pstLatas, szMarca, atoi(szLitros));
                vPrintLista(pstLatas);
                break;
            case 3:
                vLiberarLista(&pstLatas);
                vPrintLista(pstLatas);
                return 0;
            default:
                break;
        }          
    }
     

    return 0;
    
    //fAreaB = PI * pow(fRaio, 2);
    //fAreaL = 2 * PI * fRaio * fAlt;
    //fAreaExt = 2 * fAreaB + fAreaL;
    //fNumLatas = ( fAreaExt / METROS_POR_LITRO  ) / LITROS_LATA  ;
    // fValorTotal = VALOR_LATA * fNumLatas;
    
    // printf("%.f\n", fNumLatas);
    // printf("%.2f\n", fValorTotal);


    
    //return 0;
}
