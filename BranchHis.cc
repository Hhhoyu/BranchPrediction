#include "BranchHis.h"
#include "math.h"

BranchHis::BranchHis(){
}

BranchHis::BranchHis(unsigned n):n(n){
    BranchData=0;
}

void BranchHis::SetData(int i){
    BranchData=((i<<n)+BranchData)>>1 ;
}

unsigned BranchHis::GetData(){
    return BranchData;
}
