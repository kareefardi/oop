#include <iostream>
#include "bag.h"
#include <string>
using namespace std;

string codeHand(unsigned char c)
{
        string m;
        switch(c) {
        //static unsigned char res[] = {'g', 'v', 'h', 'u', 'l', 'r'};
        case 'g':
                m = "element out of range";
                break;
        case 'v':
                m = "frequency overflow";
                break;
        case 'u':
                m = "frequency underflow";
                break;
        case 'i':
                m = "element inserted";
                break;
        case 'r':
                m = "element removed";
                break;
        default:
                m = c;
                break;
        }
        return m;
}

void foo(Bag &b, int r, int op)
{
        if (op)
                cout << r << " " << codeHand(b.ins(r)) << endl;
        else
                cout << r << " " << codeHand(b.rmv(r)) << endl;
}

int main2() {
        Bag test;
        int x;
        x = 2;
        foo(test, x, 1);
        foo(test, x, 1);
        foo(test, x, 0);
        foo(test, x, 0);
        foo(test, x, 0);
        x = -1;
        foo(test, x, 1);
        foo(test, x, 0);
        x = 300;
        foo(test, x, 1);
        foo(test, x, 0);
        x = 5;
        for (int i = 0; i < 255; ++i)
                test.ins(x);
        foo(test, x, 1);
        return 0;
}