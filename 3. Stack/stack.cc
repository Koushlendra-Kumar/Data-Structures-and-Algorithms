#include <iostream>

template <class T>
class stack
{
    private:
        T* arr;
        int the_size ;
        int the_capacity;
    public:
        stack()
        {
            arr = new T[16];
            the_size = 0;
            the_capacity = 16;
        }

        ~stack()
        {
            delete[] arr;
        }

        void push(T data)
        {   
            if(the_capacity == the_size){
                std::cout << "Stack overflow" << std::endl;
            }
            arr[the_size] = data;
            the_size++;
        }

        void pop()
        {   
            if(the_size > 0){
                the_size--;
                return;
            }
            std::cout << "The stack is empty!" << std::endl;
            return;
        }

        T top()
        {   
            if(the_size> 0){
                return arr[the_size - 1];
            }
            throw std::runtime_error("stack is empty");
        }

        bool empty()
        {
            return the_size == 0;
        }

        int size()
        {
            return the_size;
        }

        void print()
        {   
            std::cout << "Stack top to bottom:" ;
            for(int i = the_size-1; i>=0; i--){
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
};

int main()
{
    stack<int> s;

    // Test size and empty functions on an empty stack
    std::cout << "Size of the stack: " << s.size() << std::endl; // Output: Size of the stack: 0
    std::cout << "Is the stack empty? " << (s.empty() ? "Yes" : "No") << std::endl; // Output: Is the stack empty? Yes

    // Test push and print functions
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << "Stack after pushes:" << std::endl;
    s.print(); // Output: Stack top to bottom: 30 20 10

    // Test size and empty functions after pushes
    std::cout << "Size of the stack: " << s.size() << std::endl; // Output: Size of the stack: 3
    std::cout << "Is the stack empty? " << (s.empty() ? "Yes" : "No") << std::endl; // Output: Is the stack empty? No

    // Test top function
    int topElement = s.top();
    std::cout << "Top element: " << topElement << std::endl; // Output: Top element: 30

    // Test pop function and print
    s.pop();
    std::cout << "Stack after pop:" << std::endl;
    s.print(); // Output: Stack top to bottom: 20 10

    // Test size and empty functions after pop
    std::cout << "Size of the stack: " << s.size() << std::endl; // Output: Size of the stack: 2
    std::cout << "Is the stack empty? " << (s.empty() ? "Yes" : "No") << std::endl; // Output: Is the stack empty? No

    // Test multiple pops
    s.pop();
    s.pop();
    std::cout << "Stack after multiple pops:" << std::endl;
    s.print(); // Output: Stack top to bottom:

    // Test size and empty functions after multiple pops
    std::cout << "Size of the stack: " << s.size() << std::endl; // Output: Size of the stack: 0
    std::cout << "Is the stack empty? " << (s.empty() ? "Yes" : "No") << std::endl; // Output: Is the stack empty? Yes

    // Test top function on an empty stack
    try {
        int emptyTop = s.top(); // This should throw an exception
    } catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl; // Output: Exception: stack is empty
    }

    return 0;
}
