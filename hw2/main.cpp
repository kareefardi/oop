#include <iostream>
#include "bag.h"
#include <exception> 

using namespace std;

void foo(Bag &b, int r, int op)
{
        if (op) {
                b.ins(r);
                cout << r << " added \t freq " <<  b.chk(r) << '\n';
        }
        else
                b.rmv(r);
                cout << r << " removed \t freq " << b.chk(r) << '\n';
}

int main() {
        Bag test;
        int x;
        x = 2;
        try {
                foo(test, x, 1);
                foo(test, x, 1);
                foo(test, x, 0);
                x = -1;
                foo(test, x, 1);
                foo(test, x, 0);
                x = 300;
                foo(test, x, 1);
                foo(test, x, 0);
        }
        catch (char const* err) {
                cerr << err << endl;
        }
        return 0;
}