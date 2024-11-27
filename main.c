#include <stdbool.h>
#include <stdio.h>

int toIndex(int x, int y, int size){
    if(x >= size || y >= size){
        return -1;
    }
    return y*size + x;
}

int isValid(int x, int y, bool* visited, int size) {
    if(x >= size || x < 0 || y >= size || y < 0) {
        return 0;
    }
    if(visited[toIndex(x, y, size)]) {
        return 0;
    }
        return 1;
}

bool solveKnightTour(int x, int y, int moveCount, int size, bool* visited, int *op) {
    printf("Move: %d \t Operation: %lu \n", moveCount, *op);
    for(int j = 0; j < (size*size); j ++) {
        if(visited[j]) {
            printf("x");
        }else {
            printf("O");
        }
        if((j+1) % size == 0 && j != 0) {
            printf("\n");
        }
    }
    int dx[8] = {2, 1, -2, -1, 2, 1, -2, -1};
    int dy[8] = {1, 2, -1, -2, -1, -2, 1, 2};
    for(int i = 0; i < 8; i++) {
        *op += 1;
        int posX = x + dx[i];
        int posY = y + dy[i];
        if(isValid(posX, posY, visited, size) == 1) {
            visited[toIndex(posX, posY, size)] = true;
            if(solveKnightTour(posX, posY, moveCount++, size, visited, op)) {
                if(moveCount == (size*size)-1) {
                    return true;
                }
            }else {
                visited[toIndex(posX, posY, size)] = false;
            }
        }
    }
    return false;
}

int main(void) {
    unsigned long op = 0;
    int n = 8;
    bool visited[(n*n)-1];
    visited[0] = true;
    for(int i = 1; i < (n*n)-1; i++){
        visited[i] = false;
    }
    solveKnightTour(0, 0, 0, n, visited, &op) ? printf("Weg gefunden\n") : printf("Kein Weg moeglich\n");
    return 0;
}
