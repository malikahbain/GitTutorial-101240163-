#ifndef RGB_H
#define RGB_H

#include "defs.h"
#include <iostream>
#include <string>

using namespace std;

class RGB{
    public :
        // Constructors
        RGB(int r, int b, int g);
        RGB(CuColour colour);
        RGB();

        // Getters
        int getR();
        int getB();
        int getG();
        CuColour getColour();

        // Setters
        void setR(int r);
        void setB(int b);
        void setG(int g);
        void setColour(CuColour colour);

        // Other Methods
        static RGB WHITE();
        static RGB BLACK();
        static RGB RED();
        static RGB GREEN();
        static RGB BLUE();
        void print();

    private:
        int r;
        int b;
        int g;

};

#endif