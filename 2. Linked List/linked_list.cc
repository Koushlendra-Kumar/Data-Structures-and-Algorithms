#include <iostream>

// Doubley Linked List 
// struct Node {
//         T data;
//         struct Node* next;
//         struct Node* prev;
//     }


//*Zero based indexing
template <class T>
class list
{
    private:
        struct Node {
            T data;
            struct Node* next;
        };
        struct Node* head;
        struct Node* tail;
        int the_size;

    public:
        list() 
        {
            head = nullptr;
            tail = nullptr;
            the_size = 0;
        }

        ~list() 
        {
            struct Node* current = head;
            while(current){
                struct Node* nextNode = current->next;
                delete current;
                current = nextNode;

            }
        }

        int size()
        {
            return the_size;
        }

        bool is_empty() 
        {
            return the_size == 0;
        }

        T at(int index)
        {   
            int i = 0;
            struct Node* temp = head;
            while(i < index && temp->next != nullptr){
                temp = temp->next;
                i++;
            }
            return temp->data;
        }

        void push_front(T data)
        {
            struct Node* temp = new Node;
            temp->data = data;
            temp->next = head;
            head = temp;
            if(tail == nullptr){
                tail = temp;
            }
            the_size++;
        }

        T pop_front()
        {
            T temp = at(0);
            erase(0);
            if(the_size == 0){
                tail = nullptr;
            }
            return temp;
        }

        void push_back(T data)
        {
            insert(data, the_size);
        }

        T pop_back()
        {
            T temp = at(the_size-1);
            erase(the_size-1);
            if(the_size == 0){
                tail = nullptr;
            }
            return temp;
        }

        T front()
        {
            return at(0);
        }

        T back()
        {
            return tail->data;
        }

        void insert(T data, int index)
        {
            if(index > the_size){
                std::cout<< "Exceeding bounds" << std::endl;
                return;
            } else if(index == 0){
                push_front(data);
                return;
            }
            struct Node* prev = head;
            struct Node* temp = new Node;
            int i = 0;
            while(i<index-1 && prev->next != nullptr){
                i++;
                prev = prev->next;
            }
            temp->data = data;
            temp->next = prev->next;
            prev->next = temp;
            if(index == the_size){
                tail = temp;
            }
            the_size++;
        }

        void erase(int index)
        {   
            if (head == nullptr || index >= the_size) {
                return;
            }
            if (index == 0){
                struct Node* temp = head;
                head = temp->next;
                delete temp;
                the_size--;
                return;
            } 
            struct Node* temp = head;
            int i = 0;
            while(i < index-1 && temp->next != nullptr){
                i++;
                temp = temp->next;
            }
            if(index == the_size-1){
                tail = temp;
            }
            struct Node* node_to_remove = temp->next;
            temp->next = node_to_remove->next;
            delete node_to_remove;
            the_size--;
            return;
        }

        void reverse()
        {
            struct Node* prev = nullptr;
            struct Node* cur = head;
            struct Node* next;

            while(cur != nullptr){
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            tail = head;
            head = prev;
        }

        int find(T value)
        {
            int i = 0;
            struct Node* temp = head;
            while(i < the_size){
                if(temp->data == value){
                    return i;
                }
                i++;
                temp = temp->next;
            }
            return -1;

        }
        void remove_value(T value)
        {
            erase(find(value));
            return;
        }

        T value_nth_from_end(int n)
        {
            int i = the_size-1;
            while(n > 1){
                i--;
                n--;
            }
            return at(i);
        }

        void print()
        {
            int i = 0;
            while(i < the_size){
                std::cout<< i << " -> " << at(i) << ", ";
                i++;
            }
            std::cout << std::endl;
        }
};

int main() {
    list<int> my_list;

    // Test size and is_empty functions
    std::cout << "Size: " << my_list.size() << ", Empty: " << (my_list.is_empty() ? "true" : "false") << std::endl;

    // Test push_front and push_back
    my_list.push_front(10);
    my_list.push_front(20);
    my_list.push_back(30);
    std::cout << "After push operations:" << std::endl;
    my_list.print();

    // Test size and is_empty after adding elements
    std::cout << "Size: " << my_list.size() << ", Empty: " << (my_list.is_empty() ? "true" : "false") << std::endl;

    // Test pop_front
    int frontValue = my_list.pop_front();
    std::cout << "Popped front value: " << frontValue << std::endl;

    // Test pop_back
    int backValue = my_list.pop_back();
    std::cout << "Popped back value: " << backValue << std::endl;

    // Test front and back functions
    std::cout << "Front value: " << my_list.front() << ", Back value: " << my_list.back() << std::endl;

    // Test insert function
    my_list.insert(15, 1);
    my_list.insert(25, 2);
    std::cout << "After insert operations:" << std::endl;
    my_list.print();

    // Test erase function
    my_list.erase(1);
    std::cout << "After erase operation:" << std::endl;
    my_list.print();

    // Test reverse function
    my_list.reverse();
    std::cout << "After reverse operation:" << std::endl;
    my_list.print();

    // Test find function
    int index = my_list.find(10);
    std::cout << "Index of value 10: " << index << std::endl;

    // Test remove_value function
    my_list.remove_value(10);
    std::cout << "After removing value 10:" << std::endl;
    my_list.print();

    // Test value_nth_from_end function
    int nthValue = my_list.value_nth_from_end(1);
    std::cout << "Value 1st from the end: " << nthValue << std::endl;

    return 0;
}
