#include<stdio.h>
#include<stdlib.h>
#include"DataStruct.h"
#include"RecordType.h"

void SelectSort(RecordList *rl){
    int len = rl->length;
    int k,j;
    for(int i = 1;i < len;++i){
        k = i;
        for(j = i + 1;j < len + 1;++j){
            if(rl->r[j].key < rl->r[k].key){
                k = j;
            }
        }
        if(k != i){
            RecordType x = rl->r[i];
            rl->r[i] = rl->r[k];
            rl->r[k] = x;
        }
    }
}

void main(){//选择排序
    RecordList *rl =  Init();

    // 选择排序
    // SelectSort(rl);

    Print(*rl);
}