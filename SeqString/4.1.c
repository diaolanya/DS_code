#include<stdio.h>
#include<string.h>
#define MAXSIZE 20

typedef struct /*定义串结构*/
{
    char s[MAXSIZE];
    int len;
}SeqString;

int StrCat(SeqString *S1,SeqString *S2){
    /*将S2连接到S1的末尾组成新串，若S2可以完全连接到S1的末尾，返回1，否则，返回0*/
    int i;
    if(S1->len + S2->len < MAXSIZE){
        for ( i = 0; i < S2->len; i++)
        {
            S1->s[S1->len+i] = S2->s[i];
        }
        S1->len = S1->len + S2->len;
        return 1;
    }else{
        for (i = 0; i < MAXSIZE-S1->len; i++)
        {
            S1->s[S1->len+i] = S2->s[i];
        }
        S1->len = S1->len + S2->len;
        return 0;
    }
}

int StrSub(SeqString *S1,SeqString *S,int i,int piecelen){
    /*求子串,S1为主串,S为子串,i为起始位置,piecelen为长度*/
    if(i + piecelen > MAXSIZE){
        printf("子串越界");
        return 0;
    }else{
        for(int k=0;k<piecelen;k++){
            S->s[k] = S1->s[i+k];
        }
    }
    S->len = piecelen;
    return 1;
}

int StrInsert(SeqString *S,int i,SeqString *T){
    /*将串T插入到串S的第i个字符之后,S中的第i个字符之后的字符后移*/
    if (S->len + T->len > MAXSIZE)
    {
        printf("无法插入");
        return 0;
    }else if(i == 0){
        for (int k=S->len+T->len;k>T->len;k--){
            S->s[k] = S->s[k-T->len];
        }
        for (int k=0;k<T->len;k++){
            S->s[k] = T->s[k];
        }
        S->len = S->len + T->len;
    }else if(i == S->len){
        for (int k=S->len;k<S->len+T->len;k++){
            S->s[k] = T->s[k-S->len];
        }
        S->len = S->len + T->len;
    }else{
        for (int k=S->len-1;k>=i;k--){
            S->s[k+T->len] = S->s[k];
        }
        for (int k=0;k<T->len;k++){
            S->s[i+k] = T->s[k];
        }
        S->len = S->len + T->len;
        return 1;
    }

    
}

int StrDelete(SeqString *S,int i,int piecelen){
    if(i + piecelen > S->len){
        printf("子串越界");
        return 0;
    }else{
        for(int k=i+piecelen;k<S->len;k++,i++){
            S->s[i] = S->s[k];
        }
        return 1;
    }
}

int StrIndex(SeqString *S,SeqString *T){
    int i=0,j=0;
    while(i<S->len&&j<T->len){
        if(S->s[i] == T->s[j]){
            i++;j++;
        }else{
            i=i-j+1;
            j=0;
        }
    }
    if(j>=T->len){
        return i-T->len;
    }else{
        return 0;
    }
}

void main(){//串
    SeqString s; SeqString *S = &s;
    SeqString s1 = {"hello",5}; SeqString *S1 = &s1;
    SeqString s2 = {"China",5}; SeqString *S2 = &s2;
    SeqString s3 = {"shujujiegouchengxu",18}; SeqString *S3 = &s3;
    SeqString s4 = {"wdnmnmdwuwdnmd",14}; SeqString *S4 = &s4;
    SeqString s5 = {"wdnmd",5}; SeqString *S5 = &s5;
    
    // StrCat测试
    // int status1 = StrCat(S1,S2);
    // printf("StrCat测试:状态码:%d,S1和S2拼接后字符串:%s\n",status1,S1->s);
    // int status2 = StrCat(S1,S3);
    // printf("StrCat测试:状态码:%d,S1和S2拼接后字符串:%s\n",status2,S1->s);

    // StrSub测试
    // int status3 = StrSub(S3,S,2,5);
    // printf("StrSub测试:状态码:%d,子串:%s\n",status3,S->s);

    // StrInsert测试
    // int status4 = StrInsert(S1,1,S2);
    // printf("StrInsert测试:状态码%d,结果串:%s\n",status4,S1);

    // StrDelete测试
    // int status5 = StrDelete(S1,1,2);
    // printf("StrDelete测试:状态码:%d,结果串:%s\n",status5,S1);

    // StrIndex测试
    int result = StrIndex(S4,S5);
    printf("StrIndex测试:结果:%d\n",result);
}
