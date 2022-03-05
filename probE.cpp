#include <iostream>
#include <vector> 

using namespace std;

int destX, destY, p; 
int num_ways = 0; 
int potholesGrid[55][55];

bool is_valid(int i, int j) {
    return (i <= destX && j <= destY);
}

void recurse(int i, int j) {
    if (potholesGrid[i][j] == 1) {
        return; 
    }
    if (i == destX && j == destY){
        num_ways++; return; 
    }

    if (is_valid(i + 1, j) && potholesGrid[i + 1][j] != 1) {
        recurse(i + 1, j);
    }

    if (is_valid(i, j + 1) && potholesGrid[i][j + 1] != 1) {
        recurse(i, j + 1);
    }    
}

int main() {
    cin >> destX >> destY >> p; 

    int px, py; 
    for (int i = 0; i < p; i++) {
        cin >> px >> py; 
        potholesGrid[px][py] = 1; 
    }

    //cout << "recurse start" << endl;
    recurse(0, 0); 
    cout << num_ways << endl;
}