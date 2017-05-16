#include "../include/TileSet.hpp"

TileSet::TileSet(int _tileWidth, int _tileHeight, std::string file) : tileSet(file){
	tileWidth = _tileWidth;
	tileHeight = _tileHeight;

	rows = tileSet.getHeight()/tileHeight;
	columns = tileSet.getWidth()/tileWidth;

	numberTiles = rows*columns;
}

void TileSet::render(unsigned index, float x, float y){
	if(index < numberTiles){
		int row = index/columns;
		int col = index%columns;

		tileSet.setClip(tileHeight*col, tileWidth*row, tileWidth, tileHeight);
	
		tileSet.render(x,y);
	}
	else
		printf("Tile %u not found\n", index);
}

int TileSet::getTileWidth() const{
	return tileWidth;
}

int TileSet::getTileHeight() const{
	return tileHeight;
}
