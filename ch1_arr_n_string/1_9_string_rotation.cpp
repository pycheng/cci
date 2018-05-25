#include <iostream>
using namespace std;


bool str_rot(string a, string b){
    string tmp = b+b;
    return (tmp.find(a) != string::npos);
}

int main(){
    cout << str_rot("waterbottle", "terbottlewa") <<"\n";
    cout << str_rot("waaterbottle", "terbottlewa") <<"\n";
    return 0;
}
