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
    Node *prev = NULL, *curr = head, *next = head->next;
    while (curr != NULL) {
        curr->next = prev;
        head = curr;
        prev = curr;
        curr = next;
        if (next != NULL)
            next = next->next;
    }
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