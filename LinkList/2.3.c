#include<stdio.h>
#include<stdlib.h>
typedef int DataType;

typedef struct node{//链表数据结构
    DataType data;
    struct node *next;
}LinkList;

LinkList *AddHead(){/*用头插法建立带头结点的单链表*/
    int x;
    LinkList *head,*p;
    head = (LinkList *)malloc(sizeof(LinkList));
    head->next = NULL;
    scanf("%d",&x);
    while(x!=-1){
        p=(LinkList *)malloc(sizeof(LinkList));
        p->data = x;
        p->next = head->next; head->next = p;
        scanf("%d",&x);
    }
    return head;
}

LinkList *AddTail(){/*用尾插发建立带头结点的单链表,注意,头插法和尾插发头结点都不存数据*/
    LinkList *head,*p,*q; 
    head = (LinkList *)malloc(sizeof(LinkList));
    head->next=NULL; q=head;
    int x;
    scanf("%d",&x);
    while(x!=-1){
        p = (LinkList *)malloc(sizeof(LinkList));
        p->data = x;
        if(head->next==NULL){
            head->next=p;
        }else{
            q->next=p;
        }
        q = p;
        scanf("%d",&x);
    }
    if(q!=NULL){
        q->next = NULL;
    }
    return head;
}

LinkList *GetNode(LinkList *head,int i){
    /*在带头节点的单链表中查找第i个节点，若找到则返回该节点指针，否则返回NULL*/
    LinkList *p=head;
    int j=0;
    while(p->next&&j<i){
        j++;
        p=p->next;
    }
    if(j==i){
        return p;
    }else{
        return NULL;
    }
}

LinkList *LocateNode(LinkList *head,int x){//单链表按值查找，返回指向第一个值相同节点的指针
    LinkList *p=head->next;
    while(p&&p->data!=x){
        p=p->next;
    }
    return p;
}

int InsertNode(LinkList *p,int x){//插入节点
    LinkList *q = (LinkList *)malloc(sizeof(LinkList));
    q->data=x; q->next=p->next; p->next=q;
}

int DeleteNode(LinkList *p){//删除p的下一个节点，注意在使用GetNode获取节点的时候，获取i-1个节点，即pre
    if(p->next){
        LinkList *q=p->next;
        p->next=q->next;
        free(q);
        return 1;
    }else{
        return 0;
    }
}

int PrintLinkList(LinkList *head){//打印当前的链表
    LinkList *p;
    p = head->next; 
    printf("[] --> ");   
    while(p){
        printf("%d",p->data);
        if(p->next){
            printf(" --> ");
            p = p->next;
        }else{
            return 0;
        }
    }
}

int ListLen(LinkList *head){
    LinkList *p=head;
    int len = 0;
    while(p->next){
        len++;
        p=p->next;
    }
    return len;
}

void main(){//单链表
    LinkList *head;

    // 头插法建表
    // head = AddHead();

    // 尾插法建表
    // head = AddTail();

    // 在链表中查找节点
    // head = AddHead();
    // LinkList *test1 = GetNode(head,2);
    // printf("DATA:%d NEXT:%d\n",test1->data,test1->next);

    // 在链表中插入节点
    // head = AddHead();
    // LinkList *test1 = GetNode(head,2);
    // int status = InsertNode(test1,0);

    // 在链表中删除节点
    // head = AddHead();
    // LinkList *test2 = GetNode(head,2);
    // int status = DeleteNode(test2);

    // 在单链表中按值查找节点
    // head = AddHead();
    // LinkList *test3 = LocateNode(head,2);
    // if(test3){
    //     printf("DATA:%d NEXT:%d",test3->data,test3->next);
    // }else{
    //     printf("NULL");
    // }

    // 求单链表长度
    // head = AddHead();
    // int len = ListLen(head);
    // printf("%d",len);

    PrintLinkList(head);
}