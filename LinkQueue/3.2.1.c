#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct QNode{
    DataType data;
    struct QNode *next;
}QType; //链队中的节点类型
typedef struct qptr{
    QType *front,*rear;
}LinkQueue; //链队类型

LinkQueue *InitLinkQueue(){//初始化链队
    LinkQueue *lq = (LinkQueue *)malloc(sizeof(LinkQueue));
    lq->front=NULL; lq->rear=NULL;
    return lq;
}

void EnQueue(LinkQueue *lq,DataType x){//入队
    QType *s = (QType *)malloc(sizeof(QType));
    s->data = x; s->next = NULL;
    if (lq->front == NULL&&lq->rear == NULL)
    {
        lq->front = s; lq->rear = s;
    }else{
        lq->rear->next = s;
        lq->rear = s;
    }
}

int DeQueue(LinkQueue *lq){//入队
    QType *s;
    if(lq->front == NULL&&lq->rear == NULL){//空队列
        return 0;
    }
    s = lq->front;
    int x = s->data;
    if(lq->rear->data == lq->front->data){//若原队列中只有一个节点，删除后队列变成空队列
        lq->front==NULL; lq->rear==NULL;
    }
    lq->front = s->next;
    free(s);
    return x;
}

int GetHead(LinkQueue *lq){//取队头元素
    if (lq->front == NULL&&lq->rear == NULL)
    {
        return 0;
    }
    else
    {
        return lq->front->data;
    }
    
}

int QueueEmpty(LinkQueue *lq){//判断队列是否为空
    if(lq->front == NULL&&lq->rear == NULL){
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void main(){//队列的链式存储结构
    LinkQueue *lq = InitLinkQueue();

    EnQueue(lq,0);
    EnQueue(lq,1);
    EnQueue(lq,2);
    EnQueue(lq,3);

    int status = QueueEmpty(lq);
    int x1 = DeQueue(lq);
    int x2 = DeQueue(lq);
    int head = GetHead(lq);
    int x3 = DeQueue(lq);
    int status1 = QueueEmpty(lq);
    int x4 = DeQueue(lq);
    int status2 = QueueEmpty(lq);

    printf("QUEUEEMPTY? %d\n",status);
    printf("%d\n",x1);
    printf("%d\n",x2);
    printf("HEAD: %d\n",head);
    printf("%d\n",x3);
    printf("QUEUEEMPTY? %d\n",status1);
    printf("%d\n",x4);
    printf("QUEUEEMPTY? %d\n",status2);
}