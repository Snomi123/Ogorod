#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses.h>

#define mapWidth 80
#define mapHeight 25

typedef struct SObject {
    float x,y;
    float width, height;
} TObject;

char map[mapHeight][mapWidth+1];
TObject mario;

void ClearMap(){
    for (int i = 0; i < mapWidth; i++)
        map[0][i] = '.';
    map[0][mapWidth] = '\0';
    for (int j = 1; j < mapHeight; j++)
        sprintf(map[j], map[0]);
}

void ShowMap(){
    map[mapHeight - 1][mapWidth - 1] = '\0';
    for (int j = 0; j < mapHeight; j++)
        printw("%s\n", map[j]);  // Изменено на printw для ncurses
}

void SetObjectPos(TObject *obj, float xPos, float yPos){
    (*obj).x = xPos;
    (*obj).y = yPos;
}

void InitObject(TObject *obj, float xPos, float yPos, float oWidth, float oHeight){  // Исправлено: oHeigth -> oHeight
    SetObjectPos(obj, xPos, yPos);
    (*obj).width = oWidth;
    (*obj).height = oHeight;
}

void PutObjectOnMap(TObject obj){
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);  // Исправлено: было round(obj.x) вместо obj.y
    int iWidth = (int)round(obj.width);
    int iHeight = (int)round(obj.height);  // Исправлено: Height -> iHeight
    
    for (int i = ix; i < (ix + iWidth); i++)  // Исправлено: добавил ;
        for (int j = iy; j < (iy + iHeight); j++)
            map[j][i] = '@';
    
    map[iy][ix] = '@';
}

int main(){
    // Инициализация ncurses
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);  // Скрыть курсор (аналог hide_cursor())
    timeout(0);   // Неблокирующий ввод
    
    InitObject(&mario, 39, 10, 3, 3);
    
    bool running = true;
    while (running) {
        // Проверка нажатия ESC
        int ch = getch();
        if (ch == 27) {  // 27 - код клавиши ESC
            running = false;
        }
        
        ClearMap();
        PutObjectOnMap(mario);
        clear();    // Очистка экрана ncurses
        ShowMap();
        refresh();  // Обновление экрана ncurses
        napms(50);  // Небольшая задержка для снижения нагрузки на CPU
    }
    
    endwin();  // Завершение работы с ncurses
    return 0;
}
