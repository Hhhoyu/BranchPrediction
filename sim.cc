#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "Bimodal.h"
//#include "Gshare.h"
#include <iomanip>

using namespace std;

int main(int argc,char *argv[]){
    Bimodal bPredictor;
    //GShare gPredictor;
    //Smith sPredictor;
    string model=argv[1];
    string TraceFile;
    //predictor
    char TakenorNot; // taken or notaken
    unsigned pc;       //pc
    int isTaken;
    unsigned PredictionNum=0; //number of predictions
    unsigned Miss=0;          
    //unsigned Hit=0;
    //file data
    //init
    switch (model[0])
    {
    case 'b':
        {
            int m=atoi(argv[2]);
            bPredictor=Bimodal(static_cast<unsigned>(m));
            TraceFile=argv[3];
            break;
        }
        
    case 'g':
        {
            
            break;
        }
        
    case 's':
        {

            break;
        }

    default:
        break;
    }
    string buf="";
    stringstream s;
    ifstream infile; 
    infile.open(TraceFile,ios::in);
    if(!infile.is_open()){
        cout<<"open error!"<<endl;
        exit(1);
    }
    while(getline(infile,buf)){
        string adress=buf.substr(0,6);
        s<<hex<<adress<<endl;
        s>>pc;
        PredictionNum++;
        TakenorNot=buf[7];
        switch (model[0])
        {
        case 'b':
            {
                if(TakenorNot=='t') isTaken=1;
                else isTaken=0;
                unsigned p1=bPredictor.GetIndex(pc);
                unsigned p3=bPredictor.cTable.GetCounts(p1);
                if(bPredictor.Predict(pc)!=isTaken){
                    Miss++;
                }
                bPredictor.Update(pc,isTaken);
                p3=bPredictor.cTable.GetCounts(p1);
            }
            break;
        
        default:
            break;
        }
    }
    cout<<"number of predictions: "<<PredictionNum<<endl;
    cout<<"number of mispredictions: "<<Miss<<endl;
    cout<<"misprediction rate: "<<fixed<<setprecision(2)<<(float)Miss*100/PredictionNum<<"%"<<endl;
    infile.close();
    switch (model[0])
    {
    case 'b':
        bPredictor.Print();
        break;
    
    default:
        break;
    }
}