#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    long long min = nums[0];
    long long max_income = nums[1] - nums[0];
    int min_index = 0;
    for (int i = 1; i < n; i++){
        max_income = max_income > nums[i] - min ? max_income : nums[i] - min;
        min = min < nums[i] ? min : nums[i];
    }
    cout << max_income << endl;
}