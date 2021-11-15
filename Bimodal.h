#ifndef BIMODAL_H
#define BIMODAL_H
#include "CountsTable.h"
class Bimodal{
    public:
        CountsTable cTable;
        size_t EntryNum;
        Bimodal(size_t m);
        size_t GetIndex(size_t pc);
        bool Predict(size_t pc);
        void Update(size_t pc, bool isTaken);
}
#endif