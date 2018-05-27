//case: null, odd, even
//notice odd handle
#include <iostream>
#include <stack>
using namespace std;


bool palindrome_string(string s){
    stack<char> sc;
    int si=0, fi=0;

    if(s.size() == 0)  return false;
    //push the first half string stack <char>
    for(;fi<s.size();si++, fi+=2){
        sc.push(s[si]);
    }

    //adjust si for s.size()
    if(1==s.size()%2){ 
        sc.pop();
    }

    //compare stack.pop with rest of the string
    for(;si<s.size();si++){
        if(s[si]!=sc.top()) return false;
        sc.pop();
    }

    return true;
}

int main(){
    
    cout << palindrome("") << "\n";
    cout << palindrome("a") << "\n";
    cout << palindrome("aba") << "\n";
    cout << palindrome("abc") << "\n";
    cout << palindrome("abba") << "\n";
    cout << palindrome("abbc") << "\n";
    return 0;
}
