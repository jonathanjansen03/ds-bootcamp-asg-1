#include <stdio.h>
#include <stdlib.h>

struct Data{
    int num;
    Data *next;
}*head=NULL, *tail=NULL;

int idx=0;

Data *createNode(int num){
    Data *newNode=(Data*)malloc(sizeof(Data));
    newNode->num=num;
    newNode->next=NULL;
    return newNode;
}

void pushTail(int num){
    Data* newNode=createNode(num);

    if(!head){
        head=tail=newNode;
    } else {
        tail->next=newNode;
        tail=newNode;
    }
    idx++;
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

void printMid(){
    Data *curr=head;
    int mid=idx%2 ? idx/2 : idx/2-1;

    while(mid--){
        curr=curr->next;
    }
    printf("%d\n", curr->num);
}

int main(){
    for(int i=10; i<51; i+=10){
        pushTail(i);
    }

    print();
    puts("");

    puts("Middle node:");
    printMid();
    return 0;
}
