#include <iostream>
#include "bag.h"

using namespace std;

void foo(Bag &b, int r, int op)
{
        if (op)
                if (b.ins(r))
                        cout << r << " added \t freq " <<  b.chk(r) << '\n';
                else
                        cout << r << " out of range \n";
        else
                if (b.rmv(r))
                        cout << r << " removed \t freq " << b.chk(r) << '\n';
                else
                        cout << r << " out of range \n";

}

int main() {
        Bag test;
        int x;
        x = 2;
        foo(test, x, 1);
        foo(test, x, 1);
        foo(test, x, 0);
        x = -1;
        foo(test, x, 1);
        foo(test, x, 0);
        x = 300;
        foo(test, x, 1);
        foo(test, x, 0);
        return 0;
}