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
vector<int> hdb3(string bits) {
    vector<int> s;
    int last = -1;
    int pulses = 0;
    for (int i = 0; i < (int)bits.size();) {
        if (i + 4 <= (int)bits.size() && bits.substr(i, 4) == "0000") {
            if (pulses % 2 == 1) {
            
                int v = (last == 0) ? 1 : last;
                s.push_back(0); s.push_back(0); s.push_back(0); s.push_back(v);
                last = v;
            } else {
         
                int b = -last;
                s.push_back(b); s.push_back(0); s.push_back(0); s.push_back(b);
                last = b;
            }
            pulses = 0;
            i += 4;
        } else {
            if (bits[i] == '0') s.push_back(0);
            else {
                last = -last;
                s.push_back(last);
                pulses++;
            }
            i++;
        }
    }
    return s;
}

string decodeNrzL(vector<int> s) {
    string bits = "";
    for (int x : s) bits += (x == 1 ? '0' : '1');
    return bits;
}

string decodeNrzI(vector<int> s) {
    string bits = "";
    int previous = 1;
    for (int x : s) {
        bits += (x == previous ? '0' : '1');
        previous = x;
    }
    return bits;
}

string decodeManchester(vector<int> s) {
    string bits = "";
    for (int i = 0; i + 1 < (int)s.size(); i += 2)
        bits += (s[i] == 1 && s[i+1] == -1 ? '0' : '1');
    return bits;
}

string decodeDiffManchester(vector<int> s) {
    string bits = "";
    int previous = 1;
    for (int i = 0; i + 1 < (int)s.size(); i += 2) {
        bits += (s[i] == previous ? '1' : '0');
        previous = s[i+1];
    }
    return bits;
}

string decodeAmi(vector<int> s) {
    string bits = "";
    for (int x : s) bits += (x == 0 ? '0' : '1');
    return bits;
}

string decodeB8zs(vector<int> s) {
    string bits = "";
    for (int i = 0; i < (int)s.size();) {
        if (i + 8 <= (int)s.size() && s[i] == 0 && s[i+1] == 0 &&
            s[i+2] == 0 && s[i+3] != 0 && s[i+4] != 0 &&
            s[i+5] == 0 && s[i+6] != 0 && s[i+7] != 0) {
            bits += "00000000";
            i += 8;
        } else {
            bits += (s[i] == 0 ? '0' : '1');
            i++;
        }
    }
    return bits;
}