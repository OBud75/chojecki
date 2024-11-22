#include <stdio.h>
#include <stdlib.h>

typedef struct Map {
	int height;
	int width;
] Map;

typedef struct Block {
	int pos_x;
	int pos_y;
	struct Block* top, right, bot, left;
} Block;

typedef struct Player {
	struct Block* position;
}Player;

Map* get_map(int height, int width);
void load_blocks(Map* map);	
void move(Player* player, char direction);
// direction 't', 'r', 'b','l'
