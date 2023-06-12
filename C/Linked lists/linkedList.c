#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void InsertNodeAtTheBegining(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
    
}
void PrintNodes(){
    struct Node* temp = head;
    while(temp != NULL){
        printf(" %d ",temp->data);
        temp = temp -> next;
    }
    printf("\n");
}
int main () {
    InsertNodeAtTheBegining(1);
    InsertNodeAtTheBegining(2);
    InsertNodeAtTheBegining(3);
    InsertNodeAtTheBegining(4);
    PrintNodes();
    printf("this is linked list!!");
}