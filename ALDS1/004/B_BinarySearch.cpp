#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(int n, vector<int> S, int key){
    int left = 0;
    int right = n;
    while(left < right){
        int mid = (left + right) / 2;
        if(S[mid] == key){
            return true;
            //return mid;
        }else if(key < S[mid]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return false;
}

int main(){
    int n, q;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++){
        cin >> S[i];
    }
    cin >> q;
    vector<int> T(q);
    int count = 0;
    for (int i = 0; i < q; i++){
        cin >> T[i];
        if(binarySearch(n, S, T[i])) count++;
    }
    cout << count << endl;
}