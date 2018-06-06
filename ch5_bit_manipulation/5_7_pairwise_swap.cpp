#include <iostream>
#include <iomanip>
using namespace std;

int pair_swap(int v)
{
    unsigned int uv = v;
    unsigned int even, odd;
    
    even = uv&0xaaaaaaaa;
    odd  = uv&0x55555555;
    
    return (even >> 1)|(odd << 1);
}


int main(){
    
    cout << hex << pair_swap(0xaaaaaaaa) << "\n";
    cout << hex << pair_swap(0x55555555) << "\n";

    return 0;
}
