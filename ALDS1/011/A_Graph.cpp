﻿#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, u, k, e;
    cin >> n;

    vector<vector<int> > V(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> e;
            V[u - 1][e - 1] = u;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n-1) {
                cout << V[i][j] << endl;
                continue;
            }
            cout << V[i][j] << " ";
        }
    }
}