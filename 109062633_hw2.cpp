#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int TSP()
{

}

int main () 
{
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
    return 0;
}