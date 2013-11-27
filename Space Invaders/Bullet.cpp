#include "Bullet.h"
#include <thread>

Bullet::Bullet (int y, int x, char updown)
{
    ypos = y;
    xpos = x;
    ud = updown;
}

void Bullet::move (char a[][238])
{
    if (ud == 'd')
    {
        while (ypos != 73 && a[ypos+1][xpos] == ' ')
        {
            ypos++;
            a[ypos-1][xpos] = ' ';
            a[ypos][xpos] = 'v';
            std::chrono::milliseconds dura(100);
            this_thread::sleep_for(dura);
        }
            a[ypos+1][xpos] = ' ';
    }
    else
        while (ypos != 0 && a[ypos][xpos] != '=')
        {
            ypos--;
            a[ypos+1][xpos] = ' ';
            a[ypos][xpos] = '^';
            std::chrono::milliseconds dura(100);
            this_thread::sleep_for(dura);
        }
        a[ypos][xpos] = ' ';
}