#h6 ---------------------------- RESOURCES --------------------------------------    

1. Don't use rand() function to generate the random numbers. It is not that much good to generate random 	numbers. Instead use this https://codeforces.com/blog/entry/61587 ,	https://www.geeksforgeeks.org/random-header-c-set-1generators/ .

2. Problems in hashing in c++ because they use std::hash to find the hash of the key, which use uses rand() function to produce a hash. And rand() is very frequent in to repeat the numbers. So, we use point 1 define technique to generate the unique hash every time and made our solution more accurate and unhackable https://codeforces.com/blog/entry/62393 .

3. INT_MAX, LLONG_MAX, UINT_MAX, ULLONG_MAX (different varients to get maximums). But don't use them instead use 		1e9, -1e9 or 1e18, -1e18.

4. Fastest integer factorization methods https://stackoverflow.com/questions/2267146/what-is-the-fastest-factorization-algorithm?rq=1 , https://cp-algorithms.com/algebra/factorization.html

5. Site to for resources of algorithms http://e-maxx.ru/algo/ . But it is in russion so, translator is needed. https://cp-algorithms.com/ It is English version of e-maxx

6. Time measurement in c++ by chrono https://www.geeksforgeeks.org/chrono-in-c/ , https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/ , https://www.geeksforgeeks.org/measure-execution-time-function-cpp/ , https://www.geeksforgeeks.org/measure-execution-time-function-cpp/ , https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/

7. codeforces c++ tricks and others resources: https://codeforces.com/blog/entry/57282 , 
	tricks in c++:  https://codeforces.com/blog/entry/74684
resources heavy: https://codeforces.com/blog/entry/23054
DS/Algo: https://codeforces.com/blog/entry/13529
some others but already covered above: https://codeforces.com/blog/entry/13520 , https://youtu.be/09_LlHjoEiY (free code camp graphs).


8. Sites for competitive programming https://blog.codingblocks.com/2019/sites-and-tools-for-competitive-programming/
 and setting an enviroment for c++ with some tricks  https://blog.codingblocks.com/2019/setting-up-a-c-competitive-programming-environment/ , https://codeforces.com/blog/entry/53909

9.  https://codeforces.com/blog/entry/55274 (A blog with all ques with topic wise)
	https://cses.fi/problemset/ for problems  (problem set)
10. Segment tree ques: https://codeforces.com/blog/entry/22616  

11. https://codeforces.com/blog/entry/20935 DP on trees

12. Permutation Tree: https://codeforces.com/blog/entry/78898

13. ICPC archive: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=0

14. https://codeforces.com/blog/entry/405  (Dont use %lld in C++14)

15. Optimation in C++ which passes Naive solutions (approx 10^9 iterations in 1-2sec): https://codeforces.com/blog/entry/66279, https://codeforces.com/blog/entry/89634?#comment-780234 

16. Hashing the sets and multisets: https://codeforces.com/blog/entry/85900

17. Nice resource for CP topics and problems: https://usaco.guide/dashboard