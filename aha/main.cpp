#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

#define MAX 20
#define FUNDAL WHITE

int stanga,sus,width,height,latura, numar, x=1;
bool gata;

int TablaDeJoc[MAX][MAX];
int jucator=1;
int scor;
void initTabla(int tabla[MAX][MAX])
{
    int i,j;
    for(i=1; i<=7; i++)
        for(j=1; j<=7; j++)
        {
            if(((i==1 || j==1 || i==7 || j==7)&&abs(i-j)%3==0)||((i==2 || j==2 || i==6 || j==6)&&abs(i-j)%2==0))
                tabla[i][j]=0;
            else
                tabla[i][j]=-1;
        }
    for(i=3; i<=5; i++)
        for(j=3; j<=5; j++)
            tabla[i][j]=0;
    tabla[4][4]=-1;
}
void afiseazaScor()
{
    setcolor(FUNDAL);
    setcolor(BLUE);
    if(jucator==1)
        outtextxy(200,50,"Este randul jucatorului 1");
    else
        outtextxy(200,50,"Este randul jucatorului 2");
}
int verificaMoara(int tabla[MAX][MAX],int lin,int col)
{
    int i,suma;
    if(lin==4)
    {
        if(col<4)
            for(i=1; i<4; i++)
                suma+=tabla[lin][i];
        else if(col>4)
            for(i=5; i<=7; i++)
                suma+=tabla[lin][i];
    }
    if(col==4)
    {
        if(lin<4)
            for(i=1; i<4; i++)
                suma+=tabla[i][col];
        else if(lin>4)
            for(i=5; i<=7; i++)
                suma+=tabla[i][col];
    }
    for(i=1; i<=7; i++)
        suma+=tabla[lin][i];
    for(i=1; i<=7; i++)
        suma+=tabla[i][col];
    return suma;
}
void punerePiesa()
{
    int linia,coloana,x,y;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if (!(x>=stanga && x<=stanga+width && y>=sus&&y<=sus+height))
            gata=true;
        else
        {
            linia=(y-sus)/latura+1;
            coloana=(x-stanga)/latura+1;
            if (TablaDeJoc[linia][coloana]==0)
            {
                TablaDeJoc[linia][coloana]=1;
                // stergere
                setcolor(FUNDAL);
                setfillstyle(SOLID_FILL,FUNDAL);
                x1=stanga+latura*(coloana-1);
                y1=sus+latura*(linia-1);
                x2=x1+latura;
                y2=y1+latura;
                xmijloc=(x1+x2)/2;
                ymijloc=(y1+y2)/2;
                bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
                // afisez cerc rosu aprins
                if(jucator==1)
                {
                    setcolor(WHITE);
                    setfillstyle(SOLID_FILL,BLUE);
                }
                if(jucator==2)
                {
                    setcolor(LIGHTRED);
                    setfillstyle(SOLID_FILL,RED);
                }
                fillellipse(xmijloc,ymijloc,18,18);
                jucator=3-jucator;
            }
            else // 2-> 0
                if(TablaDeJoc[linia][coloana]==1)
                {
                    TablaDeJoc[linia][coloana]=0;
                    setcolor(FUNDAL);
                    setfillstyle(SOLID_FILL,FUNDAL);
                    x1=stanga+latura*(coloana-1);
                    y1=sus+latura*(linia-1);
                    x2=x1+latura;
                    y2=y1+latura;
                    xmijloc=(x1+x2)/2;
                    ymijloc=(y1+y2)/2;
                    bar(xmijloc-22,ymijloc-22,xmijloc+22,ymijloc+22);
                    //jucator=1-jucator;
                }
            afiseazaScor();
        }
    }
}

void desen()
{
    int i,j;
    numar=7;
    width=400;
    height=400;
    latura=width/numar;
    sus=(getmaxy()-width)/2;
    stanga=(getmaxx()-height)/2;
    setbkcolor(FUNDAL);
    clearviewport();
    setcolor(BLUE);
    for (i=1; i<=numar; i++)
        for (j=1; j<=numar; j++)
            if(((i==1 || j==1 || i==numar || j==numar)&&abs(i-j)%3==0)||((i==2 || j==2 || i==numar-1 || j==numar-1)&&abs(i-j)%2==0))
                rectangle(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*i,sus+latura*j);
    for(i=3; i<=5; i++)
        for(j=3; j<=5; j++)
            rectangle(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*i,sus+latura*j);

}

int main()
{
    initwindow(800,600);
    scor=0;
    int i,j;
    desen();
    afiseazaScor();
    initTabla(TablaDeJoc);
    gata=false;
    do
    {
        punerePiesa();
    }
    while (!gata);
    getch();
    closegraph();
    return 0;
}






//if(((linia==1 || coloana==1 || linia==7 || coloana==7)&&abs(linia-coloana)%3==0)||((linia==2 || coloana==2 || linia==6 || coloana==6)&&abs(linia-coloana)%2==0)||(linia>2 && linia<6 && coloana>2 && coloana<6))
