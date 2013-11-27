#include <iostream>
#include <ncurses.h>
#include <thread>
#include <string>
#include <ctime>
#include <fstream>
#include "Bullet.h"
using namespace std;

char up[2], down[2], left[2], right[2], fire[2];


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

void mainmenu (char a[][238])
{
    char key = ERR;
    int crsr = 0;
    string menu[6];
    menu[0] = "Arcade Mode";
    menu[1] = "Custom Mode";
    menu[2] = "Coopoerative Mode";
    menu[3] = "VS Mode";
    menu[4] = "Options";
    menu[5] = "Highscore Board";
    
    for (int i=0; i<6; i++)
        for (int j=0; j<menu[i].size(); j++)
            a[38 + 4*i][100+j] = menu[i].at(j);
    
    while (key != '\n')
    {
        key = ERR;
        a[38 + 4*crsr][99] = '>';
        
        for (int i=0; i<74; i++)
            for (int j=0; j<238; j++)
                mvaddch(i, j, a[i][j]);
        refresh();
        
        timeout(100);
        key = getch();
        
        a[38 + 4*crsr][99] = ' ';
        
        
        if ((key == up[0] || key == up[1]) && crsr != 0)
            crsr--;
        else
            if ((key == down[0] || key == down[1]) && crsr != 5)
                crsr++;
    }
    
     game(a);
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
    
    //Initialize the Space Invaders Logo
    ///////////////////////////////////////////////////////////////////////////////////
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
    ///////////////////////////////////////////////////////////////////////////////////
    
    //This loop blinks the "Press Any Key" sentence
    ///////////////////////////////////////////////////////////////////////////////////
    while (key == ERR)
    {
        
        for (int i=0; i<screen[12].size(); i++)
            a[30+13][105+i] = screen[12].at(i);
        
        for (int i=0; i<74; i++)
            for (int j=0; j<238; j++)
                mvaddch(i, j, a[i][j]);
        
        refresh();
        
        timeout(500);
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
    ///////////////////////////////////////////////////////////////////////////////////
    
    mainmenu(a);
    
}



int main()
{
    char a[74][238];
    ifstream input;
    ofstream output;
    
    
    initscr();
 
    //
    for (int i=0; i<74; i++)
        for (int j=0; j<238; j++)
            a[i][j] = ' ';
    
    startscreen(a);
    
    
    endwin();
    
    
    return 0;
}