#include <ncurses.h>
#include <string>
#include "menu.h"
#ifndef Space_Invaders_mainmenu_h
#define Space_Invaders_mainmenu_h
class mainmenu: public menu
{
public:
    mainmenu();
    void blink (char[][238]);
};
#endif

mainmenu::mainmenu()
{
    screen[0] = "    _________                                                                   ";
    screen[1] ="    /   _____/______ _____     ____   ____                                      ";
    screen[2] ="    \\_____  \\ \\____ \\\\__  \\  _/ ___\\_/ __ \\                                     ";
    screen[3] ="    /        \\|  |_> >/ __ \\_\\  \\___\\  ___/                                     ";
    screen[4] ="   /_______  /|   __/(____  / \\___  >\\___  >                                    ";
    screen[5] ="           \\/ |__|        \\/      \\/     \\/                                     ";
    screen[6] ="                    .___                           .___                       ";
    screen[7] ="                    |   |  ____ ___  _______     __| _/ ____ _______  ______  ";
    screen[8] ="                    |   | /    \\\\  \\/ /\\__  \\   / __ |_/ __ \\\\_  __ \\/  ___/  ";
    screen[9] ="                    |   ||   |  \\\\   /  / __ \\_/ /_/ |\\  ___/ |  | \\/\\___ \\   ";
    screen[10] ="                    |___||___|  / \\_/  (____  /\\____ | \\___  >|__|  /____  >  ";
    screen[11] ="                              \\/            \\/      \\/     \\/            \\/    ";
    
    choice[0] = "Arcade Mode";
    choice[1] = "Custom Mode";
    choice[2] = "Coopoerative Mode";
    choice[3] = "VS Mode";
    choice[4] = "Options";
    choice[5] = "Highscore Board";
}

void mainmenu::blink(char a[][238])
{
    string blinker = "Press Any Key";
    while (1)
    {
        for (int i=0; i<blinker.size(); i++)
            a[30+13][105+i] = blinker.at(i);
        
        for (int i=0; i<74; i++)
            for (int j=0; j<238; j++)
                mvaddch(i, j, a[i][j]);
        
        refresh();
        
        timeout(500);
        key = getch();
        if (key != ERR) break;
        
        for (int i=0; i<blinker.size(); i++)
            a[30+13][105+i] = ' ';
        
        for (int i=0; i<74; i++)
            for (int j=0; j<238; j++)
                mvaddch(i, j, a[i][j]);
        
        refresh();
        
        key = getch();
        if (key != ERR) break;
    }
    for (int i=0; i<blinker.size(); i++)
        a[30+13][105+i] = ' ';
}

