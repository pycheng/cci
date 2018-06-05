#include <iostream>
using namespace std;


string b2s(double n){
    string res;
    double v = n;

    //base case check 
    if(n<=0 || n>=1) return "ERROR";
    res+=".";
    while(n > 0){
        if(res.size() > 32) return "ERROR";
        double r = n*2;
        if(r>=1){
            res+="1";
            n = r-1;
        }else{
            res+="0";
            n = r;
        }
    }

    return res;
}

int main(){
    double r = 1.0/8;
    cout << b2s(r);

}
