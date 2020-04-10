#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack{
private:
    vector<string> s;
public:
    Stack(vector<string> str){
        s = str;
    }

    void push(string x){
        s.push_back(x);
    }

    string pop(){
        string back = s.back();
        s.pop_back();
        return back;
    }

    bool isEmpty(){
        return s.empty();
    }
};

int main(){
    vector<string> str(200);
    Stack stack = Stack(str);
    string s;
    long long a, b;

    while(cin >> s){//入力の終わりまで処理
        if(s == "+"){
            b = stoll(stack.pop());
            a = stoll(stack.pop());
            stack.push(to_string(a + b));
        }else if(s == "-"){
            b = stoll(stack.pop());
            a = stoll(stack.pop());
            stack.push(to_string(a - b));
        }else if(s == "*"){
            b = stoll(stack.pop());
            a = stoll(stack.pop());
            stack.push(to_string(a * b));
        }else{
            stack.push(s);
        }
    }
    cout << stack.pop() << endl; 
}