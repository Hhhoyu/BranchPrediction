#ifndef SMITH_H
#define SMITH_H
#include"CountsTable.h"
class Smith{
    public:
        unsigned max;
        unsigned init;
        unsigned data;
        Smith();
        Smith(unsigned m);
        int Predict();
        void Update(int isTaken);
        void Print();
};
#endif