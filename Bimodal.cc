#include"Bimodal.h"

Bimodal::Bimodal(size_t m){
    cTable=CountsTable(m,4); //the initial value of the title is 4
    EntryNum=pow(2,m);
}

inline size_t Bimodal::GetIndex(size_t pc){
    return (EntryNum-1)&&(pc>>2); //discard the last two digits of pc
}

inline bool Bimodal::Predict(size_t pc){
    return cTable.GetCounts(GetIndex(PC))>=4;
}

void Bimodal::Update(size_t pc,bool isTaken){
    int flag=isTaken?1:-1;
    cTable.ModifyTable(GetIndex(pc),flag);
}