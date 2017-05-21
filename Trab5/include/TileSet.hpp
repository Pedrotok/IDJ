#ifndef TILESET_H_
#define TILESET_H_

#include "Sprite.hpp"
#include <string>

class TileSet{
	Sprite tileSet;

	int rows, columns;
	int tileWidth, tileHeight;
	int numberTiles;

	public:
		TileSet(int _tileWidth, int _tileHeight, std::string file);
		void render(unsigned index, float x, float y);
		int getTileWidth() const;
		int getTileHeight() const;
};

#endif