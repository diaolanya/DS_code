#include<stdio.h>
#include<stdlib.h>
#include"RecordType.h"
#include"DataStruct.h"

RecordList *Init(){//初始化
    RecordList *rl = (RecordList *)malloc(sizeof(RecordList));
    RecordType *rt;
    int x,y;
    scanf("%d",&x);
    rl->length = x;
    for(int i = 1;i < x + 1;i++){
        scanf("%d",&y);
        rt = (RecordType *)malloc(sizeof(RecordType));
        rt->key = y;
        rl->r[i] = *rt;    
    }
    return rl;
}

void Print(RecordList l){//打印
    RecordType rt;
    int x = l.length + 1;
    printf("\n*****PRINT*****\n");
    for(int i = 1;i < x;i++){
        rt = l.r[i];
        printf("%d\t",rt.key);
    }
}