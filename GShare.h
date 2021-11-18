#ifndef  GSHARE_H
#define GSHARE_H

#include"CountsTable.h"
#include"BranchHis.h"

class GShare{
    public:
        CountsTable cTable;
        BranchHis bHis;
        unsigned EntryNum;
        unsigned m;
        unsigned n;
        GShare();
        GShare(unsigned m, unsigned n);
        unsigned GetIndex(unsigned pc);
        int Predict(unsigned pc);
        void Update(unsigned pc, int i);
        void Print();
};
#endif