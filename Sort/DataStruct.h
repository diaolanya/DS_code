#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#define MAX_SIZE 20

typedef int OtherType;
typedef int KeyType;
typedef struct{
    KeyType key;
    OtherType other_data;
}RecordType;
typedef struct{
    RecordType r[MAX_SIZE];
    int length;
}RecordList;

#endif