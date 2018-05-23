#include <iostream>
using namespace std;

void to_lower(wstring &s){
    for(int i=0; i<s.size(); i++){
        if(s[i]>='A' && s[i]<='Z')
            s[i]-=('Z'-'z');
    }
}
    
bool pp(wstring s){
    int hash[256]={0};
    int cnt_one = 0;
    to_lower(s);
    for(auto i:s){
        if(i!=' ') hash[i]++;
    }
    for(auto i:hash){
        if(i%2 == 1) cnt_one++;
    }
    return (cnt_one<=1)?true:false;
}

int main(){
    cout<<pp(L"Tact coa")<<"\n";
    cout<<pp(L"Tact, coa")<<"\n";
    return 1;
}
