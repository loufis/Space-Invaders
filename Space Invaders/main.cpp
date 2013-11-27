#include <iostream>
#include <ncurses.h>
#include <thread>
#include <string>
#include <ctime>
#include "Bullet.h"
using namespace std;

void game(char a[][238])
{
    char key;
    thread* t;
    Bullet* amo;
    
    srand(time(NULL));
    
    while(1)
    {
        key = '0';
        
        refresh();
        
        for (int i=0; i<74; i++)
            for (int j=0; j<238; j++)
                mvaddch(i, j, a[i][j]);
        
        timeout(100);
        key = getch();
        
        if (key == ' ')
        {
            amo = new Bullet(10, 100,'d');
            t = new thread(&Bullet::move, ref(amo), a);
            t->detach();
        }
    }
}

void startscreen(char a[][238])
{
    char key = ERR;
    bool revealed[12], seen[12][238], flag = true;
    string screen[16];
    int row, col;
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
    screen[12] = "Press Any Key";
    
    for (int i=0; i<12; i++)
    {
        revealed[i] = false;
        for(int j=0; j<238; j++)
            seen[i][j] = false;
    }
    
    while (flag)
    {
        
        do
        {
            row = rand()%12;
        } while (revealed[row]);
        
        do
        {
            col = rand()%screen[row].size();
        } while (seen[row][col]);
        
        
        /*for (int i=0; i<12; i++)
         for (int j=0; j<screen[i].size(); j++)
         a[i+20][j+70] = screen[i].at(j);*/
        a[15+row][75+col] = screen[row].at(col);
        seen[row][col] = true;
        
        
        revealed[row] = true;
        for (int i=0; i<screen[row].size(); i++)
            if (!seen[row][i])
                revealed[row] = false;
        
        
        flag = false;
        for (int i=0; i<12; i++)
            if (!revealed[i])
                flag = true;
        
        for (int i=0; i<74; i++)
            for (int j=0; j<238; j++)
                mvaddch(i, j, a[i][j]);
        
        refresh();
    }
    
    while (key == ERR)
    {
        
        for (int i=0; i<screen[12].size(); i++)
            a[30+13][105+i] = screen[12].at(i);
        
        for (int i=0; i<74; i++)
            for (int j=0; j<238; j++)
                mvaddch(i, j, a[i][j]);
        
        refresh();
        
        timeout(1000);
        key = getch();
        
        for (int i=0; i<screen[12].size(); i++)
            a[30+13][105+i] = ' ';
        
        for (int i=0; i<74; i++)
            for (int j=0; j<238; j++)
                mvaddch(i, j, a[i][j]);
        
        refresh();
        
        //timeout(500);
        key = getch();
    }
    
    while (1)
    {
        
    }
    
    game(a);
    
        
}



int main()
{
    char a[74][238];

    initscr();
 
    for (int i=0; i<74; i++)
        for (int j=0; j<238; j++)
            a[i][j] = ' ';
    
    startscreen(a);
    
    
    endwin();
    
    
    return 0;
}