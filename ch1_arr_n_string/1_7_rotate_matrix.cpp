//<iomanip> setfill setw
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


void rotate_matrix(vector<vector<int>> & mt){

    for(int layer = 0; layer < mt.size()/2; layer++){
        int s_idx = layer;
        int e_idx = mt.size()-s_idx;
        for(int i = s_idx; i<e_idx-1; i++){

            //(y,x) tmp    = (0, 1) 
            //(0,1)        = (len-1,0)
            //(len-1,0)    = (len, len-1)
            //(len, len-1) = (1, len)
            //(1,len)      = (0, 1)
            int v1 = layer;
            int v2 = e_idx-1;
            int tmp = mt[v1][v1+i];
            mt[v1][v1+i] = mt[v2-i][v1];
            mt[v2-i][v1] = mt[v2][v2-i];
            mt[v2][v2-i] = mt[v1+i][v2];
            mt[v1+i][v2] = tmp;

        }
    }

}

int main(){
    vector<vector<int>> mt(5, vector<int>(5, 0));
    int k = 0;
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            mt[i][j] = k++;
            cout << setfill('0') << setw(2) << mt[i][j] << ",";
        }
        cout << "\n";
    }
    rotate_matrix(mt);
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cout << setfill('0') << setw(2) << mt[i][j] << ",";
        }
        cout << "\n";
    }
    return 0;
}
