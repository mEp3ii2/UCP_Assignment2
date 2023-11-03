#ifndef MAPSTRUCT_H
#define MAPSTRUCT_H

typedef struct {
    int ** map;
    int row;
    int col;
    int goalrow;
    int goalcol;
} Map;

#endif