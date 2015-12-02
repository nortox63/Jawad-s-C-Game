#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#endif
#include <stdio.h>

#define MAX 10

char laby[MAX][MAX] = {
"-------------",
"|  -        |",
"| -- -- --  |",
"|           |",
"| ---- - -  |",
"|    -      |",
"| -- ---    |",
"| -------   |",
"|           |",
"|------- -  |"
};

int MyGetch()
{
#ifdef _WIN32
    return getch();
#endif
// trouver alternative hors Windows.
}

void Locate(int x,int y)
{
#ifdef _WIN32
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD C;
    C.X=(SHORT)x;
    C.Y=(SHORT)y;
    SetConsoleCursorPosition(H,C);
#endif
    // trouver alternative hors Windows.
}

void Afficher(int x,int y)
{
    int i,j;
    Locate(0,0);
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            if (i==x && j==y)
                printf("p");
            else
                printf("%c",laby[i][j]);
        }
        printf("\n");
    }
}

void TryMove(int* x,int* y,int vx,int vy)
{
    if (laby[*x+vx][*y+vy]=='-')
        return;
    (*x)+=vx;
    (*y)+=vy;
}

int main()
{
    int x,y;  // position joueur
    int touche;
    x = y = 1;
    touche = 0;
    while(touche!=27) // ECHAP
    {
        Afficher(x,y);
        touche = MyGetch();
        switch(touche)
        {
        case 'q':
            TryMove(&x,&y,0,-1);
            break;
        case 'd':
            TryMove(&x,&y,0,1);
            break;
        case 'z':
            TryMove(&x,&y,-1,0);
            break;
        case 's':
            TryMove(&x,&y,1,0);
        default:
            break;
        }
    }
    return 0;
}

