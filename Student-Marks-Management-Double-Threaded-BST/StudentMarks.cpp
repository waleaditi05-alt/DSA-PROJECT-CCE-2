#include <iostream>
#include <string>
using namespace std;

const int S = 7;
const int MAX = 50;

string sub[S] = {"MSS", "DS", "DC", "ELM", "BA", "PMF", "CEP"};

struct Student {
    string name;
    int roll, marks[S];
} st[MAX];

struct Node {
    int idx, marks;
    Node *left, *right;
    bool lt, rt;
};

int total = 0;

// Insert node into Double-Threaded BST
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
        t->left = par;
        t->right = par->right;
        par->rt = false;
        par->right = t;
    }

    return root;
}

// Display marks in descending order using left threads
void displayDescending(Node* root) {
    if (root == NULL) {
        cout << "No records available!\n";
        return;
    }

    Node* p = root;

    // Start from the highest marks
    while (!p->rt)
        p = p->right;

    cout << "\nRoll No.\tName\t\tMarks\n";
    cout << "--------------------------------------\n";

    while (p != NULL) {
        cout << st[p->idx].roll << "\t\t"
             << st[p->idx].name << "\t\t"
             << p->marks << "\n";

        if (p->lt) {
            p = p->left;
        } else {
            p = p->left;

            while (p != NULL && !p->rt)
                p = p->right;
        }
    }
}

void deleteTree(Node* root) {
    if (root == NULL)
        return;

    if (!root->lt)
        deleteTree(root->left);

    if (!root->rt)
        deleteTree(root->right);

    delete root;
}

// Enter a new student record
void addStudent() {
    if (total == MAX) {
        cout << "Student limit reached!\n";
        return;
    }

    int roll;

    cout << "Enter Roll Number: ";
    cin >> roll;

    if (roll <= 0) {
        cout << "Roll number must be positive!\n";
        return;
    }

    for (int i = 0; i < total; i++) {
        if (st[i].roll == roll) {
            cout << "Roll number already exists!\n";
            return;
        }
    }

    cout << "Enter Student Name: ";
    getline(cin >> ws, st[total].name);

    st[total].roll = roll;

    for (int j = 0; j < S; j++) {
        cout << "Enter " << sub[j] << " Marks (0-100): ";
        cin >> st[total].marks[j];

        while (st[total].marks[j] < 0 ||
               st[total].marks[j] > 100) {
            cout << "Invalid marks! Enter again: ";
            cin >> st[total].marks[j];
        }
    }

    total++;
    cout << "Student record added successfully!\n";
}

// Display one subject for all students
void showSubject(int s) {
    if (total == 0) {
        cout << "Please add student records first!\n";
        return;
    }

    Node* root = NULL;

    for (int i = 0; i < total; i++)
        root = insert(root, i, st[i].marks[s]);

    cout << "\n" << sub[s]
         << " Marks in Descending Order\n";

    displayDescending(root);
    deleteTree(root);
}

// Display all subjects
void showAllSubjects() {
    if (total == 0) {
        cout << "Please add student records first!\n";
        return;
    }

    for (int i = 0; i < S; i++)
        showSubject(i);
}

int main() {
    int ch;

    do {
        cout << "\n===== STUDENT MARKS MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display MSS Marks\n";
        cout << "3. Display DS Marks\n";
        cout << "4. Display DC Marks\n";
        cout << "5. Display ELM Marks\n";
        cout << "6. Display BA Marks\n";
        cout << "7. Display PMF Marks\n";
        cout << "8. Display CEP Marks\n";
        cout << "9. Display All Subjects\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                addStudent();
                break;
            case 2:
                showSubject(0);
                break;
            case 3:
                showSubject(1);
                break;
            case 4:
                showSubject(2);
                break;
            case 5:
                showSubject(3);
                break;
            case 6:
                showSubject(4);
                break;
            case 7:
                showSubject(5);
                break;
            case 8:
                showSubject(6);
                break;
            case 9:
                showAllSubjects();
                break;
            case 10:
                cout << "Program ended successfully!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (ch != 10);

    return 0;
}
