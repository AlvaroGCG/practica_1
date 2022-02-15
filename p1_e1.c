/* 
 * File:   p1_e1.c
 * Author: Santiago Salas
 *
 * Created on 08 de febrero de 2022, 12:00
 */

#include <stdio.h>
#include "point.h"

#define TAM_TABLA 4
int main()
{
    Point*p[TAM_TABLA];
    Bool resultado;

    p[0] = point_new(0,0, BARRIER);
    p[1] = point_new(0,1,BARRIER);
    
    point_print(stdout, p[0]);
    point_print(stdout, p[1]);
    printf("\n");

    printf("Equal points p[0] and p[1]? ");
    resultado = point_equal(p[0], p[1]);
    if (resultado == TRUE)
        printf("Yes\n");
    else
        printf("No\n");
    
    printf("Creating p[2]:");
    p[2] = point_hardcpy(p[0]);
    point_print(stdout, p[2]);
    printf("\n");

    printf("Equal points p[0] and p[2]? ");
    resultado = point_equal(p[0], p[2]);
    if (resultado == TRUE)
        printf("Yes\n");
    else
        printf("No\n");

    printf("Modifying p[2]:");
    point_setSymbol(p[2], SPACE);
    point_print(stdout, p[2]);
    printf("\n");

    printf("Equal points p[0] and p[2]? ");
    resultado = point_equal(p[0], p[2]);
    if (resultado == TRUE)
        printf("Yes\n");
    else
        printf("No\n");

    printf("Assign p[3] = p[0]\n");
    p[3] = p[0];
    printf("Modifying p[3]:");
    point_setSymbol(p[3], OUTPUT);
    point_print(stdout, p[3]);
    printf("\n");

    for(int i = 0; i < TAM_TABLA; i++)
        point_print(stdout, p[i]);
    
    printf("\n");

    for(int i = 0; i < TAM_TABLA -1; i++)
        point_free(p[i]);
    

}
