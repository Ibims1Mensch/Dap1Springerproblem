#include <stdbool.h>
#include <stdio.h>

int toIndex(int x, int y, int size){ // Returns -1 if the x, y Coordinates are not in the array, and the index of the field when its in Bounds
    if(x >= size || y >= size){
        return -1;
    }
    return y*size + x;
}

int isValid(int x, int y, bool* visited, int size) {//returns 0 on an unvalid field and 1 on an Valid field
    if(x >= size || x < 0 || y >= size || y < 0) {
        return 0; //Field is not on the Board
    }
    if(visited[toIndex(x, y, size)]) {
        return 0; // Field has allready been visited
    }
        return 1; // Field is valid
}

bool solveKnightTour(int x, int y, int moveCount, int size, bool* visited) {
    printf("Move: %d\n", moveCount);
    int dx[8] = {2, 1, -2, -1, 2, 1, -2, -1};
    int dy[8] = {1, 2, -1, -2, -1, -2, 1, 2};
    for(int i = 0; i < 8; i++) { // try out new moves till there are no more left or a solution has been found
        int posX = x + dx[i]; // New Positions after Move
        int posY = y + dy[i];
        if(isValid(posX, posY, visited, size) == 1) { // if the move is Vallid
            visited[toIndex(posX, posY, size)] = true;
            if(solveKnightTour(posX, posY, moveCount++, size, visited)) { // if the next move was succesfull
                if(moveCount == (size*size)-1) { // if all fields have been visited
                    return true;
                }
            }else { // if there was a "dead end" in later moves
                visited[toIndex(posX, posY, size)] = false;
            }
        }
    }
    return false;
}

int main(void) {
    int n = 8;
    bool visited[(n*n)-1];
    visited[0] = true; // set starting pos as Visited
    for(int i = 1; i < (n*n)-1; i++){
        visited[i] = false;
    }
    solveKnightTour(0, 0, 0, n, visited) ? printf("Weg gefunden\n") : printf("Kein Weg moeglich\n");
    return 0;
}
