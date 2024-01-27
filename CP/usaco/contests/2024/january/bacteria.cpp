#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll N;
	cin>>N;
	ll a[N], i, j, k, L, count=0, sign=1;
	for (i=0;i<N;i++) cin>>a[i];
	for (i=0;i<N;i++){
		if (a[i]==0) continue;

		// if (i==0){
		// 	L = abs(a[0]);
		// 	if (a[0]>0) sign=-1;
		// 	else sign = 1;
		// 	for (j=0;j<N;j++){
		// 		a[j] += sign*L;
		// 		L++;
		// 	}

		// 	count++;	
		// }

		L = abs(a[i]);
		if (a[i]>0) sign=-1;
		else sign = 1;
		for (j=i;j<N;j++){
			a[j] += sign*L*(j-i+1);
		}
		count += L;

	}

	cout<<count;
}
