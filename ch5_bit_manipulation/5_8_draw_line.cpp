#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
#if 0
(5,0)(10,0)
00001111
11000000
#endif
void drawline(vector<char> &screen, int width, int x1, int x2, int y)
{
    //row index = y*width/8
    int s_idx = x1/8;
    int s_off = x1%8;
    int e_idx = x2/8;
    int e_off = x2%8;

    // fill the s_idx+1 to end_idx-1 with 0xff
    for(int i=s_idx+1; i<e_idx; i++){
        screen[i+y*width/8] = (char) 0xff;
    }

    screen[s_idx+y*width/8] = ((1<<(s_off-1)) -1) & 0xff;
    screen[e_idx+y*width/8] = (((1<<e_off)-1) << (8-e_off)) & 0xff;
    //cout << bitset<8>((int)(screen[e_idx+y*width/8]))<< "\n\n";

    return;
}

void dump(vector<char> s)
{
    for(int i=0; i<s.size(); i++){
        cout << bitset<8>((int)s[i]);
        if(i%4 == 3) cout<<"\n";
    }
}

int main(){
    vector<char> s(32, 0);
    drawline(s, 32, 5, 10, 3);
    dump(s);
}

