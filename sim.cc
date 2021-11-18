#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "Bimodal.h"
#include "GShare.h"
#include "Smith.h"
#include <iomanip>

using namespace std;

int main(int argc,char *argv[]){
    Bimodal bPredictor;
    GShare gPredictor;
    Smith sPredictor;
    string model=argv[1];
    string TraceFile;
    //predictor
    char TakenorNot; // taken or notaken
    unsigned pc;       //pc
    int isTaken;
    unsigned PredictionNum=0; //number of predictions
    unsigned Miss=0;          
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
            int m=atoi(argv[2]);
            int n=atoi(argv[3]);
            gPredictor=GShare(static_cast<unsigned>(m),static_cast<unsigned>(n));
            TraceFile=argv[4];
            break;
        }
        
    case 's':
        {
            int m=atoi(argv[2]);
            sPredictor=Smith(static_cast<unsigned>(m));
            TraceFile=argv[3];         
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
        if(TakenorNot=='t') isTaken=1;
        else isTaken=0;
        switch (model[0])
        {
        case 'b':
            {
                if(bPredictor.Predict(pc)!=isTaken) Miss++;
                bPredictor.Update(pc,isTaken);
            }
            break;
        case 'g':
            {
                if(gPredictor.Predict(pc)!=isTaken) Miss++;
                gPredictor.Update(pc,isTaken);
            }
            break;
        case 's':
            {
                if(sPredictor.Predict()!=isTaken) Miss++;
                sPredictor.Update(isTaken);
            }
            break;
        default:
            break;
        }
    }
    cout<<"COMMAND"<<endl;
    for(int i=0;i<argc-1;i++){
        cout<<argv[i]<<" ";
    }
    cout<<argv[argc-1]<<endl;
    cout<<"OUTPUT"<<endl;
    cout<<"number of predictions: "<<PredictionNum<<endl;
    cout<<"number of mispredictions: "<<Miss<<endl;
    cout<<"misprediction rate: "<<fixed<<setprecision(2)<<(double)(Miss*100)/(double)PredictionNum<<"%"<<endl;
    infile.close();
    switch (model[0])
    {
    case 'b':
        bPredictor.Print();
        break;
    case 'g':
        gPredictor.Print();
        break;
    case 's':
        sPredictor.Print();
        break;
    default:
        break;
    }
}