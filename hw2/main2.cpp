#include "MaxHeap.h"
using namespace std;
int main() {
        MaxHeap naw(19);
        naw.Insert(2);
        MaxHeap naw2 = naw;
        naw.Insert(3);
        naw2.Insert(4);
        cout << "naw: " << naw << endl << "naw2: " << naw2 << endl;
        naw = naw;
        MaxHeap naw3(15);
        cout << "naw: " << naw << endl;
        naw3 = naw2 + naw;
        cout << "naw3: " << naw3 << endl;
        naw3 += naw3;
        cout << "naw3: " << naw3 << endl;
        cout << "naw3[2]: " << naw3[2] << endl;
        try {
                cout << naw[4] << endl;
        }
        catch (char const* c) {
                cerr << c << endl;
        }
        naw = naw + 1;
        cout << "naw: " << naw << endl;
        naw += 8;
        cout << "naw: " << naw << endl;
        return 0;
}