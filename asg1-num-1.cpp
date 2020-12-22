#include <stdio.h>
#include <stdlib.h>

struct Data1{
    int num;
    Data1 *next;
}*head1=NULL, *tail1=NULL;

struct Data2{
    int num;
    Data2 *next;
}*head2=NULL, *tail2=NULL;

Data1 *createNode1(int num){
    Data1 *newNode=(Data1*)malloc(sizeof(Data1));
    newNode->num=num;
    newNode->next=NULL;
    return newNode;
}

Data2 *createNode2(int num){
    Data2 *newNode=(Data2*)malloc(sizeof(Data2));
    newNode->num=num;
    newNode->next=NULL;
    return newNode;
}

void pushHead(int num){
    Data1 *newNode=createNode1(num);

    if(!head1){
        head1=tail1=newNode;
    } else {
        newNode->next=head1;
        head1=newNode;
    }
}

void pushTail1(int num){
    Data1 *newNode=createNode1(num);
    if(!head1){
        head1=tail1=newNode;
    } else {
        tail1->next=newNode;
        tail1=newNode;
    }
}

void pushTail2(int num){
    Data2 *newNode=createNode2(num);
    if(!head2){
        head2=tail2=newNode;
    } else {
        tail2->next=newNode;
        tail2=newNode;
    }
}

void pushMid(int num){
    Data1 *newNode=createNode1(num);
    if(!head1){
        head1=tail1=newNode;
    } else if(newNode->num < head1->num){
        pushHead(num);
    } else if(newNode->num > tail1->num){
        pushTail1(num);
    } else {
        Data1 *curr=head1;
        while(newNode->num > curr->next->num){
            curr=curr->next;
        }
        newNode->next=curr->next;
        curr->next=newNode;
    }
}

void popHead(){
    if(!head2){
        return;
    } else {
        Data2 *temp=head2;
        head2=head2->next;
        free(temp);
        temp=NULL;
    }
}

void merge(){
    Data2 *curr=head2;
    while(curr){
        pushMid(curr->num);
        curr=curr->next;
        popHead();
    }
}

void print1(){
    printf("%d", head1->num);
    Data1 *curr=head1->next;
    while(curr){
        printf(" -> ");
        printf("%d", curr->num);
        curr=curr->next;
    }
    puts("");
}

void print2(){
    printf("%d", head2->num);
    Data2 *curr=head2->next;
    while(curr){
        printf(" -> ");
        printf("%d", curr->num);
        curr=curr->next;
    }
    puts("");
}

int main(){
    for(int i=10; i<31; i+=10){
        pushTail1(i);
    }
    puts("First linked list:");
    print1();

    for(int i=40; i<61; i+=10){
        pushTail2(i);
    }
    puts("");
    puts("Second linked list:");
    print2();

    merge();
    puts("");
    puts("Merged linked list:");
    print1();
    return 0;
}
