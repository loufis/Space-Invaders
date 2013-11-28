#include <iostream>
#include <ncurses.h>
#include <thread>
#include <string>
#include <fstream>
#include "Bullet.h"
#include "mainmenu.h"
#include "options.h"
void openmainmenu();
void openoptmenu();
void game();

using namespace std;

char up[2], down[2], lft[2], rt[2], fire[2];
char a[74][238];
enum mainchoices {Arcade, Custom, Cooperative, VS, Options, Highscore, back=-1};

void openoptmenu ()
{
    options opt;
    opt.displaytitle(a);
    opt.optmenu(a);
    openmainmenu();
}

void openmainmenu ()
{
    int x;
    mainmenu man;
    man.displaytitle(a);
    do
    {
        man.clearmenu(a);
        man.blink(a);
        x = man.displaymenu(a);
    }
    while(mainchoices(x) == back);

    switch (mainchoices(x))
    {
        case Arcade: {break;}
        case Custom: {break;}
        case Cooperative: {break;}
        case VS: {break;}
        case Options: {openoptmenu(); break;}
        case Highscore: {break;}
    }
}



void game()
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

    
    initscr();
 
    for (int i=0; i<74; i++)
        for (int j=0; j<238; j++)
            a[i][j] = ' ';
    
    openmainmenu();
    
    game();
    
    endwin();
    
    
    return 0;
}