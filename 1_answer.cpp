#include<iostream>
using namespace std;
int main(){

    /** outer loop runs from -6 to 6 inorder to reflect upper half to 
    get lower half **/
    for(int i=-6;i<=6;i++){
        for(int j=1;j<=7;j++){
            if(j>=7-abs(i))
            cout<<j<<"   ";
            else cout<<"  ";
        }
        cout<<endl;
    }

    return 0;
}