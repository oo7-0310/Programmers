#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
//옷종류, 개수 쌍으로 하면 될 듯
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    //vector <string> clothes2;
    
    unordered_map <string, int> jongru;
    //for(auto name:clothes2.second){
     //   jongru[name]++;
    //}
    
    //반복문에서 바로 백터 넣자(쌍으로 갖고 있음, 아직 2차원임)
    for(vector<string> clothes2 : clothes){
        jongru[clothes2[1]]++;
    }
    
    for(auto e : jongru){
        answer = answer * (e.second+1);
    }
    
    return answer -1;
}
