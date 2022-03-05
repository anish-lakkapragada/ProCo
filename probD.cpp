#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std; 

int main() {
    int N; cin >> N;
    int maxH; cin >> maxH; 
    vector<pair<int, int>> trees(N);
    for (int i =0; i <N ;i++) {
        cin >> trees[i].first >> trees[i].second; 
    }

    int max_distance = -1; 
    for (int i =0; i < N - 1; i++) {
        int x1 = trees[i].first; 
        int h1 = trees[i].second; 
        int x2 = trees[i + 1].first; 
        int h2 = trees[i + 1].second; 

        int distance = x2 - x1; 
        if (h1 > maxH && h2 > maxH) {
            distance -= 2; 
        }

        else if (h1 > maxH) {distance -= 1;}
        else if (h2 > maxH) {distance -= 1;}

        max_distance = max(max_distance, distance);
    }

    cout << max_distance << endl;
}