#ifndef  COUNTS_TABLE_H
#define  COUNTS_TABLE_H

class CountsTable{
    public:
        size_t EntryNum;                //number of entries in the table
        size_t *CountsTableArr;           //table
        void CountsTable(size_t m,size_t n);     
        void ModifyTable(size_t index ,int flag);
        void GetCounts(size_t index);
}
#endif