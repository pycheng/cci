#include <iostream>
using namespace std;

bool isunique(string s)
{
    int hash[256] = {0};
    for(auto i: s){
        if(hash[i]!=0) return false;
        else hash[i]++;
    }
    return true;
}

int main(){
    string t1 = "abcdefgh";
    string t2 = "aabckdwihf";

    cout << isunique(t1) << "\n";
    cout << isunique(t2) << "\n";

    return 1;
}
