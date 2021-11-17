#ifndef BIMODAL_H
#define BIMODAL_H
#include "CountsTable.h"
class Bimodal{
    public:
        CountsTable cTable;
        unsigned EntryNum;
        Bimodal();
        Bimodal(unsigned m);
        unsigned GetIndex(unsigned pc);
        int Predict(unsigned pc);
        void Update(unsigned pc, bool isTaken); 
        void Print();
};
#endif