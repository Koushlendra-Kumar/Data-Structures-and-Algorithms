#include <iostream>

struct Node {
    int val;
    struct Node* next;
};

struct Node* head = NULL;

void InsertFiveNodesAtBegining()
{
    for(int i = 0; i< 5; i++){
        int tempVal ;
        struct Node* tempNode = new Node;
        std::cout << "Add node at the begining of the Linked List : ";
        std::cin >> tempVal;
        tempNode->val = tempVal;
        tempNode->next = head;
        head = tempNode;
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
    return 0;
}