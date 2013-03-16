#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Member{
    public:
    int val;
    
    Member();
    Member(int init);

    bool operator()(Member i,Member j){ return i.val<j.val; }

};
Member::Member(){
    val = 3;
}
Member::Member(int init){
    val = init;
}

bool func(Member i, Member j){
    return i.val<j.val;
}

int main(){
    srand(time(0));
    
    vector<int> myList;
    vector<Member> derList;

    
    for(int i = 0;i<100;i++){
        myList.push_back(rand()%300);   
        derList.push_back(Member(rand()%400));
    }

    for(int i = 0;i<myList.size();i++){
        cout<<myList[i]<<endl;
        cout<<derList[i].val<<endl;
    }

    sort(myList.begin(),myList.end());
    sort(derList.begin(),derList.end(),func);

    for(int i = 0;i<myList.size();i++){
        cout<<myList[i]<<","<<derList[i].val<<endl;
    }
    
    
    return 0;
}


