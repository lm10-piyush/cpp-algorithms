#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define arr_watch(arr, n) for(int i=0;i<n;++i) cout<<arr[i]<<" \n"[i==n-1]
using namespace std;

int piTable[100002];

void kmpPreProcess(string pattern){
	piTable[0] = 0;
	for (int i = 1, j = 0; i < (int)pattern.size(); ++i){
		while(j > 0 and pattern[j] != pattern[i])
			j = piTable[j-1];
		
		if(pattern[i] == pattern[j]){
			piTable[i] = ++j;
		} else{
			piTable[i] = j;
		}
	}
}

vector<int> kmpMatch(string text, string pattern){
	vector<int> idx;
	for (int i = 0, j = 0; i < (int)text.size(); ++i){
		while(j > 0 and pattern[j] != text[i])
			j = piTable[j-1];
		
		if (pattern[j] == text[i]){
			if(j+1 == pattern.size()){
				idx.push_back(i-j);
				j = piTable[j];
			}
			else j++;			
		}

	}

	return idx;
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    
    // freopen("D:/TestFiles/input.txt","r",stdin);
	
	#endif
	/*********************** CODE IS HERE *****************************************/

    int t; cin >> t;
    while(t--){
	    string pattern = "AABA";
	   	string text = "AABAACAADAABAABA";
	   	
	   	// string pattern, text; cin >> pattern >> text;
	   	kmpPreProcess(pattern);

	   	//for (int i = 0; i < pattern.size(); ++i)
	   	//	cout << piTable[i] << " ";
	   	//cout << endl;

	   	vector<int> idx = kmpMatch(text, pattern);
	   	for (int i: idx)
	   		cout << i << ' ';
	}
	return 0;
}
