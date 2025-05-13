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

