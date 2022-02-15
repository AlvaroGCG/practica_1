/* 
 * File:   point.c
 * Author: Santiago Salas
 *
 * Created on 08 de febrero de 2022, 11:30
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "point.h"

struct _Point 
{
    int x, y;
    char symbol;
    Bool visited; // for DFS
};

Point * point_new (int x, int y, char symbol)
{   
    //Pointer to the point we just created
    Point *NewPoint = NULL;

    //Allocate memory
    NewPoint = (Point*)malloc(sizeof(Point));
    if(!NewPoint)
        return NULL;

    //Inicializes the values
    NewPoint->x = x;
    NewPoint->y = y;
    NewPoint->symbol = symbol;

    return NewPoint;
}

void point_free (Point *p)
{   
    //Liberates memory, points pointer to NULL
    free(p);
    p = NULL;
}

int point_getCoordinateX (const Point *p) 
{   
    //Error checking
    if(!p)
        return INT_MAX;
    
    //Returns X
    return p->x;
}

int point_getCoordinateY (const Point *p) 
{
    //Error checking
    if(!p)
        return INT_MAX;
    
    //Returns Y
    return p->y;
}

char point_getSymbol (const Point *p) 
{
    //Error checking
    if(!p)
        return INT_MAX; //Preguntar
    
    //Returns symbol
    return p->symbol; 
}

Status point_setCoordinateX (Point *p, int x)
{   
    //Error checking
    if(!p || x < 0)
        return ERROR;

    //Sets value
    p->x = x;

    return OK;
}

Status point_setCoordinateY (Point *p, int y) 
{
    //Error checking
    if(!p || y < 0)
        return ERROR;
    
    //Sets value
    p->y = y;

    return OK;
}

Status  point_setSymbol (Point *p, char c) 
{
    //Error checking
    if(!p)
        return ERROR;

    //Checks thats its a valid symbol
    if(is_valid_symbol(c) == FALSE)
        return ERROR;

    //Sets value
    p->symbol = c;

    return OK;
}

Point *point_hardcpy (const Point *src)
{   
    //Error checking
    if(!src)
        return NULL;
    
    //Creates a new pointer for the hardcopy
    Point *hardcopy = NULL;

    //Allocates memory and initializes the values to the corresponding values 
    hardcopy = point_new(point_getCoordinateX(src), point_getCoordinateY(src), point_getSymbol(src));

    //Error checking
    if (hardcopy == NULL)
        return NULL;
    
    //Returns pointer tto the new point
    return hardcopy;
}

Bool point_equal (const void *p1, const void *p2)
{   
    //Error checking 
    if(!p1 || !p2)
        return FALSE;
    
    //Compares X, Y and Symbol
    if(point_getCoordinateX(p1) == point_getCoordinateX(p2) && point_getCoordinateY(p1) == point_getCoordinateY(p2) && point_getSymbol(p1) == point_getSymbol(p2))  
        return TRUE;
          
    else
        return FALSE;
}

int point_print (FILE *pf, const void *p)
{   
    //Error checking
    if(!p || !pf)
        return -1;

    //Prints the point in the file and returns the number of things it wrote
    return fprintf(pf, " [(%d, %d): %c]", point_getCoordinateX(p), point_getCoordinateY(p), point_getSymbol(p));
}

Bool is_valid_symbol (char c)
{
    if(c == ERRORCHAR || c == INPUT || c == OUTPUT || c == BARRIER || c == SPACE)
        return TRUE;
    
    return FALSE;
}