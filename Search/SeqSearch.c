#include<stdio.h>
#include<stdlib.h>
#include"RecordList.h"
#include"DataStruct.h"

int SeqSearch(RecordList l,KeyType x){//使用监视哨的顺序查找
    l.r[0].key = x; int i = l.length + 1;
    while (l.r[i].key != x)
    {
        i--;
    }
    return i;
}

int SeqSearch1(RecordList l,KeyType x){//不使用监视哨的顺序查找
    int i = l.length + 1;
    while (i>=1&&l.r[i].key != x)
    {
        i--;
    }
    if(i>=1){
        return i;
    }else{
        return 0;
    }
    
}

void main(){//顺序查找
    RecordList *rl = Init();
    
    // 使用监视哨的顺序查找
    int result = SeqSearch(*rl,5);
    printf("SEQSEARCH:%d",result);

    // 不使用监视哨的顺序查找
    // int result1 = SeqSearch1(*rl,5);
    // printf("SEQSEARCH1:%d",result1);

    PrintList(rl);
}