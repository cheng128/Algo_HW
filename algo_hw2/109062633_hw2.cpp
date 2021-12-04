#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

class Node{
    public:
        int level;
        vector<int> path;
        int bound;
};

struct cmp{
    bool operator()(Node a, Node b) {
        return a.bound > b.bound;
    }
};

vector<vector<int>> parse(string file){
    string s;
    int dim;
    vector<string> numbers;
    ifstream ifs(file, std::ios::in);
    if (!ifs.is_open()) {
        cout << "Failed to open file.\n";
    }else {
        while (ifs >> s)
            numbers.push_back(s);
        ifs.close();
    }
    dim = stoi(numbers[0]);
    vector<vector<int>> edges(dim+1, vector<int>(dim+1, 0));
    for(int i = 1; i <= dim; i++){
        for(int j = 1; j <= dim; j++){
            edges[i][j] = stoi(numbers[1 + (i-1) * dim + (j-1)]);
        }
    }
    return edges;
}

void print(vector<vector<int>>& mat){
    int dim = mat.size();
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int find_min(int key, vector<int> W){
    int min_weight = *max_element(W.begin(), W.end());
    for(int i=1; i<W.size();i++){
        if(i != key)
            min_weight = min(min_weight, W[i]);
    }
    return min_weight;
}

int bound(int n, const vector<vector<int>> &edges, vector<int> visited){
    
    int size = visited.size();
    int fixed_cost = 0;
    int lower_bound = 0;

    if (size > 1){
        int j;
        for(int i=0; i < size - 2 + 1; i++){
            j = i + 1;
            fixed_cost += edges[i][j];
        }
    }
    //TODO find min weight in each row to calculate lower bound

    return fixed_cost + lower_bound;
}

int TSP(int n, const vector<vector<int>>& W, vector<int>& opttour, int& length){
    priority_queue<Node, vector<Node>, cmp> node_pq;
    Node u, v;
    v.level = 1;
    v.path = {1};

    double minlength = numeric_limits<double>::infinity();
    node_pq.push(v);


    return 0;
}

int main () 
{
    vector<vector<int>> edges = parse("tsp_input.txt");
    cout << find_min(1, edges[1]) << endl;
    // int answer = TSP(*edges);

    return 0;
}
