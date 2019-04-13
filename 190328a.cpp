#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int Isaeiou(char ch) {
    if (ch == 'a'|| ch == 'e'|| ch == 'i'|| ch == 'o'|| ch == 'u') {
        return 1;
    }
    return 0;
}

int main() {
    char s1[2000], s2[2000];
    scanf("%s", s1);
    scanf("%s", s2);
    int flag = 1;
    int i = 0;
    if (strlen(s1) != strlen(s2)) {
        flag = 0;
    }
    while (s1[i] != '\0') {
        if (Isaeiou(s1[i]) != Isaeiou(s2[i])) {
            flag = 0;
            break;
        }
        i++;
    }
    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
