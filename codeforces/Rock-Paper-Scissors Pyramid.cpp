//
// Created by k0itoYuu on 2025/11/16.
//
#include<bits/stdc++.h>
using namespace std;
//r石头p布s剪刀
char pd(char sa,char sb){
    if(sa==sb)return sa;
    if(sa=='R'){
        if(sb=='S')return sa;
        else return sb;
    }else if(sa=='P'){
        if(sb=='R')return sa;
        else return sb;
    }else if(sa=='S'){
        if(sb=='P')return sa;
        else return sb;
    }
}string s;
void solve(){

    cin>>s;
    stack<char>st;

    st.push(s[0]);
    for(int i=1;i<s.size();i++){
        //cout<<i<<"|"<<st.size()<<endl;

        int r=s[i];
        char e=s[i];
        while(true){
            if(st.empty()){
                st.push(r);
                break;
            }
            //cout<<st.top()<<endl;
            e=pd(e,st.top());
            if(!st.empty()&&e==r){
                st.pop();
            }else {
                st.push(r);
                break;
            }
        }

    }
    //cout<<st.size()<<endl;
    while(st.size()>1){
        st.pop();
    }
    cout<<st.top()<<endl;
    //cout<<now<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();

}
