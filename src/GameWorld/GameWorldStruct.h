//
// GameWorldStruct.h
//
//
//

#ifndef _GAMEWORLDSTRUCT_H_
#define _GAMEWORLDSTRUCT_H_

typedef struct s_WorldPoint
{
   int x;
   int y;
} WorldPoint;

typedef struct s_MapInfoData
{
   int visibility;
   bool occupied;
   bool discovered;
   bool isCrossable;
   list<int> items;
};

#endif
