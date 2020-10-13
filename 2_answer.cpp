// solution of question no- 2

#include<iostream>
#include<map>
#include<vector>
#include<iterator>
using namespace std;

// function to check if the characters of two segments match
bool match(map<char,int> a,map<char,int> b){
    int l1=a.size(),l2=b.size();
    map<char,int> :: iterator it;
    if(l1>=l2){
        for(it=a.begin(); it!=a.end();it++){
            if((*it).second!= b[(*it).first]){
                return false;
            }
        }
        return true;
    }
    else{
        for(it=b.begin();it!=b.end();it++){
            if((*it).second!= a[(*it).first]){
                return false;
            }
        }
    }
    return true;
    
}

int main(){
    // input string
    string str1,str2;
    cin>>str1>>str2;

    int length1=str1.size(), length2=str2.size();

    // storing frequency of all the characters str2
    map<char,int> characters;
    for(int i=0;i<length2;i++) characters[str2[i]]++;

    // prefix vector of frequency of characters for str1
    vector<map<char,int> > freq;
    map<char,int> temp;

    for(int i=0;i<length1;i++){
        temp[str1[i]]++;
        freq.push_back(temp);
    }

    // to store the index at which substring is found
    vector<int> res;

    map<char,int> :: iterator it;

    // checking at every index of str1
    for(int i=0;i<length1-length2+1;i++){

        //difference of frequency of two postions of str1 to get frequency of characters of the segment
        map<char,int> diff;
        if(i==0) diff=freq[length2-1];
        else{
            for(it=freq[i+length2-1].begin();it!=freq[i+length2-1].end();it++){
                diff[(*it).first]=(*it).second - freq[i-1][(*it).first];
            }
        }

        // storing the index ,if frequency of characters of segment matched with the frequency of characters of str2 
        if(match(diff,characters)){
            res.push_back(i);
        }

    }

    // output
    for(int i=0;i<res.size();i++){
        cout<<"substring '"<<str1.substr(res[i],length2)<<"'"<<" present at index "<<res[i]<<endl;
    }



    return 0;
}