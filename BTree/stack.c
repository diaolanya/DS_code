#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

LinkStack *InitLinkStack(){//栈的初始化
    LinkStack *ls = NULL;
    return ls;
}

void Push(LinkStack **l,LinkStack *ls,StackDataType x){//压栈
    LinkStack *p = (LinkStack *)malloc(sizeof(LinkStack));
    p->data = x;
    p->next = ls;
    *l = p;
}

StackDataType Pop(LinkStack **l,LinkStack *ls){//弹栈
    LinkStack *p;
    StackDataType x;
    if(ls==NULL){
        return 0;
    }else{
        x = ls->data;
        p = ls;
        *l = ls->next;
        free(p);
        return x;
    }
}

StackDataType GetTop(LinkStack *ls){//取栈顶元素
    if(ls == NULL){
        return 0;
    }else{
        return ls->data;
    }
}

int IsStackEmpty(LinkStack *ls){//判断栈空
    if(ls == NULL){
        return 1;
    }else{
        return 0;
    }
}