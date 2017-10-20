//
//  ScoreHistory.cpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/17.
//

#include "ScoreHistory.hpp"

void ScoreHistory::memoryscore(std::string i_name,int i_score){
    Score memory = {i_name,i_score};
    auto p = scorehistory.begin();
    for (int i=0; i<scorehistory.size() && i_score < (*p).score; i++,p++);
    scorehistory.insert(p, memory);//スコア順にリストに追加
    if (scorehistory.size()>=3) {
        scorehistory.pop_back();//リストが10を超えた場合最後を削除
    }
}

int ScoreHistory::getscore(const int n) {
    auto itr = scorehistory.begin();
    for(int i=0;i<n; ++itr, ++i);
    return itr->score;
}
std::string ScoreHistory::getname(const int n){
    auto itr = scorehistory.begin();
    for(int i=0;i<n; ++itr, ++i);
    return itr->name;
}
