#include<stdio.h>
#include<stdlib.h>
#include"DataStruct.h"
#include"RecordType.h"

void QuickSort(RecordList *rl,int low,int high){
    int pos;
    if(low < high){
        pos = QuickPass(rl,low,high);
        QuickSort(rl,low,pos - 1);
        QuickSort(rl,pos + 1,high);
    }
}

int QuickPass(RecordList *rl,int left,int right){
    /*对记录数组r中的r[left]至r[right]部分进行一趟排序,并得到基准的位置,使得排序后的结果
    满足其之后(前)的记录的关键字均不小于(大于)基准记录*/
    RecordType t  = rl->r[left]; //基准
    int low = left; int high = right;
    while(low < high){
        while(low < high&&rl->r[high].key >= t.key){ //high从右向左找小于基准的记录
            high--;
        }
        if(low < high){  //进行交换
            rl->r[low] = rl->r[high]; low++; 
        }
        while(low < high&&rl->r[low].key < t.key){ //low从左向右找大于基准的元素
            low++;
        }
        if(low < high){ //交换
            rl->r[high] = rl->r[low]; high--;
        }
    }
    rl->r[low] = t;
    return low;
}


void main(){//快速排序
    RecordList *rl =  Init();

    //快速排序
    QuickSort(rl,1,5);

    Print(*rl);
}