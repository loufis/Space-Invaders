#include <string>
#include <ncurses.h>
#include <fstream>
#ifndef Space_Invaders_menu_h
#define Space_Invaders_menu_h
class menu
{
protected:
    int crsr = 0;
    char key = ERR;
public:
    string screen[12], choice[20];
    char up[2], down[2], lft[2], rt[2], fire[2];
    menu();
    void displaytitle(char[][238]);
    void displaymenu(char[][238]);
};
#endif

menu::menu()
{
    ifstream input;
    ofstream output;
    
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
}

void menu::displaytitle(char a[][238])
{
    bool revealed[12], seen[12][238], flag = true;
    int row, col;
    
    for (int i=0; i<12; i++)
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
    /////////////////////////////////////////////////////////////////////////////////////
}

void menu::displaymenu(char a[][238])
{
    for (int i=0; i<12; i++)
        for (int j=0; j<choice[i].size(); j++)
            a[38 + 4*i][100+j] = choice[i].at(j);
    
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
            if ((key == down[0] || key == down [1]) && crsr != 5)
                crsr++;
    }

}
