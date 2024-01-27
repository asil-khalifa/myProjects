//! THIS CODE DOESN'T WORK FOR ALL TEST CASES
// max_con =  min(con, p)
// max sentences here = max_con*2 + (p-max_con)

/*
max_nouns = iv + tv*2;
if (n > max_nouns){
	if (C>= max_nouns - iv -2){
		total_nouns = max_nouns;
	}
	
}
*/

/*
iterate over all iv's:
	if (count_nouns>0 &&  P>0) 
		count_nouns--;
		no_words += 2;
		print(nouns[-1])
		print(iv)

		if (!no_con && con>0 && (count_nouns>0 && iv>0 || count_nouns>1 && tv>0))
			no_con = 1;
			print(word_con[0]);
			con--;
			no_words ++;
		else
			print(.)
			no_con = 0;
	else
		break

iterate over all tv's:
	if (count_nouns>1 && P>0)
		count_nouns--;
		no_words += 3;
		print(nouns[0])
		print(tv)
		print(nouns[0])
		
		if (C>0 && (tv_index is last index || count_nouns == 1))
			while (C>0 && count_nouns>0)
				print(, )
				print(nouns[0])
				C--;
		else if (!no_con && con>0 && (count_nouns>1 && tv>0))
			no_con = 1;
			print(word_con[0]);
			con--;
			no_words ++;
		else
			print(.)
			no_con = 0;
	else
		break
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin>>T;
	int i, j, k;
	int N, C, P;

	vector <string> nouns, iv, tv, con;
	int no_words, no_con;
	// int count_nouns, count_con;
	string word, type;
	for (i=0;i<T;i++){
		nouns.clear(); iv.clear(); tv.clear(); con.clear();
		no_words = 0;
		string output;
		cin>>N>>C>>P;
		for (j=0;j<N;j++){
			cin>>word>>type;
			if (type == "noun") nouns.push_back(word);
			else if (type == "transitive-verb") tv.push_back(word);
			else if (type == "intransitive-verb") iv.push_back(word);
			else con.push_back(word);
		}
		no_con = 0;
		output = "";
		while (iv.size()>0){
			if ((P==1 || iv.size() == 1 && nouns.size() == 2) && nouns.size()>1 && con.size()==0 && tv.size()>0) break; // If there's room for only one more sentence and a compound sentence is not possible and number of nouns are 2, 3, ... then we need a tv
			// if ()
			if (nouns.size()>0 && P>0){
				if (no_words!=0) output += " ";
				output += nouns.back();
				output += " " + iv.back();
				nouns.pop_back();
				iv.pop_back();
				no_words += 2;

				if (!no_con && con.size()>0 && (nouns.size()>0 && iv.size()>0 || nouns.size()>1 && tv.size()>0)){
					no_con = 1;
					output += " " + con.back();
					con.pop_back();
					no_words++;
				}
				else{
					output += ".";
					no_con = 0;
					P--;
				}
			}
			else break;
		}

		while(tv.size()>0){
			if (nouns.size()>1 && P>0){
				if (no_words!=0) output += " ";
				output += nouns.back();
				nouns.pop_back();
				output += " " + tv.back();
				tv.pop_back();
				output += " " + nouns.back();
				nouns.pop_back();
				no_words += 3;

				if (C>0 && (tv.size()==0 || P==1 || nouns.size() == 1)){
					while (C>0 && nouns.size()>0){
						output += ", " + nouns.back();
						nouns.pop_back();
						no_words++;
						C--;
					}
					output += ".";
					P--;
				}
				else if (!no_con && con.size()>0 && (nouns.size()>1 && tv.size()>0)){
					no_con = 1;
					output += " " + con.back();
					con.pop_back();
					no_words++;
				}
				else{
					output += ".";
					no_con = 0;
					P--;
				}
			}
			else break;
		}
		cout<<no_words<<"\n"<<output<<"\n";
	}
/*
! Use size of nouns and con for counting
iterate over all tv's:
	if (count_nouns>1 && P>0)
		count_nouns--;
		no_words += 3;
		print(nouns[0])
		print(tv)
		print(nouns[0])
		
		if (C>0 && (tv_index is last index || count_nouns == 1))
			while (C>0 && count_nouns>0)
				print(, )
				print(nouns[0])
				C--;
		else if (!no_con && con>0 && (count_nouns>1 && tv>0))
			no_con = 1;
			print(word_con[0]);
			con--;
			no_words ++;
		else
			print(.)
			no_con = 0;
	else
		break
*/
}

/*
!Error: 
10 1 5
ijrwuys intransitive-verb
aninru transitive-verb
lcuqpiwnk noun
ijrwuys intransitive-verb
tbae noun
kmksozp noun
tbae noun
ijrwuys intransitive-verb
ijrwuys intransitive-verb
tbae noun
note: here iv = 4, tv = 1, n =5
9
tbae ijrwuys. tbae ijrwuys. kmksozp ijrwuys. tbae aninru lcuqpiwnk. [correct]

8
tbae ijrwuys. tbae ijrwuys. kmksozp ijrwuys. tbae ijrwuys.
											@
											n = 2, tv=1, iv=1, p=2, c=1

*/

/*
1
9 2 2
lc noun
wtohvdpl transitive-verb
agkdyanak noun
yxctwlr intransitive-verb
qxoyhg noun
qxoyhg noun
jrr transitive-verb
fkkn noun
agkdyanak noun
7
agkdyanak yxctwlr. fkkn jrr qxoyhg, qxoyhg, agkdyanak. [Wrong]

8
agkdyanak jrr fkkn. qxoyhg wtohvdpl qxoyhg, agkdyanak, lc. [Correct]
*/

