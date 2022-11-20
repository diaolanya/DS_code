#include<stdio.h>
#include<stdlib.h>
#define StackSize 100

typedef int DataType;
typedef struct sqst{
    DataType data[StackSize];
    int top;  //栈指针
}SeqStack,*SeqStackLink;

SeqStackLink InitStack(){//栈初始化
    SeqStackLink sq = (SeqStack *)malloc(sizeof(SeqStack));
    sq->top = -1;
    return sq;
}

int Push(SeqStackLink sq,DataType x){//压栈
    if (sq->top == StackSize - 1)//栈满
    {
        return 0;
    }else{
        sq->top++;
        sq->data[sq->top] = x;
        return 1; 
    }
    
}

int Pop(SeqStackLink sq){//弹栈
    if(sq->top == -1){
        return 0;
    }else{
        return sq->data[sq->top--];
    }
}

int GetTop(SeqStackLink sq){//取栈顶元素
    if(sq->top == -1){
        return 0;
    }else{
        return sq->data[sq->top];
    }
}

int IsStackEmpty(SeqStackLink sq){
    return sq->top=-1?1:0;
}

void main(){//顺序栈
    SeqStackLink sq = InitStack();

    Push(sq,2);
    Push(sq,3);
    int result = Pop(sq);
    printf("RESULT:%d\n",result);
    int topelem = GetTop(sq);
    printf("TOPELEM:%d\n",topelem);
    int result1 = Pop(sq);
    printf("RESULT1:%d\n",result1);
    int result2 = Pop(sq);
    printf("RESULT2:%d\n",result2);
    printf("%d\n",IsStackEmpty(sq));

}