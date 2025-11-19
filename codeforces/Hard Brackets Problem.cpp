//
// Created by k0itoYuu on 2025/11/19.
//
#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    stack<char>st;
    int l=0;
    string ans="";
    for(int i=0;i<s.size();i++){
        if(st.empty()&&s[i]==')'){
            for(int j=0;j<l;j++){
                ans+=')';

            }l=0;
            ans+=')';
        }
        else if(s[i]=='('){
            for(int j=0;j<l;j++){
                ans+=')';

            }l=0;
            ans+='(';
            st.push('(');
        }else if(!st.empty()&&s[i]==')'){

            st.pop();
            l++;
        }
        //cout<<i<<" "<<l<<" "<<ans<<endl;
    }
    if(!st.empty())cout<<"impossible\n";
    else cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
/*
3
((()))
(
)))()
 (()())))
((())()))
 */