#include <iostream>
#include <ncurses.h>
#include <thread>
#include <string>
#include <fstream>
#include "Bullet.h"
#include "mainmenu.h"
using namespace std;

char up[2], down[2], lft[2], rt[2], fire[2];

void game(char a[][238])
{
    char key;
    thread* t;
    Bullet* amo;
        
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


int main()
{
    char a[74][238];
    
    initscr();
 
    for (int i=0; i<74; i++)
        for (int j=0; j<238; j++)
            a[i][j] = ' ';
    
    //startscreen(a);
    
    mainmenu abc;
    abc.displaytitle(a);
    abc.blink(a);
    abc.displaymenu(a);
    game(a);
    
    endwin();
    
    
    return 0;
}