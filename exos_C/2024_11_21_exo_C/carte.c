#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void display_matrix(char matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c  ", matrix[i][j]);
        }
        printf("\n");
    }
}


void move_player(char matrix[SIZE][SIZE], int *x, int *y, char direction) {
    matrix[*x][*y] = '.';  
    
    switch (direction) {
        case 'z': 
            if (*x > 0) {
                (*x)--;
            }
            break;
        case 's': 
            if (*x < SIZE - 1) {
                (*x)++;
            }
            break;
        case 'q': 
            if (*y > 0) {
                (*y)--;
            }
            break;
        case 'd': 
            if (*y < SIZE - 1) {
                (*y)++;
            }
            break;
        default:
            printf("erreur\n");
            return;
    }

    matrix[*x][*y] = 'P'; 
}

int main() {
    char matrix[SIZE][SIZE];
    int x = SIZE - 1, y = SIZE / 2; 

   
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = '.';
        }
    }

    matrix[x][y] = 'P'; 

    
    display_matrix(matrix);

    char input;
    while (1) {
        
        printf("touches à utiliser : z = haut, s = bas, q = gauche, d = droite, x = quitter\n");
        printf("azppuyez sur la touche pour bouger le joueur: ");
        scanf(" %c", &input); 

        if (input == 'x') {
            break; 
        }

        
        move_player(matrix, &x, &y, input);

        
        display_matrix(matrix);
    }

    return 0;
}
