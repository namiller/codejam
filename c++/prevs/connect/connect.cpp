//
//  main.cpp
//  googleConnectN
//
//  Created by Nolan Miller on 3/15/13.
//  Copyright (c) 2013 Nolan Miller. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void print2d(char**array,int x,int y){
    for (int i =0; i<x; i++) {
        for (int ii = 0; ii<y; ii++) {
            cout<<array[i][ii]<<" ";
        }
        cout<<endl;
    }
}

void brotate(char **array,int n){
    for (int i=0; i<n; i++) {
        for (int ii =i; ii<n; ii++) {
            swap(array[i][ii], array[ii][i]);
        }
    }
}

void bshift(char**array,int n){
    for (int a =0; a<n; a++) {
        for (int i = n-1; i>=0; i--) {
            for (int ii= n-1; ii>=0; ii--) {
                if(array[i][ii] == '.'){
                    if (i == 0) {
                        array[i][ii] = '.';
                    }
                    else
                    swap(array[i][ii], array[i-1][ii]);
                }
            }
        }
    }
}
string calc(char**array,int n,char p1,char p2,int k){
    int curp1 = 0;
    int maxp1 = 0;
    int curp2 = 0;
    int maxp2 = 0;
    for (int i = 0; i<n; i++) {
        for (int ii =0; ii<n; ii++) {
            if (array[i][ii] == p2) {
                if (curp2 == 0) {
                    maxp1 = (maxp1>curp1)?maxp1:curp1;
                    curp1 =0;
                }
                curp2++;
            }
            else if (array[i][ii] == p1) {
                if (curp1 == 0){
                    maxp2 = (maxp2>curp2)?maxp2:curp2;
                    curp2 = 0;
                }
                curp1++;
            }
            else{
                maxp2 = (maxp2>curp2)?maxp2:curp2;
                maxp1 = (maxp1>curp1)?maxp1:curp1;
                curp1 = 0;
                curp2 = 0;
            }
        }
        maxp2 = (maxp2>curp2)?maxp2:curp2;
        maxp1 = (maxp1>curp1)?maxp1:curp1;
        curp1 = 0;
        curp2 = 0;
    }
    for (int ii = 0; ii<n; ii++) {
        for (int i =0; i<n; i++) {
            if (array[i][ii] == p2) {
                if (curp2 == 0) {
                    maxp1 = (maxp1>curp1)?maxp1:curp1;
                    curp1 =0;
                }
                curp2++;
            }
            else if (array[i][ii] == p1) {
                if (curp1 == 0){
                    maxp2 = (maxp2>curp2)?maxp2:curp2;
                    curp2 = 0;
                }
                curp1++;
            }
            else{
                maxp2 = (maxp2>curp2)?maxp2:curp2;
                maxp1 = (maxp1>curp1)?maxp1:curp1;
                curp1 = 0;
                curp2 = 0;
            }
        }
        maxp2 = (maxp2>curp2)?maxp2:curp2;
        maxp1 = (maxp1>curp1)?maxp1:curp1;
        curp1 = 0;
        curp2 = 0;
    }
    //begin broke ass shit for diagonals
    for (int i =0; i<n; i++) {
        for (int ii = 0; ii<(n-i); ii++) {
//            array[ii+i][ii] = i+'0';
            if (array[ii+i][ii] == p2) {
                if (curp2 == 0) {
                    maxp1 = (maxp1>curp1)?maxp1:curp1;
                    curp1 =0;
                }
                curp2++;
            }
            else if (array[ii+i][ii] == p1) {
                if (curp1 == 0){
                    maxp2 = (maxp2>curp2)?maxp2:curp2;
                    curp2 = 0;
                }
                curp1++;
            }
            else{
                maxp2 = (maxp2>curp2)?maxp2:curp2;
                maxp1 = (maxp1>curp1)?maxp1:curp1;
                curp1 = 0;
                curp2 = 0;
            }
        }
        maxp2 = (maxp2>curp2)?maxp2:curp2;
        maxp1 = (maxp1>curp1)?maxp1:curp1;
        curp1 = 0;
        curp2 = 0;
    }
    for (int i =0; i<n; i++) {
        for (int ii = 0; ii<(n-i); ii++) {
//            array[ii][ii+i] = i+'0';
            if (array[ii][ii+i] == p2) {
                if (curp2 == 0) {
                    maxp1 = (maxp1>curp1)?maxp1:curp1;
                    curp1 =0;
                }
                curp2++;
            }
            else if (array[ii][ii+i] == p1) {
                if (curp1 == 0){
                    maxp2 = (maxp2>curp2)?maxp2:curp2;
                    curp2 = 0;
                }
                curp1++;
            }
            else{
                maxp2 = (maxp2>curp2)?maxp2:curp2;
                maxp1 = (maxp1>curp1)?maxp1:curp1;
                curp1 = 0;
                curp2 = 0;
            }
        }
        maxp2 = (maxp2>curp2)?maxp2:curp2;
        maxp1 = (maxp1>curp1)?maxp1:curp1;
        curp1 = 0;
        curp2 = 0;
    }
    for (int i =0; i<n; i++) {
        for (int ii = 0; ii<(n-i); ii++) {
//            array[ii][n-(ii+i)-1] = i+'0';
            if (array[ii][n-(ii+i)-1] == p2) {
                if (curp2 == 0) {
                    maxp1 = (maxp1>curp1)?maxp1:curp1;
                    curp1 =0;
                }
                curp2++;
            }
            else if (array[ii][n-(ii+i)-1] == p1) {
                if (curp1 == 0){
                    maxp2 = (maxp2>curp2)?maxp2:curp2;
                    curp2 = 0;
                }
                curp1++;
            }
            else{
                maxp2 = (maxp2>curp2)?maxp2:curp2;
                maxp1 = (maxp1>curp1)?maxp1:curp1;
                curp1 = 0;
                curp2 = 0;
            }
        }
        maxp2 = (maxp2>curp2)?maxp2:curp2;
        maxp1 = (maxp1>curp1)?maxp1:curp1;
        curp1 = 0;
        curp2 = 0;
    }
    for (int i =0; i<n; i++) {
        for (int ii = 0; ii<(n-i); ii++) {
//            array[(ii+i)][n-1-ii] = i+'0';
            if (array[(ii+i)][n-1-ii] == p2) {
                if (curp2 == 0) {
                    maxp1 = (maxp1>curp1)?maxp1:curp1;
                    curp1 =0;
                }
                curp2++;
            }
            else if (array[(ii+i)][n-1-ii] == p1) {
                if (curp1 == 0){
                    maxp2 = (maxp2>curp2)?maxp2:curp2;
                    curp2 = 0;
                }
                curp1++;
            }
            else{
                maxp2 = (maxp2>curp2)?maxp2:curp2;
                maxp1 = (maxp1>curp1)?maxp1:curp1;
                curp1 = 0;
                curp2 = 0;
            }
        }
        maxp2 = (maxp2>curp2)?maxp2:curp2;
        maxp1 = (maxp1>curp1)?maxp1:curp1;
        curp1 = 0;
        curp2 = 0;
    }
    
    
//    cout<<endl;
//    print2d(array, n, n);
    
    
    
    if (maxp2>=k && maxp1>=k) {
        return "Both";
    }
    if (maxp2>=k) {
        return "Blue";
    }
    if (maxp1>=k) {
        return "Red";
    }
    return "Neither";

}



int main(int argc, const char * argv[])
{
    int num;
    cin>>num;
    for (int i =0; i<num; i++) {
        int k,n;
        cin>>n;
        cin>>k;
        char ** board = new char*[n];
        for (int ii =0; ii<n; ii++) {
            board[ii] = new char[n];
        }
        for (int ii = 0; ii<n; ii++) {
            for (int iii =0; iii<n; iii++) {
                cin>>board[ii][iii];
            }
        }
//        print2d(board, n, n);
        brotate(board, n);
//        cout<<endl;
//        print2d(board, n, n);
        bshift(board, n);
//        cout<<endl;
//        print2d(board, n, n);
        cout<<"Case #"<<i+1<<": ";
        cout << calc(board, n, 'R', 'B', k)<<endl;
        for (int ii = 0; ii<n; ii++) {
            delete [] board[ii];
        }
        delete board;
        
    }
    
    return 0;
}


