#include<bits/stdc++.h>
using namespace std;

// a.x + b.y = d
int gcd(int a, int b, int &x, int &y){

	if(a == 0){
		y = 1;
		x = 0;
		return b;
	}

	int x1, y1;
	int d = gcd(b%a, a, x1, y1);

	x = y1 - (b/a)*x1;
	y = x1;

	return d;
}


int  main(){
	int a, b, x, y; cin >> a >> b;
	
	int d = gcd(a, b, x, y);
	cout << x << ' ' << y << ' ' << d;
}