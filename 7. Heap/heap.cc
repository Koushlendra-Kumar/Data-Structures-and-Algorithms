#include <iostream>
#include <cmath>

class heap
{
    private:
        int* arr;
        int the_size;

    public:
        heap()
        {
            arr = new int[16];
            the_size = 0;
        }
        ~heap()
        {
            delete[] arr;
            the_size = 0;
        }

        void insert(int value)
        {
            arr[++the_size] = value;
            shift_up(the_size);
        }

        void shift_up(int index)
        {
            while(index > 1){
                int parent_index = std::floor(index/2);
                if(arr[index] > arr[parent_index]){
                    int temp = arr[index];
                    arr[index] = arr[parent_index];
                    arr[parent_index] = temp;
                } else {
                    break;
                }
                index = parent_index;
            }
        }

        int get_max()
        {
            return arr[1];
        }

        int get_size()
        {
            return the_size;
        }

        bool is_empty()
        {
            return the_size == 0;
        }

        int extract_max()
        {
            int temp = arr[1];
            arr[1] = arr[the_size];
            arr[the_size] = temp;
            the_size--;
            shift_down(1, the_size);
            return temp;
        }

        void shift_down(int index, int size)
        {   
            while(index <= size){
                int left_index = 2 * index;
                int right_index = 2 * index + 1;
                bool has_left = left_index <= size;
                bool has_right = right_index <= size;
                if(has_right && has_left){
                    if(arr[left_index] > arr[right_index] && arr[index] < arr[left_index]){
                        int temp = arr[index];
                        arr[index] = arr[left_index];
                        arr[left_index] = temp;
                        index = left_index;
                        continue;
                    } else if(arr[left_index] < arr[right_index] &&  arr[index] < arr[right_index]){
                        int temp = arr[index];
                        arr[index] = arr[right_index];
                        arr[right_index] = temp;
                        index = right_index;
                        continue;
                    }
                } else if(has_right){
                    int temp = arr[index];
                    arr[index] = arr[right_index];
                    arr[right_index] = temp;
                    index = right_index;
                    continue;
                } else if(has_left){
                    int temp = arr[index];
                    arr[index] = arr[left_index];
                    arr[left_index] = temp;
                    index = left_index;
                    continue;
                } else {
                    break;
                }
            }
            return;
        }

        void remove(int index)
        {
            int temp = arr[index];
            arr[index] = arr[the_size];
            arr[the_size] = temp;
            the_size--;
            shift_down(index, the_size);
            return;
        }

        void heap_sort()
        {
            int unsorted_size = the_size;
            while(unsorted_size > 0){
                int temp = arr[1];
                arr[1] = arr[unsorted_size];
                arr[unsorted_size] = temp;
                unsorted_size--;
                shift_down(1, unsorted_size);
            }
            return;
        }

        void print()
        {
            for(int i = 1; i <= the_size; i++){
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
};

int main() {
    heap my_max_heap;

    // Test 1: Insertion and get_max
    my_max_heap.insert(30);
    my_max_heap.insert(20);
    my_max_heap.insert(50);
    my_max_heap.insert(10);
    my_max_heap.print();  // Expected: 50 20 30 10
    std::cout << "Max element: " << my_max_heap.get_max() << std::endl;  // Expected: 50

    // Test 2: Extract Max
    int max_value = my_max_heap.extract_max();
    std::cout << "Extracted max: " << max_value << std::endl;  // Expected: 50
    my_max_heap.print();  // Expected: 30 20 10

    // Test 3: Heap Sort
    my_max_heap.heap_sort();
    my_max_heap.print();  // Expected: 10 20 30

    // Test 4: Removing an element
    my_max_heap.remove(2);  // Remove the element at index 2 (value 20)
    my_max_heap.print();    // Expected: 10 30

    // Test 5: Check if the heap is empty
    std::cout << "Heap is empty: " << (my_max_heap.is_empty() ? "true" : "false") << std::endl;  // Expected: false

    return 0;
}
