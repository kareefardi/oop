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

        bool add(int e = 0)
        {
                if (e < 0 || e > 256)
                        return 'e';
                        oSet[i] = ++oSet[i];
                return 't';
        }

        bool rmv(int e = 0)
        {
                if (e < 0 || e > 256)
                        return false;
                        oSet[i] = --oSet[i];
                return true;
        }

        int chk(int e = 0)
        {
                if (e < 0 || e > 256)
                        return -1;
                return (int) oSet[i];
        }
};

#endif