#ifndef TILEMAP_H_
#define TILEMAP_H_

#include "Sprite.hpp"
#include "TileSet.hpp"
#include <string>
#include <vector>

class TileMap{
	std::vector<int> tileMatrix;
	TileSet* tileSet;
	int mapWidth, mapHeight, mapDepth;

	public:
		TileMap(std::string file, TileSet* _tileSet);
		void load(std::string file);
		void setTileSet(TileSet* _tileSet);
		int& at(int x, int y, int z);
		void render(int cameraX, int cameraY);
		void renderLayer(int layer, int cameraX, int cameraY);
		int getWidth() const;
		int getHeight() const;
		int getDepth() const;
};

#endif