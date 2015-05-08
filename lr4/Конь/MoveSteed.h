#ifndef MOVESTEED_H_INCLUDED
#define MOVESTEED_H_INCLUDED

#include "list.h"
#include "Math.h"

typedef int Chessboard[8][8];

struct Move
{
    Coord current_position;
    List *move;
};

#endif // MOVESTEED_H_INCLUDED
