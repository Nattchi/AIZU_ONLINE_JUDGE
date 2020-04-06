#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, q;
    cin >> n;
    vector<long long> S(n);
    for (int i = 0; i < n; i++){
        cin >> S[i];
    }
    cin >> q;
    vector<long long> T(q);
    for (int i = 0; i < q; i++){
        cin >> T[i];
    }
    int matched = 0;
    for (int i = 0; i < q; i++){
        for (int j = 0; j < n; j++){
            if(S[j] == T[i]){
                matched++;
                break;
            }
        }
    }
    cout << matched << endl;
}