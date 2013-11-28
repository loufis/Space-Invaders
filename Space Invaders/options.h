#ifndef Space_Invaders_options_h
#define Space_Invaders_options_h
#include "menu.h"


class options: public menu
{
public:
    options();
    void optmenu(char[][238]);
    //void initoptions();
};

options::options()
{
    menu::menu();
    menusize = 10;
    titlesize = 6;
    
    screen[0] = "    ________            __   .__";
    screen[1] = "    \\_____  \\  ______ _/  |_ |__|  ____    ____    ______";
    screen[2] = "     /   |   \\ \\____ \\\\   __\\|  | /  _ \\  /    \\  /  ___/";
    screen[3] = "    /    |    \\|  |_> >|  |  |  |(  <_> )|   |  \\ \\___ \\";
    screen[4] = "    \\_______  /|   __/ |__|  |__| \\____/ |___|  //____  >";
    screen[5] = "            \\/ |__|                           \\/      \\/";
    //for (int i=6; i<12; i++)
      //  screen[i] = " ";
    
    choice[0] = "up:       ";
    choice[1] = "down:     ";
    choice[2] = "left:     ";
    choice[3] = "right:    ";
    choice[4] = "fire:     ";
    choice[5] = "up:       ";
    choice[6] = "down:     ";
    choice[7] = "left:     ";
    choice[8] = "right:    ";
    choice[9] = "fire:     ";
    
    for (int i=0; i<10; i++)
        choice[i] += "\"";
    
    choice[0] += up[0];
    choice[1] += down[0];
    choice[2] += lft[0];
    choice[3] += rt[0];
    choice[4] += fire[0];
    choice[5] += up[1];
    choice[6] += down[1];
    choice[7] += lft[1];
    choice[8] += rt[1];
    choice[9] += fire[1];
    
    for (int i=0; i<10; i++)
        choice[i] += "\"";
}

void options::optmenu(char a[][238])
{
    int x;
    char key;
    int c=0;
    string optfile = "up1: down1: left1: right1: fire1: up2: down2: left2: right2: fire2: ";
    
    while (1)
    {
    x = displaymenu(a);
    if (x == -1) return;
    
    
    timeout(10000000);
    key = getch();
    if (key == '`') continue;
    controls[x] = key;
    output.open("/Users/Admin/Documents/Space Invaders/Space Invaders/Options.txt");

    
    for (int i=0; i<10; i++)
    {
        while (optfile.at(c) != ' ')
            output << optfile.at(c++);
        c++;
        output << controls[i] << "\n";
    }
    output.close();
        
    up[0] = controls[0];
    down[0] = controls[1];
    lft[0] = controls[2];
    rt[0] = controls[3];
    fire[0] = controls[4];
    up[1] = controls[5];
    down[1] = controls[6];
    lft[1] = controls[7];
    rt[1] = controls[8];
    fire[1] = controls[9];
    
    for (int i=0; i<10; i++)
    {
        choice[i].erase(choice[i].size()-2, 2);
        choice[i] += controls[i];
        choice[i] += "\"";
    }
    }
}
#endif
