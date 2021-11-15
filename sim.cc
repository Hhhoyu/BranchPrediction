#include "Bimodal.h"
#include "GShare.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc,char *argv[]){
    Bimodal bPredictor;
    //GShare gPredictor;
    //Smith sPredictor;
    string  model=argv[1];
    string TraceFile;
    //init
    switch (model)
    {
    case "bimodal":
        {
            bPredictor(static_cast<size_t>(argv[2]));
            TraceFile=argv[3];
            break;
        }
        
    case "gshare":
        {
            
            break;
        }
        
    case "smith":
        {

            break;
        }

    default:
        break;
    }
    ifstream infile;
    infile.open(TraceFile,ios::in);
    if(!infile.is_open()){
        cout<<"open error!"<<endl;
        exit(1);
    }
    //predictor
    bool TakenorNot;
    size_t pc;
    size_t PredictionNum=0;
    size_t Miss=0;
    size_t Hit=0;
    string buf="";
    while(getline(infile,buf)){
        string adress=buf.substr(0,6);

    }
}