#include <iostream>
#include <algorithm>
using namespace std;

int optimalMerge(int files[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (files[j] > files[j + 1]) {
                swap(files[j], files[j + 1]);
            }
        }
    }
    int cost = 0;
    while (n > 1) {
        int mergedFileSize = files[0] + files[1];
        cost += mergedFileSize;
        files[0] = mergedFileSize;
        for (int i = 1; i < n - 1; i++) {
            files[i] = files[i + 1];
        }
        n--; 
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (files[j] > files[j + 1]) {
                    swap(files[j], files[j + 1]);
                }
            }
        }
    }
    return cost;
}
int main() {
    int files[] = {5, 10, 20, 30, 30};
    int n = sizeof(files) / sizeof(files[0]);
    cout<<"Number of files: "<<n<<endl;
    cout<<"Size of files: ";
    for (int i = 0; i < n; i++){
        cout<<files[i]<<" ";
    }
    cout<<endl;
    int minCost = optimalMerge(files, n);
    cout << "Minimum cost of merging is: " << minCost << " Comparisons\n";
    return 0;
}