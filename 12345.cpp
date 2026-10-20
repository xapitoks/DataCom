#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

string randomBits(int n) {
    string bits = "";
    for (int i = 0; i < n; i++)
        bits += char('0' + rand() % 2);
    return bits;
}

string bitsWithZeros(int n, int run) {
    string bits = randomBits(n);
    int start = rand() % (n - run + 1);
    for (int i = start; i < start + run; i++)
        bits[i] = '0';
    return bits;
}

string longestPalindrome(string bits) {
    int bestStart = 0, bestLength = 0;
    for (int centre = 0; centre < (int)bits.size(); centre++) {
        for (int side = 0; side < 2; side++) {
            int left = centre;
            int right = centre + side;
            while (left >= 0 && right < (int)bits.size() &&
                   bits[left] == bits[right]) {
                if (right - left + 1 > bestLength) {
                    bestStart = left;
                    bestLength = right - left + 1;
                }
                left--;
                right++;
            }
        }
    }
    return bits.substr(bestStart, bestLength);
}

vector<int> nrzL(string bits) {
    vector<int> s;
    for (char b : bits) s.push_back(b == '0' ? 1 : -1);
    return s;
}

vector<int> nrzI(string bits) {
    vector<int> s;
    int level = 1;
    for (char b : bits) {
        if (b == '1') level = -level;
        s.push_back(level);
    }
    return s;
}

vector<int> manchester(string bits) {
    vector<int> s;
    for (char b : bits) {
        if (b == '0') { s.push_back(1); s.push_back(-1); }
        else { s.push_back(-1); s.push_back(1); }
    }
    return s;
}

vector<int> diffManchester(string bits) {
    vector<int> s;
    int level = 1;
    for (char b : bits) {
        if (b == '0') level = -level;
        s.push_back(level);
        level = -level;
        s.push_back(level);
    }
    return s;
}

vector<int> ami(string bits) {
    vector<int> s;
    int level = 1;
    for (char b : bits) {
        if (b == '0') s.push_back(0);
        else { s.push_back(level); level = -level; }
    }
    return s;
}


vector<int> b8zs(string bits) {
    vector<int> s;
    int last = -1;
    for (int i = 0; i < (int)bits.size();) {
        if (i + 8 <= (int)bits.size() && bits.substr(i, 8) == "00000000") {
            int v = (last == 1) ? 1 : -1;
            int b = -v;
            s.push_back(0); s.push_back(0); s.push_back(0);
            s.push_back(v); s.push_back(b); s.push_back(0);
            s.push_back(v); s.push_back(b);
            last = b;
            i += 8;
        } else {
            if (bits[i] == '0') s.push_back(0);
            else {
                last = -last;
                s.push_back(last);
            }
            i++;
        }
    }
    return s;
}
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

string randomBits(int n) {
    string bits = "";
    for (int i = 0; i < n; i++)
        bits += char('0' + rand() % 2);
    return bits;
}

string bitsWithZeros(int n, int run) {
    string bits = randomBits(n);
    int start = rand() % (n - run + 1);
    for (int i = start; i < start + run; i++)
        bits[i] = '0';
    return bits;
}

string longestPalindrome(string bits) {
    int bestStart = 0, bestLength = 0;
    for (int centre = 0; centre < (int)bits.size(); centre++) {
        for (int side = 0; side < 2; side++) {
            int left = centre;
            int right = centre + side;
            while (left >= 0 && right < (int)bits.size() &&
                   bits[left] == bits[right]) {
                if (right - left + 1 > bestLength) {
                    bestStart = left;
                    bestLength = right - left + 1;
                }
                left--;
                right++;
            }
        }
    }
    return bits.substr(bestStart, bestLength);
}

vector<int> nrzL(string bits) {
    vector<int> s;
    for (char b : bits) s.push_back(b == '0' ? 1 : -1);
    return s;
}

vector<int> nrzI(string bits) {
    vector<int> s;
    int level = 1;
    for (char b : bits) {
        if (b == '1') level = -level;
        s.push_back(level);
    }
    return s;
}

