#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#define LIST_SIZE 20

typedef int KeyType;
typedef int OtherType;

//顺序查找数据结构
//折半查找顺序结构
typedef struct 
{
    KeyType key;
    OtherType other_data;
}RecordType;
typedef struct
{
    RecordType r[LIST_SIZE + 1]; //r[0]为工作单元
    int length;
}RecordList;


#endif