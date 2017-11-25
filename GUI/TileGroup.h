//
// Created by Chloé Belguermi on 11/11/2017.
//

#ifndef NUMKINCH_TILEGROUP_H
#define NUMKINCH_TILEGROUP_H

#include <vector>
#include "Tile.h"

using namespace std;

class TileGroup : public Tile {

private:
    vector<Tile> _tiles;

public:
    TileGroup(const char * path, int x, int y, int w, int h);

};


#endif //NUMKINCH_TILEGROUP_H
