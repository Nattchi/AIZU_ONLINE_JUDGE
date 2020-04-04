#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for (int i = 0; i < n - 1; i++) {
      cout << nums[i] << " ";
    }
    cout << nums[n - 1] << endl;
    int v, j;
    for (int i = 1; i < n; i++){
        v = nums[i];
        j = i - 1;
        while(j >= 0 && nums[j] > v){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = v;
        for (int i = 0; i < n - 1; i++){
            cout << nums[i] << " ";
        }
        cout << nums[n - 1] << endl;
    }
}