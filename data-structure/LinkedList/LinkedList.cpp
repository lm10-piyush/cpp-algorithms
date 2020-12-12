#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

struct Node {
    int data;
    Node *next;
    Node(int a) { //constructor
        data = a;
        next = NULL;
    }
};

//to print the nodes
void printNode(Node *head) {
    while (head != NULL) {
        cout << head->data << ' ';
        head = head->next;
    }
}

void insertAtBegining(Node * &head, int val) {
    Node *node = new Node(val);
    node->next = head;  
    head = node;
}

void insertAtEnd(Node * &head, int val) {
    Node *node = new Node(val);
    if (head == NULL) {
        head = node;
        return;
    }
    Node *curr = head; 
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = node;
}

void deleteBegininig(Node * &head) {
    if (head == NULL) return;
    Node *curr = head;
    head = head->next;
    delete curr;
    curr = NULL;
}

void deleteEnd(Node * &head) {
    if (head == NULL) return;
    Node *curr = head, *prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    delete curr;
    curr = NULL;
    if (prev == NULL) head = NULL;
    else prev->next = NULL;
}


void reverseList(Node * &head) {
    if (head == NULL) return;
    Node *prev = NULL, *curr = head;
    while (curr != NULL) {
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev; //prev will point the last end
}

//middle node of the linked list
Node *middle(Node *head) {
    if (head == nullptr) return head;
    Node *slow = head, *fast = head;
    while (fast != nullptr and fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n; //number of nodes
    int val;
    Node *head = NULL;

    for (int i = 0; i < n; ++i) {
        cin >> val;             //input the value
        insertAtBegining(head, val);  //insert at the beginging
    }
    //print the nodes
    printNode(head);
    cout << endl;

    //insert at the end, 'n' nodes
    for (int i = 0; i < n; ++i) {
        cin >> val;
        insertAtEnd(head, val); //insert at the end
    }

    //print the nodes
    printNode(head);
    cout << endl;
    
    deleteBegininig(head); //delete begining
    
    //print the nodes
    printNode(head);
    cout << endl;

    deleteEnd(head); //delete the end Node

    //print the nodes
    printNode(head);
    cout << endl;

    reverseList(head);  //reverse the linked list

    printNode(head);

    return 0;
}

//https://leetcode.com/problems/linked-list-cycle/  (Cycle finding by Floywarshall tortoise, hare)
//https://leetcode.com/problems/reverse-linked-list/  (reverse the linked list)
//https://leetcode.com/problems/reverse-linked-list-ii/  (https://pastebin.com/Ddu1hKAL)
//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/  (Divide and conquer)
//https://leetcode.com/problems/sort-list/          (Sort the linked list in O(n.logn), O(1) space, divide and conquer, merge sort, https://pastebin.com/BFQRwCJF)
//https://leetcode.com/problems/intersection-of-two-linked-lists/
//https://leetcode.com/problems/odd-even-linked-list/
//https://leetcode.com/problemset/all/?search=Linked%20list
// https://leetcode.com/problems/palindrome-linked-list/  (solution is combined with reverse at the midle, https://pastebin.com/6YW48eJN)
//https://www.interviewbit.com/problems/add-two-numbers-as-lists/  (soln: https://pastebin.com/5yVDc7Yb)
//https://leetcode.com/problems/add-two-numbers-ii/  (soln: https://pastebin.com/i7wTkuJP)
//https://leetcode.com/problems/middle-of-the-linked-list/
//https://leetcode.com/problems/reorder-list/     (middle find and reverse, https://pastebin.com/m3K4vNxG)
//https://leetcode.com/problems/reverse-linked-list-ii/  (https://pastebin.com/27ftfb6Z)
// https://leetcode.com/problems/reverse-nodes-in-k-group/  (reverse and some corner casesoln: https://pastebin.com/uXdR0DHa)
//https://www.interviewbit.com/problems/reverse-alternate-k-nodes/   (reverse, https://pastebin.com/Jw1e0pzZ)
//https://www.interviewbit.com/problems/kth-node-from-middle/    (reverse, https://pastebin.com/Dm4GsCE6)