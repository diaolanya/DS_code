#include<stdio.h>
#include<stdlib.h>
typedef int DataType;

typedef struct node{//双向链表数据结构
    DataType data;
    struct node *prior,*next;
}DNode,*DLink;

DLink InitHead(){//初始化双向链表头结点
    DLink head = (DNode *)malloc(sizeof(DNode));
    head->prior = NULL;
    head->next = NULL;
    return head;
}

void AddTail(DLink head){//使用尾插法建立双向链表
    DLink p = head,q;  //p指向链表最后一个节点，q指向新创建的节点
    int x;
    scanf("%d",&x);
    while(x!=-1){
        q = (DNode *)malloc(sizeof(DNode));
        q->data = x; q->next = NULL; q->prior = p; p->next = q;
        p = q; 
        scanf("%d",&x);
    }
}

void PrintDLink(DLink head){//按照单链表方式，打印双向链表
    DLink p = head;
    if(p == NULL){
        printf("HEAD NULL!");
    }else if(p->next == NULL){
        printf("[]");
    }else{
        printf("[]");
        p = p->next;
        while (p)
        {
            printf(" --> ");
            printf("%d",p->data);
            p = p->next;
        }
    }
}

DLink GetNode(DLink head,int i){//查找第i个节点指针
    DLink p = head;
    int j = 0;
    while(p->next&&j<i){
        j++;
        p = p->next;
    }
    if(j==i){
        return p;
    }else{
        return NULL;
    }


}

void InsertNodePrior(DLink prior,int x){//双向链表在prior后插入节点
    DLink p = prior,q; //p指向插入节点的前驱，q指向插入的节点
    q = (DNode *)malloc(sizeof(DNode)); //创建q节点
    q->data = x; //q节点赋值
    q->next = p->next;  //令q的后继指向p的后继
    if(p->next){ //如果p的后继存在，令p的后继的前驱指向q
        p->next->prior =  q;
    }
    q->prior = p; //令q的前驱指向p
    p->next = q; //令p的后继指向q
}

void InsertNodeNext(DLink next,int x){//双向链表在next之前插入节点
    DLink n = next,q; //q指向正在处理的节点，即插入节点
    q = (DNode *)malloc(sizeof(DNode));
    q->data = x; 
    q->prior = n->prior; n->prior->next = q;
    q->next = n; n->prior = q;
}

int DeleteNode(DLink prior){//双向链表删除prior后面的节点
    DLink p = prior;
    if(p->next == NULL){
        return 0;
    }else{
        DLink q = p->next;
        p->next = q->next;
        if(p->next!=NULL){
            p->next->prior = p;
        }
        free(q);
        return 1;
    }
}

void main(){//双向链表
    DLink head = InitHead();
    AddTail(head);

    // 插入节点测试,插入到prior之后
    // DLink prior = GetNode(head,2);
    // InsertNodePrior(prior,100);

    //插入节点测试，插入到next之前
    // DLink next = GetNode(head,4);
    // InsertNodeNext(next,100);

    // 删除节点测试
    // DLink prior = GetNode(head,2);
    // int status = DeleteNode(prior);
    // printf("STATUS:%d\n",status);

    PrintDLink(head);
}