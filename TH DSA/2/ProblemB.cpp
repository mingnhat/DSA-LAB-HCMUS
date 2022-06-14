#include <iostream>
using namespace std;

int findGCD1(int u, int v, int& countCompare) {
    if (++countCompare && u == 0)
        return v;
    if (++countCompare && v == 0)
        return u;
    if (++countCompare && u == v)
        return u;
    if (++countCompare && u > v)
        return findGCD1(u - v, v, countCompare);
    return findGCD1(u, v - u, countCompare);
}

int findGCD2(int u, int v, int& countCompare) {
    if (++countCompare && v == 0)
        return u;
    return findGCD2(v, u % v, countCompare);
}
int main() {
    cout << "Problem B:" << endl;
    int u, v;
    cout << "U = "; cin >> u;
    cout << "V = "; cin >> v;
    int countCompare = 0;
    cout << "Greatest common divisor of " << u << " and " << v << " is: " << findGCD1(u, v, countCompare) << endl;
    cout << "Number of comparisions: " << countCompare << endl << endl;

    countCompare = 0;
    cout << "Greatest common divisor of " << u << " and " << v << " is: " << findGCD2(u, v, countCompare) << endl;
    cout << "Number of comparisions: " << countCompare << endl << endl;
    return 0;
}