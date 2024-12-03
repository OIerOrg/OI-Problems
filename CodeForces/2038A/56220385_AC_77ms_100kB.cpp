#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1005],b[1005],c[1005],s[1005];
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=n;i;i--){
		c[i]=a[i]/b[i];
		s[i]=s[i+1]+c[i];
	}
	if(s[1]<k) for(int i=1;i<=n;i++) cout<<"0 ";
	else{
		for(int i=n;i;i--)
			if(s[i]>k){
				c[i]=k-s[i+1];
				for(int j=1;j<i;j++) c[j]=0;
				break;
			}
		for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	}
	return 0;
}