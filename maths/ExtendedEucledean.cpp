#include<bits/stdc++.h>
using namespace std;

// a.x + b.y = g, where g = gcd(a, b)
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


/*
 NOTE:
 * We can use Extended Euclidean theorem for solving the Diaphotine equation: a.x + b.y = c. To do that use above theorem and calculate x', y':
   a.x' + b.y' = g, where g = gcd(a, b)
	if (c % g != 0) return -1; //that means no solution exists for the equation.
   
   So, that means it have infinitely many solutions,
   To get the first solution: x = x' * c / g, y = x' * c / g.

	To get the many solutions: suppose x', y' are the solution of diaphotine equation.
	then further solutions: x = x' + k.b/g, y = y' - k.a/g.

 * We can the modulo multiplicative inverse of A under modulo M, then use the extendend euclidean theorem as:
   A.x + M.y = d, where d = gcd(A, M), and d == 1 (must) otherwise no solution.
   Suppose solution is:
   A.x' + M.y' = 1,
   Apply modulo M on both sides: 
   A.x' = 1
   x' = (x' + M) % M
   x' => will be the modulo multiplicative inverse.

   We can use the Fermat Little theorem to calcualte the Modulo multiplicative inverse but M should be prime and gcd(A, M) = 1.
   then, inv = power(A, M-2)

*/

/*
https://atcoder.jp/contests/abc186/tasks/abc186_e
https://atcoder.jp/contests/abc186/submissions/18922280

*/