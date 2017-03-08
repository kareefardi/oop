#ifndef BAG_H
#define BAG_H

class Bag {
        unsigned char oSet[256];
public:
        Bag()
        {
                for (int i = 0; i < 256; ++i)
                        oSet[i] = (unsigned char) 0;
        }

        ~Bag()
        {
        }

        void ins(int e)
        {
                if (e < 0 || e > 256) {
                        throw "insert out of range";
                        if (oSet[e] == 255)
                                throw "max freq reached";
                        else
                                oSet[e] = ++oSet[e];
                }
        }

        void rmv(int e)
        {
                if (e < 0 || e > 256) {
                        throw "remove out of range";
                        if (oSet[e] == 0)
                                throw "min freq reached";
                        else
                                oSet[e] = --oSet[e];
                }
        }

        int chk(int e)
        {
                if (e < 0 || e > 256)
                        return -1;
                return (int) oSet[e];
        }
};

#endif