#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#define endl '\n'
using namespace std;
int n,ret=1e9;
signed main(){
	cin>>n;
	for(int i=0;i<=n;++i){
		if(i*3>n) break;
		for(int j=0;j<=n;++j){
			if(j*2+i*3>n) break;
			for(int k=0;k<=n;++k){
			    int f1=i*3+j*2+k,f2=j+2*k,ans=i+j+k+(n+1)/2;
				if(n%2){
					if(f2<n) f2++;
					else if(f1<n) f1++;
				}
				if(f1>n||f2>n) break;
				ans+=(n-f2+1)/2;
			 //   cout<<f1<<" "<<f2<<" "<<ans<<" ";
				if(f1+(n-f2+1)/2<n) ans+=(n-(f1+(n-f2+1)/2)+2)/3;
			//	cout<<ans<<endl;
				ret=min(ret,ans);
			}
		}
	}
	cout<<ret;
	return 0;
}