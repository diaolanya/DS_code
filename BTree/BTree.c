#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#define MAXSIZE 20

BTNode *CreateBtree(char *str){//创建二叉树
    BTNode *bt;
    BTNode *St[MAXSIZE],*p = NULL;
    int top = -1,k,j = 0;
    char ch;
    bt = NULL;
    ch = str[j];
    while (ch!='\0')
    {
        switch (ch)
        {
        case '(': top++;St[top]=p;k=1;break; //为左孩子节点
        case ')': top--;break;
        case ',': k=2;break; //为右孩子节点
        default:
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch; p->lchild = p->rchild = NULL;
            if(bt == NULL){
                bt = p;
            }else{
                switch (k)
                {
                case 1: St[top]->lchild=  p; break;
                case 2: St[top]->rchild = p; break;
                }
            }
        }
        j++;
        ch = str[j];
    }
    return bt;
}

int BTHeight(BTNode *bt){//求树的高度
    int lchilddep,rchilddep;
    if (bt == NULL)
    {
        return 0;
    }
    else
    {
        lchilddep = BTHeight(bt->lchild); //求左子树高度
        rchilddep = BTHeight(bt->rchild); //求右子树高度
        return (lchilddep>rchilddep)?(lchilddep + 1):(rchilddep + 1);
    } 
}

int NodeCount(BTNode *bt){//统计节点的数量
    int lchildnode,rchildnode;
    if(bt == NULL){
        return 0;
    }else{
        lchildnode = NodeCount(bt->lchild);
        rchildnode = NodeCount(bt->rchild);
        return lchildnode + rchildnode + 1;
    }
}

int LeafCount(BTNode *bt){//统计二叉树叶子节点的数量
    int lchildleafnum,rchildleafnum;
    if(bt == NULL){
        return 0;
    }else if(bt->lchild == 0&&bt->rchild == 0){
        return 1;
    }else{
        lchildleafnum = LeafCount(bt->lchild);
        rchildleafnum = LeafCount(bt->rchild);
        return lchildleafnum + rchildleafnum;
    }
}

void DispBTree(BTNode *bt){
    if (bt != NULL){
        printf("%c",bt->data);
        if(bt->lchild != NULL||bt->rchild != NULL){
            printf("(");
            DispBTree(bt->lchild);
            if(bt->rchild != NULL){
                printf(",");
            }
            DispBTree(bt->rchild);
            printf(")");
        }
    }
    
}

void PreOrder(BTNode *bt){//先序遍历,递归算法
    if(bt != NULL){
        printf("%c",bt->data);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

void PreOrder1(BTNode *bt,LinkStack *ls){//先序遍历,非递归算法
    BTNode *p = bt;
    while (p != NULL||!IsStackEmpty(ls))
    {
        if(p != NULL){
            printf("%c",p->data);
            Push(&ls,ls,p);
            p = p->lchild;
        }else{
            p = Pop(&ls,ls);
            p = p->rchild;
        }
    }  
}

void InOrder(BTNode *bt){//中序遍历,递归算法
    if(bt != NULL){
        InOrder(bt->lchild);
        printf("%c",bt->data);
        InOrder(bt->rchild);
    }
}

void PostOrder(BTNode *bt){//后序遍历,递归算法
    if(bt != NULL){
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        printf("%c",bt->data);
    }
}

void main(){//二叉树
    LinkStack *ls = InitLinkStack(); //链栈
    char str[] = "A(B(E,F),C(G,(K,L)))";
    char *s = str;
    BTNode *bt = CreateBtree(s);

    // 求树的高度
    // int height = BTHeight(bt);
    // printf("HEIGHT: %d\n",height);

    // 求树的总节点个数
    // int nodenum = NodeCount(bt);
    // printf("NODENUM: %d\n",nodenum);

    // 求树的叶子节点个数
    // int leafnum = LeafCount(bt);
    // printf("LEAFNUM: %d",leafnum);

    // 以括号表示法输出树的运算算法
    // printf("(");
    // DispBTree(bt);

    // 先序遍历,递归算法
    //PreOrder(bt);

    // 先序遍历,非递归算法
    PreOrder1(bt,ls);

    // 中序遍历,递归算法
    // InOrder(bt);

    // 后序遍历,递归算法
    // PostOrder(bt);
}