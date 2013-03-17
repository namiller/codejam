//
//  main.cpp
//  googleStars
//
//  Created by Nolan Miller on 3/17/13.
//  Copyright (c) 2013 Nolan Miller. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct level {
    int one;
    int two;
};

bool onecomp(level a, level b){
    return a.one > b.one;
}
bool twocomp(level a, level b){
    return a.one > b.one;
}


int mindex(vector<int>& vect){
    int min = vect[0];
    int index = 0;
    for(int i =1; i<vect.size();i++){
        if(vect[i] < min){
            min = vect[i];
            index = i;
        }
    }
    return index;
}


int main(int argc, const char * argv[])
{
    int len;
    cin>>len;
    for (int i=0; i<len ; i++) {
        int levels;
        int stars = 0;
        int plays = 0;
        cin>>levels;
        vector<int> ones;
        vector<int> twos;
        for (int ii =0; ii<levels;ii++) {
            int star1,star2;
            cin>>star1>>star2;
            ones.push_back(star1);
            twos.push_back(star2);
        }
        //read in of data is done.
        //sort it first.
//        sort(twos.begin(), twos.end());
//        sort(ones.begin(), ones.end());
//this will be an optomization but would require a sort function and a struct.
        int mdex;
        bool stuck = 0;
        while (!twos.empty()&&!stuck) {
            if (twos[(mdex = mindex(twos))]<=stars) {
                if (ones[mdex]==-1)
                    stars+=1;
                else
                    stars+=2;
                plays++;
                twos.erase(twos.begin() + mdex);
                ones.erase(ones.begin() + mdex);
                //not sure if that will work correctly...
            }
            else if (ones[(mdex = mindex(ones))]<=stars){
                ones[mdex] = -1;
                stars+=1;
                plays++;
            }
            else
                stuck = true;
        }
        if (stuck) {
            cout<<"Case #"<<i+1<<": Too Bad"<<endl;
        }
        else
            cout<<"Case #"<<i+1<<": "<<plays<<endl;
    }

    return 0;
}


