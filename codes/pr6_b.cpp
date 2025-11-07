//Printer Spooler(Circular Queue)
#include <iostream>
#include <string>
using namespace std;
#define SIZE 5
string jobs[SIZE];
int front = -1, rear = -1;
void insertJob() {
 if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
 cout << "\nSorry... Spooler is FULL!" << endl;
 return;
 }
 string job;
 cout << "\nEnter print job name: ";
 cin >> job;

 if (front == -1) front = 0;
 rear = (rear + 1) % SIZE;
 jobs[rear] = job;
 cout << "Print job \"" << job << "\" added to the spooler." << endl;
}
void deleteJob() {
 if (front == -1) {
 cout << "\nSorry... Spooler is EMPTY!" << endl;
 return;
 }
 cout << "Processing print job: \"" << jobs[front] << "\"" << endl;

 if (front == rear) front = rear = -1;
 else front = (front + 1) % SIZE;
}
void showJobs() {
 if (front == -1) {
 cout << "\nSorry... Spooler is EMPTY!" << endl;
 return;
 }
 cout << "\nCurrent Print Queue: ";
 for (int i = front; ; i = (i + 1) % SIZE) {
 cout << "\"" << jobs[i] << "\"";
 if (i == rear) break;
 cout << " -> ";
 }
 cout << endl;
}
int main() {
 int choice;
 while (1) {
 cout << "\n--- Printer Spooler Menu ---\n"
 << "1. Add Print Job\n2. Process Print Job\n"
 << "3. Show All Print Jobs\n4. Exit\n"
 << "Enter your choice: ";
 cin >> choice;

 if (choice == 1) insertJob();
 else if (choice == 2) deleteJob();
 else if (choice == 3) showJobs();
 else if (choice == 4) exit(0);
 else cout << "\nInvalid choice!" << endl;
 }
 return 0;
}
