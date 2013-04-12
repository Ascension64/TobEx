#ifndef PATHFIND_H
#define PATHFIND_H

#define TERRAINCODE_OBSTACLE_OPAQUE			0
#define TERRAINCODE_DIRT					1
#define TERRAINCODE_METAL					2
#define TERRAINCODE_PLANK					3
#define TERRAINCODE_STONE_ECHO				4
#define TERRAINCODE_CARPET					5
#define TERRAINCODE_PUDDLE					6
#define TERRAINCODE_STONE_HARD				7
#define TERRAINCODE_OBSTACLE_TRANSPARENT	8
#define TERRAINCODE_WOOD_FIXED				9
#define TERRAINCODE_WALL					10
#define TERRAINCODE_WATER_SHALLOW			11
#define TERRAINCODE_WATER_DEEP				12
#define TERRAINCODE_MOUNTAIN				13
#define TERRAINCODE_WORLD_EXIT				14
#define TERRAINCODE_GRASS					15

struct CSearchBitmap;

struct TerrainTable { //Size 10h
//For use with search map, each bit corresponding to the search map pixel value
//0x05 = passable, 0xFF = impassable
//Typical for CCreatureObject is Ter1
//Everything else is Ter2/3
/*
Pixel	Col			R	G	B	Ter1	Ter2/3	SurfType
0		Black		0	0	0	-1		-1	Obstacle, light blocking
1		DarkRed		128	0	0	5		5	Dirt
2		DarkGreen	0	128	0	5		5	Metal
3		DarkYellow	128	128	0	5		5	Planks (e.g. rope bridge, stairs)
4		DarkBlue	0	0	128	5		5	Stone, echo-ey
5		DarkPink	128	0	128	5		5	Carpet
6		DarkAqua	0	128	128	5		5	Water puddle
7		LightGrey	192	192	192	5		5	Stone, hard
8		DarkGrey	128	128	128	-1		5	Obstacle, non light blocking
9		Red			255	0	0	5		5	Fixed wooden structures
10		Green		0	255	0	-1		-1	Wall
11		Yellow		255	255	0	5		5	Shallow water
12		Blue		0	0	255	-1		5	Deep water
13		Pink		255	0	255	-1		-1	Mountain/Building
14		Aqua		0	255	255	-1		5	World Map Exit
15		White		255	255	255	5		5	Grass
*/
	unsigned char type[16]; //0h
};

struct CSearchRequest { //Size 60h
	char m_serviceState; //0h, range: 0-5, (AACC98)4 = SERVICE_STALE
	char u1;
	int u2;
	char cEnemyAlly; //6h, of owner
	char u7;
	char u8; //numElements of array at u3c
	char u9;
	int ua;
	char ue;
	CSearchBitmap* m_pSearchMap; //10h
	TerrainTable tt; //14h
	BOOL u24; //gets value from Animation v58()
	int u28;
	ENUM e; //2ch, of owner
	int u30;
	int u34;
	int* u38;
	ENUM* u3c; //array of u8 ENUM targets
	int* u40;
	int u44;
	int u48;
	int u4c;
	int u50;
	int u54;
	short u58;
	short nPath; //5ah
	int* pPath; //5ch
};

#endif //PATHFIND_H