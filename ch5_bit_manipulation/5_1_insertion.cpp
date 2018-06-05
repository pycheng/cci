#include <iostream>
#include <math.h>
#include <algorithm>
#include <bitset>
using namespace std;

int insertion(int n, int m, int i, int j){
    int low_bit = (i<j)?i:j;
    int len = abs(j-i+1);

    //clear n[j..i] and then | m << low_bit
    int mask = (1<<len-1) << low_bit;
    
    return (n&~mask)|(m<<low_bit);
}


int main(){
    int n = 1<<10;
    int m = 16+3;
    cout << bitset<32>(n) << "\n" << bitset<32>(m) << "\n";
    cout << bitset<32>(insertion(n, m, 2, 6));

}
