#include"Smith.h"
#include<math.h>
#include<iostream>

using namespace std;

Smith::Smith(){
}
Smith::Smith(unsigned m){
    max=pow(2,m)-1;
    data=pow(2,m-1);
    init=data;
}
void Smith::Update(int isTaken){
    if(isTaken&&data<max) data++;
    if(!isTaken&&data>0) data--;
}
int Smith::Predict(){
    return data>=init;
}
void Smith::Print(){
    cout<<"FINAL COUNTER CONTENT:"<<"\t"<<data<<endl;
}