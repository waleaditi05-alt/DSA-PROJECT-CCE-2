# Student Marks Management System Using Double-Threaded BST

## Problem Statement
Develop a student marks management system using a double-threaded Binary Search Tree (BST) to display students' marks in descending order by using left threads.

## Objectives
- Store student names, roll numbers, and marks in seven subjects.
- Construct a double-threaded BST for each subject.
- Display subject marks in descending order.
- Use threads to traverse the tree without recursion or an auxiliary stack.
- Validate marks so they remain between 0 and 100.

## Subjects
- MSS
- DS
- DC
- ELM
- BA
- PMF
- CEP

## Data Structure Used
A double-threaded Binary Search Tree stores links to child nodes and uses otherwise-null pointers as threads. In this program, `lt` and `rt` indicate whether the left and right pointers are threads (`true`) or child links (`false`).

## Operations
1. Enter records for five students.
2. Display one subject's marks in descending order.
3. Display all subjects' marks in descending order.
4. Exit.

## Concepts Used
- C++
- Double-threaded Binary Search Tree
- Structures and pointers
- Dynamic memory allocation
- Thread-based traversal
- Descending-order traversal
- Input validation

## Algorithm
1. Start the program.
2. Read each student's name, roll number, and marks for all seven subjects.
3. Validate each mark to ensure it is in the range 0–100.
4. Display the menu.
5. For the selected subject, insert each student's marks into a double-threaded BST.
6. Find the rightmost node, which contains the highest marks.
7. Display the current node and move to its inorder predecessor using the left thread or by entering its left subtree and finding the rightmost node.
8. Continue until all nodes have been displayed in descending order.
9. Repeat until the user selects Exit.
10. Stop the program.

## How to Compile and Run

Using g++:
```bash
g++ StudentMarks.cpp -o StudentMarks
./StudentMarks
```

On Windows:
```bash
g++ StudentMarks.cpp -o StudentMarks.exe
StudentMarks.exe
```

## Sample Output (illustrative)
```text
MSS Marks in Descending Order
Roll    Name            Marks
--------------------------------
105     Student Five    95
102     Student Two     88
104     Student Four    76
101     Student One    65
103     Student Three  52
```

*The sample values above are illustrative. Actual output depends on the marks entered by the user.*

## Advantages
- Displays marks in descending order.
- Uses threads to support traversal without recursion or a separate stack.
- Supports multiple subjects.
- Checks that marks are within the valid range.

## Limitations
- The program accepts five students and seven subjects, as defined by `N` and `S`.
- Records are stored in memory and are not saved after the program exits.
- A separate tree is constructed each time a subject is displayed.

## Conclusion
The project demonstrates how a double-threaded Binary Search Tree can be used to organize student marks and display them in descending order. It uses threaded traversal to move through the tree without recursive traversal or an auxiliary stack.
