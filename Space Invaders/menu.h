#ifndef Space_Invaders_menu_h
#define Space_Invaders_menu_h
#include <string>
#include <ncurses.h>
#include <fstream>
class menu
{
protected:
    int crsr = 0;
    char key = ERR;
public:
    string screen[12], choice[20];
    char up[2], down[2], lft[2], rt[2], fire[2];
    char controls[10];
    menu();
    void displaytitle(char[][238]);
    int displaymenu(char[][238]);
    int menusize = 0, titlesize = 0;
    ifstream input;
    ofstream output;
};

menu::menu()
{
    input.open("/Users/Admin/Documents/Space Invaders/Space Invaders/Options.txt");
    
    for (int j=0; j<2; j++)
        for (int i=0; i<5; i++)
        {
            input.ignore(100,':');
            switch(i)
            {
                case 0: {up[j] = input.get(); break;}
                case 1: {down[j] = input.get(); break;}
                case 2: {lft[j] = input.get(); break;}
                case 3: {rt[j] = input.get(); break;}
                case 4: {fire[j] = input.get(); break;}
            }
        }
    input.close();
    controls[0] = up[0];
    controls[1] = down[0];
    controls[2] = lft[0];
    controls[3] = rt[0];
    controls[4] = fire[0];
    controls[5] = up[1];
    controls[6] = down[1];
    controls[7] = lft[1];
    controls[8] = rt[1];
    controls[9] = fire[1];
    
}


int menu::displaymenu(char a[][238])
{
    for (int i=0; i<menusize; i++)
        for (int j=0; j<choice[i].size(); j++)
            a[30 + 3*i][100+j] = choice[i].at(j);
    
    key = ERR;
    while (key != '\n')
    {
        key = ERR;
        a[30 + 3*crsr][99] = '>';
        
        for (int i=0; i<74; i++)
            for (int j=0; j<238; j++)
                mvaddch(i, j, a[i][j]);
        refresh();
        
        timeout(100);
        key = getch();
        
        a[30 + 3*crsr][99] = ' ';
        
        
        if ((key == up[0] || key == up[1]) && crsr != 0)
            crsr--;
        else
            if ((key == down[0] || key == down [1]) && crsr != menusize-1)
                crsr++;
    }
    for (int i=0; i<menusize; i++)
        for (int j=0; j<choice[i].size(); j++)
            a[30 + 3*i][100+j] = ' ';
    /*for (int i=0; i<74; i++)
        for (int j=0; j<238; j++)
            a[i][j] = ' ';*/
    return crsr;
}

void menu::displaytitle(char a[][238])
{
    bool revealed[12], seen[12][238], flag = true;
    int row, col;
    
    for (int i=0; i<titlesize; i++)
    {
        revealed[i] = false;
        for(int j=0; j<238; j++)
            seen[i][j] = false;
    }
    
    //Initialize the Title
    ///////////////////////////////////////////////////////////////////////////////////
    while (flag)
    {
        
        do
        {
            row = rand()%titlesize;
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
        for (int i=0; i<titlesize; i++)
            if (!revealed[i])
                flag = true;
        
        for (int i=0; i<74; i++)
            for (int j=0; j<238; j++)
                mvaddch(i, j, a[i][j]);
        
        refresh();
    }
    /////////////////////////////////////////////////////////////////////////////////////
}

#endif

