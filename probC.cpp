#include <iostream>
#include <vector> 
#include <climits> 
#include <algorithm> 
using namespace std;

int main() {
    int N, p; cin >> N; 
    cin >> p; 
    vector<pair<int, int>> people(N); // when they sleep, index number 
    int stime; 
    for (int i =0; i < N; i++) {
        cin >> stime; 
        people[i] = make_pair(stime, i + 1); 
    }

    // sort the pairs in ascending order based on the first     index
    sort(people.begin(), people.end()); 
    
    bool works = true; 
    // check whether or not it works
    int curTime = 0; 
    for (pair<int, int> person: people) {
        curTime += p; // move here 
        stime = person.first; 
        if (curTime > stime) {
            works = false; 
        }
    }

    if (!works) {
        cout << "FAILED!" << endl;
        return 0; 
    }

    cout << "SUCCESSFUL!" << endl;
    for (pair<int, int> person: people){
        cout << person.second << endl;
    }
    
}
