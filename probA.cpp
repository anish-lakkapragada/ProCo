#include <iostream>
#include <algorithm> 

using namespace std;

struct assignment {
    int a, p, t;
};

bool sort_assignments(assignment a1, assignment a2) {
    double x = (double) a1.p / (double) a1.t;
    double y = (double) a2.p / (double) a2.t;
    if (x == y) {
        return a1.a < a2.a;
    }
    else {
        return x > y;
    }
}

int main() {
    int N;
    cin >> N;
    
    assignment x[N];
    for (int i = 0; i < N; ++i) {
        cin >> x[i].a >> x[i].p >> x[i].t;
    }

    sort(x, x + N, sort_assignments);
    for (int i = 0; i < N; ++i) {
        cout << x[i].a << endl;
    }
}