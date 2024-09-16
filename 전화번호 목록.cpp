#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
//일단 다 넣고보자

using namespace std;

bool solution(vector<string> phone_book) {
    //bool answer = true;
    //어떤 값을 접두어로 나누면 몫은 1xxxx임 
    //어떻게 안될까.. 해시 어케함
    //unordered_set<string> s;
    //sort(phone_book.begin(), phone_book.end());
    //for(auto num : phone_book){
     //   s.insert(num);
    //}
    
    
    unordered_map<string, int> phoneBook;
    for(auto phone : phone_book){
        phoneBook[phone] = 1; //음?
    }
    
    for(int i = 0; i < phone_book.size(); i++){
        
        //for(int j = i+1; j < phone_book.size(); j++){
           // answer = phone_book[j].substr(0, phone_book[i].size()-1)==phone_book[i]?false:true;
            
            //if(answer==false) return answer;
        for (int j = 0; j < phone_book[i].size() - 1; j++) { 
            string phone_number = phone_book[i].substr(0, j + 1); 
            if (phoneBook[phone_number])
                return false;


            //string number = phone_book[j].substr(0,phone_book[i].size()-1);
            //if(phone_book[i]==number)
                //return false;
         }
        
        /*for (int j = 0; j < phone_book[i].size() - 1; j++) { 
            string phone_number = phone_book[i].substr(0, j + 1); 
            if (phoneBook[phone_number]) 
                return false; 
        }*/
        }
    

        
        
    //}
    return true;
    
    
    
    
    
    
    //for(auto cmp : phone_book){
        //for(auto cmp2 : phone_book){
            //if(cmp2.substr(0,cmp.size()-1)==cmp)
                //return cmp2;
            //answer = strncmp(cmp, cmp2, cmp.size())
            //if(answer==false)
            //    return true;
        //}
        //return false;
    //}
    //return "aaa";
    

}
