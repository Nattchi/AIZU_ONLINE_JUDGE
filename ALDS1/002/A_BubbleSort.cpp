#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
int main(){
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    bool flag = true;
    int count = 0;
    while(flag){
        flag = false;
        for (int j = n - 1; j >= 1; j--){
            if(A[j] < A[j - 1]){
                swap(A[j], A[j - 1]);
                count++;
                flag = true;
            }
        }
    }
    for (int i = 0; i < n - 1; i++){
        cout << A[i] << " ";
    }
    cout << A[n - 1] << endl;
    cout << count << endl;
}