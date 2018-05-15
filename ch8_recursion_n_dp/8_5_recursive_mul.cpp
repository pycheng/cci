#include <iostream>
#include <cmath>
using namespace std;

//O(n)
int rec_mul_on(int a, int b)
{
    int res = 0;
    if (a==0||b==0)return 0;
    res = rec_mul_on(abs(a)-1,abs(b))+abs(b);
    if((a<0&&b>0)||(a>0&&b<0))
        res = -res;
    return res;
}

//O(log(small.size()));
int mul_inner(int a, int b)
{
    int div2;
    if(a==0) return 0;

    div2 = mul_inner((a>>1), b);

    return (a%2==1)?
                div2+div2+b:
                div2+div2;
        
}
int rec_mul(int a, int b)
{
    bool neg;
    int res;

    neg = ((a>0&&b<0)||(a<0&&b>0))?true:false;
    a = abs(a); b = abs(b);

    res = a<b?mul_inner(a,b):mul_inner(b,a);
    return neg?-res:res;
}

int main(){
    cout << rec_mul(2,5) << "\n";
    cout << rec_mul(-9,5) << "\n";

    return 0;
}
