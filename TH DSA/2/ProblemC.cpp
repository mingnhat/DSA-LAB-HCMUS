#include <iostream>
using namespace std;

void worldCloudProblem1(char** W, int n) {
    int countCompare = 0;
    int* ch = new int[n];
    int* countArr = new int[n];
    bool in = false;
    int cur = 0;
    for (int i = 0; ++countCompare && i < n; i++) {
        bool in = false;
        for (int j = 0; ++countCompare && j < cur; j++) {
            if (++countCompare && strcmp(W[i], W[ch[j]]) == 0) {
                countArr[j] += 1;
                in = true;
                break;
            }
        }
        if (++countCompare && !in) {
            ch[cur] = i;
            countArr[cur] = 1;
            cur += 1;
        }
    }
    for (int i = 0; i < cur; i++) {
        cout << W[ch[i]] << ": " << countArr[i] << endl;
    }
    cout << "Number of comparisions: " << countCompare << endl;
}
void worldCloudProblem2(char** W, int n) {
    int count;
    int countCompare = 0;
    bool* checked = new bool[n] {0};
    for (int i = 0; ++countCompare && i < n; i++) {
        if (checked[i] == 1) continue;
        count = 1;
        for (int j = i + 1; ++countCompare && j < n; j++)
        {
            if (strcmp(W[i], W[j]) == 0) {
                checked[j] = 1;
                count += 1;
            }
        }
        cout << W[i] << ": " << count << '\n';
    }
    cout << "Number of comparisions: " << countCompare << endl;
}

int main() {
    cout << "Problem C:" << endl;
    int n;
    cout << "Input length of list W: ";
    cin >> n;

    char** W = new char* [n];
    string temp;
    cout << "Input list W: ";
    for (int i = 0; i < n; i++) {
        cin >> temp;
        W[i] = new char[temp.length() + 1];

        for (int j = 0; j < temp.length() + 1; j++) {
            W[i][j] = temp[j];
        }
    }
    cout << "\nMethod 1: " << endl;
    worldCloudProblem1(W, n);

    cout << "\nMethod 2: " << endl;
    worldCloudProblem2(W, n);

}