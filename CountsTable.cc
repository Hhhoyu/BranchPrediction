#include"CountsTable.h"
#include<stdlib.h>
#include<math.h>
#include<algorithm>
CountsTable::CountsTable(){
}
CountsTable::CountsTable(unsigned m,unsigned n){
    EntryNum=pow(2,m);
    CountsTableArr.resize(EntryNum,n);
}

void CountsTable::ModifyTable(unsigned index ,int flag){
    unsigned count=GetCounts(index);
    if((count<7&&count>0)||(count==7&&flag==-1)||(count==0&&flag==1))
    CountsTableArr[index]+=flag;
}

unsigned CountsTable::GetCounts(unsigned index){
    return CountsTableArr[index];
} 