// 4NIMBelakang_DoublelinkedList
#include <iostream>
using namespace std;

// membuat struktur untuk object double linkedList
struct Node {
    // deklarasi noMHS dan name untuk menampung data
    int noMHS;
    string name;
    // deklarasi pointer next dan pref untuk data sebelum dan sesudah
    Node*next;
    Node*prev;
};

// deklarasi pointer START dan pemberian nilai
Node*START = NULL;

// deklarasi prosedur addnote
void addnode() {

    // pembuatan node dan pemberian value untuk data noMHS dan name 
    Node *newNode = new Node(); // step 1 buat node baru
    cout << "\nEnter the roll number of the student : ";
    cin >> newNode->noMHS; // assign value to the data field of the new node
    cout << "\nEnter the same of the student : ";
    cin >> newNode->name; // Assign value to the data field of th

    
}