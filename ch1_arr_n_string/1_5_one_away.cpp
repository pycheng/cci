#include <iostream>
using namespace std;


bool onediff(string a, string b){
    bool diff = false;
    for(int i = 0; i<a.size(); i++){
        if(a[i]!=b[i]){
            if(diff == false){ 
                diff = true;
            }else{
                return false;
            }
        }
    }
    return true;
}

bool oneex(string l, string s)
{
    bool diff = false;
    for(int i= 0, j=0; i<s.size(); i++, j++){
        if(s[i] != l[j]){
            if( (j-i) > 1) return false;
            i--;
        }
    }
    return true;
}

bool oneaway(string a, string b){
    int lendiff = a.size()-b.size();
    //onediff or oneex
    if(lendiff == 0){
        return onediff(a, b);
    }else if(abs(lendiff)==1){
        return (a.size()>b.size())?oneex(a, b):oneex(b, a);
    }
    
    return false;
}

int main(){
    cout << oneaway("pale", "ple") << "\n";
    cout << oneaway("pales", "pale") << "\n";
    cout << oneaway("pale", "bale") << "\n";
    cout << oneaway("pale", "bae") << "\n";
    return 0;
}
