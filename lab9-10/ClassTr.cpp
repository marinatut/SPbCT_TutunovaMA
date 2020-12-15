#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "ClassTr.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int M = 3;
    vector<Triangle> T(M);
    cout << "Треугольники: " << endl;
    for (int i = 0; i < T.size(); i++)
    {
        T[i] = Triangle((rand() % 1000 + 500) / 10.0, (rand() % 1000 + 500) / 10.0, (rand() % 500 + 1) / 10.0);
        cout << T[i] << endl;        
    }
    cin.get();
    return 0;
}
