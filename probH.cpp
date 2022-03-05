#include <iostream>
#include <algorithm> 
#include <climits> 
#include <vector> 
typedef long long ll; 

using namespace std; 

int main() {
    int N; cin >> N;  
    vector<ll> stacks(N); 
    ll sum = 0; 
    for (int i=0; i < N; i++) {
        cin >> stacks[i]; 
        sum += stacks[i]; 
    }

    ll required = (sum) / N; 
    ll numMovements =0 ; 
    for (int i =0; i < N; i++) {
        if (stacks[i] < required) {
            numMovements += abs(stacks[i] - required);
        }
    }

    cout << numMovements << endl;
    
}