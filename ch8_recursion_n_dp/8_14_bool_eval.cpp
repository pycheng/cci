//#vlstr, #dp
//        str_l=str.substr(0, i-1); //from 0 get length i-1
//        str_r=str.substr(i+1);    //i+1 to the end
//notice the hash key
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;


int counteval(string str, bool val, unordered_map<string, int>& hash){
    int num_rep = 0;
    char b_exp;
    int left_true   = 0;
    int left_false  = 0;
    int right_true  = 0;
    int right_false = 0;
    int total = 0;

    //base case
    if(str.size()==0) return 0;
    if(str.size()==1){
       if((str=="1"&&val==true)||(str=="0"&&val==false))
           return true;
       else
           return false;
    }
    //hash case
    if(hash.count(str+to_string(val)) > 0) return hash[str+to_string(val)];

    //for each bool expression
    for(int i=1; i<str.size(); i+=2){
    //recursively call two substring with true/false
    //left_true, left_false, right_true, right_false
        string str_l, str_r;
        b_exp = str[i];
        str_l=str.substr(0, i); //from 0 get length i-1
        str_r=str.substr(i+1);    //i+1 to the end

        left_true   = counteval(str_l, true,  hash);
        left_false  = counteval(str_l, false, hash);
        right_true  = counteval(str_r, true,  hash);
        right_false = counteval(str_r, false, hash);
        total = (left_true + left_false) * (right_true + right_false);
//    cout << "char: " << b_exp << "\n";
//    cout << "l_str: " << str_l << "r_str: " << str_r << "\n";
//    cout << left_true << "," << left_false << "," << right_true << "," << right_false << "\n";
    
        int num_of_true = 0;
        if(b_exp == '&'){
            num_of_true = left_true*right_true;
        }else if(b_exp == '|'){
            num_of_true = left_true*right_true  +\
                      left_true*right_false +\
                      left_false*right_true;
        }else if(b_exp == '^'){
            num_of_true = left_true*right_false +\
                      left_false*right_true;
        }else{
            cout << "invalid expression: " << str << "\n";
            return 0;
        }
        num_rep += (val)?num_of_true: total-num_of_true;
    }
    // watch out the hash table
    hash[str+to_string(val)] = num_rep;
    return num_rep; //number of valid representation
}


int counteval(string str, bool val){
    unordered_map<string, int> hash;
    return counteval(str, val, hash);
}

int main(){
    cout << counteval("1^0|0|1", false)   << "\n"; //2 
    cout << counteval("0&0&0&1^1|0", true)<< "\n"; //10
    return 0;
}
