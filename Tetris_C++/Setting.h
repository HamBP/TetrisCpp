#pragma once

CONSOLE_CURSOR_INFO cursor;

cursor.bVisible = 0;
cursor.dwSize = 1;
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

system("title Tetris (sjy_9484@naver.com)");
system("color 70");
system("mode con: cols=60 lines=25");