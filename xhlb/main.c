//
//  main.c
//  xhlb
//
//  Created by 王浩潼 on 2017/9/15.
//  Copyright © 2017年 Wangh7. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data; 
    struct LNode *next;
}LNode;

LNode *CreateList(){
    int data;
    LNode *head,*p,*q;
    head=p=(LNode *)malloc(sizeof(LNode));
    p->next = NULL;
    while(1){
        scanf("%d",&data);
        if(data==32767)break;
        q=(LNode *)malloc(sizeof(LNode));
        q->data=data;
        q->next=p->next;
        p->next=q;
        p=q;
    }
    return head;
}

void FindList(LNode *L,int key){
    LNode *p=L->next;
    while(p&&p->data!=key)
        p=p->next;
    if(!p){
        printf("Not Found!\n");
    }
    else
        printf("Found %d\n",p->data);
}

void InsertList(LNode *L,int i,int e){
    int j=0;
    LNode *p,*q;
    p=L->next;
    while(p!=NULL&&j<i-1){  //首位为0
        p=p->next;
        j++;
    }
    if(j!=i-1)
        printf("i is too large or i is zero\n");
    else{
        q=(LNode*)malloc(sizeof(LNode));
        q->data=e;
        q->next=p->next;
        p->next=q;
    }
}

void DeleteList(LNode *L,int key){
    LNode *p=L,*q=L->next;
    while(q&&q->data!=key){
        p=q;
        q=q->next;
    }
    if(!q)
        printf("Not Found!\n");
    else{
        p->next=q->next;
        free(q);
    }
}

void PrintList(LNode *h){
    LNode *p;
    p=h->next;
    while (p){
        printf("%d",p->data);
        p=p->next;
        printf("\n");
    }
}

int main(){
    LNode *h;
    int k,n,data_ins,data_del;
    h=CreateList();
    printf("press the key to find:\n");
    scanf("%d",&k);
    FindList(h, k);
    printf("press the data to insert:\n");
    scanf("%d%d",&n,&data_ins);
    InsertList(h ,n , data_ins);
    printf("after insert:\n");
    PrintList(h);
    printf("press the data to delete:\n");
    scanf("%d",&data_del);
    DeleteList(h, data_del);
    printf("after delete:\n");
    PrintList(h);
    return 0;
}

