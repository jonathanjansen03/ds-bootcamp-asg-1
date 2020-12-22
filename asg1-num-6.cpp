#include <stdio.h>
#include <stdlib.h>

struct Data{
    int num;
    Data *next;
}*head=NULL, *tail=NULL;

Data *createNode(int num){
    Data *newNode=(Data*)malloc(sizeof(Data));
    newNode->num=num;
    newNode->next=NULL;
    return newNode;
}

void pushTail(int num){
    Data *temp=createNode(num);
    if(!head){
        head=tail=temp;
    } else {
        tail->next=temp;
        tail=temp;
    }
}

void reverse(){
    Data *curr=head, *prev=NULL, *next=NULL;

    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

void print(){
    printf("%d", head->num);
    Data *curr=head->next;
    while(curr){
        printf(" -> ");
        printf("%d", curr->num);
        curr=curr->next;
    }
    puts("");
}

int main(){
    for(int i=10; i<51; i+=10){
        pushTail(i);
    }
    puts("Before reversing:");
    print();

    puts("");
    
    reverse();
    puts("After reversing:");
    print();

    return 0;
}
