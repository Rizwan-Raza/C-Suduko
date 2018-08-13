#include"rizzu\GRPHCS.H"
#include<conio.h>
short int a[9][9]=
{
    {5,3,9,1,4,0,6,8,0},
    {0,0,2,0,8,6,0,0,0},
    {0,0,0,9,0,3,4,2,5},
    {8,7,0,0,0,0,0,0,0},
    {9,0,0,0,0,0,0,0,6},
    {0,0,0,0,0,0,0,4,3},
    {1,2,6,4,0,9,0,0,0},
    {0,0,0,3,1,0,2,0,0},
    {0,9,8,0,6,7,1,5,4}
},b[9][9]=
{
    {5,3,9,1,4,0,6,8,0},
    {0,0,2,0,8,6,0,0,0},
    {0,0,0,9,0,3,4,2,5},
    {8,7,0,0,0,0,0,0,2},
    {9,0,0,0,0,0,0,0,6},
    {0,0,0,0,0,0,0,4,3},
    {1,2,6,4,0,9,0,0,0},
    {0,0,0,3,1,0,2,0,0},
    {0,9,8,2,6,7,1,5,4}
},sol[9][9]=
{
    {5,3,9,1,4,2,6,8,7},
    {7,4,2,5,8,6,3,9,1},
    {6,8,1,9,7,3,4,2,5},
    {8,7,4,6,3,5,9,1,2},
    {9,1,3,8,2,4,5,7,6},
    {2,6,5,7,9,1,8,4,3},
    {1,2,6,4,5,9,7,3,8},
    {4,5,7,3,1,8,2,6,9},
    {3,9,8,2,6,7,1,5,4}
},i,j,move=0;
void printrem() {
    textbackground(14);
    textcolor(12);
    gotoxy(61,16);
    printf("%02d",move);
    textbackground(10);
}
void printmove()
{
    drawbgcolor(57,12,10,3,1,12);
    textbackground(12);
    textcolor(1);
    gotoxy(59,13);
    printf("Moves:");
    drawbgcolor(57,15,10,3,12,14);
    printrem();
}
void printfnum()
{
    textcolor(12);
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            gotoxy(11+j*4,9+i*2);
            if(a[i][j]==0)
            {
                printf("   ");
                continue;
            }
            printf(" %d ",a[i][j]);
        }
    }
    printrem();
}
int endGame()
{
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(a[i][j]!=sol[i][j])
                return 0;
        }
    }
    return 1;
}
int main()
{
    char c;
    int x=12,y=9;
    setbkcolor(1);
    setConSize(80,30);
    drawBox2(1,1,78,27,1,10);
    gotoxy(1, 30);
    printf("Press W, S, A and D for movement of cursor and then input number.");
    drawbgcolor(10,3,37,3,14,12);
    textcolor(1);
    gotoxy(25,4);
    printf("SUDUKU");
    drawSuduku99(10,8,4,2,1,10,1);
    printmove();
    while(!endGame())
    {
        if(x<12)
            x=44;
        else if(x>46)
            x=12;
        if(y<9)
            y=25;
        else if(y>25)
            y=9;
        printfnum();
        gotoxy(x,y);
        c=getch();
        if(c=='w')
            gotoxy(x,y-=2);
        else if(c=='s')
            gotoxy(x,y+=2);
        else if(c=='a')
            gotoxy(x-=4,y);
        else if(c=='d')
            gotoxy(x+=4,y);
        else if(c>='1' && c <='9')
        {
            printf("%c",c);
            a[y/2-4][x/4-3]=c-48;
            move++;
        } else if (c == '*') {
            clrscr();
            exit(0);
        }
    }
    clrscr();
    gotoxy(12,12);
    printf("You Win. Moves used: %d", move);
    return 0;
}
