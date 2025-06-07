#pragma once

#include <windows.h>

typedef struct Block {
    RECT rt;
    bool lava_plag;
    bool floor_plag;
    bool grass_plag;
}block;



extern block blocks[149];

void init_blocks();