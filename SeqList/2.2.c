#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 20

typedef int DataType;
typedef struct
{
    DataType *elem;
    int length;
    int listsize;
}SeqList;

int InitSeqlist(SeqList *L){//顺序表初始化
    L->elem = (DataType *)malloc(LIST_INIT_SIZE*sizeof(DataType));
    if(!L->elem){
        exit(0);
    }
    DataType *p;
    L->length=5;
    L->listsize=LIST_INIT_SIZE;
    for(int i=0;i<5;i++){//赋初值0,1,2,3,4
        p = L->elem + i;
        *p = i;
    }
    return 1;
}

int InsertSeqList(SeqList *L,int i,DataType e){
    DataType *p,*q;
    if(i<1||i>L->length+1){
        return 0;
    }else{
        if(L->length>=L->listsize){
            printf("顺序表已满"); return 0;
        }else{
            q=L->elem+i; /*插入点*/
            for(p=L->length+L->elem;p>=q;--p){
                *(p+1) = *p;
            }
            *q=e;
            ++L->length;
            return 1;
        }

    }
}

int DeleteSeqList(SeqList *L,int i){
    /*初始条件:顺序线性表L已存在,1<=i<=L->length*/
    if(i<1||i>L->length){
        printf("不存在第i个元素!");
        return 0;
    }else{
        for (int j=i;j<L->length;j++)
        {
            L->elem[j]=L->elem[j+1];
        }
        L->length--;
        return 1;
    }
}

int SearchSeqList(SeqList *L,int x){
    int j = 0;
    while (j<=L->length&&L->elem[j]!=x)
    {
        j++;
    }
    if(j>L->length){
        return -1;
    }else{
        return j;
    }
    
}

void PrintSeqList(SeqList *L){
    printf("********************RTSULT PRINT*********************\n");
    DataType *p;
    for (int i=0;i<LIST_INIT_SIZE;i++){
        p = L->elem + i;
        printf("%d\t",*p);
        if((i+1)%5==0){
            printf("\n");
        }
    }
}

void main(){//顺序表
    SeqList l; SeqList *L = &l;
    InitSeqlist(L);

    // 插入运算(InsertSeqList)测试
    // int status = InsertSeqList(L,2,5);
    // printf("STATUS:%d\n",status);

    // 删除运算(DeleteSeqList)测试
    // int status1 = DeleteSeqList(L,2);
    // printf("STATUS:%d\n",status1);
    // int status2 = DeleteSeqList(L,7);
    // printf("STATUS:%d\n",status2);

    // 查找运算(SearchSeqList)测试
    // int result = SearchSeqList(L,3);
    // printf("RESULT:%d\n",result);

    PrintSeqList(L);
}