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
#define BIG 1000000
using namespace std;

struct level {
    int one;
    int two;
};
void printVect(vector<int> in){
    for (int i =0; i<in.size(); i++) {
        cout.width(3);
        cout<<(in[i]!=BIG?in[i]:-1)<<" ";
    }
    cout<<endl;
}
bool onecomp(level a, level b){
    return a.one > b.one;
}
bool twocomp(level a, level b){
    return a.one > b.one;
}


int mindex(vector<int>& vect){
    int min = vect[0];//big number
    int index = 0;
    for(int i =1; i<vect.size();i++){
        if(vect[i] < min){
            min = vect[i];
            index = i;
        }
    }
    return index;
}

int bestMatch(vector<int> ones, vector<int> twos,int stars,int mdex){
    int max = twos[mdex];
    int index = mdex;
    for (int i =0; i<ones.size(); i++) {
        
        if (ones[i] <= stars) {
            if (twos[i]>max) {
                max = twos[i];
                index = i;
            }
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
        //sort it first?
        int mdex;
        bool stuck = 0;
        while (!twos.empty()&&!stuck) {
            if (twos[(mdex = mindex(twos))]<=stars) {
                if (ones[mdex]==BIG)
                    stars+=1;
                else
                    stars+=2;
                plays++;
                twos.erase(twos.begin() + mdex);
                ones.erase(ones.begin() + mdex);
                //not sure if that will work correctly...
            }
            else if (ones[(mdex = mindex(ones))]<=stars){
                //find best match (ie ones that fulfils and twos taht is the highest
                mdex = bestMatch(ones, twos, stars, mdex);
                ones[mdex] = BIG;
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


