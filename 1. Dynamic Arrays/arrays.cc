#include <iostream>
#include <stdlib.h>

template <class T> 
class vector
{
    private:
        int the_size;
        int the_capacity;
        T* arr;
        void resize(int new_capacity)
        {
            T* temp = new T[new_capacity];
            for(int i = 0; i < the_size; i++){
                temp[i] = arr[i];
            }
            delete[] arr;
            the_capacity = new_capacity;
            arr = temp;
        }
    public:
        vector()
        {
            arr = new T[2];
            the_capacity = 2;
            the_size = 0;
        }
        ~vector()
        {
            delete [] arr;
        }

        void push(T data)
        {
            if(the_size == the_capacity){
                resize(the_capacity * 2);
            }
            arr[the_size] = data;
            the_size++;
        }

        void insert(T data, int index)
        {   
            if(index > the_size){
                std::cout << "Index is exceeding the size of the vector." << std::endl;
                exit(EXIT_FAILURE);
            } else {
                if(the_size == the_capacity){
                    resize(the_capacity * 2);
                }
                int i = the_size;
                while(i > index){
                    arr[i] = arr[i-1];
                    i--;
                }
                arr[index] = data;
                the_size++;
            } 
        }

        void prepend(T data)
        {
            insert(data, 0);
        }

        void print()
        {
            for(int i = 0; i < the_size; i++){
                std::cout << i << " -> " << arr[i]  << ", ";
            }
            std::cout << std::endl;
        }
        bool is_empty(){
            if(the_size == 0){
                return true;
            }
            return false;
        }

        int size(){
            return the_size;
        }

        int capacity(){
            return the_capacity;
        }

        T at(int index)
        {
            return arr[index];
        }

        void delete_at(int index)
        {
            if(index > the_size-1){
                std::cout << "Exceeds bounds" << std::endl;
                exit(EXIT_FAILURE);
            }
            if(the_size == the_capacity/4){
                resize(the_capacity/2);
            }
            for(int i = index; i < the_size-1; i++){
                arr[i] = arr[i+1];
            }
            the_size--;
        }

        T pop() 
        {
            T value = arr[the_size - 1];
            delete_at(the_size-1);
            
            return value;
        }

        void remove(T item)
        {
            for(int i = 0; i<the_size; i++){
                if(arr[i] == item){
                    delete_at(i);
                    i--;
                }
            }
        }

        int find(T item)
        {
            for(int i = 0; i< the_size; i++){
                if(arr[i] == item){
                    return i;
                }
            }
            return -1;
        }
};

int main()
{
    vector<int> v;

    // Test Case 1: Initial state
    std::cout << "Test Case 1: Initial state\n";
    std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << ", Is Empty: " << (v.is_empty() ? "Yes" : "No") << std::endl;
    v.print(); // Expected output: (Empty)

    // Test Case 2: Push elements
    std::cout << "\nTest Case 2: Push elements\n";
    v.push(10);
    v.push(20);
    v.push(30);
    std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << ", Is Empty: " << (v.is_empty() ? "Yes" : "No") << std::endl;
    v.print(); // Expected output: Size: 3, Capacity: 4, Is Empty: No | 0 -> 10, 1 -> 20, 2 -> 30,

    // Test Case 3: Insert element
    std::cout << "\nTest Case 3: Insert element\n";
    v.insert(15, 1);
    std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << ", Is Empty: " << (v.is_empty() ? "Yes" : "No") << std::endl;
    v.print(); // Expected output: Size: 4, Capacity: 4, Is Empty: No | 0 -> 10, 1 -> 15, 2 -> 20, 3 -> 30,

    // Test Case 4: Access element using 'at'
    std::cout << "\nTest Case 4: Access element using 'at'\n";
    int element = v.at(2);
    std::cout << "Element at index 2: " << element << std::endl; // Expected output: Element at index 2: 20

    // Test Case 5: Prepend element
    std::cout << "\nTest Case 5: Prepend element\n";
    v.prepend(5);
    std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << ", Is Empty: " << (v.is_empty() ? "Yes" : "No") << std::endl;
    v.print(); // Expected output: Size: 5, Capacity: 8, Is Empty: No | 0 -> 5, 1 -> 10, 2 -> 15, 3 -> 20, 4 -> 30,

    // Test Case 6: Pop elements
    std::cout << "\nTest Case 6: Pop elements\n";
    int popped1 = v.pop();
    int popped2 = v.pop();
    std::cout << "Popped value 1: " << popped1 << ", Popped value 2: " << popped2 << std::endl; // Expected output: Popped value 1: 30, Popped value 2: 20
    std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << ", Is Empty: " << (v.is_empty() ? "Yes" : "No") << std::endl;
    v.print(); // Expected output: Size: 3, Capacity: 8, Is Empty: No | 0 -> 5, 1 -> 10, 2 -> 15,

    // Test Case 7: Delete element
    std::cout << "\nTest Case 7: Delete element\n";
    v.delete_at(1);
    std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << ", Is Empty: " << (v.is_empty() ? "Yes" : "No") << std::endl;
    v.print(); // Expected output: Size: 2, Capacity: 4, Is Empty: No | 0 -> 5, 1 -> 15,

    // Test Case 8: Remove elements
    std::cout << "\nTest Case 8: Remove elements\n";
    v.push(20);
    v.push(15);
    v.remove(15);
    std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << ", Is Empty: " << (v.is_empty() ? "Yes" : "No") << std::endl;
    v.print(); // Expected output: Size: 3, Capacity: 8, Is Empty: No | 0 -> 5, 1 -> 20, 2 -> 15,

    // Test Case 9: Find elements
    std::cout << "\nTest Case 9: Find elements\n";
    int index1 = v.find(20);
    int index2 = v.find(10);
    std::cout << "Index of 20: " << index1 << ", Index of 10: " << index2 << std::endl; // Expected output: Index of 20: 1, Index of 10: -1

    return 0;
}

