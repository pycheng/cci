#include <iostream>
#include <string>
using namespace std;


string strcprs(string s){
    int cur = 0;
    int cnt = 0;
    string res;
    
    if(s.size()==0) return s;
    res += s[0];

    for(int i=0; i<s.size(); i++){
        if(s[i]==s[cur]){
            cnt++;
        }else{
            res += to_string(cnt);
            res += s[i];
            cnt = 1; cur = i;
        }
    }

    res += to_string(cnt);

    return res;
}


int main(){
    cout << strcprs("aabcccccaaa") << "\n";
    cout << strcprs("abcde") << "\n";
    cout << strcprs("a") << "\n";
    cout << strcprs("") << "\n";
    return 0;
}
