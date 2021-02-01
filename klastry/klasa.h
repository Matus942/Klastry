#ifndef KLASA_H
#define KLASA_H

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

class klasa
{
private:
    int M[6][6];///M[m][n]
    int M1[6][6];
    int m = 6;
    int n = 6;
    double p = 0.2;
    int s = p*m*n;
    int x = 0;
    int y = 0;
    int ct = 0;
    int a  = 0;
    int b = 0;
    int lc = 1;
public:
    void wypelnij();
    void wylosuj();
    void rysuj();
    void sprawdz();
};

#endif // KLASA_H
