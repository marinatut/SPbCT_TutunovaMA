#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <bitset>
#include "MyForm.h"


using namespace std;
class Mass {
private:	 int m = 10, j = 0;
    
public:
    unsigned short N[10], N1[10];
    int A1[10], A[10];
    Mass() {};
    Mass(int B[])
    { 
       
        for (int i = 0; i < 10; i++)
        {
            
            A[i] = rand() % 255;
            B[i] = A[i];
          
           
        }
       

        for (int i = 0; i < 10; i++) {
            int dec, bin = 0, j;
            dec = A[i];
            for (j = 0; dec > 0; j++)
            {
                bin += (dec % 2) * pow(10.0, j);
                dec /= 2;
            }
            A1[i] = bin;
        }
    }
    int getM()
    {
        return m;
     }
    unsigned short * Print()
    {
        return N1;
    }
    void mPrint(int A[])
    {
        int a, count;
        for (int i = 0; i < 10; i++) {
            a = A[i];
            for (count = 0; a != 0; a &= (a - 1))
                ++count;
        }
        
        for (int i = 0; i < 10; i++) {
          
            if (A[i] % 2 == 1) {
                 N[i] = A[i];
                 N1[i] = N[i] >> 1;
                bitset<16> bitset12{ N1[i] };
               
               // cout << N1 << " ";
            }
        }
        
        
        for (int i = 0; i < 10; i++)
            if (N1[i])//åñëè çíà÷åíèå ïîëîæèòåëüíî ò.å. íå ðàâíû íóëè
                N[j++] = N1[i];//êîïèðóåì åãî âî âòîðîé ìàññèâ è óâåëè÷èâàåì j íà åäèíèöó
             m--;

    }



};
