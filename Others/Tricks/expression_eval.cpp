#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


//Solution for simple expressions with +, -, *, /, brackets only binary operators and numbers.
class Solution {
public:
	ll calculate(string s) {
		int n = s.size();
		stack <ll> operands;
		stack <char> operators;
		auto priority = [](char a) {
			if (a == '+' or a == '-')
				return 1;
			else if (a == '(')
				return -1;
			return 2;
		};
		auto pop = [&]() {
			int b = operands.top(); operands.pop();
			int a = operands.top(); operands.pop();
			char x = operators.top(); operators.pop();
			ll res;
			if (x == '+')
				res = a + b;
			else if (x == '-')
				res  = a - b;
			else if (x == '*')
				res = a * b;
			else res = a / b;
			operands.push(res);
		};

		for (int i = 0; i < n; ++i) {
			if (s[i] == ' ') continue;
			if (isdigit(s[i])) {
				ll curr = 0;
				while (isdigit(s[i])) {
					curr = curr * 10 + s[i] - '0';
					i++;
				}
				operands.push(curr);
				i--;
			}
			else if (s[i] == '(' or s[i] == ')') {
				if (s[i] == '(') operators.push('('); //if it is open bracket
				else {
					while (operators.top() != '(')
						pop();
					operators.pop();  //poping out closing bracket
				}
			}
			else { //whenever you hit operator
				while (!operators.empty() and priority(operators.top()) >= priority(s[i])) //precdence check and associativity
					pop();
				operators.push(s[i]);
			}
		}
		while (!operators.empty())
			pop();
		return operands.top();

	}
};

//Solution with above solution  + right associative operators like unary operators
//Assuming expression is correct
class Solution2 {
public:
	ll calculate(string s) {
		int n = s.size();
		stack <ll> operands;
		stack <char> operators;
		bool isUnary = true;
		auto priority = [](char a) {
			if (a < 0)
				return 3;
			if (a == '+' or a == '-')
				return 1;
			else if (a == '*' or a == '/')
				return 2;
			return -1;
		};
		auto pop = [&]() {
			char x = operators.top(); operators.pop();
			ll res;
			if (x < 0) {
				int a = operands.top(); operands.pop();
				if ((-x) == '+')
					res = a;
				else res = -a;
			}
			else {
				int b = operands.top(); operands.pop();
				int a = operands.top(); operands.pop();
				if (x == '+')
					res = a + b;
				else if (x == '-')
					res  = a - b;
				else if (x == '*')
					res = a * b;
				else res = a / b;
			}
			operands.push(res);
		};

		auto right_assoc = [](char a) {
			return (a < 0); //unary operators are right associative
		};

		for (int i = 0; i < n; ++i) {
			if (s[i] == ' ') continue;
			if (isdigit(s[i])) {
				ll curr = 0;
				while (isdigit(s[i])) {
					curr = curr * 10 + s[i] - '0';
					i++;
				}
				operands.push(curr);
				i--;
				isUnary = false;
			}
			else if (s[i] == '(' or s[i] == ')') {
				if (s[i] == '(') {  //if it is open bracket
					operators.push('(');
					isUnary = true;
				}
				else {
					while (operators.top() != '(')
						pop();
					operators.pop();
					isUnary = false;
				}
			}
			else { //whenever you hit operator
				if (isUnary) {
					s[i] = -s[i];
				}

				while (!operators.empty() and ((!right_assoc(s[i]) and priority(operators.top()) >= priority(s[i]))
				                               or (right_assoc(s[i]) and priority(operators.top()) > priority(s[i]))
				                              )) //precdence check and associativity
					pop();
				operators.push(s[i]);
				isUnary = true;
			}
		}
		while (!operators.empty())
			pop();
		return operands.top();

	}
};



int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	string s; getline(cin, s);
	Solution sol;
	cout << sol.calculate(s) << endl;
	Solution2 sol2;
	cout << sol.calculate(s);


	return 0;
}


/*
 * Calculated using Postfix operation.
 Operator precedence:
brackets
Unary operators,  associativity: right to left
exponents, associativity: right to left, ex: 2^2^3 => 2^8 => 256
*, / => associativity: left to right
+, - => associativity: left to right

Humans use infix to solve calculations, but in computer we use either prefix or postfix because prefix and postfix are ordered according to
precedence and associativity. Postfix is generally preferred
because of easy to use and intiuitive

To maintain the precedence and associativity (left to right)
If an operator has strictly higher precedence than operator of top of the stack then just push the current one to the stack.
else pop operators which are higher or equal precedence to the current one.

caution in case of exponent, because above rule is good for left associativity not for right associativity.

Here in the code, we deal with +, -, *, /.
I've not exlicitly calculate the postfix, I just calculate on the go and at same time solving the equation.

https://introcs.cs.princeton.edu/java/11precedence/       (precedence)

In case of brackets, when you get open bracket just push it into the operators (because brackets have highest precedence),
now if you get other operand just treat the bracket as new begining without considering that new operator has lower precedence than bracket.
Treat each open bracket as new begining, go as you do left to right insert operands and operators normally you untill you get closing bracket.
You get closing one then just apply pop operation untill the corresponding opening bracket is popout.

Resource: https://cp-algorithms.com/string/expression_parsing.html

https://leetcode.com/problems/basic-calculator-ii/    (Basic operations, only binary operators and numbers)
https://pastebin.com/m8QPfEQy

https://leetcode.com/problems/basic-calculator/      (unary + binary operators, numbers, brackets)
https://pastebin.com/taVuWnxF
https://pastebin.com/CFJS8CSc

*/