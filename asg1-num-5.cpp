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

void solve(int n){
    if(n>idx) puts("Data not found!");

    Data *curr=head;
    for(int i=1; i<n; i++){
        curr=curr->next;
    }

    printf("Number in node %d: %d\n", n, curr->num);
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
    print();

    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}
