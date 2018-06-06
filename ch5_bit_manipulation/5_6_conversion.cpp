#include <iostream>
#include <assert.h>
using namespace std;


int count_one_v1(unsigned int v)
{
    int cnt = 0;

    while(v>0){
        cnt += 1;
        v = v&(v-1);
    }

    return cnt;
}

int count_one(unsigned int v)
{
    int cnt = 0;
    int v1 = v;

    while(v>0){
        cnt += (v&1);
        v = v >> 1;
    }

    assert(cnt == count_one_v1(v1));
    //there's another way using hash (or lut)
    //cnt = hash[v1 && 0xff]       + hash[(v1>>8)  && 0xff] 
    //    + hash[(v1>>16) && 0xff] + hash[(v1>>24) && 0xff]
    return cnt;
}

int convert(int a, int b){
    unsigned int ua, ub, v;
    ua = a; ub = b;

    // a xor b to obtain the bit that is different in a and b
    v = ua^ub;

    return count_one(v);
}

int main(){
    cout << convert(29, 15) << "\n";
}
