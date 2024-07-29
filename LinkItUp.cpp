#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int position, int data) {
        if (position < 1) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* newNode = new Node(data);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int position) {
        if (position < 1 || head == nullptr) {
            cout << "Invalid position or list is empty" << endl;
            return;
        }
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }

    int searchByIndex(int index) {
        if (index < 1) {
            cout << "Invalid index" << endl;
            return -1;
        }
        Node* temp = head;
        for (int i = 1; i < index && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Index out of bounds" << endl;
            return -1;
        }
        return temp->data;
    }

    int searchByValue(int value) {
        Node* temp = head;
        int index = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    int length() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int position, int data) {
        if (position < 1) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* newNode = new Node(data);
        if (position == 1) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteAtPosition(int position) {
        if (position < 1 || head == nullptr) {
            cout << "Invalid position or list is empty" << endl;
            return;
        }
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp;
        }
        delete nodeToDelete;
    }

    void reverse() {
        Node* temp = nullptr;
        Node* current = head;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }

    int searchByIndex(int index) {
        if (index < 1) {
            cout << "Invalid index" << endl;
            return -1;
        }
        Node* temp = head;
        for (int i = 1; i < index && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Index out of bounds" << endl;
            return -1;
        }
        return temp->data;
    }

    int searchByValue(int value) {
        Node* temp = head;
        int index = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    int length() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAtPosition(int position, int data) {
        if (position < 1) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* newNode = new Node(data);
        if (position == 1) {
            if (head == nullptr) {
                head = newNode;
                head->next = head;
                return;
            }
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            head = newNode;
            temp->next = head;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp->next == head) {
            cout << "Position out of bounds" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* nodeToDelete = head;
        head = head->next;
        temp->next = head;
        delete nodeToDelete;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
    }

    void deleteAtPosition(int position) {
        if (position < 1 || head == nullptr) {
            cout << "Invalid position or list is empty" << endl;
            return;
        }
        if (position == 1) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Node* nodeToDelete = head;
            head = head->next;
            temp->next = head;
            delete nodeToDelete;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp->next == head) {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void reverse() {
        if (head == nullptr || head->next == head) {
            return;
        }
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);
        head->next = prev;
        head = prev;
    }

    void display() {
        if (head == nullptr) {
            cout << "Null" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "head" << endl;
    }

    int searchByIndex(int index) {
        if (index < 1) {
            cout << "Invalid index" << endl;
            return -1;
        }
        Node* temp = head;
        for (int i = 1; i < index && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp->next == head) {
            cout << "Index out of bounds" << endl;
            return -1;
        }
        return temp->data;
    }

    int searchByValue(int value) {
        if (head == nullptr) {
            return -1;
        }
        Node* temp = head;
        int index = 1;
        do {
            if (temp->data == value) {
                return index;
            }
            temp = temp->next;
            index++;
        } while (temp != head);
        return -1;
    }

    int length() {
        if (head == nullptr) {
            return 0;
        }
        Node* temp = head;
        int count = 1;
        while (temp->next != head) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

void displayMenu() {
    cout << "1. Singly Linked List" << endl;
    cout << "2. Doubly Linked List" << endl;
    cout << "3. Circular Linked List" << endl;
    cout << "Select Linked List Type:";
}

int main() {
    int choice;
    displayMenu();
    cin >> choice;

    SinglyLinkedList singlyLinkedList;
    DoublyLinkedList doublyLinkedList;
    CircularLinkedList circularLinkedList;

    while (true) {
        cout << "\nLinked List Operations:" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete at beginning" << endl;
        cout << "5. Delete at end" << endl;
        cout << "6. Delete at position" << endl;
        cout << "7. Reverse" << endl;
        cout << "8. Display" << endl;
        cout << "9. Search by index" << endl;
        cout << "10. Search by value" << endl;
        cout << "11. Length" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        int operation;
        cin >> operation;

        int data, position, index, value;
        switch (operation) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                if (choice == 1) {
                    singlyLinkedList.insertAtBeginning(data);
                } else if (choice == 2) {
                    doublyLinkedList.insertAtBeginning(data);
                } else {
                    circularLinkedList.insertAtBeginning(data);
                }
                break;
            case 2:
                cout << "Enter data to insert: ";
                cin >> data;
                if (choice == 1) {
                    singlyLinkedList.insertAtEnd(data);
                } else if (choice == 2) {
                    doublyLinkedList.insertAtEnd(data);
                } else {
                    circularLinkedList.insertAtEnd(data);
                }
                break;
            case 3:
                cout << "Enter position to insert: ";
                cin >> position;
                cout << "Enter data to insert: ";
                cin >> data;
                if (choice == 1) {
                    singlyLinkedList.insertAtPosition(position, data);
                } else if (choice == 2) {
                    doublyLinkedList.insertAtPosition(position, data);
                } else {
                    circularLinkedList.insertAtPosition(position, data);
                }
                break;
            case 4:
                if (choice == 1) {
                    singlyLinkedList.deleteAtBeginning();
                } else if (choice == 2) {
                    doublyLinkedList.deleteAtBeginning();
                } else {
                    circularLinkedList.deleteAtBeginning();
                }
                break;
            case 5:
                if (choice == 1) {
                    singlyLinkedList.deleteAtEnd();
                } else if (choice == 2) {
                    doublyLinkedList.deleteAtEnd();
                } else {
                    circularLinkedList.deleteAtEnd();
                }
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                if (choice == 1) {
                    singlyLinkedList.deleteAtPosition(position);
                } else if (choice == 2) {
                    doublyLinkedList.deleteAtPosition(position);
                } else {
                    circularLinkedList.deleteAtPosition(position);
                }
                break;
            case 7:
                if (choice == 1) {
                    singlyLinkedList.reverse();
                } else if (choice == 2) {
                    doublyLinkedList.reverse();
                } else {
                    circularLinkedList.reverse();
                }
                break;
            case 8:
                if (choice == 1) {
                    singlyLinkedList.display();
                } else if (choice == 2) {
                    doublyLinkedList.display();
                } else {
                    circularLinkedList.display();
                }
                break;
            case 9:
                cout << "Enter index to search: ";
                cin >> index;
                if (choice == 1) {
                    cout << "Data at index " << index << " is " << singlyLinkedList.searchByIndex(index) << endl;
                } else if (choice == 2) {
                    cout << "Data at index " << index << " is " << doublyLinkedList.searchByIndex(index) << endl;
                } else {
                    cout << "Data at index " << index << " is " << circularLinkedList.searchByIndex(index) << endl;
                }
                break;
            case 10:
                cout << "Enter value to search: ";
                cin >> value;
                if (choice == 1) {
                    cout << "Index of value " << value << " is " << singlyLinkedList.searchByValue(value) << endl;
                } else if (choice == 2) {
                    cout << "Index of value " << value << " is " << doublyLinkedList.searchByValue(value) << endl;
                } else {
                    cout << "Index of value " << value << " is " << circularLinkedList.searchByValue(value) << endl;
                }
                break;
            case 11:
                if (choice == 1) {
                    cout << "Length of the list is " << singlyLinkedList.length() << endl;
                } else if (choice == 2) {
                    cout << "Length of the list is " << doublyLinkedList.length() << endl;
                } else {
                    cout << "Length of the list is " << circularLinkedList.length() << endl;
                }
                break;
            case 12:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
