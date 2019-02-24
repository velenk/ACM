#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        string name[n] = { };
        int ri[n] = { };
        int vi[n] = { };
        int pi[n] = { };
        int bi[n] = { };
        double ei[n] = { };
        for (int i =0; i < n; ++i) {
            cin >> name[i] >> ri[i] >> vi[i] >> pi[i] >> bi[i];
        }
        /*for (int i =0; i < n; ++i) {
            double sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += 1./(exp((ri[i]-ri[j])/218.) + 1);
            }
            ei[i] = .5 + sum;
        }*/
        int newri[n] = { };
        for (int i = 0; i < n; ++i) {
            double temp = ri[i] + bi[i];
            newri[i] = (int)(temp);
        }
        int test[n] = { };
        int nowmax = 0;
        int nowname = 0;
        for (int i = 0; i < n; ++i) {
        nowmax = -1e8;
        nowname = 0;
        for (int j = 0; j < n; ++j) {
            if (test[j] == 0) {
                if (newri[j] > nowmax) {
                    nowmax = newri[j];
                    nowname = j;
                } else if (newri[j] == nowmax) {
                    if (name[j] < name[nowname]) {
                        nowmax = newri[j];
                        nowname = j;
                    }
                }
            }
        }
        test[nowname] = 1;
        cout << name[nowname] << endl;
        }
    }
    return 0;
}
