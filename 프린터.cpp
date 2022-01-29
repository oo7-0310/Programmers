#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue <pair<int, int>> q; //(위치, priorities)
    priority_queue <int> pq;
    
    //pair 값 넣어주기
    for(int i = 0; i < priorities.size(); i++){
        q.push({i, priorities[i]});//인덱싱, 우선순위 값
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        if((q.front().second)==pq.top()){
            answer++;//당연히 같은 값 아닌가? //차례대로 count해서 나오는 게 loaction값의 호출 순서와 같다?(front인 줄) top이랑 비교임 //왜 끝이랑 비교하지?
            if(q.front().first==location){
                return answer;
            }
            q.pop();//계속 맨 앞의 숫자들만 비교할 거니까 방금 비교한 값은 없애주자
            pq.pop();
        }
        else{
            pair<int, int> tmp = {q.front().first, q.front().second}; //else가 나오는 경우가 있나? 왜 했을까
            q.pop();
            q.push(tmp);
        }
    }
    
    
    return answer;
}
