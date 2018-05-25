#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

void zero_mt(vector<vector<int>> &mt){
    bool row0zero = false;
    bool col0zero = false;
    int rowsz = 0, colsz = 0;

    rowsz = mt.size();
    if(rowsz <1) return;

    colsz = mt[0].size();
   
    for(int i=0; i<colsz; i++){
        if(mt[0][i] == 0) row0zero=true;
    }
    for(int i=0; i<rowsz; i++){
        if(mt[i][0] == 0) col0zero=true;
    }

    for(int i=0; i<rowsz; i++){
        for(int j=0; j<colsz; j++){
            if(mt[i][j] == 0){
                mt[0][j] = 0;
                mt[i][0] = 0;
            }
        }
    }
    for(int i=1; i<rowsz; i++){
        if(mt[i][0] == 0){
            for(int j = 1; j<colsz; j++) mt[i][j] = 0;
        }
    }

    for(int i=1; i<colsz; i++){
        if(mt[0][i] == 0){
            for(int j = 1; j<rowsz; j++) mt[j][i] = 0;
        }
    }
    if(row0zero){
        for(int i=0; i<rowsz; i++){
            mt[i][0] = 0; 
        }
    }
    if(col0zero){
        for(int i=0; i<colsz; i++){
            mt[0][i] = 0;
        }
    }
}

int main(){
    vector<vector<int>> mt = {
        {1,2,3,4,5},
        {2,2,3,4,5},
        {1,2,0,4,5},
        {2,2,3,4,5},
    };
    vector<vector<int>> mt1 = {
        {1,2,0,4,5},
        {0,2,3,4,5},
        {1,2,0,4,5},
        {2,2,3,4,5},
    };
    
    zero_mt(mt);
    for(int i = 0; i<4; i++){
        for(int j = 0; j<5; j++){
            cout << setfill('0') << setw(2)<< mt[i][j] << ",";
        }
        cout << "\n";
    }
    cout << "\n";
    zero_mt(mt1);
    for(int i = 0; i<4; i++){
        for(int j = 0; j<5; j++){
            cout << setfill('0') << setw(2)<< mt1[i][j] << ",";
        }
        cout << "\n";
    }
}
