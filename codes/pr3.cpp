//LoadBalancing
#include <iostream>
using namespace std;

class LoadBalancer {
    int n_servers;
    int hash_table[100];
    
public:
    LoadBalancer(int n) {
        n_servers = n;
        for (int i = 0; i < n_servers; i++) {
            hash_table[i] = 0;
        }
    }
    
    int hashFunction(int val) {
        return val % n_servers;
    }
    
    int processIP(char ip[]) {
        int sum = 0, num = 0;
        for (int i = 0; ip[i] != '\0'; i++) {
            if (ip[i] == '.') {
                sum += num;
                num = 0;
            } else {
                num = num * 10 + (ip[i] - '0');
            }
        }
        sum += num;
        return sum;
    }
    
    void insert(char ip[]) {
        int val = processIP(ip);
        int idx = hashFunction(val);
        int start = idx;
        
        while (hash_table[idx] != 0) {
            idx = (idx + 1) % n_servers;
            if (idx == start) {
                cout << "All servers are busy! Cannot assign " << ip << endl;
                return;
            }
        }
        
        hash_table[idx] = val;
        cout << "Request " << ip << " (sum = " << val 
             << ") is handled by Server " << idx << endl;
    }
    
    void display() {
        cout << "\nServer Load Summary:\n";
        for (int i = 0; i < n_servers; i++) {
            cout << "Server " << i << " <- ";
            if (hash_table[i] != 0) {
                cout << hash_table[i];
            } else {
                cout << "<empty>";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, r;
    cout << "Enter number of servers: ";
    cin >> n;
    cout << "Enter number of IP requests: ";
    cin >> r;
    
    LoadBalancer lb(n);
    
    for (int i = 0; i < r; i++) {
        char ip[50];
        cout << "Enter Request " << i + 1 << " IP: ";
        cin >> ip;
        lb.insert(ip);
    }
    
    lb.display();
    return 0;
}
