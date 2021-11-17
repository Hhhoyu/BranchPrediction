#include"Bimodal.h"
#include<math.h>
#include<iostream>

using namespace std;

Bimodal::Bimodal(){
}
Bimodal::Bimodal(unsigned m){
    cTable=CountsTable(m,4); //the initial value of the title is 4
    EntryNum=pow(2,m);
}

unsigned Bimodal::GetIndex(unsigned pc){ 
    return (EntryNum-1)&(pc>>2); //discard the last two digits of pc
}

int Bimodal::Predict(unsigned pc){
    if(cTable.GetCounts(GetIndex(pc))>=4) return 1;
    else return 0;
}

void Bimodal::Update(unsigned pc,bool isTaken){
    int flag=isTaken==true?1:-1;
    cTable.ModifyTable(GetIndex(pc),flag);
}

void Bimodal::Print(){
    cout<<"FINAL BIMODAL CONTENTS";
    for(unsigned i=0;i<EntryNum;i++){
        cout<<endl;
        cout<<dec<<i<<"\t"<<cTable.GetCounts(i);
    }
    cout<<endl;
}
