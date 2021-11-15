#include"CountsTable.h"
#include<iostram>

CountsTable::CountsTable(size_t m,size_t n){
    EntryNum=pow(2,m);
    CountsTableArr=new size_t(EntryNum);
    fill(CountTableArr,CountTableArr+EntryNUm,n);  //weekly taken
}

CountsTable::ModifyTable(size_t index ,int flag){
    if(index>0&&index<7) 
        CountsTableArr[index]+=flag;
}

CountsTable::GetCounts(size_t index){
    return CountsTableArr[index];
}