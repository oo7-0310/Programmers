#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

//쌍1 (장르, 총 재생수) => 어떤 장르 먼저 해야하는지
//쌍 2 (재생수, 고유번호) => 장르 선택 후 그 장르 안에서 재생 수에 따라 고유번호 배치
//셋다 쌍으로 만들 수 있나?
// ....라고 생각은 했는데 모르겠는데요
//구글링+이해를 목표로 잡음 ㅠㅠㅠㅠㅠㅠㅠㅠㅠ
using namespace std;

bool cmpGenres(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;
}

bool cmpPair(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,vector<pair<int,int>>> album;    
    unordered_map<string,int> count;   
    
    for(int i=0;i<genres.size();i++){
        album[genres[i]].push_back(make_pair(i,plays[i]));
        count[genres[i]] += plays[i];
    }
    
    vector<pair<string,int>> cntv;     
    cntv.assign(count.begin(), count.end());
    sort(cntv.begin(), cntv.end(), cmpGenres);
    
    for(auto &gen : album){
        sort(gen.second.begin(), gen.second.end(), cmpPair);
    }
    
    for(int i=0;i<cntv.size();i++){
        string gen = cntv[i].first;
        for(int j=0;j<2 && j<album[gen].size();j++){
            answer.push_back(album[gen][j].first);
        }
    }
    return answer;
}
