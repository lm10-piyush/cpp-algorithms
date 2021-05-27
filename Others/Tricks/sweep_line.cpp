/*
 * It is like normal traversal we generally do on array, eg, moving left to right.
 * Here we maintain some data structure also while traversing the items.
 * The term SWEEP LINE, you mainly heard in geometry points or segments problem, and the solution is same as above described, first order them,
  move in one direction, maintain some data structure and answer the queries.
 * There is concept of event. An event means a point or segement where you do some operations, because there could be infinte points we just use some of them
   mainly given of them and call them events, eg: given segments, we call events: 1) start of the segment, 2) end of the segment.
   So, first order the points, moving left to right, maintaining the data structure and do some operation on events.

 * Resource and diagram how it works: https://en.wikipedia.org/wiki/Sweep_line_algorithm
 * Resources:
   https://www.topcoder.com/thrive/articles/Line%20Sweep%20Algorithms
   https://cp-algorithms.com/geometry/intersecting_segments.html
   https://codeforces.com/blog/entry/20377
   https://www.hackerearth.com/practice/math/geometry/line-sweep-technique/tutorial/
   https://www.youtube.com/watch?v=_zYMsx4iOSc         (parvel marvin, A&DS S02E04. 2D Segment Tree Problems)

 * A basic problem:
   https://www.e-olymp.com/en/contests/20844/problems/226453
   soln: https://pastebin.com/4usTnV3h
   There are more problems on segments, checkout my Adhocs.txt file.
   some more: https://www.e-olymp.com/en/contests/20844
 * Another little bit better problem: find the area of the union of rectangles, all reactangles are at same base level. :
   link: https://www.e-olymp.com/en/contests/20844/problems/226456
   soln: https://pastebin.com/BRWq31FC


*/