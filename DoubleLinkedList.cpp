#include <iostream>
using namespace std;

// membuat struktur untuk object double linkedList
struct Node {
    // deklarasi noMHS dan name untuk menampung data
    int noMHS;
    string name;
    // deklarasi pointer next dan prev untuk data sebelum dan sesudah
    Node* next;
    Node* prev;
};

// deklarasi pointer START dan pemberian nilai
Node* START = NULL;

// deklarasi prosedur addnode
void addnode() {
    // pembuatan node dan pemberian value untuk data noMHS dan name
    Node* newNode = new Node(); // step 1 buat node baru
    cout << "\nEnter the roll number of the student : ";
    cin >> newNode->noMHS; // assign value to the data field of the new node
    cout << "\nEnter the name of the student : ";
    cin >> newNode->name; // Assign value to the data field of the new node

    // Insert the new node in the list
    // kondisi jika START == NULL atau noMHS node baru <= noMHS START
    if (START == NULL || newNode->noMHS <= START->noMHS) {
        // step 2: insert the new node at the beginning
        // kondisi jika START tidak kosong dan noMHS node baru sama dengan noMHS START
        if (START != NULL && newNode->noMHS == START->noMHS) {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            delete newNode; // to free the allocated memory for the new node
            return;
        }
        // if the list is empty, make the new node the start
        newNode->next = START; // step 3: make the new node point to the first node
        if (START != NULL) {
            START->prev = newNode; // step 4: make the first node point to the new node
        }
        newNode->prev = NULL; // step 5 : make the new node's prev pointer null
        START = newNode; // step 6 : make the new node the first node
    }
    else {
        
    }
}


