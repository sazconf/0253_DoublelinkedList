#include <iostream>
using namespace std;

// membuat struktur untuk object double linkedList
struct Node {
    int noMHS;
    string name;
    Node* next;
    Node* prev;
};

// deklarasi pointer START dan pemberian nilai
Node* START = NULL;

// deklarasi prosedur addnode
void addnode() {
    Node* newNode = new Node(); 
    cout << "\nEnter the roll number of the student : ";
    cin >> newNode->noMHS; 
    cout << "\nEnter the name of the student : ";
    cin >> newNode->name;

    if (START == NULL || newNode->noMHS <= START->noMHS) {
        if (START != NULL && newNode->noMHS == START->noMHS) {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            delete newNode; 
            return;
        }
        newNode->next = START; 
        if (START != NULL) {
            START->prev = newNode;
        }
        newNode->prev = NULL; 
        START = newNode; 
    } else {
        Node* current = START; 
        Node* previous = NULL; 
        while (current != NULL && current->noMHS < newNode->noMHS) {
            previous = current;
            current = current->next;
        }
        newNode->next = current; 
        newNode->prev = previous; 
        if (current != NULL) {
            current->prev = newNode; 
        }
        if (previous != NULL) {
            previous->next = newNode; 
        } else {
            START = newNode;
        }
    }
}

// pembuatan  function search untuk mencari data
bool search(int rollNo, Node **previous, Node **current) {
    *previous = *current;
    *current = START;
    while (*current != NULL && (*current)->noMHS != rollNo) {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

// prosedur delete untuk menghapus data
void deletenode() {
    Node *previous, *current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be delete  : ";
    cin >> rollNo;

    if (START == NULL) {
        cout << "list is empty" << endl;
        return;
    }

    current = START; 
    previous = NULL; 

    while (current != NULL && current->noMHS != rollNo) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "\033[31mThe record with roll number " 
        << rollNo << " not found\033[0m" <<endl;
        return;
    }

    if (current == START) {  // fixed the condition
        START = START->next; 
        if (START != NULL) {
            START->prev = NULL;
        }
    } else {
        previous->next = current->next;
        if (current->next != NULL) {
            current->next->prev = previous;
        }
    }

    delete current; // free the memory of the deleted node
}

// method untuk mencek apakah list kosong
bool listEmpty() {
    return (START == NULL);
}

// prosedur traverse untuk menampilkan data secara urut
void traverse() {
    if (listEmpty()) {
        cout << "\nList is empty" << endl;
    } else {
        cout << "\nRecords in ascending order of roll number are:" << endl;
        Node* currentNode = START;
        while (currentNode != NULL) {  // corrected loop logic to print the list
            cout << currentNode->noMHS << " " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}

// reverse traverse
void revtraverse() {
    if (listEmpty()) {
        cout << "\nList is empty" << endl;
    } else {
        cout << "\nRecords in descending order of roll number are:" << endl;
        Node* currentNode = START;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        while (currentNode != NULL) {
            cout << currentNode->noMHS << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}

// search data
void searchData() {
    if (listEmpty()) {
        cout << "\nList is empty" << endl;
        return;
    }

    Node *prev, *curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record you want to search:";
    int num;
    cin >> num;
    if (search(num, &prev, &curr) == false) {
        cout << "\nRecord not found" << endl;
    } else {
        cout << "\nRecord found" << endl;
        cout << "\nRoll number: " << curr->noMHS << endl;
        cout << "\nName: " << curr->name << endl;
    }
}

int main() {
    while (true) {
        try {
            cout << "\nMenu" << endl;
            cout << "1. Add a record to the list " << endl;
            cout << "2. Delete a record" << endl;
            cout << "3. View all records in the ascending order of Roll number" << endl;
            cout << "4. View all records in the descending order of Roll number" << endl;  // fixed typo
            cout << "5. Search for a record" << endl;
            cout << "6. Exit";
            cout << "\nEnter your choice(1-6):";
            char ch;
            cin >> ch;

            switch (ch) {
                case '1':
                    addnode();
                    break;
                case '2':
                    deletenode();
                    break;
                case '3':
                    traverse();
                    break;
                case '4':
                    revtraverse();
                    break;
                case '5':
                    searchData();
                    break;
                case '6':
                    return 0;
                default:
                    cout << "\nInvalid choice" << endl;
                    break;
            }
        } catch(exception &e) {
            cout << "Check for the values entered. " << endl;
        }
    }
}
