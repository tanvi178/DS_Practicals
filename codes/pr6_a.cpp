//Coffee Shop (Simple Queue)
#include <iostream>
#include <string>
using namespace std;
#define MAX 10
class Queue {
 string arr[MAX];
 int front, rear;
public:
 Queue() : front(0), rear(-1) {}

 void enqueue(string name) {
 if (rear == MAX - 1) cout << "Queue is full. Cannot add more customers.\n";
 else cout << (arr[++rear] = name) << " joined the line.\n";
 }

 void dequeue() {
 if (front > rear) cout << "No customers in line.\n";
 else cout << arr[front++] << "'s order is ready. They leave the line.\n";
 }

 void display() {
 if (front > rear) cout << "The line is empty.\n";
 else {
 cout << "Current Line: ";
 for (int i = front; i <= rear; i++)
 cout << arr[i] << (i < rear ? " -> " : "\n");
 }
 }
};
int main() {
 Queue q;
 int choice;
 string name;
 do {
 cout << "\n--- Coffee Shop Queue Menu ---\n"
 << "1. New Customer Arrival (Enqueue)\n"
 << "2. Serve Customer (Dequeue)\n"
 << "3. Show Queue\n4. Exit\n"
 << "Choose an option: ";
 cin >> choice;

 if (choice == 1) {
 cout << "Enter customer name: ";
 cin >> name;
 q.enqueue(name);
 } else if (choice == 2) q.dequeue();
 else if (choice == 3) q.display();
 else if (choice == 4) cout << "Exiting... Thank you!\n";
 else cout << "Invalid option. Try again.\n";
 } while (choice != 4);

 return 0;
}
