// HONESTLY, I'D RECOMMEND JUST RETRYING THIS IN PYTHON, IN CPP IT'S TOO LONG AND ANNOYING!!!
#include <bits/stdc++.h>
using namespace std;

// string* impose(string*a, string*b, int N){
// 	int i, j;
// 	string c[N];
// 	for (i=0;i<N;i++){
// 		c[i] = "";
// 		for (j=0;j<N;j++) c[i] += a[i][j];
// 	}
// 	for (i=0;i<N;i++){
// 		for (j=0;j<N;j++){
// 			if (a[i][j]== '.' && b[i][j]=='#') c[i][j] = '#';
// 			else if (a[i][j] == '#' && b[i][j] == '#'){
// 				c[0] = "";
// 				return c;
// 			}
// 		}
// 	}

// 	return c;

// }
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int i, j, p, q, r, s;
	int N, K;
	cin>>N>>K;
	string original[N];
	for (i=0;i<N;i++) cin>>original[i];

	string pieces[K][N];
	for (i=0;i<K;i++){
		for (j=0;j<N;j++) cin>>pieces[i][j];
	}

	string b[N], c[N], x[N], y[N];
	
	// for (i=0;i<N;i++) cin>>a[i];
	// for (i=0;i<N;i++) cin>>b[i];

	// for (i=0;i<N;i++) c[i] = a[i];

	int possible=1, done;
	int top[2], bot[2], left[2], right[2];
	int ix, jx, iy, jy;
	for (p=0;p<K-1;p++){
		for (q=p;q<K;q++){
			for (r=0;r<N;r++) x[r] = pieces[p][r];
			for (r=0;r<N;r++) y[r] = pieces[q][r];

			// if (p==0 && q==2){
			// 	cout<<"DEBUG\n";
			// 	for (r=0;r<N;r++) cout<<c[r]<<"\n";
			// 	cout<<"\n";
			// 	for (r=0;r<N;r++) cout<<b[r]<<"\n";

			// }	
			bot[0] = bot[1] = left[0] = left[1] = right[0] = right[1] = top[0] = top[1] = 0;
			
			for (r=0;r<N;r++){
				for (s=0;s<N;s++){
					if (c[r][s] == '#'){
						top[0] = min(top[0], j);
						bot[0] = max(bot[0], j);
						right[0] = max(right[0], j);
						left[0] = min(left[0], j);
					}
				}
			}
			for (r=0;r<N;r++){
				for (s=0;s<N;s++){
					if (b[r][s] == '#'){
						top[1] = min(top[1], j);
						bot[1] = max(bot[1], j);
						right[1] = max(right[1], j);
						left[1] = min(left[1], j);
					}
				}
			}
			right[0] = N-1-right[0]; right[1] = N-1-right[1]; bot[0] = N-1-bot[0]; bot[1] = N-1-bot[1];
			
			for (ix=-top[0];ix<=bot[0];ix++){
				for (jx=-left[0];jx<=right[0];jx++){
					for (iy=-top[1];iy<=bot[1];iy++){
						for (jy=-left[1];jy<=right[1];jy++){

							//This code shifts the pieces:
							for (r=0;r<N;r++){
								for (s=0;s<N;s++){
									if ((r-ix)<0 || (r-ix)>=N || (s-jx)<0 || (s-jx)>=N) c[r][s] = '.';
									else c[r][s] = x[r-ix][s-jx];
								}
							}
							for (r=0;r<N;r++){
								for (s=0;s<N;s++){
									if ((r-ix)<0 || (r-ix)>=N || (s-jx)<0 || (s-jx)>=N) b[r][s] = '.';
									else b[r][s] = y[r-ix][s-jx];
								}
							}
							possible = 1;
							for (i=0;i<N;i++){
								for (j=0;j<N;j++){
									if (c[i][j]=='.' && b[i][j] == '#') c[i][j] = '#';
									else if (c[i][j]=='#' && b[i][j] == '#'){
										possible = 0;
										break;
									}

									// if (p==0 && q==2){
									// 	cout<<"DEBUG: "<<i<<" "<<j<<" "<<c[i][j]<<" "<<b[i][j]<<"\n";
									// }
								}
								if (!possible) break;
							}
							if (possible){
								done = 1;
								for (r=0;r<N;r++){
									if (c[r] != original[r]){
										done = 0;
										break;
									}
								}
								if (done){
									cout<<p+1<<" "<<q+1;
									break;
								}
							}
						// if (p==0 && q==2){
						// 	cout<<"DEBUG\n";
						// 	for (r=0;r<N;r++) cout<<c[r]<<"\n";
						// }	

						}
						if (done) break;
					}
					if (done) break;
				}
				if (done) break;
			}
			if (done) break;
			
		}
		if (done) break;
	}
	

	// if (possible){
	// 	for (i=0;i<N;i++) cout<<c[i]<<"\n";
	// }
	// else cout<<"NOt possible";
	
}
/*
.##
#..
#..

#..
..#
.##

###
#.#
###
*/
//!Self testcase:
/*
##
##

#.
.#

..
.#

#.
..

##
..

..
##

..
..

*/
//!without space
/*
2 3
##
##
#.
.#
##
..
.#
#.
*/
