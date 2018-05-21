#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct box{
    int height;
    int width;
    int depth;
};

bool sort_by_height(struct box b1, struct box b2){
    return b1.height > b2.height;
}

int sof_rec_hash(int idx, vector<struct box> b, vector<int> &height_map){
    int max_height = 0;
    
    if(height_map[idx]!=0) return height_map[idx];

    for(int i=idx; i<b.size(); i++){
        if(b[i].width < b[idx].width &&
           b[i].depth < b[idx].depth){
            max_height = max(max_height, sof_rec_hash(i, b, height_map));
        }

        for(auto i: height_map) cout << i << ","; cout << "\n";
    }

    height_map[idx] = max_height + b[idx].height;
    max_height = height_map[idx];
    return max_height;

}

int sof_rec(int idx, vector<struct box> b, vector<int> &height_map){
    int max_height=0;

    for(int i = idx; i< b.size(); i++){
        if(b[i].width < b[idx].width &&
           b[i].depth < b[idx].depth){
            max_height = max(max_height, sof_rec(i, b, height_map));
        }
    }
    max_height+=b[idx].height;
    return max_height;
}


int stackofbox(vector<struct box>& b){
    int max_height = 0;
    vector<int> height_map(b.size(),0);
    
    sort(b.begin(), b.end(), sort_by_height);

    //for(int i = 0; i<b.size(); i++){
    //    max_height = max(max_height, sof_rec(i, b, height_map));
    //}
    max_height = sof_rec(0, b, height_map);

    max_height = sof_rec_hash(0, b, height_map);
    for(auto i: height_map) cout << i << ","; cout << "\n";
    return max_height;
}



int main(){
    vector<struct box> in(3);
    in[0].height = 3;
    in[0].width  = 3;
    in[0].depth  = 3;
    in[1].height = 2;
    in[1].width  = 2;
    in[1].depth  = 2;
    in[2].height = 5;
    in[2].width  = 5;
    in[2].depth  = 5;

    cout << stackofbox(in);

}
