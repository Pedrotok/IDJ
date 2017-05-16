#include "../include/TileSet.hpp"

TileSet::TileSet(int _tileWidth, int _tileHeight, std::string file){
	tileWidth = _tileWidth;
	tileHeight = _tileHeight;
	tileSet = *(new Sprite(file));

	rows = tileSet.getHeight()/tileHeight;
	columns = tileSet.getWidth()/tileWidth;

	printf("%d %d\n", rows, columns);

	numberTiles = rows*columns;
}

void TileSet::render(unsigned index, float x, float y){
	if(index >= 0 && index < numberTiles){
		int row = index/columns;
		int col = index%columns;

		tileSet.setClip(tileWidth*row, tileHeight*col, tileWidth, tileHeight);
	
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
