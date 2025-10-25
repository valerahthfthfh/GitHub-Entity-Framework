#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int graph;  
    vector<vector<int>> list;

    void output(int number, vector<bool>& visited) {  
        visited[number] = true;
        cout << number << " ";

        for (int i = 0; i < list[number].size(); i++) {  
            int v = list[number][i];  
            if (!visited[v]) {
                output(v, visited);
            }
        }
    }

public:
    Graph(int v) {
        this->graph = v;
        this->list.resize(v);  // инициализация вектора
    }

    void add(int w, int v) {
        list[w].push_back(v);
        list[v].push_back(w);
    }

    void dfs(int start) {  
        vector<bool> visited(graph, false);
        output(start, visited);
        cout << endl;
    }
};

int main()
{
    Graph W(5);

    W.add(0, 1);
    W.add(0, 2);
    W.add(1, 3);
    W.add(1, 4);
    W.add(2, 4);
    
    W.dfs(0);
}   