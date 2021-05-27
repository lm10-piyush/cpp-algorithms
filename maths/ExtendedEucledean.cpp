#include<bits/stdc++.h>
using namespace std;

// a.x + b.y = g, where g = gcd(a, b)
int gcd(int a, int b, int &x, int &y) {

	if (a == 0) {
		y = 1;
		x = 0;
		return b;
	}

	int x1, y1;
	int d = gcd(b % a, a, x1, y1);

	x = y1 - (b / a) * x1;
	y = x1;

	return d;
}


int  main() {
	int a, b, x, y; cin >> a >> b;

	int d = gcd(a, b, x, y);
	cout << x << ' ' << y << ' ' << d;
}


/*
 NOTE:
 * Mod and gcd are inter-related, that means: gcd(a, b) == gcd(a+b, a) == gcd(a, b % a) == gcd(a, b - a). That means mod doesn't
  change the gcd between SAME numbers. Actually this is the main step of Eucleadean theorem which says: gcd(a, b) == gcd(a, r), where r = remainder = b % a.

 * NOTE: gcd(a, b) != gcd(a, b - x), x is any number. This is not allowed.... You cannot introduce any number from outside.

 *  Problem: Suppose there is an ant which jumps is initially at position '0' in a wheel of circumference 'm' and ant jumps with length 'a', then what
 	are the positions the ant can jump at??
 	Actually you need to find : y = (a*x) % m, find all y's.
 	Answer is gcd(a, m). Ant can be any of the place which are divisible by gcd(a, m).
 	Proof: Ant jumps: 0, 2*a % m, 3*a % m, .....
 	And we know gcd doesn't can with mod, so all these places would be multiple of gcd(a, m), so answer is places divisible of gcd(a, m).


 * We can use Extended Euclidean theorem for solving the Diaphotine equation: a.x + b.y = c. To do that use above theorem and calculate x', y':
   a.x' + b.y' = g, where g = gcd(a, b)
	if (c % g != 0) return -1; //that means no solution exists for the equation.

   So, that means it have infinitely many solutions,
   To get the first solution: x = x' * c / g, y = x' * c / g.

	To get the many solutions: suppose x', y' are the solution of diaphotine equation.
	then further solutions: x = x' + k.b/g, y = y' - k.a/g.

 * We can the modulo multiplicative inverse of A under modulo M, then use the extendend euclidean theorem as:
   A.x + M.y = d, where d = gcd(A, M, x', y'), and d == 1 (must) otherwise no solution (because as we know d will always be the multiple of gcd(a, b)
   because mod and gcd are inter-related).
   Suppose solution is:
   A.x' + M.y' = 1,
   Apply modulo M on both sides:
   A.x' = 1
   x' = (x' + M) % M
   x' => will be the modulo multiplicative inverse.

   We can use the Fermat's little theorem to calcualte the Modulo multiplicative inverse but M should be prime and gcd(A, M) = 1.
   then, inv = power(A, M-2)

 * Suppose 'x' is the inverse of 'n' under mod 'm', then it would be unique in range: [0, m). That means in this range [0, m), there exists atmost 1 multiplicative inverse.

*/

/*
https://atcoder.jp/contests/abc186/tasks/abc186_e
https://atcoder.jp/contests/abc186/submissions/18922280

*/