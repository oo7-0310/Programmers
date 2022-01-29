#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> count2;
    queue<int> q;
    
    for(int i = 0; i < progresses.size(); i++){//할 일의 수만큼 반복
        int count = 0;
        while(progresses[i]<=100){
            progresses[i]+=progresses[i]*speeds[i];
            count++;//100이 될 때까지 +1 day
            
        }
        count++;
        count2.push_back(count);
        int cnt = 1;
        for(int i = 0; i<progresses.size(); i++){
            if(count2[i]>=count2[i+1]){
                cnt++;
                continue;
            }
            answer.push_back(cnt);
        }
        
    }
    return answer;
    
}
