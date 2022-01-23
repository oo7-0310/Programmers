#include <string>
#include <vector>
#include <unordered_map>
//왜 다들 unordered_map으로 하지 이걸 굳이 키-값 쌍을 만들어야 하나? 

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    vector<string> answer;
    //unordered_multiset<string> p;//바로 participant로 선언하면 안되겠지? 이미 선언하면서 인자로 들어온거니까..
    
    //참여자를 p에 다 넣어
    //for (auto elem : participant){
    //    p[elem]++;
//}
    
    //p.find(completion에 있는 값) ! = p.end()
    
    //p중에 completion 있는지 확인하고 없으면 뱉으면 되는 겅 아닌가
    //for (auto elem : completion){
    //    if(p.find(elem) != p.end())
    //        return p.find(elem)
    //}
    
    //작전바꿔
    //participant 중복 '값' count
    //completion 마찬가지.. 굳이?
    //count 수 다르면 완주 못한거지 -> 또 count 해야되잖아 빼는게 더 이득임
    
    unordered_map<string, int> p;
    for(auto elem : participant ){
        p[elem]++; //동명이인 있으면 value값이 +1됨 처음에는 0으로 초기화 되는 건가?
    }
    
    for(auto elem : completion ){
        if(p.find(elem)!=p.end())//있다면-> 없어도 되는 듯
            p[elem]--;//완주자는 참여자 중에 반드시 있으니까
        
    }

    //value 값이 1이상이면 완주 못한거
    for (auto c : p){
        //if(c.second >=1) answer.push_back(c.first); // 이거 왜안돼..?
        if(c.second >= 1) return c.first;
    }
}
