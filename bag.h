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

        bool ins(int e = 0)
        {
                if (e < 0 || e > 256)
                        return false;
                        oSet[e] = ++oSet[e];
                return true;
        }

        bool rmv(int e = 0)
        {
                if (e < 0 || e > 256)
                        return false;
                        oSet[e] = --oSet[e];
                return true;
        }

        int chk(int e = 0)
        {
                if (e < 0 || e > 256)
                        return -1;
                return (int) oSet[e];
        }
};

#endif