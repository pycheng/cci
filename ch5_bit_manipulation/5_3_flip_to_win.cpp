#include <iostream>
using namespace std;

//return the length of longest 1 with 1 flip
int flip_to_win(int i)
{
    unsigned int v = i;
    int cur_len = 0;
    int pre_len = 0;
    int res = 0;

    //11110110111001111
    //for(int i=0; i<=sizeof(int)*8; i++)
    while(v>0)
    {
        if(v&1){
            cur_len++;
        }else{
            res = max(cur_len+pre_len+1, res);
            pre_len = cur_len;
            cur_len = 0;
        }
        v = v >> 1;
    }
    return res;
}

int main(){
    cout << flip_to_win(0b11101110111001111);//7
    cout << flip_to_win(0b1110111011101111); //8
}
