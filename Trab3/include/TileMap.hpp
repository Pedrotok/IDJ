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
		int& at(int x, int y, int z = 0);
		void render(int cameraX = 0, int cameraY = 0);
		void renderLayer(int layer, int cameraX = 0, int cameraY = 0);
		int getWidth() const;
		int getHeight() const;
		int getDepth() const;
};

#endif