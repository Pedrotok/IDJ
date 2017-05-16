#include "../include/TileMap.hpp"
#include <fstream>

TileMap::TileMap(std::string file, TileSet* _tileSet){
	tileSet = _tileSet;
	load(file);
}

void TileMap::load(std::string file){
	std::ifstream myFile;
	myFile.open(file);
	std::string value;

	std::getline(myFile, value, ',');
	mapHeight = std::stoi(value);
	std::getline(myFile, value, ',');
	mapWidth = std::stoi(value);
	std::getline(myFile, value, ',');
	mapDepth = std::stoi(value);

	while(std::getline(myFile, value, ',') && value != "\n"){
		tileMatrix.push_back(std::stoi(value)-1);
	}
}

void TileMap::setTileSet(TileSet* _tileSet){
	tileSet = _tileSet;
}

int& TileMap::at(int x, int y, int z = 0){
	int pos = (x*mapWidth + y) + z*mapWidth*mapHeight;
	return pos;
}

void TileMap::render(int cameraX = 0, int cameraY = 0){
	for(int i = 0; i < mapDepth; i++)
		renderLayer(i,cameraX,cameraY);
}

void TileMap::renderLayer(int layer, int cameraX = 0, int cameraY = 0){
	for(int i = layer*mapWidth*mapHeight, j = 0; i < (layer+1)*mapWidth*mapHeight; i++, j++){
		if(tileMatrix[i] != -1){
			int newX = (j%mapWidth)*mapHeight + cameraX;
			int newY = (j/mapWidth)*mapWidth + cameraY;
			tileSet->render(tileMatrix[i],newX, newY);
		}
	}
}

int TileMap::getWidth() const{
	return mapWidth;
}

int TileMap::getHeight() const{
	return mapHeight;
}

int TileMap::getDepth() const{
	return mapDepth;
}
