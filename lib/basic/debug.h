#include <bits/stdc++.h>
#include <string>
using namespace std;

inline string to_string(const string& s){return '"' + s + '"';}
inline string to_string(const char* s){return to_string((string(s)));}
inline string to_string(bool b){return (b ? "true" : "false");}
inline string to_string(char c){return string(1, c);}

// Pair
template <typename A, typename B>
string to_string(pair<A, B> p){
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
// Container
template <typename A>
string to_string(A v){
    bool first = true;
    string res = "{";
    for (const auto &x : v){
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

// debug_out
inline void debug_out() {cerr << endl;}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

