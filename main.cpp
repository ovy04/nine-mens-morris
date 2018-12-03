#include <iostream>

using namespace std;

int pieseramase1, pieseramase2;
int TablaDeJoc[8][8],pl;

void afisareTablaDeJoc()
{
    for (int i=1; i<8; i++)
    {
        for (int j=1; j<8; j++)
            cout<<TablaDeJoc[i][j]<<" ";
        cout<<"\n";

    }
    cout<<"\n";
}

bool esteBunaPozitia (int TablaDeJoc[8][8], int i, int j)
{
    if (TablaDeJoc[i][j]!=0)
        return false;
    else if (i==4 && j==4)
        return false;
    else if (i==j || i+j==8)
        return true;
    else if ((i==4 && j!=4) || (j==4 && i!=4))
        return true;
    else if (i==3 && (j==3 || j==4 || j==5))
        return true;
    else if (i==5 && (j==3 || j==4 || j==5))
        return true;
    else
        return false;
}
//test
bool test (int TablaDeJoc[8][8], int i, int j)
{
    int var;
    if (i==j)
    {
        var=TablaDeJoc[i][j];
        if (TablaDeJoc[i][4]==var && TablaDeJoc[4][i]==var)
            return true;
    }
    else if (i+j==8)
    {
        var=TablaDeJoc[i][j];
        if (TablaDeJoc[4][j]==var && TablaDeJoc[i][4]==var)
            return true;
    }
    else if (i==4)
    {
        var=TablaDeJoc[i][j];
        if ((TablaDeJoc[j][j]==var && TablaDeJoc[2*i-j][j]==var && TablaDeJoc[i][j+1]==var) ||
                (TablaDeJoc[j][j]==var && TablaDeJoc[2*i-j][j]==var && TablaDeJoc[i][j-1]==var) ||
                (TablaDeJoc[j][j]==var && TablaDeJoc[2*i-j][j]==var && TablaDeJoc[i][j+1]==var && TablaDeJoc[i][j-1]==var))
            return true;
    }
    else if (j==4)
    {
        var=TablaDeJoc[i][j];
        if ((TablaDeJoc[i][i]==var && TablaDeJoc[i][2*j-i]==var && TablaDeJoc[i+1][j]==var) ||
                (TablaDeJoc[i][j]==var && TablaDeJoc[i][2*j-i]==var && TablaDeJoc[i-1][j]==var) ||
                (TablaDeJoc[i][i]==var && TablaDeJoc[i][2*j-i]==var && TablaDeJoc[i+1][j]==var && TablaDeJoc[i-1][j]==var))
            return true;
    }
    else
        return false;
}

//fixeaza pozitiile pe care se poate forma o moara / doar pozitii adiacente /

    bool moara (int TablaDeJoc[8][8],int linie, int coloana, int sum, int pl)
    {

        int var=0;
        for(int j=1; j<8; j++){
        if (TablaDeJoc[linie][j]==pl)
        var=var+TablaDeJoc[linie][j];}
        if (sum==var)
            return true;
        var=0;
        for (int i=1; i<8; i++){
        if (TablaDeJoc[i][coloana]==pl)
        var=var+TablaDeJoc[i][coloana];}
        if (var==sum)
            return true;
        return false;
    }


void pozitiiDisponibilePlayer1()
{
    int i,j;
    i=1;
    j=1;
    {
        while ((i<8) && (j<8))
        {
            if (TablaDeJoc[i][j]==1)
            {
                if (i==j || i+j==8)
                {
                    if (i!=4 && j!=4)
                    {
                        if (TablaDeJoc[4][i]==0)
                        {
                            cout<<4<<" "<<i;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[i][4])
                        {
                            cout<<i<<" "<<4;
                            cout<<"\n";
                        }
                    }

                }
            }
            else if (i==4)
            {
                if (j==1)
                {
                    if (TablaDeJoc[j][j]==0)
                    {
                        cout<<j<<" "<<j;
                        cout<<"\n";
                    }
                    if (TablaDeJoc[i][j+1]==0)
                    {
                        cout<<i<<" "<<j+1;
                        cout<<"\n";
                    }
                    if (TablaDeJoc[8-j][j]==0)
                    {
                        cout<<8-j<<" "<<j;
                        cout<<"\n";
                    }
                }

                if (j==7)
                {
                    if (TablaDeJoc[j][j]==0)
                    {
                        cout<<j<<" "<<j;
                        cout<<"\n";
                    }
                    if (TablaDeJoc[i][j-1]==0)
                    {
                        cout<<i<<" "<<j-1;
                        cout<<"\n";
                    }
                    if (TablaDeJoc[8-j][j]==0)
                    {
                        cout<<8-j<<" "<<j;
                        cout<<"\n";
                    }
                }

                else
                {
                    if (TablaDeJoc[j][j]==0)
                    {
                        cout<<j<<" "<<j;
                        cout<<"\n";
                    }
                    if( TablaDeJoc[i][j+1]==0)
                    {
                        cout<<i<<" "<<j+1;
                        cout<<"\n";
                    }
                    if (TablaDeJoc[8-j][j]==0)
                    {
                        cout<<8-j<<" "<<j;
                        cout<<"\n";
                    }
                    if( TablaDeJoc[i][j-1]==0)
                    {
                        cout<<i<<" "<<j-1;
                        cout<<"\n";
                    }
                }
            }
            else if (j==4)
            {
                if (i==1)
                {
                    if (TablaDeJoc[i][i]==0)
                    {
                        cout<<i<<" "<<i;
                        cout<<"\n";
                    }
                    if (TablaDeJoc[i+1][j]==0)
                    {
                        cout<<i+1<<" "<<j;
                        cout<<"\n";
                    }
                    if (TablaDeJoc[i][8-i]==0)
                    {
                        cout<<i<<" "<<8-i;
                        cout<<"\n";
                    }
                }
                if (j==7)
                {
                    if (TablaDeJoc[i][i]==0)
                    {
                        cout<<j<<" "<<j;
                        cout<<"\n";
                    }
                    if (TablaDeJoc[i-1][j]==0)
                    {
                        cout<<i-1<<" "<<j;
                        cout<<"\n";
                    }
                    if (TablaDeJoc[i][8-i]==0)
                    {
                        cout<<j<<" "<<8-i;
                        cout<<"\n";
                    }
                }
                else
                {
                    if (TablaDeJoc[i][i]==0)
                    {
                        cout<<j<<" "<<j;
                        cout<<"\n";
                    }
                    if (TablaDeJoc[i-1][j]==0)
                    {
                        cout<<i-1<<" "<<j;
                        cout<<"\n";
                    }
                    if (TablaDeJoc[i][8-i]==0)
                    {
                        cout<<j<<" "<<8-i;
                        cout<<"\n";
                    }
                    if (TablaDeJoc[i+1][j]==0)
                    {
                        cout<<i+1<<" "<<j;
                        cout<<"\n";
                    }



                }

            }
        }
    }
    if (j==7)
    {
        i++;
        j=1;
    }
    else
        j++;
}


void pozitiiDisponibilePlayer2()
{
    int i,j;
    i=1;
    j=1;
    {
        while ((i<8) && (j<8))
        {
            if (TablaDeJoc[i][j]==2)
            {
                if (i==j || i+j==8)
                {
                    if (i!=4 && j!=4)
                    {
                        if (TablaDeJoc[4][i]==0)
                        {
                            cout<<4<<" "<<i;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[i][4])
                        {
                            cout<<i<<" "<<4;
                            cout<<"\n";
                        }
                    }

                }
                else if (i==4)
                {
                    if (j==1)
                    {
                        if (TablaDeJoc[j][j]==0)
                        {
                            cout<<j<<" "<<j;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[i][j+1]==0)
                        {
                            cout<<i<<" "<<j+1;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[8-j][j]==0)
                        {
                            cout<<8-j<<" "<<j;
                            cout<<"\n";
                        }
                    }

                    if (j==7)
                    {
                        if (TablaDeJoc[j][j]==0)
                        {
                            cout<<j<<" "<<j;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[i][j-1]==0)
                        {
                            cout<<i<<" "<<j-1;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[8-j][j]==0)
                        {
                            cout<<8-j<<" "<<j;
                            cout<<"\n";
                        }
                    }

                    else
                    {
                        if (TablaDeJoc[j][j]==0)
                        {
                            cout<<j<<" "<<j;
                            cout<<"\n";
                        }
                        if( TablaDeJoc[i][j+1]==0)
                        {
                            cout<<i<<" "<<j+1;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[8-j][j]==0)
                        {
                            cout<<8-j<<" "<<j;
                            cout<<"\n";
                        }
                        if( TablaDeJoc[i][j-1]==0)
                        {
                            cout<<i<<" "<<j-1;
                            cout<<"\n";
                        }
                    }
                }
                else if (j==4)
                {
                    if (i==1)
                    {
                        if (TablaDeJoc[i][i]==0)
                        {
                            cout<<i<<" "<<i;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[i+1][j]==0)
                        {
                            cout<<i+1<<" "<<j;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[i][8-i]==0)
                        {
                            cout<<i<<" "<<8-i;
                            cout<<"\n";
                        }
                    }
                    if (j==7)
                    {
                        if (TablaDeJoc[i][i]==0)
                        {
                            cout<<j<<" "<<j;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[i-1][j]==0)
                        {
                            cout<<i-1<<" "<<j;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[i][8-i]==0)
                        {
                            cout<<j<<" "<<8-i;
                            cout<<"\n";
                        }
                    }
                    else
                    {
                        if (TablaDeJoc[i][i]==0)
                        {
                            cout<<j<<" "<<j;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[i-1][j]==0)
                        {
                            cout<<i-1<<" "<<j;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[i][8-i]==0)
                        {
                            cout<<j<<" "<<8-i;
                            cout<<"\n";
                        }
                        if (TablaDeJoc[i+1][j]==0)
                        {
                            cout<<i+1<<" "<<j;
                            cout<<"\n";
                        }



                    }

                }
            }
        }
        if (j==7)
        {
            i++;
            j=1;
        }
        else
            j++;
    }
}


int main ()
{
    int sum;
    cout<<"Incepe Jocul ";
    cout<<"\n";
    int player1=9;
    int player2=9;
    //tabla de joc - initializare
    for (int i=1; i<8; i++)
        for (int j=1; j<8; j++)
            TablaDeJoc[i][j]=0;
    cout<<"\n";
    afisareTablaDeJoc();
    //player1 va juca cu val 1 iar player2 cu val 2 - prima etapa a jocului
    //partea 1: umplerea table de joc
    while (player1!=0 && player2!=0)
    {
        int player;
        int linpl1, colpl1, linpl2, colpl2;
        cout<<"Introduceti pozitia pe care doriti sa amplasati pionul dvs.: ";
        cout<<"\n";
        cout<<"Este randul lui player1: ";
        cout<<"\n";
        int ok=1;
        while (ok)
        {
            cin>>linpl1>>colpl1; // citeste pozitia pl1
            if (esteBunaPozitia(TablaDeJoc,linpl1,colpl1)==false)
            {
                cout<<"Pozitie incorecta! Mai incercati odata: ";
                cout<<"\n";
            }
            else
                ok=0;

        }
        TablaDeJoc[linpl1][colpl1]=1;
        //Verificam daca am format o moara
        sum=3; pl=1;
        if (moara(TablaDeJoc,linpl1,colpl1,sum,pl)==true)
        {
            player2--;
            cout<<"\n";
            cout<<"Player1 a format o moara! :) ";
            cout<<"\n";
            afisareTablaDeJoc();
            cout<<"\n";
            cout<<"Pozitia de pe care doriti sa eliminati pionul advrsarului: ";
            cout<<"\n";
            int var1, var2;
            ok=1;
            while (ok)
            {
                cin>>var1>>var2;
                if (TablaDeJoc[var1][var2]==1)
                {
                    cout<<"Pe pozitia introdusa se afla un pion ce iti apartine. Introdu alta pozitie pentru a elemina un pion al advrsarului: ";
                    cout<<"\n";
                }
                else
                {
                    ok=0;
                    TablaDeJoc[var1][var2]=0;
                }
            }
        }

        player1--;
        afisareTablaDeJoc();
        cout<<"Este randul lui player2: ";
        cout<<"\n";
        ok=1;
        while (ok)
        {
            cin>>linpl2>>colpl2; // citeste pozitia pl2
            if (esteBunaPozitia(TablaDeJoc,linpl2,colpl2)==false)
                cout<<"Pozitie incorecta! Mai incercati odata: ";
            else
                ok=0;

        }
        TablaDeJoc[linpl2][colpl2]=2;
        //verificam daca am format o moara
        sum=6;
        pl=2;
        if (moara(TablaDeJoc,linpl2,colpl2,sum,pl)==true)
        {

            player1--;
            cout<<"\n";
            cout<<"Player2 a format o moara! :) ";
            cout<<"\n";
            afisareTablaDeJoc();
            cout<<"\n";
            cout<<"\n";
            cout<<"Pozitia de pe care doriti sa eliminati pionul advrsarului: ";
            cout<<"\n";
            int var1, var2;
            ok=1;
            while (ok)
            {
                cin>>var1>>var2;
                if (TablaDeJoc[var1][var2]==2)
                {
                    cout<<"Pe pozitia introdusa se afla un pion ce iti apartine. Introdu alta pozitie pentru a elemina un pion al advrsarului: ";
                    cout<<"\n";
                }
                else
                {
                    ok=0;
                    TablaDeJoc[var1][var2]=0;
                }
            }
        }
        player2--;
        afisareTablaDeJoc();
    }
    //daca cineva a creat mai multe mori si a lasar adersarul doar cu doua piese pe masa
    if (pieseramase1==2)
    {
        cout<<"\n";
        cout<<"Player 2 a castigat!";
        return 0;
    }
    else
    {
        cout<<"\n";
        cout<<"Player1 a castigat!";
        return 0;
    }
    //partea a 2-a
    cout<<"\n";
    cout<<"Asezarea pionilor pe masa a luat sfarsit! ";
    cout<<"\n";
    afisareTablaDeJoc();
    cout<<"\n";
    cout<<"Muta pionii pe pozitii adiacente astfel incat sa poti forma mori si sa elimini cati mai multi pioni ai adversarului. ";
    cout<<"\n";
    //calculam pionii ramasi pe masa
    int pioni1=0;
    int pioni2=0;
    //verificam intai daca vreun jucator este blocat si nu mai poate muta pionii
    int ok1=0;
    int ok2=0;
    int i=1;
    int j=1;
    while ((i<8) && (j<8) && (ok1==0) && (ok2==0))
    {
        //pt player1
//....................................................................................
        if (TablaDeJoc[i][j]==1)
        {
            if (i==j || i+j==8)
            {
                if (i!=4 && j!=4)
                    if (TablaDeJoc[4][i]==0 || TablaDeJoc[i][4])
                        ok1=1;
            }
            else if (i==4)
            {
                if (j==1)
                    if (TablaDeJoc[j][j]==0 || TablaDeJoc[i][j+1]==0 || TablaDeJoc[8-j][j]==0)
                        ok1=1;
                if (j==7)
                    if (TablaDeJoc[j][j]==0 || TablaDeJoc[i][j-1]==0 || TablaDeJoc[8-j][j]==0)
                        ok1=1;
                    else if (TablaDeJoc[j][j]==0 || TablaDeJoc[i][j+1]==0 || TablaDeJoc[8-j][j]==0 || TablaDeJoc[i][j-1]==0)
                        ok1=1;
            }
            else if (j==4)
            {
                if (i==1)
                    if (TablaDeJoc[i][i]==0 || TablaDeJoc[i+1][j]==0 || TablaDeJoc[i][8-i]==0)
                        ok1=1;
                if (j==7)
                    if (TablaDeJoc[i][i]==0 || TablaDeJoc[i+1][j]==0 || TablaDeJoc[i][8-i]==0)
                        ok1=1;
                    else if (TablaDeJoc[i][i]==0 || TablaDeJoc[i+1][j]==0 || TablaDeJoc[i][8-i]==0 || TablaDeJoc[i-1][j]==0)
                        ok1=1;
            }

        }

//....................................................................................
        //pt player2
//....................................................................................

        if (TablaDeJoc[i][j]==2)
        {
            if (i==j || i+j==8)
            {
                if (i!=4 && j!=4)
                    if (TablaDeJoc[4][i]==0 || TablaDeJoc[i][4])
                        ok2=1;
            }

        }
        else if (i==4)
        {
            if (j==1)
                if (TablaDeJoc[j][j]==0 || TablaDeJoc[i][j+1]==0 || TablaDeJoc[8-j][j]==0)
                    ok2=1;
            if (j==7)
                if (TablaDeJoc[j][j]==0 || TablaDeJoc[i][j-1]==0 || TablaDeJoc[8-j][j]==0)
                    ok2=1;
                else if (TablaDeJoc[j][j]==0 || TablaDeJoc[i][j+1]==0 || TablaDeJoc[8-j][j]==0 || TablaDeJoc[i][j-1]==0)
                    ok2=1;
        }
        else if (j==4)
        {
            if (i==1)
                if (TablaDeJoc[i][i]==0 || TablaDeJoc[i+1][j]==0 || TablaDeJoc[i][8-i]==0)
                    ok2=1;
            if (j==7)
                if (TablaDeJoc[i][i]==0 || TablaDeJoc[i+1][j]==0 || TablaDeJoc[i][8-i]==0)
                    ok2=1;
                else if (TablaDeJoc[i][i]==0 || TablaDeJoc[i+1][j]==0 || TablaDeJoc[i][8-i]==0 || TablaDeJoc[i-1][j]==0)
                    ok2=1;
        }
        if (j==7)
        {
            i++;
            j=1;
        }
        else
            j++;

    }
//....................................................................................

//verificam daca exista vreun jucator blocat

    if (ok1)
    {
        cout<<"\n";
        afisareTablaDeJoc();
        cout<<"\n";
        cout<<"Player2 a castigat! Felicitari! :) ";
    }
    else if(ok2)
    {
        cout<<"\n";
        afisareTablaDeJoc();
        cout<<"\n";
        cout<<"Player1 a castigat! Felicitari! :) ";
    }
    else
    {
        //verificam cate piese are fiecare jucator
        pieseramase1=0;
        pieseramase2=0;
        for (int i=1; i<8; i++)
        {
            for (int j=1; j<8; j++)

                if (TablaDeJoc[i][j]==1)
                    pieseramase1++;
                else if (TablaDeJoc[i][j]==2)
                    pieseramase2++;
        }
        //partea 2 propriu-zisa

        while (pieseramase1>2 || pieseramase2>2)
        {
            int player;
            //pl1
            cout<<"\n";
            cout<<"Randul lui player1: ";
            cout<<"\n";
            cout<<"Mai ai "<<pieseramase1<<" mutari disponibile!";
            cout<<"\n";
            cout<<"Pozitii disponibile: ";
            cout<<"\n";
            cout<<"Mutari disponibile pentru player1: ";
            pozitiiDisponibilePlayer1();
            cout<<"\n";
            cout<<"Introduceti coordonatele pionului pe care doriti sa il mutati: ";
            int x,y; //coord. pion ce trebuie mutat
            cin>>x>>y;
            cout<<"Alegeti una din pozitiile disponibile: ";
            int a,b;//coord pozitie valida
            cin>>a>>b;
            swap(TablaDeJoc[x][y],TablaDeJoc[a][b]);
            cout<<"\n";
            afisareTablaDeJoc();
            cout<<"\n";
            pieseramase1--;
            player=1;
            //vf daca este formata o moara
            sum=3;pl=1;
            if (moara(TablaDeJoc,a,b,sum,pl)==true)
            {
                pieseramase2--;
                cout<<"\n";
                cout<<"Player1 a format o moara! :) ";
                cout<<"\n";
                cout<<"\n";
                cout<<"Pozitia de pe care doriti sa eliminati pionul advrsarului: ";
                cout<<"\n";
                int var1, var2;
                int ok=1;
                while (ok)
                {
                    cin>>var1>>var2;
                    if (TablaDeJoc[var1][var2]==1)
                    {
                        cout<<"Pe pozitia introdusa se afla un pion ce iti apartine. Introdu alta pozitie pentru a elemina un pion al advrsarului: ";
                        cout<<"\n";
                    }
                    else
                    {
                        ok=0;
                        TablaDeJoc[var1][var2]=0;
                        cout<<"\n";
                        afisareTablaDeJoc();
                        cout<<"\n";
                    }
                }
            }

            //pl2
            cout<<"\n";
            cout<<"Randul lui player2: ";
            cout<<"\n";
            cout<<"Mai ai "<<pieseramase2<<" mutari disponibile!";
            cout<<"\n";
            cout<<"Pozitii disponibile: ";
            cout<<"\n";
            cout<<"Mutari disponibile pentru player2: ";
            pozitiiDisponibilePlayer2();
            cout<<"\n";
            cout<<"Introduceti coordonatele pionului pe care doriti sa il mutati: ";
            //coord. pion ce trebuie mutat
            cin>>x>>y;
            cout<<"Alegeti una din pozitiile disponibile: ";
            //coord pozitie valida
            cin>>a>>b;
            swap(TablaDeJoc[x][y],TablaDeJoc[a][b]);
            cout<<"\n";
            afisareTablaDeJoc();
            cout<<"\n";
            pieseramase2--;
            player=2;
            //vf daca este formata o moara
            sum=6;pl=2;
            if (moara(TablaDeJoc,a,b,sum,pl)==true)
            {
                pieseramase1--;
                cout<<"\n";
                cout<<"Player2 a format o moara! :) ";
                cout<<"\n";
                cout<<"\n";
                cout<<"Pozitia de pe care doriti sa eliminati pionul advrsarului: ";
                cout<<"\n";
                int var1, var2;
                int ok=1;
                while (ok)
                {
                    cin>>var1>>var2;
                    if (TablaDeJoc[var1][var2]==2)
                    {
                        cout<<"Pe pozitia introdusa se afla un pion ce iti apartine. Introdu alta pozitie pentru a elemina un pion al advrsarului: ";
                        cout<<"\n";
                    }
                    else
                    {
                        ok=0;
                        TablaDeJoc[var1][var2]=0;
                        cout<<"\n";
                        afisareTablaDeJoc();
                        cout<<"\n";
                    }
                }
            }
        }
    }

    if (pieseramase1==2)
    {
        cout<<"\n";
        cout<<"Player 2 a castigat!";
    }
    else
    {
        cout<<"\n";
        cout<<"Player1 a castigat!";
    }
    return 0;
}
