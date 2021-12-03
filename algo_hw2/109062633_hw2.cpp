#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
    vector<int> visited;
    int bound;
};

int bound(int edges, vector<int> visited){
    
    int size = visited.size();
    int fixed_cost = 0;
    if (size> 1){
        int j;
        for(int i=0; i < size - 2 + 1; i++){
            j = i + 1;
            fixed_cost += edges[i][j];
        }
    }

    return fixed_cost;
}

int TSP(int *edges){

    return 0;
}

int main(){
    vector<string> numbers;

    ifstream ifs("tsp_input.txt", std::ios::in);
    if (!ifs.is_open()) {
        cout << "Failed to open file.\n";
    } else {
        string s;
        while (ifs >> s)
            numbers.push_back(s);
        ifs.close();
    }

    int num_rows = stoi(numbers[0]);
    int edges[num_rows+1][num_rows+1];

    int idx = 1;
    for (int i = 1; i <= num_rows; i++) {
        for (int j = 1; j <= num_rows; j++) {
            edges[i][j] = stoi(numbers[idx]);
            idx += 1;
        }
    }

    int answer = TSP(*edges);

    return 0;
}