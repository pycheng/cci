#include <iostream>
#include <bitset>
using namespace std;

//get next small num
//10115
//10096
int next_small_num(int v)
{
    //next small num
    //1. locate most right non-trailing 1
    // p  = pos
    // c1 = num of one in v[0..p]
    //0b1011011 --> bit 3 --> p=3, c1=2 
    unsigned v1 = v;
    int c1 = 0, p = 0;
    bool trailing_one = (v1&1);

    cout << bitset<32>(v1) << "," << trailing_one << "\n";
    while(((v1&1)==0)||(trailing_one == true)){
        if(v1&1){
            c1++;
        }else{
            trailing_one = false;
        }
        p++;
        v1 = v1>>1;
    }
    cout << p << "," << c1 << "\n";

    //2. flip v[p] and set v[0..p-1] to 0
    unsigned int mask = (1<<(p+1))-1;
    v1 = v;
    v1 = v1&~mask;

    cout << bitset<32>(v1) << "\n";
    //3. set v[p-1-c1..p-1] as 1
    mask = (1<<(c1+1))-1;
    mask = mask << (p-1-c1);
    v1 = v1|mask;
    cout << bitset<32>(v1) << "\n";
    return v1;
}

//get next big num
//13948    = 0b11011001111100
//13967    = 0b11011010001111
int next_big_num(int v)
{
    //find the location of 1st non-trailing zero
    //ex. 1100110 --> p = 4, c1 = 2;
    unsigned int v1 = v;
    int c1 = 0, p = 0;
    bool trailing_zero = ((v1&1)==0);

    while((trailing_zero == true) || ((v1&1)==1))
    {
        if((v1&1)==1){
            trailing_zero = false;
            c1++;
        }
        p++;
        v1 = v1>>1;
    }
    //flip v[p] and set v[0..p-1]=0
    unsigned int mask = (1<<p);
    v1 = v;
    v1 = v1|mask;
    v1 = v1&~(mask-1);
    
    //set v[0..c1-2]=1
    mask = 1<<(c1-1);
    v1 = v1 | (mask-1);

    return v1;
}


int main(){
    cout << next_small_num(10115)<<"\n";
    cout << next_big_num(13948) << "\n";
}

