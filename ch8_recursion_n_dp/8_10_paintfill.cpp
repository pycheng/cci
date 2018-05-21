#include <vector>
#include <iostream>
using namespace std;
enum color{
    green = 0,
    pruple,
    red,
    blue,
    black
};


void painfill(color co, vector<vector<int>> &grid, int r, int c)
{
//    cout << r << "," << c << "\n";
    if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size()) return;

    if(grid[r][c]!=co){
        grid[r][c] = co;
#if 1    
        for(auto i:grid)
        {
            string sep = "";
            for(auto j:i){
                cout<<sep << j;
                sep = ",";
            }
            cout << "\n";
        }
        cout << "\n";
#endif
        painfill(co, grid, r-1, c);
        painfill(co, grid, r+1, c);
        painfill(co, grid, r  , c-1);
        painfill(co, grid, r  , c+1);
    }
}

int main(){
    vector<vector<int>> grid(5,vector<int>(5,0));
    cout << grid.size();
    painfill(black, grid, 4, 4);
}

