#include<stdio.h>
#include<stdlib.h>
#include"DataStruct.h"
#include"RecordList.h"

RecordList *Init(){//初始化
    int x;
    RecordType *q; //工作节点
    RecordList *rl = (RecordList *)malloc(sizeof(RecordList));
    scanf("%d",&x);
    rl->length = x;
    for (int i = 1; i < rl->length+1; i++) //r[0]是工作节点
    {
        scanf("%d",&x);
        q = (RecordType *)malloc(sizeof(RecordType));
        q->key = x;
        rl->r[i] = *q;
    }
    return rl;
}

void PrintList(RecordList *rl){//打印结果
    printf("\n**********PrintList**********\n");
    int x = rl->length;
    for (int i = 1; i < rl->length + 1; i++)
    {
        printf("%d\t",rl->r[i]);
    }
    
}