#include <iostream>
#include <vector> 
#include <algorithm> 
#include <climits> 
using namespace std; 

struct assignment {
    int point, time, deadline, id; 
    bool done; 
};

int main() {
    int N, T; cin >> N >> T; 
    vector<assignment> assignments(N);
    vector<int> deadlines(N);
    
    for (int i = 0; i < N; i++) {
        cin >> assignments[i].id >> assignments[i].point >> assignments[i].time >> assignments[i].deadline; 
        assignments[i].done = false;
        deadlines[i] = assignments[i].deadline; 
    }

    int curTime = 0; // start from the current deadline 
    long long max_points =0; 
    int lastDeadline = 0; 

    while (curTime < T) {
        int points = INT_MIN; 
        int selectedId = -1; 
        for (assignment task : assignments) {
            if (task.done == false && (curTime + task.time) <= task.deadline) {
                if (task.point > points) {
                    points = task.point; 
                    selectedId = task.id; 
                }
            }
        }

        if (selectedId < 0) {break;}
        assignments[selectedId - 1].done = true; 
        curTime += assignments[selectedId - 1].time; 
        max_points += points;
    }

    cout << max_points << endl;

    
}