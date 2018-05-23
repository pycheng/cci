//stk.push(string(1, _str[i]));
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string urlify(string _str, int len){
    string res="";
    stack<string> stk;
    int first_char = 0;
    for(int i=_str.size()-1; i>=0; i--){
        if(_str[i] == ' ' && first_char!=0){
            //replace ' ' with %20
            stk.push("%20");
        }else if(_str[i]!=' '){
            first_char ++;
            stk.push(string(1, _str[i]));
        }
    }
    while(!stk.empty()){
        res+=stk.top();
        stk.pop();
    }
    return res;
}

int main(){
    cout << urlify("Mr John Smith     ", 13);
}

