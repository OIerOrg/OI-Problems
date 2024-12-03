#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#define endl '\n'
using namespace std;
int t;
string s;
signed main(){
	//ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>s;
		int a=s[0]-'0',b=s[2]-'0';
		char x=s[1];
		if(a==b){
			s[1]='=';
			cout<<s;
		}
		if(a<b){
			s[1]='<';
			cout<<s;
        }
        if(a>b){
			s[1]='>';
			cout<<s;
		}
		cout<<endl;
	}
	return 0;
}