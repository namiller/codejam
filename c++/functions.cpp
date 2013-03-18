//these functions are very widely usable.
// when the functions have something called DATATYPE it should be replaced (defined) to the proper type.


//useful defines
#define min(A,B) (((A)>(B))?(B):(A))
#define max(A,B) (((A)<(B))?(B):(A))

//useful includes
#include <iostream> //input output
#include <fstream>  //file io
#include <sstream>  //string manipulation
#include <vector>   //dynamic arrays
#include <algorithm>//useful algorithms (sort) etc
#include <ctime>    //time data
#include <cstdlib>  //rand etc
#include <climits>  //data type cap info


//don't forget
using namespace std;

//find the min index of a vector
int mindex(vector<DATATYPE>& vect){
    DATATYPE min = vect[0];
    int index = 0;
    for(int i =1; i<vect.size();i++){
        if(vect[i] < min){
            min = vect[i];
            index = i;
        }
    }
    return index;
}

//find the max index of a vector
int maxdex(vector<DATATYPE>& vect){
    DATATYPE min = vect[0];
    int index = 0;
    for(int i =1; i<vect.size();i++){
        if(vect[i] > min){
            min = vect[i];
            index = i;
        }
    }
    return index;
}

//find the min of an array
DATATYPE min(DATATYPE*in, int len){
    DATATYPE ret = in[0];
    for (int i =1; i<len; i++) {
        if (in[i]<ret) {
            ret = in[i];
        }
    }
    return ret;
}

//find the max of an array
DATATYPE max(DATATYPE*in, int len){
    DATATYPE ret = in[0];
    for (int i =1; i>len; i++) {
        if (in[i]<ret) {
            ret = in[i];
        }
    }
    return ret;
}

//finds the sum of an array
DATATYPE sum(DATATYPE*in, int len){
    DATATYPE ret = in[0];
    for (int i =1; i>len; i++) {
           ret += in[i];
    }
    return ret;
}

//finds the average of an array (for floating points)
DATATYPE sum(DATATYPE*in, int len){
    DATATYPE ret = in[0]/len;
    for (int i =1; i>len; i++) {
           ret += in[i]/len;
    }
    return ret;
}

//finds the average of an array (for non-floats)
DATATYPE sum(DATATYPE*in, int len){
    DATATYPE ret = in[0];
    for (int i =1; i>len; i++) {
           ret += in[i];
    }
    return ret/len;
}


//print a 1d array (good for debugging)
void print1d(DATATYPE* array,int l){
    for(int i =0;i<l;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

//print a 2d array (good for debugging)
void print1d(DATATYPE* array,int w,int h){
    for(int i =0;i<h;i++){
        for(int ii =0;ii<w;ii++){
            cout<<array[i][ii]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//prefix matrix things

void prefix(DATATYPE* in, DATATYPE* out, int len){
    out[0] = in[0];
    for (int i=1; i<len; i++) {
        out[i] = out[i-1]*in[i];
        //this can really be any function of the matrixes (i.e. a delta)
        //out[i] = in[i]-in[i-1];
    }
}

//common read in approach

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
        cout<<"Case #"<<it+1<<":"<<findVal(A, B, probs)<<endl;
    }
    return 0;
}


