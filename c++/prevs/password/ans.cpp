//
//  main.cpp
//  googlePasswordBetter
//
//  Created by Nolan Miller on 3/16/13.
//  Copyright (c) 2013 Nolan Miller. All rights reserved.
//

#include <iostream>

using namespace std;

void print1d(double* array,int l){
    for(int i =0;i<l;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void prefix(double* in, double* out, int len){
    out[0] = in[0];
    for (int i=1; i<len; i++) {
        out[i] = out[i-1]*in[i];
    }
}
double min(double*in,int len){
    double ret = in[0];
    for (int i =1; i<len; i++) {
        if (in[i]<ret) {
            ret = in[i];
        }
    }
    return ret;
}

double findVal(int A, int B, double* probs){
    double pref[A];
    double cost[A+1];
    //will need to separately calculat the cost of hitting enter straight away.
    prefix(probs, pref, A);
    for (int i = 0; i<A; i++) {
        cost[i] = ((i*2)+B-A+1)*pref[A-i-1]+((i*2)+B-A+1+B+1)*(1-pref[A-i-1]);
    }
    cost[A] = B+2;
    
    return min(cost,A+1);
}


int main(int argc, const char * argv[])
{
    int cnt;
    cin>>cnt;
    int A,B;
    for (int it=0; it<cnt; it++) {
        cin>>A>>B;
        double probs[A];
        for (int pri=0; pri<A; pri++) {
            cin>>probs[pri];
        }
//        print1d(probs, A);
        cout.precision(7);
        cout<<"Case #"<<it+1<<": "<<findVal(A, B, probs)<<endl;
//        findVal(A, B, probs);
        //probs = probability that it is correct.
        //to calculate the cases just count in binary.
    }
    return 0;
}


