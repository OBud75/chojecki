
#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int x, y;
    struct Block *haut, *droite, *bas, *gauche;
} Block;

// carte struct
typedef struct Map {
    int height, width;
    Block*** blocks;
} Map;

// player
typedef struct Player {
    Block* position;
} Player;

// carte taille
Map* get_map(int height, int width) {
    Map* map = malloc(sizeof(Map));
    if (!map) {
        perror("Erreur");
        exit(EXIT_FAILURE);
    }

    map->height = height;
    map->width = width;

    // grille
    map->blocks = malloc(height * sizeof(Block**));
    if (!map->blocks) {
        perror("Erreur");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < height; i++) {
        map->blocks[i] = malloc(width * sizeof(Block*));
        if (!map->blocks[i]) {
            perror("Erreur");
            exit(EXIT_FAILURE);
        }
    }

    return map;
}


void load_blocks(Map* map) {
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            Block* current = malloc(sizeof(Block));
            if (!current) {
                perror("Erreur");
                exit(EXIT_FAILURE);
            }


            current->x = i;
            current->y = j;
            current->haut = (i > 0) ? map->blocks[i - 1][j] : NULL;
            current->gauche = (j > 0) ? map->blocks[i][j - 1] : NULL;
            current->bas = NULL;
            current->droite = NULL;


            if (current->haut) {
                current->haut->bas = current;
            }
            if (current->gauche) {
                current->gauche->droite = current;
            }


            map->blocks[i][j] = current;
        }
    }
}


void display_map(Map* map, Player* player) {
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            if (player->position == map->blocks[i][j]) {
                printf(" P ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}


void move_player(Player* player, char direction) {
    Block* current = player->position;

    switch (direction) {
        case 'z':
            if (current->haut) {
                player->position = current->haut;
                printf("haut\n");
            } else {
                printf("erreurn");
            }
            break;
        case 's':
            if (current->bas) {
                player->position = current->bas;
                printf("erreur\n");
            } else {
                printf("erreur\n");
            }
            break;
        case 'q':
            if (current->gauche) {
                player->position = current->gauche;
                printf("erreur\n");
            } else {
                printf("erreur\n");
            }
            break;
        case 'd':
            if (current->droite) {
                player->position = current->droite;
                printf("erreur\n");
            } else {
                printf("erreur\n");
            }
            break;
        default:
            printf("erreur\n");
            break;
    }
}

int main() {
    int height = 5, width = 5;


    Map* map = get_map(height, width);
    load_blocks(map);


    Player player;
    player.position = map->blocks[0][0];

    printf("matrice de jeu :\n");
    display_map(map, &player);

    char input;
    while (1) {
        printf("z: haut, q: gauche, s: bas, d: droite, x: quitter");
        scanf(" %c", &input);
        // scanf ne vide pas le buffer d'entrée comme std::endl par exemple
        // il faudrait ici utiliser quelque chose comme
        // int ch;
        // while ((ch = getchar()) != '\n' && ch != EOF)
        //      continue;
        // Possibilité aussi d'utiliser fgetchar ou fgetstring
        // char input;
        // input = fgetc(stdin);
        // Cela lit uniquement le 1er caractère et donc ne vide pas non plus
        // le buffer (même chose que précédement)

        // fgets lui lit tout le buffer d'entrée et donc le vide au passage
        // char buffer[10];
        // if (fgets(buffer, sizeof(buffer), stdin)) {input = buffer[0];}


        if (input == 'x') {
            printf("Quitter \n");
            break;
        }

        move_player(&player, input);
        printf("Carte mise à jour :\n");
        display_map(map, &player);
    }


    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            free(map->blocks[i][j]);
        }
        free(map->blocks[i]);
    }
    free(map->blocks);
    free(map);

    return 0;
}
