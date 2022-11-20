typedef  struct bkbtnode* StackDataType;
typedef int DataType;

typedef struct stnode{//链栈数据结构
    StackDataType data;
    struct stnode *next;
}LinkStack;

typedef struct bkbtnode{//二叉树数据结构
    DataType data;
    struct bkbtnode *lchild;
    struct bkbtnode *rchild;
}BTNode,*BKBTree;

LinkStack *InitLinkStack();
void Push(LinkStack **l,LinkStack *ls,StackDataType x);
StackDataType Pop(LinkStack **l,LinkStack *ls);
StackDataType GetTop(LinkStack *ls);
int IsStackEmpty(LinkStack *ls);