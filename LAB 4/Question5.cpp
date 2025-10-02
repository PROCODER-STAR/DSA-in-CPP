#include <iostream>
using namespace std;

struct Node {
    int seat;
    Node* next;
};

void insertEnd(Node*& head, int seat) {
    Node* newNode = new Node{seat, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->seat << " ";
        temp = temp->next;
    }
    cout << endl;
}

int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void listToArray(Node* head, int arr[]) {
    Node* temp = head;
    int i = 0;
    while (temp != nullptr) {
        arr[i++] = temp->seat;
        temp = temp->next;
    }
}

void arrayToList(Node*& head, int arr[]) {
    Node* temp = head;
    int i = 0;
    while (temp != nullptr) {
        temp->seat = arr[i++];
        temp = temp->next;
    }
}

void combSort(int arr[], int n) {
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped) {
        // Update gap
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;

        swapped = false;

        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

bool linearSearch(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->seat == key)
            return true;
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Enter number of booked seats: ";
    cin >> n;

    cout << "Enter booked seat numbers:\n";
    for (int i = 0; i < n; i++) {
        int seat;
        cin >> seat;
        insertEnd(head, seat);
    }

    cout << "\nBooked seats (original order): ";
    displayList(head);

    int size = countNodes(head);
    int* arr = new int[size];
    listToArray(head, arr);

    combSort(arr, size);

    arrayToList(head, arr);

    cout << "\nBooked seats (sorted): ";
    displayList(head);

    int key;
    cout << "\nEnter seat number to check availability: ";
    cin >> key;

    if (linearSearch(head, key)) {
        cout << "Seat " << key << " is already booked.\n";
    } else {
        cout << "Seat " << key << " is available.\n";
    }

    delete[] arr;
    return 0;
}
