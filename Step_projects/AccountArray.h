#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Account.h"
typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray {
    private:
        ACCOUNT_PTR* arr;   // Pointer array
        int arrlen;
        BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray &ref) {}
        BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray &ref) {}
    
    public:
        BoundCheckAccountPtrArray(int len = 100);
        ACCOUNT_PTR& operator[] (int index);
        ACCOUNT_PTR operator[] (int index) const;
        int GetArrLen() const;
        ~BoundCheckAccountPtrArray();
};
#endif