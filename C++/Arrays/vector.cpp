#include <iostream>
#include <vector>

//Implement a find function to find the first index of given element
int find(int val, std::vector<int> arr)
{
    for(int i = 0; i< arr.size(); i++){
        if(arr[i] == val){
            return i;
        }
    }
    return -1;
}
int main() 
{
    std::cout << "!!!!!! Practice vector(dynamic arrays) in c++ !!!!!!"<< std::endl;

    //Create new array with allocated memory
    std::vector<int>dy_arr {1,2,3,4,5};

    //Initial size and capacity of vector
    std::cout << "Size of vector " << dy_arr.size() << std::endl;
    std::cout << "Capacity of vector " << dy_arr.capacity() << std::endl;

    //Print all the elements 
    std::cout << "items of the initial vector ";
    for(int i = 0; i<dy_arr.size(); i++){
        std::cout << dy_arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Push item at the end " << std::endl;
    //Add item at the end of the vetor
    dy_arr.push_back(6);

    //Size and capacity after insertion at the end
    std::cout << "Size of vector " << dy_arr.size() << std::endl;
    std::cout << "Capacity of vector " << dy_arr.capacity() << std::endl;    //capacity doubles

    //Print all the elements 
    std::cout << "items ";
    for(int i = 0; i<dy_arr.size(); i++){
        std::cout << dy_arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Pop item " << std::endl;
    //Remove item from the end of the vector
    dy_arr.pop_back();

    //Print all the elements 
    std::cout << "items ";
    for(int i = 0; i<dy_arr.size(); i++){
        std::cout << dy_arr[i] << " ";
    }
    std::cout << std::endl;
    
    //Get element at specific position using at(position) function
    std::cout << "Element at position 0 is " << dy_arr.at(0) << std::endl;

    //Checks whether vector is empty or not
    std::cout << "Is vector empty " << dy_arr.empty() << std::endl;

    std::cout << "Insert Item at the begining " << std::endl;
    //Points to the fist element of the vector
    std::vector<int>::iterator it ;
    it = dy_arr.begin();

    //Inset item at specific position
    dy_arr.insert(it,0);

    //Prit element at position 0 after insertion
    std::cout << "Element at position 0 is " << dy_arr.at(0) << std::endl;

    //Print all the elements 
    std::cout << "items after insertion at the begining ";
    for(int i = 0; i<dy_arr.size(); i++){
        std::cout << dy_arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Reduce the size of vector " << std::endl;
    //Reduce the capacity of vetor and free up empty space
    dy_arr.shrink_to_fit();

    //Print the size and capacity of vector after shrinkage
    std::cout << "Size of vector " << dy_arr.size() << std::endl;
    std::cout << "Capacity of vector " << dy_arr.capacity() << std::endl;

    std::cout << "Delete item from start " << std::endl;
    //delete element at specific position
    dy_arr.erase(dy_arr.begin());

    //Print all the elements 
    std::cout << "items after deletion ";
    for(int i = 0; i<dy_arr.size(); i++){
        std::cout << dy_arr[i] << " ";
    }
    std::cout << std::endl;
    //Find the first index of element 
    //returns -1 if element doesn't exist
    std::cout << "first index of 2 in dynamic vector " << find(2, dy_arr) << std::endl;
    std::cout << "first index of 0 in dy_arr " << find(0, dy_arr) << std::endl;

    std::cout << "Resize " << std::endl;
    //resize the vector and fill with zeros 
    dy_arr.resize(20);

    //Print the size of vector after resizing
    std::cout << "size " << dy_arr.size() << std::endl;

    //Print all the elements after resizing vector
    std::cout << "items after resizing ";
    for(int i = 0; i<dy_arr.size(); i++){
        std::cout << dy_arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Items after resizing with val as second parameter " << std::endl;
    //resize the vector and fill with second param if new size is greater than prev size
    dy_arr.resize(22, 7);

    //Print the size of vector after resizing
    std::cout << "size " << dy_arr.size() << std::endl;

    //Print all the elements after resizing vector
    std::cout << "items after resizing ";
    for(int i = 0; i<dy_arr.size(); i++){
        std::cout << dy_arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}