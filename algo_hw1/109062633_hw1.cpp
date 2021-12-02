#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int Select(vector<int> &N, int K, int G)
{
    if (N.size() <= G)
    {
        sort(N.begin(), N.end());
        return N[K - 1];
    }

    // collect all medians in every group
    vector<int> AllMedians;
    for (int i = 0; i < N.size(); i += G)
    {
        if (N.begin() + i + G <= N.end())
        {
            vector<int> medians(N.begin() + i, N.begin() + i + G);
            int MedianK = (G + 1) / 2;
            AllMedians.push_back(Select(medians, MedianK, G));
        }
    }

    // last group(may not have enough elements)
    if (N.size() % G != 0)
    {
        vector<int> medians(N.begin() + (N.size() / G) * G, N.end());
        int MedianK = (medians.size() + 1) / 2;
        AllMedians.push_back(Select(medians, MedianK, G));
    }

    // find median of medians
    int MedianK = (AllMedians.size() + 1) / 2;
    int MedianOfMedians = Select(AllMedians, MedianK, G);

    vector<int> Smaller;
    vector<int> Larger;
    int duplicate = 0;
    for (int j = 0; j < N.size(); j++)
    {
        if (N[j] < MedianOfMedians)
            Smaller.push_back(N[j]);
        else if (N[j] > MedianOfMedians)
            Larger.push_back(N[j]);
        else
            duplicate++;
    }

    if (K >= Smaller.size() + 1 && K <= Smaller.size() + duplicate)
        return MedianOfMedians;
    else if (K <= Smaller.size())
        return Select(Smaller, K, G);
    else
        return Select(Larger, K - Smaller.size() - duplicate, G);
}

int main()
{
    int N, K, G;
    cout << "input N: ";
    cin >> N;
    cout << "input K: ";
    cin >> K;
    cout << "input G: ";
    cin >> G;

    srand(123);
    int min = 1;
    int max = 10000000;
    vector<int> A;
    for (int i = 0; i < N; i++)
        A.push_back(rand() % (max - min + 1) + min);

    int answer = Select(A, K, G);
    cout << "answer: " << answer << "\n";
    return 0;
}