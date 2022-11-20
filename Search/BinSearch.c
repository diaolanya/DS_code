#include<stdio.h>
#include<stdlib.h>
#include"DataStruct.h"
#include"RecordList.h"

int BinSearch(RecordList l,KeyType k){
    //在有序表l中折半查找其关键字等于k的元素,若找到,则函数值为该元素在表中的位置
    int low = 1,high = l.length + 1,mid;
    while (low < high)
    {
        mid = (low + high) /2;
        if( k == l.r[mid].key){
            return mid;
        }else if(k < l.r[mid].key){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return 0;
}


void main(){//折半查找
    RecordList *rl = Init();

    // 折半查找
    int result = BinSearch(*rl,5);
    printf("BINSEARCH:%d",result);

    PrintList(rl);
}