# C++ Linked List Tasks with Solutions

## Task 1: Create and Print a Linked List

### Problem:
Create a simple singly linked list and print all its elements.

<details>
<summary>Solution</summary>

```cpp
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};

    printList(head);

    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
```

</details>

### Output:
```
1 -> 2 -> 3 -> NULL
```

---

## Task 2: Insert a Node at the Beginning

### Problem:
Write a function to insert a new node at the beginning of a linked list.

<details>
<summary>Solution</summary>

```cpp
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);

    printList(head);

    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
```

</details>

### Output:
```
1 -> 2 -> 3 -> NULL
```

---

## Task 3: Delete a Node by Value

### Problem:
Write a function to delete the first occurrence of a given value in the linked list.

<details>
<summary>Solution</summary>

```cpp
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteNode(Node*& head, int key) {
    if (!head) return;

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next && current->next->data != key) {
        current = current->next;
    }

    if (current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, nullptr}}};

    cout << "Before deletion: ";
    printList(head);

    deleteNode(head, 2);

    cout << "After deletion: ";
    printList(head);

    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
```

</details>

### Output:
```
Before deletion: 1 -> 2 -> 3 -> NULL
After deletion: 1 -> 3 -> NULL
```

---

## Task 4: Reverse a Linked List

### Problem:
Write a function to reverse a linked list.

<details>
<summary>Solution</summary>

```cpp
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, nullptr}}};

    cout << "Original list: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
```

</details>

### Output:
```
Original list: 1 -> 2 -> 3 -> NULL
Reversed list: 3 -> 2 -> 1 -> NULL
```

---

