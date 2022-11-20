#include<stdio.h>
#include<stdlib.h>
#include"DataStruct.h"
#include"RecordType.h"

void InsSort(RecordList *rl){
    RecordType x;
    int j;
    for (int i = 2; i < rl->length + 1; i++)
    {
        rl->r[0] = x = rl->r[i]; j=i-1;
        while (x.key<rl->r[j].key)
        {
            rl->r[j+1] = rl->r[j]; j = j - 1;
        }
        rl->r[j+1] = rl->r[0];
    }
}

void main(){
    RecordList *rl =  Init();

    // 直接插入排序
    InsSort(rl);

    Print(*rl);
}