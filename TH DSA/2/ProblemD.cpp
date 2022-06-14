#include <iostream>
#include <string>
using namespace std;

//Problem D
void seeSawProblem(int left, int right, int* w, int n) {
    int c = left - right;
    int countCompare = 0;
    for (int i = 0; ++countCompare && i < n; i++) {
        for (int j = 0; ++countCompare && j < n; j++) {
            if (++countCompare && w[i] - w[j] == c) {
                cout << "(" << i << ", " << j << "); ";
            }
        }
    }
    cout << "\nNumber of comparisions: " << countCompare << endl;
}

int main() {
    cout << "Problem D:" << endl;
    int left, right;
    cout << "Input left: "; cin >> left;
    cout << "Input right: "; cin >> right;

    int* w, n = 5;
    w = new int[n];
    cout << "Input list of hat weights W: ";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    seeSawProblem(left, right, w, n);
}
