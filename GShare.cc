#include"GShare.h"
#include<math.h>
#include<iostream>

using namespace std;

GShare::GShare(){
}
GShare::GShare(unsigned m,unsigned n):m(m),n(n){
    cTable=CountsTable(m,4);
    bHis=BranchHis(n);
    EntryNum=pow(2,m);
}
unsigned GShare::GetIndex(unsigned pc){
    unsigned pc1=(pc>>2)&(EntryNum-1);
    unsigned his=bHis.GetData();
    return his^pc1;
}
void GShare::Update(unsigned pc,int isTaken){
    int flag=isTaken==1?1:-1;
    cTable.ModifyTable(GetIndex(pc),flag);
    bHis.SetData(isTaken);
}
int GShare::Predict(unsigned pc){
    if(cTable.GetCounts(GetIndex(pc))>=4) return 1;
    else return 0;
}
void GShare::Print(){
    cout<<"FINAL GSHARE CONTENTS";
    for(unsigned i=0;i<EntryNum;i++){
        cout<<endl;
        cout<<dec<<i<<"\t"<<cTable.GetCounts(i);
    }
    cout<<endl;
}