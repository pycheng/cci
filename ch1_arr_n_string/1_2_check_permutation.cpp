#include <iostream>
using namespace std;

bool ispermut(string a, string b){
    int hash[256]={0};
    for(auto i: a) hash[i]++;
    for(auto i: b) hash[i]--;
    for(auto i:hash){
        if(i>0) return false;
    }
    return true;
}

int main(){
    string t10 = "abcdefg";
    string t11 = "acbdefg";
    string t20 = "zbcdefg";
    string t21 = "acbdefg";
    cout<< ispermut(t10,t11) << "\n";
    cout<< ispermut(t20,t21) << "\n";
    return 0;
}
