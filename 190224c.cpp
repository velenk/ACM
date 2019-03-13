#include <iostream>
#include <cstdio>

using namespace std;

int day1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int day(int m, int y) {
    if (y%4 == 0 && y%100 != 0) {
        return day2[m];
    } else if (y%400 == 0) {
        return day2[m];
    } else {
        return day1[m];
    }
}

class Time {
public:
    int y;
    int m;
    int d;
    int h;
    int w;
    void print(int n) {
        cout << "Case #" << n << ": " << this->y << "/" << this->m << "/" << this->d << " " << this->h << endl;
    }
    Time operator+(const Time& b) {
        int tempm = this->m;
         Time temp = {0,0,0,0,0};
         temp.w = this->w;
         temp.h = this->h + b.h;
         temp.d = this->d;
         temp.m = this->m;
         temp.y = this->y;
         while (temp.h >= 24) {
             temp.h -= 24;
             temp.d++;
         }
         temp.d += b.d;
         temp.w = (temp.w+temp.d-this->d)%7;
         while (temp.d > day(tempm, this->y)) {
             temp.d -= day(tempm, this->y);
             temp.m++;
             tempm++;
             if (tempm >= 12) {
                 temp.y++;
                 tempm -= 12;
             }
         }
         temp.m += b.m;
         if (temp.m > 12) {
             temp.h -= 12;
             temp.y++;
         }
         return temp;
    }
    bool operator <(const Time& d) {
        if (this->y < d.y) {
            return true;
        }
        if (this->y == d.y && this->m < d.m) {
            return true;
        }
        if (this->y == d.y && this->m == d.m && this->d < d.d) {
            return true;
        }
        return false;
    }
};

int main() {
    int n;
    Time now;
    Time case0;
    Time addday;
    Time timego;
    Time daygo;
    
    timego.y = 0;
    timego.m = 0;
    timego.d = 0;
    timego.h = 1;
    timego.w = 0;
    
    daygo.y = 0;
    daygo.m = 0;
    daygo.d = 1;
    daygo.h = 0;
    daygo.w = 0;
    while (cin >> n) {
        
        now.y = 2001;
        now.m = 1;
        now.d = 1;
        now.h = 0;
        now.w = 0;
        
        
        addday.y = 0;
        addday.m = 0;
        addday.d = 0;
        addday.h = 0;
        addday.w = 0;
        
        int cost;
        for (int i = 0; i < n; ++i) {
            scanf("%d/%d/%d%d%d", &case0.y, &case0.m, &case0.d, &case0.h, &cost);
            int flag = 0;
            while (now < case0) {
                now = now + daygo;
                flag = 1;
            }
            if (flag) {
                now.h = case0.h;
            }
            if (cost > 40) {
                int week = cost/40;
                cost -= week*40;
                addday.d = week*7;
                now = now + addday;
            }
            while (cost > 0) {
                now = now + timego;
                //cout << now.w << " " << cost << " ";
                //now.print(i+1);
                
                if (now.w < 5 && now.h > 10 && now.h < 19) {
                    cost--;
                }
            }
            now.print(i+1);
        }
        
    }
    return 0;
}
