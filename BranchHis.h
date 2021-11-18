#ifndef BRANCHHIST_H
#define BRANCHHIST_H

class BranchHis
{
    private:
        unsigned BranchData;
        unsigned n;
    public:
        BranchHis();
        BranchHis(unsigned n);
        void SetData(int m);
        unsigned GetData();
};

#endif