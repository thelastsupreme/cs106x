#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<sstream>
using namespace std;

// The Egg Drop Problem: There is a building of n floors. If an egg drops from the kth floor or
// above, it will break. If it's dropped from any floor below, it will not break. You're given e eggs. Find
// N, while minimizing the number of drops for the worst case.

unordered_map<string,int>t;    //use map for optimization 
int eggDrop(int eggs,int floors){
    if(floors==0||floors==1){
        return floors;
    }
    if(eggs==1){
        return floors;
    }
    //used string stream instead of to_string to make a unique key
    stringstream ss;
    ss<<eggs<<" "<<floors;
    string key=ss.str();
    ss.clear();

    if(t.find(key)!=t.end()){
        return t[key];
    }
    int res=INT32_MAX;
    int bot,top=0;
    for(int k=1;k<=floors;k++){
        //***************code before optimization****************
        // int temp=1+max(eggDrop(eggs-1,k-1),eggDrop(eggs,floors-k)); //max cause assuming worst case here
        ss<<eggs-1<<" "<<k-1;
        string botkey=ss.str();
        if(t.find(botkey)!=t.end()){
            bot=t[botkey];
        }else{
            bot=eggDrop(eggs-1,k-1);
        }
        ss.clear();

        ss<<eggs<<" "<<floors-k;
        string topkey=ss.str();
        if(t.find(topkey)!=t.end()){
            top=t[topkey];
        }else{
            top=eggDrop(eggs,floors-k);
        }
        ss.clear();
        
        int temp=1+max(top,bot); 
        res=min(res,temp);
    }
    return t[key]=res;
}
//**********pseudo code for O(N^3)********************
//  for (int i = 2; i <=eggs ; i++) {
//             for (int j = 2; j <=floors ; j++) {
//                 eggDrops[i][j] = Integer.MAX_VALUE;
//                 int tempResult;
//                 for (int k = 1; k <=j ; k++) {
//                     tempResult = 1 + Math.max(eggDrops[i-1][k-1], eggDrops[i][j-k]);
//                     eggDrops[i][j] = Math.min(tempResult,eggDrops[i][j]);
//                 }
//             }
//         }
int main(){
    cout<<eggDrop(2,100);
}