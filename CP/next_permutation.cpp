//! This is my own version of the next_permutation() function in cpp

#include <bits/stdc++.h>
using namespace std;

bool my_next_per(vector <int>::iterator first, vector <int>::iterator last){
// https://marknelson.us/posts/2002/03/01/next-permutation.html

	if (first == last) return false;
	else if (first +1 == last) return false;
	else {
		vector <int>::iterator i = last-2, ii = last-1, j=last-1;
		for (;i>=first;){
			if (*i<*ii){
				while (*j<=*i) j--;
				iter_swap(i, j);
				reverse(ii, last);
				return true;
			}
			i--; ii--;
		}
		reverse(first, last);
		return false;
	}
}

int main(){
	int n, i;
	cin>>n;
	vector <int> v;
	for (i=0;i<n;i++) v.push_back(i+1);
	do{
		for (i=0;i<n;i++) cout<<v[i];
		cout<<" ";
	} while (my_next_per(v.begin(), v.end()));
}
