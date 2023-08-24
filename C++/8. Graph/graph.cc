#include <iostream>
#include <vector>
#include <queue>

// Ajacency list representation of a simple, unweighted and undirected graph
//For simplicity I am using 1,2,3,...,8 as my vertices
class graph
{
    public:
        struct edge
        {
            int vertex;
            struct edge* next;
        };

        struct edge** arr;

        graph()
        {
            arr = new edge*[8];
            for(int i = 0; i < 8; i++){
                arr[i] = nullptr;
            }
        }

        ~graph()
        {
            for(int i = 0; i < 8; i++){
                edge* temp = arr[i];
                while(temp != nullptr){
                    edge* head_node = temp;
                    temp = head_node->next;
                    delete head_node;
                }
            }
            delete[] arr;
        }

        void insert_edge(int from, int to)
        {
            //v1 & v2 <= 8
            edge* new_edge = new edge;
            new_edge->vertex = to;
            new_edge->next = arr[from -1];
            arr[from -1] = new_edge;

            new_edge = new edge;
            new_edge->vertex = from;
            new_edge->next = arr[to -1];
            arr[to -1] = new_edge;
        }
        
        bool have_visited(edge* node, std::vector<edge*> visited_arr)
        {
            for(int i = 0; i< visited_arr.size(); i++){
                if(visited_arr[i] == node){
                    return true;
                }
            }
            return false;
        }

        void print()
        {   
            for(int i = 0; i<8; i++){
                std::cout << "| " << i + 1 << " | " << "-> " ;
                edge* temp = arr[i];
                while(temp != nullptr){
                    std::cout << temp->vertex << ", ";
                    temp = temp->next;
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
};

int main()
{
    graph g;
    g.insert_edge(1,5);
    g.insert_edge(1,3);
    g.insert_edge(2,6);
    g.insert_edge(4,6);
    g.insert_edge(7,5);
    g.insert_edge(8,4);
    g.print();
}