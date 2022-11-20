#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct stnode{
    DataType data;
    struct stnode *next;
}LinkStack;

LinkStack *InitLinkStack(){//栈的初始化
    LinkStack *ls = NULL;
    return ls;
}

void Push(LinkStack **l,LinkStack *ls,DataType x){//压栈
    LinkStack *p = (LinkStack *)malloc(sizeof(LinkStack));
    p->data = x;
    p->next = ls;
    *l = p;
}

int Pop(LinkStack **l,LinkStack *ls){//弹栈
    LinkStack *p;
    DataType x;
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

int GetTop(LinkStack *ls){//取栈顶元素
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

void main(){//链栈
    LinkStack *ls = InitLinkStack(); //&ls作为ls的指针，用于修改ls指向
    Push(&ls,ls,0);
    Push(&ls,ls,1);
    Push(&ls,ls,2);

    printf("GETTOP:%d\n",GetTop(ls));
    printf("POP:%d\n",Pop(&ls,ls));
    printf("POP:%d\n",Pop(&ls,ls));
    printf("ISSTACKEMPTY:%d\n",IsStackEmpty(ls));
}