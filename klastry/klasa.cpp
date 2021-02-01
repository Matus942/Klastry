#include "klasa.h"


void klasa::wypelnij()
{
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ;j++)
        {
            M[j][i] = 0;
        }
    }
    wylosuj();
}
void klasa::wylosuj()
{
    //srand(time(NULL));
    for(int i = 0 ; i<s ; i++)
    {
        do
        {
             x = rand()%m;
             y = rand()%n;
        }while(M[x][y] != 0);
        M[x][y] = 1;
    }
}
void klasa::rysuj()
{
    for(int i = 0 ; i< n ;i++)
    {
        for(int j =0 ; j<m ; j++)
        {
            cout<<M[j][i];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    for(int i = 0 ; i< n ;i++)
    {
        for(int j =0 ; j<m ; j++)
        {
            cout<<M1[j][i]<<" ";

        }
        cout<<endl;
    }
    cout<<"Liczba klastrow: "<<lc<<endl;
}
void klasa::sprawdz()
{
    M1[0][0] = 0;
    for(int i =0 ; i<n ; i++)
    {
        for(int j =0 ; j<m ; j++)
        {
            if(j==0 && i !=0)
            {
                if(M[j][i-1]==M[j][i])M1[j][i] = M1[j][i-1];
                if(M[j][i-1]!=M[j][i])
                {
                    ct++;
                    M1[j][i] = ct;
                    lc++;
                }
                continue;
            }
            if(i==0 && j!=0)
            {
                if(M[j-1][i]==M[j][i])M1[j][i]= M1[j-1][i];
                if(M[j-1][i] != M[j][i])
                {
                    ct++;
                    M1[j][i] = ct;
                    lc++;
                }
                continue;
            }
            if(j > 0 && i > 0)
            {
                if(M[j][i] == M[j-1][i] && M[j][i] == M[j][i-1])
                {

                    if(M1[j-1][i] != M1[j][i-1])
                    {
                        a = M1[j-1][i];
                        b = M1[j][i-1];
                        M1[j][i] = a;

                        for(int i = 0;i<n;i++)
                        {
                            for(int j = 0;j<m;j++)
                            {
                                if(M1[j][i] == a)
                                    M1[j][i] = b;
                            }
                        }
                        lc--;
                    }
                    else
                        M1[j][i] = M1[j][i-1];
                    continue;

                }
                if (M[j][i] == M[j][i-1] && M[j][i] != M[j-1][i])
                {
                    M1[j][i] = M1[j][i - 1];
                    continue;
                }
                if (M[j][i] == M[j-1][i] && M[j][i] != M[j][i-1])
                {
                    M1[j][i] = M1[j-1][i];
                    continue;
                }
                if(M[j][i] != M[j-1][i] && M[j][i] != M[j][i-1])
                {
                    M1[j][i] = ct;
                    ct++;
                    lc++;
                    continue;
                }
            }
        }
        cout<<endl;
    }
}
