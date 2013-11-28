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
    int x=100;
    int inter;
    char key;
    int c;
    string optfile = "up1: down1: left1: right1: fire1: up2: down2: left2: right2: fire2: ";
    
    while (1)
    {
        
        a[30 + 3*x][113] = ' '; //erase the alternate cursor
        x = displaymenu(a);
        if (x == -1) return;    //check if back is pressed
    
        //create the alternate cursor
        /////////////////////////////////////////////////////
        a[30 + 3*x][113] = ' ';
        a[30 + 3*x][113] = '<';
        for (int i=0; i<74; i++)
            for (int j=0; j<238; j++)
                mvaddch(i, j, a[i][j]);
        refresh();
        /////////////////////////////////////////////////////

        timeout(10000000);
        key = getch();
        
        if (key == '`' || key == '\n') continue; //check if back is pressed
        
        //switch if entry is the same as an existing one
        /////////////////////////////////////////////////////
        for (c=0; c<10; c++)
            if (c != x)
                if (key == controls[c])
                {
                    inter = controls[x];
                    controls[x] = controls[c];
                    controls[c] = inter;
                    break;
                }
        //////////////////////////////////////////////////////
        
        
        //Save changes to options file
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////
        output.open("/Users/Admin/Documents/Space Invaders/Space Invaders/Options.txt");

        c=0;
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
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////


    }
}
#endif
