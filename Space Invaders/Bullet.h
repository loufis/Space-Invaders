using namespace std;
#ifndef Space_Invaders_Bullet_h
#define Space_Invaders_Bullet_h
class Bullet
{
    char ud;
    int ypos, xpos;
    public:
    Bullet (int, int, char);
    void move (char [][238]);
};
#include "Bullet.cpp"
#endif


