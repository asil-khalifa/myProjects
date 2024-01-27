//! BEWARE: It doesn't work for all testcases
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	int T;
	cin>>T;
	int i, j, t, hi=0, count=0, rep=0, atleastone=0, first=0;
	int N=0;
	for (t=0;t<T;t++){
		cin>>N;
		int types[N]{}, instances[N]{}, order[N]{};
		for (i=0;i<N;i++){
			cin>>hi;
			order[i] = hi;
			instances[hi-1]++;
		} 
		atleastone=0;
		for (i=0;i<N;i++){
			hi = order[i]-1;
			rep = instances[hi];

			if (rep == 1) continue;
			if (types[hi]) continue;
			
			count = 0;
			for (j=i;j<i+2*rep-1;j++){
				if (j>N-1) break;
				if (order[j]-1 == hi) count++;
				if (count==rep){
					types[hi] = 1;
					atleastone = 1;
					break;
				}
			}

		}
		first = 1;
		if (atleastone){
			for (i=0;i<N;i++){
				if (types[i]){
					if (!first) cout<<" ";
					cout<<i+1;
					first = 0;
				}
			}
			cout<<"\n";
		}
		else cout<<-1<<"\n";

		
	}

}
/*

1
50
11 23 37 35 25 10 50 6 21 34 42 44 47 26 17 9 30 40 7 48 49 29 20 31 1 39 41 4 33 27 38 14 5 43 43 18 19 16 32 13 15 8 2 46 45 24 3 36 12 2 */

/*
1. INPUT: while inputting:
	a. Find out max value of hi and create an array types with that many values inited to 0
	b. Create another array to store how many instances of each cow are there
2. Loop through each of the N hay types in order:
	if rep of current hi = 1 then skip
	if array types[hi] = 1 then skip

	A. init variable count to 0
	Loop start from i go till i+ 2*(rep of current hi)-1
		keep adding 1 to count if hi is current hi (found at i)
		if count is x:
			array types[hi] is made to 1
			break
3. For each element in array types:
	if value is 0 print it's index +1
		
*/
