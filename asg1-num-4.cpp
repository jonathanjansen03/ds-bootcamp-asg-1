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

void pushHead(int num){
    Data *newNode=createNode(num);

    if(!head){
        head=tail=newNode;
    } else {
        newNode->next=head;
        head=newNode;
    }
}

void pushTail(int num){
    Data* newNode=createNode(num);

    if(!head){
        head=tail=newNode;
    } else {
        tail->next=newNode;
        tail=newNode;
    }
}

void pushMid(int num){
    Data *newNode=createNode(num);
    if(!head){
        head=tail=newNode;
    } else if(newNode->num < head->num){
        pushHead(num);
    } else if(newNode->num > tail->num){
        pushTail(num);
    } else {
        Data *curr=head;
        while(newNode->num > curr->next->num){
            curr=curr->next;
        }
        newNode->next=curr->next;
        curr->next=newNode;
    }
}

void removeDuplicates(){
    Data* curr=head;
    Data* next_next;
    if(!curr) return;

    while (curr->next!=NULL){
        if(curr->num==curr->next->num){
            next_next=curr->next->next;
            free(curr->next);
            curr->next=next_next;
        } else {
            curr=curr->next;
        }
    }
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
    for(int i=10; i<61; i+=10){
        pushTail(i);
    }

    pushMid(10);
    pushMid(30);
    pushMid(40);
    pushMid(60);

    puts("With duplicates:");
    print();

    puts("");
    puts("Without duplicates:");
    removeDuplicates();
    print();

    return 0;
}
