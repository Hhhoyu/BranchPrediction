#ifndef  COUNTS_TABLE_H
#define  COUNTS_TABLE_H
#include<vector>
using namespace std;
class CountsTable{
    public:
        unsigned EntryNum;                //number of entries in the table
        vector<unsigned> CountsTableArr;           //table
        CountsTable();
        CountsTable(unsigned m,unsigned n);     
        void ModifyTable(unsigned index ,int flag);
        unsigned GetCounts(unsigned index);
};
#endif  