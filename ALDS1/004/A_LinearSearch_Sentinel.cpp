#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(vector<long long> A, int n, long long key){
    int i = 0;
    A[n] = key;//番兵
    while(A[i] != key){
        i++;
    }
    return i != n;
}

int main(){
    int n, q;
    cin >> n;
    vector<long long> S(n + 1);
    for (int i = 0; i < n; i++){
        cin >> S[i];
    }
    cin >> q;
    int matched = 0;
    vector<long long> T(q);
    for (int i = 0; i < q; i++){
        cin >> T[i];
        if (linearSearch(S, n, T[i])) matched++;
    }
    cout << matched << endl;
}