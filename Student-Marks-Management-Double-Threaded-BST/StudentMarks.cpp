#include <iostream>
#include <string>
using namespace std;

const int N = 5;
const int S = 7;

string sub[S] = {"MSS", "DS", "DC", "ELM", "BA", "PMF", "CEP"};

struct Student {
    string name;
    int roll, marks[S];
} st[N];

struct Node {
    int idx;
    int marks;
    Node *left, *right;
    bool lt, rt; // true means thread; false means child link
};

Node* insert(Node* root, int i, int m) {
    Node* p = root;
    Node* par = NULL;

    while (p != NULL) {
        par = p;

        if (m < p->marks) {
            if (!p->lt)
                p = p->left;
            else
                break;
        } else {
            if (!p->rt)
                p = p->right;
            else
                break;
        }
    }

    Node* t = new Node{i, m, NULL, NULL, true, true};

    if (par == NULL) {
        root = t;
    } else if (m < par->marks) {
        t->left = par->left;
        t->right = par;
        par->lt = false;
        par->left = t;
    } else {
        t->right = par->right;
        t->left = par;
        par->rt = false;
        par->right = t;
    }

    return root;
}

// Reverse inorder traversal using threads: descending marks.
void displayDescending(Node* root) {
    Node* p = root;

    if (p == NULL) {
        cout << "No records available.\\n";
        return;
    }

    // Find the rightmost node, which has the highest marks.
    while (!p->rt)
        p = p->right;

    cout << "Roll\\tName\\t\\tMarks\\n";
    cout << "--------------------------------\\n";

    while (p != NULL) {
        cout << st[p->idx].roll << "\\t"
             << st[p->idx].name << "\\t\\t"
             << p->marks << "\\n";

        // Left thread points to the inorder predecessor.
        if (p->lt) {
            p = p->left;
        } else {
            // Move into the left subtree, then find its rightmost node.
            p = p->left;
            while (p != NULL && !p->rt)
                p = p->right;
        }
    }
}

void showSubject(int s) {
    Node* root = NULL;

    for (int i = 0; i < N; i++)
        root = insert(root, i, st[i].marks[s]);

    cout << "\\n" << sub[s] << " Marks in Descending Order\\n";
    displayDescending(root);
}

int main() {
    cout << "STUDENT MARKS MANAGEMENT SYSTEM\\n";
    cout << "Using Double-Threaded Binary Search Tree\\n";

    for (int i = 0; i < N; i++) {
        cout << "\\nStudent " << i + 1 << "\\nName: ";
        getline(cin >> ws, st[i].name);

        cout << "Roll number: ";
        cin >> st[i].roll;

        for (int j = 0; j < S; j++) {
            cout << sub[j] << " marks (0-100): ";
            cin >> st[i].marks[j];

            while (st[i].marks[j] < 0 || st[i].marks[j] > 100) {
                cout << "Enter valid marks (0-100): ";
                cin >> st[i].marks[j];
            }
        }
    }

    int ch;
    do {
        cout << "\\n===== MENU =====\\n";
        for (int i = 0; i < S; i++)
            cout << i + 1 << ". Display " << sub[i] << "\\n";
        cout << "8. Display All Subjects\\n";
        cout << "9. Exit\\n";
        cout << "Enter your choice: ";
        cin >> ch;

        if (ch >= 1 && ch <= 7) {
            showSubject(ch - 1);
        } else if (ch == 8) {
            for (int i = 0; i < S; i++)
                showSubject(i);
        } else if (ch == 9) {
            cout << "Program ended.\\n";
        } else {
            cout << "Invalid choice!\\n";
        }
    } while (ch != 9);

    return 0;
}
