#include <stdio.h>
#include <malloc.h>

     int main(int argc, char* argv[])
     {
       int rows = 0;
       int cols = 0;
       int height = 0;
       int ***array;
       int r, c, h, a = 0, rc, cc, hc, raio0,raio1, raio2;

       printf ("3D Array has rows : ");
       scanf ("%d", &rows);
       printf ("3D Array has columns : ");
       scanf ("%d", &cols);
       printf ("3D Array has height : ");
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
             /*printf ("Enter Array Element [%d][%d][%d] : ", h, r, c);
             scanf ("%d", &array[h][r][c]);*/
           }
         }
       }

       rc=rows/2;
       cc=cols/2;
       hc=height/2;

       array[hc][rc][cc]=1;

       printf("Qual o raio da esfera? ");
       scanf("%d",&raio0);

       raio1=raio0;
       for (h=hc;h<=hc+raio0;h++) {
           raio2=raio1;
           for (r=rc;r<=rc+raio1;r++) {
               for (c=cc-raio2;c<=cc+raio2;c++) {
                   array[h][r][c]=1;
               }
               raio2--;
           }
           raio2=raio1;
           for (r=rc;r>=rc-raio1;r--) {
               for (c=cc-raio2;c<=cc+raio2;c++) {
                   array[h][r][c]=1;
               }
               raio2--;
           }
           raio1--;
       }
       raio1=raio0;
       for (h=hc;h>=hc-raio0;h--) {
           raio2=raio1;
           for (r=rc;r<=rc+raio1;r++) {
               for (c=cc-raio2;c<=cc+raio2;c++) {
                   array[h][r][c]=1;
               }
               raio2--;
           }
           raio2=raio1;
           for (r=rc;r>=rc-raio1;r--) {
               for (c=cc-raio2;c<=cc+raio2;c++) {
                   array[h][r][c]=1;
               }
               raio2--;
           }
           raio1--;
       }



       /*printf("Printing 3D Array:\n");
       for (h = 0; h < height; h++) {
         printf("Height %d\n", h);
         for (r = 0; r < rows; r++) {
           for (c = 0; c < cols; c++) {
             printf("%d ", array[h][r][c]);
        }
        printf("\n");
         }
         printf("\n");
       }*/

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
