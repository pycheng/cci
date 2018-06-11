#include <iostream>
#include <vector>
using namespace std;

enum suit{
    club    = 0,
    diamond = 1,
    heart   = 2,
    spade   = 3
};

class card{
private:
    int s;  // suit
    int v;  // value, joker
    bool available; 
public:
    card(suit s, int v): s(s), v(v), available(true) {} 
    int get_suit(){return s;}
    int get_value(){return v;}
    bool is_available(){return available;}
    void mark_unavailable(){available = false;}
    void mark_available(){available = true;}
};

class deck{
private:
    vector<card> cards;
    int delt_idx;

public:
    deck():delt_idx(0) { 
        //initalize cards 
    }

    int remain_cards()
    {
        return cards.size()-delt_idx;
    }
    void shuffle(){
        //todo
    }
    card dealcard(){
        //todo
    }
};

class hand{
private:
    vector<card> cards;
    int score;
public:
    int get_score(){
        int score = 0;
        for(auto i: cards){ 
            score += i.get_value();
        }
        return score;
    }
    int add_card(card c){
        cards.push_back(c);
    }
};

class blackjackhand : hand{
public:
    int get_score(){
        return 11;
    }
    bool busted(){ return get_score() > 21;}
    bool is21(){ return get_score() == 21;}
    bool isBlackJack {}
};

int main(){
    card *c = new card(suit::club, 1);
    cout << to_string(c->get_suit());
}
