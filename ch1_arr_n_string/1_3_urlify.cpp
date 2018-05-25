//stk.push(string(1, _str[i]));
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string urlify_stack(string _str, int len){
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

string urlify(string _str, int len)
{
    int space_cnt = 0;
    int res_idx = 0;

    for(int i = 0; i<len; i++) if(_str[i] == ' ') space_cnt++;
    res_idx = len+space_cnt*2;

    for(int i = len-1; i>=0; i--){
        if(_str[i] == ' '){
            _str[--res_idx] = '0';
            _str[--res_idx] = '2';
            _str[--res_idx] = '%';
        }else{
            _str[--res_idx] = _str[i];
        }
    }
    return _str;
}

int main(){
    cout << urlify("Mr John Smith     ", 13);
}

