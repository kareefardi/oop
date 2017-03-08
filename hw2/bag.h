#ifndef BAG_H
#define BAG_H

class Bag {
        unsigned char oSet[256];
        static char res[5];
public:
        Bag()
        {
                for (int i = 0; i < 256; ++i)
                        oSet[i] = (unsigned char) 0;
        }

        ~Bag()
        {
        }

        char ins(int e)
        {
                if (e < 0 || e > 256)
                        return res[0];
                if (oSet[e] != 255)
                        oSet[e] = ++oSet[e];
                else
                        return res[1];
                return res[2];
        }

        char rmv(int e)
        {
                if (e < 0 || e > 256)
                        return res[0];
                if (oSet[e] == 0)
                        return res[3];
                else
                        oSet[e] = --oSet[e];
                return res[4];
        }

        int chk(int e)
        {
                if (e < 0 || e > 256)
                        return -1;
                return (int) oSet[e];
        }
};

#endif

char Bag::res[5] = {'g', 'v', 'i', 'u', 'r'};;