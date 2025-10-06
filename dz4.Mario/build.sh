#!/bin/bash
echo "Компиляция Super Mario для macOS с системным ncurses..."

EXE="super_mario"
C_FILE="super_mario.c"

if [ -f "$EXE" ]; then
    rm "$EXE"
fi

gcc $C_FILE -o $EXE -lncurses -lm

if [ $? -eq 0 ]; then
    echo "Успешно скомпилировано!"
    echo "Запуск: ./$EXE"
    ./$EXE
else
    echo "Ошибка компиляции"
fi
