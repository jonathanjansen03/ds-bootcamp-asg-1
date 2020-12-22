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

int detectCycle(){
    Data *slow=head, *fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return 1;
        }
    }
    return 0;
}

int main(){
    for(int i=10; i<51; i+=10){
        pushTail(i);
    }
    head->next->next->next->next->next=head;
    detectCycle();
    
    detectCycle() ? puts("There is a cycle") : puts("There is no cycle");
    return 0;
}
