#include<stdio.h>
#include<stdlib.h>
#include"DataStruct.h"
#include"RecordType.h"

void ShellSort(RecordList *rl,int delta[],int delta_len){
    int i;
    for(i = 0;i < delta_len;i++){
        ShellInsert(rl,delta[i]);
    }
}

void ShellInsert(RecordList *rl,int delta){
    //对数组r进行一趟希尔排序,delta为增量
    int i,j;
    for (i = 1 + delta; i < rl->length + 1; i++){
        if(rl->r[i].key < rl->r[i-delta].key){
            rl->r[0] = rl->r[i]; //备份,不做监视哨
            for(j = i - delta;j > 0&&rl->r[0].key < rl->r[j].key;j-=delta){
                rl->r[j + delta] = rl->r[j];
            }
            rl->r[j + delta] = rl->r[0];
        }
    }
    
}

void main(){//希尔排序
    RecordList *rl =  Init();
    int delta[3] = {4,2,1};
    int delta_len = 3;

    ShellSort(rl,delta,delta_len);

    Print(*rl);
}