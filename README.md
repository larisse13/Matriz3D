# Matriz3D

#include <stdio.h>
#include <malloc.h>

     int main(int argc, char* argv[])
     {
       int rows = 0;
       int cols = 0;
       int height = 0;
       int ***array;
       int r, c, h, a = 0, rc, cc, hc, raio0,raio1, aux1 , raio2, aux2, aux3;

       printf ("Quantidade de linhas : ");
       scanf ("%d", &rows);
       printf ("Quantidade de colunas : ");
       scanf ("%d", &cols);
       printf ("Altura do bloco : ");
       scanf ("%d", &height);
       array = (int ***) malloc (sizeof(int ***)*height);
       for (h = 0; h < height; h++) {
         array[h] = (int **) malloc(sizeof(int*)*rows);
         for (r = 0; r < rows; r++) {
           array[h][r] = (int *) malloc(sizeof(int)*cols);
         }
       }

       for (h = 0; h < height; h++) {
         for (r = 0; r < rows; r++) {
           for (c = 0; c < cols; c++) {
             array[h][r][c]=0;
           }
         }
       }

       rc=rows/2;
       cc=cols/2;
       hc=height/2;

       array[hc][rc][cc]=1;

       printf("Qual o raio da esfera na direcao z, x, y? ");
       scanf("%d%d%d",&raio0, &aux1, &aux2);


       raio1=aux1;
       aux3=aux2;
       for (h=hc;h<=hc+raio0;h++) {
           raio2=aux2;
           for (r=rc;r<=rc+raio1;r++) {
               for (c=cc-raio2;c<=cc+raio2;c++) {
                   array[h][r][c]=1;
               }
               raio2--;
           }
           raio2=aux2;
           for (r=rc;r>=rc-raio1;r--) {
               for (c=cc-raio2;c<=cc+raio2;c++) {
                   array[h][r][c]=1;
               }
               raio2--;
           }
           raio1--;
           aux2--;
       }
       raio1=aux1;
       aux2=aux3;
       for (h=hc;h>=hc-raio0;h--) {
           raio2=aux2;
           for (r=rc;r<=rc+raio1;r++) {
               for (c=cc-raio2;c<=cc+raio2;c++) {
                   array[h][r][c]=1;
               }
               raio2--;
           }
           raio2=aux2;
           for (r=rc;r>=rc-raio1;r--) {
               for (c=cc-raio2;c<=cc+raio2;c++) {
                   array[h][r][c]=1;
               }
               raio2--;
           }
           raio1--;
           aux2--;
       }



       printf("Imprimindo a matriz:\n");
       for (h = 0; h < height; h++) {
         printf("Altura %d\n", h);
         for (r = 0; r < rows; r++) {
           for (c = 0; c < cols; c++) {
             printf("%d ", array[h][r][c]);
        }
        printf("\n");
         }
         printf("\n");
       }

       printf("Altura:\n");
       scanf("%d", &a);

         for (r = 0; r < rows; r++) {
           for (c = 0; c < cols; c++) {
             printf("%d ", array[a][r][c]);
        }
        printf("\n");
         }
         printf("\n");
       return 0;
     }
