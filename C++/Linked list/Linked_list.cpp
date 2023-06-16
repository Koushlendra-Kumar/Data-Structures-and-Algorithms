#include <iostream>

struct Node {
    int val;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;
void InsertFiveNodesAtBegining()
{
    for(int i = 0; i< 5; i++){
        int tempVal ;
        struct Node* tempNode = new Node;
        std::cout << "Add node at the BEGINING of the Linked List : ";
        std::cin >> tempVal;
        tempNode->val = tempVal;
        tempNode->next = head;
        head = tempNode;
        if(tail == NULL){
            tail = tempNode;
        }
    }
}
void InsertFiveNodesAtTheEnd()
{
    for(int i = 0; i< 5; i++){
        int tempVal ;
        struct Node* tempNode = new Node;
        std::cout << "Add node at the END of the Linked List : ";
        std::cin >> tempVal;
        tempNode->val = tempVal;
        tempNode->next = NULL;
        if(tail->next == NULL){
            tail->next = tempNode;
        }
        tail = tempNode;
    }
}

void PrintList(Node* head){
    std::cout << "Linked List : ";
    struct Node* temp = head;
    while(temp != NULL){
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{   
    InsertFiveNodesAtBegining();
    PrintList(head);
    InsertFiveNodesAtTheEnd();
    PrintList(head);
    return 0;
}