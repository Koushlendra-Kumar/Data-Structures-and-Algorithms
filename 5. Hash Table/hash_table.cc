#include <iostream>
#include <string>

template <class K, class V>
class hash_table
{
    private:
        //Linked list node for chaining
        struct object_node
        {
            K key;
            V value;
            struct object_node* next;
        };
        int the_count;
        int the_size;
        object_node** arr;
        int hash(const K& key)
        {   
            return key.length() % the_size;
        }

    public:
        hash_table()
        {
            the_size = 25;
            the_count = 0;
            arr = new struct object_node*[the_size];
            for(int i = 0; i < the_size; i++){
                arr[i] = nullptr;
            }
        }

        ~hash_table()
        {
            for(int i = 0; i< the_size; i++){
                object_node* current = arr[i];
                while(current)
                {
                    object_node* temp = current;
                    current = current->next;
                    delete temp;
                }
            }
            delete[] arr;
        }

        void add(K key, V value)
        {
            int index = hash(key);
            object_node* temp = new object_node;
            temp->key = key;
            temp->value = value;
            temp->next = arr[index];
            arr[index] = temp;
            the_count++;
        }

        bool exists(K key)
        {
            int index = hash(key);
            object_node* current = arr[index];
            while(current != nullptr){
                if(current->key == key){
                    return true;
                }
                current = current->next;
            }
            
            return false;
        }

        V get(K key)
        {
            int index = hash(key);
            object_node* current = arr[index];
            while(current != nullptr){
                if(current->key == key){
                    return current->value;
                }
                current = current->next;
            }
            return V();
        }

        void remove(K key)
        {
            int index = hash(key);
            object_node* current = arr[index];
            object_node* previous = nullptr;
            while(current != nullptr){
                if(current->key == key){
                    if(previous == nullptr){
                        arr[index] = current->next;
                    }else {
                        previous->next = current->next;
                    }
                    delete current;
                    the_count--;
                    return;
                }
                previous = current;
                current = current->next;
            }
            return;
        }

        void print()
        {
            for(int i = 0; i< the_size; i++){
                object_node* current = arr[i];
                if(current == nullptr){
                    std::cout << "Empty " ;
                    continue;
                }
                std::cout << std::endl << i << " : " ;
                while(current != nullptr){
                    std::cout << current->key << " -> " << current->value << ", ";
                    current = current->next;
                }
            }
        }
};

int main()
{
    // Create a hash_table instance to store student scores
    hash_table<std::string, int> studentScores;

    // Add scores for some students
    studentScores.add("Rahul", 85);
    studentScores.add("Priya", 92);
    studentScores.add("Amit", 78);
    studentScores.add("Deepika", 95);

    // Print the initial student scores hash table
    std::cout << "Initial student scores hash table:" << std::endl;
    studentScores.print();
    std::cout << std::endl;

    // Test exists method
    std::cout << "Exists tests:" << std::endl;
    std::cout << "Exists 'Rahul': " << studentScores.exists("Rahul") << std::endl; // Should print 1 (true)
    std::cout << "Exists 'Sita': " << studentScores.exists("Sita") << std::endl;   // Should print 0 (false)
    std::cout << std::endl;

    // Test get method
    std::cout << "Get tests:" << std::endl;
    std::cout << "Get 'Priya': " << studentScores.get("Priya") << std::endl; // Should print the score for Priya
    std::cout << "Get 'Amit': " << studentScores.get("Amit") << std::endl;   // Should print the score for Amit
    std::cout << "Get 'Krishna': " << studentScores.get("Krishna") << std::endl; // Should print 0 (default value)
    std::cout << std::endl;

    // Print the student scores hash table after additions
    std::cout << "Student scores hash table after additions:" << std::endl;
    studentScores.print();
    std::cout << std::endl;

    // Remove some student scores
    studentScores.remove("Rahul");
    studentScores.remove("Amit");

    // Print the student scores hash table after removals
    std::cout << "Student scores hash table after removals:" << std::endl;
    studentScores.print();
    std::cout << std::endl;

    return 0;
}
