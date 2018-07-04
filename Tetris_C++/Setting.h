#pragma once

CONSOLE_CURSOR_INFO cursor;

cursor.bVisible = 0;
cursor.dwSize = 1;
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

system("title Tetris (https://sjy_9484.blog.me/)");
system("color 70");
system("mode con: cols=50 lines=25");