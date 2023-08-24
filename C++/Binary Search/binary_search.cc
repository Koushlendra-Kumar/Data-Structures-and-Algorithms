#include <iostream>
#include <vector>

int bs(std::vector<int> arr, int value)
{   
    int low = 0, high = arr.size();
    while(low < high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] > value) {
            high = mid-1; 
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    // Test Case 1: Value exists in the array
    int value1 = 11;
    int index1 = bs(arr, value1);
    if (index1 != -1) {
        std::cout << "Test Case 1: Value " << value1 << " found at index " << index1 << std::endl;
    } else {
        std::cout << "Test Case 1: Value " << value1 << " not found in the array" << std::endl;
    }

    // Test Case 2: Value does not exist in the array
    int value2 = 8;
    int index2 = bs(arr, value2);
    if (index2 != -1) {
        std::cout << "Test Case 2: Value " << value2 << " found at index " << index2 << std::endl;
    } else {
        std::cout << "Test Case 2: Value " << value2 << " not found in the array" << std::endl;
    }

    // Test Case 3: Value is the first element in the array
    int value3 = 1;
    int index3 = bs(arr, value3);
    if (index3 != -1) {
        std::cout << "Test Case 3: Value " << value3 << " found at index " << index3 << std::endl;
    } else {
        std::cout << "Test Case 3: Value " << value3 << " not found in the array" << std::endl;
    }

    // Test Case 4: Value is the last element in the array
    int value4 = 19;
    int index4 = bs(arr, value4);
    if (index4 != -1) {
        std::cout << "Test Case 4: Value " << value4 << " found at index " << index4 << std::endl;
    } else {
        std::cout << "Test Case 4: Value " << value4 << " not found in the array" << std::endl;
    }

    return 0;
}
