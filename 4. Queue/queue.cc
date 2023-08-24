#include <iostream>

template <class T>
class queue
{
    private:
        T* arr;
        int the_size ;
        int the_capacity;
    
    public:
        queue()
        {
            arr = new T[16];
            the_size = 0;
            the_capacity = 16;
        }

        ~queue()
        {
            delete[] arr;
        }

        void enqueue(T data)
        {
            if(the_size < the_capacity){
                arr[the_size] = data;
                the_size++;
                return;
            }
            std::cout << "Queue is full" << std::endl;
            return;
        }

        T dequeue()
        {
            if(the_size > 0){
                T temp = arr[0];
                for(int i = 0; i< the_size-1; i++){
                    arr[i] = arr[i+1];
                }
                the_size--;
                return temp;
            }
            throw std::runtime_error("Queue is empty!");
        }

        bool empty()
        {
            return the_size == 0;
        }

        bool full()
        {
            return the_size == the_capacity;
        }

        void print()
        {
            std::cout << "Queue start to end ";
            for (int i = 0; i<the_size; i++){
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            return;
        }
};

int main()
{
    queue<int> q;

    // Test enqueue and print functions
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << "Queue after enqueues:" << std::endl;
    // Output: Queue after enqueues:
    // 10 20 30
    q.print(); 

    // Test dequeue and print functions
    int dequeuedItem1 = q.dequeue();
    std::cout << "Dequeued item: " << dequeuedItem1 << std::endl; // Output: Dequeued item: 10
    std::cout << "Queue after dequeue:" << std::endl;
    // Output: Queue after dequeue:
    // 20 30
    q.print();

    int dequeuedItem2 = q.dequeue();
    int dequeuedItem3 = q.dequeue();
    std::cout << "Dequeued items: " << dequeuedItem2 << ", " << dequeuedItem3 << std::endl;
    // Output: Dequeued items: 20, 30

    // Test empty and full functions
    std::cout << "Is the queue empty? " << (q.empty() ? "Yes" : "No") << std::endl; // Output: Is the queue empty? Yes
    std::cout << "Is the queue full? " << (q.full() ? "Yes" : "No") << std::endl; // Output: Is the queue full? No

    // Attempt to dequeue from an empty queue
    try {
        int emptyDequeue = q.dequeue(); // This should throw an exception
    } catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl; // Output: Exception: Queue is empty!
    }

    // Test enqueue and full functions
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    std::cout << "Queue after enqueues:" << std::endl;
    // Output: Queue after enqueues:
    // 40 50 60
    q.print();
    std::cout << "Is the queue full? " << (q.full() ? "Yes" : "No") << std::endl; // Output: Is the queue full? Yes

    return 0;
}
