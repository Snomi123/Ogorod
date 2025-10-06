#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>

#define mapWidth 80
#define mapHeight 25

typedef struct SObject {
    float x, y;
    float width, height;
    float vertSpeed;
} TObject;

char map[mapHeight][mapWidth + 1];
TObject mario;

void ClearMap() {
    for (int i = 0; i < mapWidth; i++)
        map[0][i] = '.';
    map[0][mapWidth] = '\0';
    for (int j = 1; j < mapHeight; j++)
        snprintf(map[j], sizeof(map[j]), "%s", map[0]);
}

void ShowMap() {
    clear();
    for (int j = 0; j < mapHeight; j++) {
        mvprintw(j, 0, "%s", map[j]);
    }
    refresh();
}

void SetObjectPos(TObject *obj, float xPos, float yPos) {
    obj->x = xPos;
    obj->y = yPos;
}

void InitObject(TObject *obj, float xPos, float yPos, float oWidth, float oHeight) {
    SetObjectPos(obj, xPos, yPos);
    obj->width = oWidth;
    obj->height = oHeight;
    obj->vertSpeed = 0;
}

void VertMoveObject(TObject *obj){
    obj->vertSpeed += 0.05;
    SetObjectPos(obj, obj->x, obj->y + obj->vertSpeed);
}

void PutObjectOnMap(TObject obj) {
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);
    int iWidth = (int)round(obj.width);
    int iHeight = (int)round(obj.height);
    
    for (int i = ix; i < (ix + iWidth); i++) {
        for (int j = iy; j < (iy + iHeight); j++) {
            if (i >= 0 && i < mapWidth && j >= 0 && j < mapHeight) {
                map[j][i] = '@';
            }
        }
    }
}

int main() {
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    timeout(0);
    
    InitObject(&mario, 39, 10, 3, 3);
    
    int running = 1;
    while (running) {
        int ch = getch();
        if (ch == 27) {
            running = 0;
        }
        
        // Управление
        if (ch == KEY_LEFT) mario.x -= 1.5;
        if (ch == KEY_RIGHT) mario.x += 1.5;
        if (ch == KEY_UP) {
            mario.vertSpeed = -1.0;
        }
        
        VertMoveObject(&mario);
        
        if (mario.x < 0) mario.x = 0;
        if (mario.x > mapWidth - mario.width) mario.x = mapWidth - mario.width;
        
        if (mario.y > mapHeight - mario.height) {
            mario.y = mapHeight - mario.height;
            mario.vertSpeed = 0;
        }

        if (mario.y < 0) {
            mario.y = 0;
            mario.vertSpeed = 0.1;
        }
        
        ClearMap();
        PutObjectOnMap(mario);
        ShowMap();
        
        napms(50);  
    }
    
    move(0, 0);
    refresh();
    
    endwin();
    return 0;
}
