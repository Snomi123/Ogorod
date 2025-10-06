#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses.h>

#define mapWidth 80
#define mapHeight 25

typedef struct SObject {
    float x, y;
    float width, height;
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
        
        if (ch == KEY_LEFT) mario.x--;
        if (ch == KEY_RIGHT) mario.x++;
        if (ch == KEY_UP) mario.y--;
        if (ch == KEY_DOWN) mario.y++;
        
        if (mario.x < 0) mario.x = 0;
        if (mario.y < 0) mario.y = 0;
        if (mario.x > mapWidth - mario.width) mario.x = mapWidth - mario.width;
        if (mario.y > mapHeight - mario.height) mario.y = mapHeight - mario.height;
        
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
