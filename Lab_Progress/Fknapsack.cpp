#include <iostream>
using namespace std;

class fractional_knapsack {
    public:
        float wt[20], pt[20], profit = 0, y[20];
        int n, w;

        void getdata() {
            cout << "\nEnter the maximum weight of the bag: ";
            cin >> w;
            cout << "\nHow many objects you want to store inside the bag?";
            cin >> n;
            cout << "\nEnter the weights of objects: ";
            for (int i = 0; i < n; i++) {
                cin >> wt[i];
            }
            cout << "\nEnter the profits of objects: ";
            for (int i = 0; i < n; i++) {
                cin >> pt[i];
            }
            cout << endl;
        }

        void sortdata() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if ((pt[j] / wt[j]) < (pt[j + 1] / wt[j + 1])) {
                        float temp = pt[j];
                        pt[j] = pt[j + 1];
                        pt[j + 1] = temp;
                        temp = wt[j];
                        wt[j] = wt[j + 1];
                        wt[j + 1] = temp;
                    }
                }
            }
        }

        void calculation() {
            profit = 0;
            for (int i = 0; i < n; i++) {
                if (wt[i] <= w) {
                    y[i] = 1.0;
                    profit += pt[i];
                    w -= wt[i];
                } else {
                    y[i] = w / wt[i];
                    profit += pt[i] * y[i];
                    break;
                }
            }
        }

        void displaydata() {
            cout << "-----------------------------------------------------\n";
            cout << "Object no.\t\tWeight\t\tProfit\t\tFraction\n";
            cout << "-----------------------------------------------------\n";
            for (int i = 0; i < n; i++) {
                cout << i + 1 << "\t\t" << wt[i] << "\t\t" << pt[i] << "\t\t" << y[i] << endl;
            }
            cout << "Maximum profit: " << profit << endl;
        }
};

int main() {
    fractional_knapsack obj;
    obj.getdata();
    obj.sortdata();
    obj.calculation();
    obj.displaydata();
    return 0;
}