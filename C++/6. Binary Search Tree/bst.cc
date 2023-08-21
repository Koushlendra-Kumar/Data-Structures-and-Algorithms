#include <iostream>
#include <queue>
#include <climits>

template <class T>
class bst
{
    public:
        struct bst_node
        {
            int data;
            bst_node* left;
            bst_node* right;
        };

        bst_node* root = nullptr;
        int node_count = 0;
        bst(){}

        ~bst()
        {
            delete_tree(root);
        }

        void delete_tree(bst_node* &root)
        {
            if(root == nullptr){
                return;
            }
            if(root->left != nullptr){
                delete_tree(root->left);
            } 
            if(root->right != nullptr){
                delete_tree(root->right);
            }
            delete root;
            root = nullptr;
        }

        bst_node* get_new_node(int value)
        {
            bst_node* new_node = new bst_node;
            new_node->data = value;
            new_node->left = new_node->right = nullptr;
            return new_node;
        }

        bst_node* insert(int value, bst_node* root)
        {
            if(root == nullptr){
                root = get_new_node(value);
                node_count++;
                return root;
            } else if (root->data >= value){
                root->left = insert(value, root->left);
            } else  {
                root->right =  insert(value, root->right);
            }
            return root;
        }

        void print_bfs(bst_node* root)
        {
            std::queue<bst_node*> node_q ;
            node_q.push(root);
            while(!node_q.empty()){
                bst_node* temp = node_q.front();
                std::cout << temp->data << " ";
                if(temp->left != nullptr){
                    node_q.push(temp->left);
                }
                if(temp->right != nullptr){
                    node_q.push(temp->right);
                }
                node_q.pop();
            }
            return;
        }

        void print_dfs_in_order(bst_node* root)
        {
            if(root == nullptr){
                return;
            }
            print_dfs_in_order(root->left);
            std::cout << root->data << " ";
            print_dfs_in_order(root->right);
        }

        bool binary_search(bst_node* root, int value)
        {
            if(root == nullptr){
                return false;
            } 
            if(root->data <value){
                return binary_search(root->right, value);
            }else if(root->data > value) {
                return binary_search(root->left, value);
            }
            return true;
        }

        bst_node* get_min_node(bst_node* root)
        {
            if(root == nullptr){
                return nullptr;
            }
            if(root->left == nullptr){
                return root;
            }
            return get_min_node(root->left);
        }

        bst_node* get_max_node(bst_node* root)
        {
            if(root == nullptr){
                return nullptr;
            } 
            if(root->right == nullptr){
                return root;
            }
            return get_max_node(root->right);
        }

        int get_height(bst_node* root)
        {
            if(root== nullptr){
                return 0;
            }
            return 1 + std::max(get_height(root->left), get_height(root->right));
        }

        bool is_between(bst_node* root, int min, int max)
        {
            if(root == nullptr){
                return true;
            }
            if(root->data > min && root->data < max &&
                is_between(root->left, min, root->data) &&
                is_between(root->right, root->data, max)){
                    return true;
            }
            else {
                return false;
            }
        }

        bool is_binary_search_tree(bst_node* root){
            return is_between(root, INT_MIN, INT_MAX);
        }

        bst_node* delete_value(bst_node* root, int value)
        {
            if(root == nullptr){
                return nullptr;
            }
            if(value < root->data){
                root->left = delete_value(root->left, value);
            } else if(value > root->data){
                root->right = delete_value(root->right, value);
            }else {
                if(root->left == nullptr && root->right == nullptr){
                    delete root;
                    root = nullptr;
                } else if(root->left == nullptr){
                    bst_node* temp = root;
                    root = root->right;
                    delete temp;
                } else if(root->right == nullptr){
                    bst_node* temp = root;
                    root = root->left;
                    delete temp;
                } else {
                    bst_node* temp = get_min_node(root->right);
                    root->data = temp->data;
                    root->right = delete_value(root->right, temp->data);
                }
            }
            return root;
        }

        bst_node* get_successsor(bst_node* root, int value)
        {
            if(root == nullptr){
                return root;
            }
            bst_node* target = root;
            while(target->data != value){
                if(value < target->data){
                    target = target->left;
                }else {
                    target = target->right;
                }
            }

            if(target->right != nullptr){
                return get_min_node(target->right);
            } else {
                return get_max_node(target->left);
            }
        }
};

int main() {
    // Create a binary search tree
    bst<int> myTree;

    // Insert values into the tree
    myTree.root = myTree.insert(50, myTree.root);
    myTree.root = myTree.insert(30, myTree.root);
    myTree.root = myTree.insert(70, myTree.root);
    myTree.root = myTree.insert(20, myTree.root);
    myTree.root = myTree.insert(40, myTree.root);
    myTree.root = myTree.insert(60, myTree.root);
    myTree.root = myTree.insert(80, myTree.root);

    // Print the tree using BFS and DFS (in-order)
    std::cout << "Breadth-First Traversal: ";
    myTree.print_bfs(myTree.root);
    std::cout << "\nIn-Order Traversal: ";
    myTree.print_dfs_in_order(myTree.root);

    // Test node count
    std::cout << "\nNode count: " << myTree.node_count << "\n";

    // Test binary search
    int valueToSearch = 40;
    if (myTree.binary_search(myTree.root, valueToSearch)) {
        std::cout << "Value " << valueToSearch << " found in the tree.\n";
    } else {
        std::cout << "Value " << valueToSearch << " not found in the tree.\n";
    }

    // Test get height
    int treeHeight = myTree.get_height(myTree.root);
    std::cout << "Tree height: " << treeHeight << "\n";

    // Test get min and get max
    bst<int>::bst_node* minNode = myTree.get_min_node(myTree.root);
    bst<int>::bst_node* maxNode = myTree.get_max_node(myTree.root);
    std::cout << "Minimum value: " << minNode->data << "\n";
    std::cout << "Maximum value: " << maxNode->data << "\n";

    // Test if it's a binary search tree
    if (myTree.is_binary_search_tree(myTree.root)) {
        std::cout << "The tree is a valid binary search tree.\n";
    } else {
        std::cout << "The tree is not a valid binary search tree.\n";
    }

    // Test delete value
    int valueToDelete = 30;
    myTree.root = myTree.delete_value(myTree.root, valueToDelete);
    std::cout << "Tree after deleting value " << valueToDelete << ":\n";
    myTree.print_bfs(myTree.root);

    // Test getting successor
    int successorValue = 50;
    bst<int>::bst_node* successorNode = myTree.get_successsor(myTree.root, successorValue);
    if (successorNode) {
        std::cout << "\nSuccessor of value " << successorValue << " is " << successorNode->data << "\n";
    } else {
        std::cout << "\nNo successor found for value " << successorValue << "\n";
    }

    // Delete the entire tree
    myTree.delete_tree(myTree.root);
    std::cout << "Tree deleted.\n";

    return 0;
}
