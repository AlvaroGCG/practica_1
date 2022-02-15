/* 
 * File:   point.c
 * Author: Santiago Salas
 *
 * Created on 15 de febrero de 2022, 11:30
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "map.h"

#define MAX_NCOLS 64 // Maximum map cols
#define MAX_NROWS 64 // Maximum map rows
#define MAX_BUFFER 64 // Maximum file line size

struct _Map 
{
    unsigned int nrows, ncols;
    Point *array[MAX_NROWS][MAX_NCOLS]; // array with the Map points
    Point *input, *output;              // points input/output
};

Map * map_new (unsigned int nrows,  unsigned int ncols)
{
    
}

void map_free (Map *) {

    
}