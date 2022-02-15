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
    //Pointer to the map we want to create
    Map *newMap = NULL;

    //Allocate memory
    newMap = (Map*) malloc (sizeof(Map));
    if(!newMap)
        return NULL;

    //Inicializes the values
    newMap->nrows = nrows;
    newMap->ncols = ncols;
    newMap->output = NULL;
    newMap->input = NULL;

    //Allocates the memory for each point
    for(int i = 0; i < nrows; i++)
    {
        for(int j = 0; j < ncols; j++)
        {
            newMap->array[i][j] = NULL;
        }
    }
    return newMap; 
}
void map_free (Map *g)
{

}

Point *map_insertPoint (Map *mp, Point *p)
{
    if(!mp || !p)
        return NULL;
    
    mp->array[point_getCoordinateX(p)][point_getCoordinateY(p)] = point_hardcpy(p);
    
    return mp->array[point_getCoordinateX(p)][point_getCoordinateY(p)];

}
int map_getNcols (const Map *mp)
{

}
int map_getNrows (const Map *mp)
{
    if(!mp)
        return -1;
    return mp->nrows;
}

Point *map_getPoint (const Map *mp, const Point *p)
{

}

Point *map_getNeighboor(const Map *mp, const Point *p, Position pos)
{   
    Point* neighboorPoint = NULL;
    Point* mapNeighboorPoint = NULL;
    if(!mp || !p)
        return NULL;
    
    switch (pos)
    {
    case 0:
      neighboorPoint = point_hardcpy(mp->array[point_getCoordinateX(p) + 1][point_getCoordinateY(p)]);
      map_getPoint(mp, neighboorPoint);
      break;

    case 1:
      neighboorPoint = point_hardcpy(mp->array[point_getCoordinateX(p)][point_getCoordinateY(p) - 1]);
      map_getPoint(mp, neighboorPoint);
      break;
    
    case 2:
      neighboorPoint = point_hardcpy(mp->array[point_getCoordinateX(p) -1][point_getCoordinateY(p)]);
      map_getPoint(mp, neighboorPoint);
      break;
    
    case 3:
      neighboorPoint = point_hardcpy(mp->array[point_getCoordinateX(p)][point_getCoordinateY(p) + 1]);
      map_getPoint(mp, neighboorPoint);
      break;

    case 4:
      neighboorPoint = point_hardcpy(mp->array[point_getCoordinateX(p)][point_getCoordinateY(p)]);
      map_getPoint(mp, neighboorPoint);
      break;

    default:
      return NULL;
    }
    point_free(neighboorPoint);
    return neighboorPoint;
}
Bool map_equal (const void *_mp1, const void *_mp2)
{

}
int map_print (FILE*pf, Map *mp)
{
    //Error checking
    if(!mp || !pf)
        return -1;

    //Prints the point in the file and returns the number of things it wrote
    return fprintf(pf, " [(%d, %d): %c]", point_getCoordinateX(p), point_getCoordinateY(p), point_getSymbol(p));
}