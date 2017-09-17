#include "Map.h"
#include <fstream>
#include "Game.h"

Map::Map()
{
	
}

Map::~Map()
{
	
}

void Map::LoadMap(std::string path, int sizeX, int sizeY)
{
	char tile;
	std::fstream mapFile;
	mapFile.open(path);

	for (int y = 0; y < sizeX; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			if(!mapFile.eof())
			{
				mapFile.get(tile);
				Game::AddTile(atoi(&tile), x * 32, y * 32);
				mapFile.ignore();
			}
		}
		mapFile.close();
	}
}