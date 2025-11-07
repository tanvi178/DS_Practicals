//Organizing Cards in Hand
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of cards: ";
    cin >> n;
    int cards[n];
    
    cout << "\nEnter the card values:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nCard " << i + 1 << ": ";
        cin >> cards[i];
    }
    
    cout << "\n\nOrganizing Cards Using Insertion Sort:\n";
    for (int i = 1; i < n; i++) {
        int key = cards[i];
        int j = i - 1;
        
        while (j >= 0 && cards[j] > key) {
            cards[j + 1] = cards[j];
            j--;
        }
        cards[j + 1] = key;
        
        cout << "\nAfter inserting card " << cards[i] << ": ";
        for (int k = 0; k <= i; k++) {
            cout << cards[k] << " ";
        }
        cout << "\n";
    }
    
    cout << "\n\nFinal Sorted Hand:\n\n";
    for (int i = 0; i < n; i++) {
        cout << cards[i] << " ";
    }
    cout << endl;
    
    return 0;
}
