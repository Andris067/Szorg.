#import<bits/stdc++.h>
using namespace std;int main(){string s;getline(cin,s);cout<<(s==string(s.rbegin(),s.rend()));int n,x[99];cin>>n;for(int i=0;i<n;)cin>>x[i++];sort(x,x+n);for(int i=0;i<n;)cout<<x[i++]<<' ';}
