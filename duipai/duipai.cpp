#include <bits/stdc++.h>

#define nl '\n'
using i64 = long long;
using i128 = __int128;

int compareFiles() {
    std::ifstream fstd("std.out");
    std::ifstream fsol("sol.out");
    std::string lineStd, lineSol;
    int lineNum = 1;

    while (true) {
        bool hasStd = (bool)std::getline(fstd, lineStd);
        bool hasSol = (bool)std::getline(fsol, lineSol);

        if (!hasStd && !hasSol) return -1;

        if (hasStd != hasSol || lineStd != lineSol) {
            return lineNum;
        }
        lineNum++;
    }
}
int main() {
    int testNum = 1000;
    for (int i = 1; i <= testNum; ++i) {
        std::system("./gen.exe > in.txt");
        std::system("./std.exe < in.txt > std.out");
        std::system("./sol.exe < in.txt > sol.out");
        int wrongLine = compareFiles();
        if (wrongLine != -1) {
            std::cout << "WA on test " << i << ", Diff at line " << wrongLine << nl;
            std::ifstream fin("in.txt");
            std::ifstream fstd("std.out");
            std::ifstream fsol("sol.out");
            std::ofstream fdiff("diff.log");
            fdiff << "[in.txt]" << nl << fin.rdbuf() << nl; 
            fdiff << "[std.out]" << nl << fstd.rdbuf() << nl;
            fdiff << "[sol.out]" << nl << fsol.rdbuf() << nl;
            std::cerr << "Look at diff.log" << nl;
            return 0;
        }else {
            if (i % 100 == 0) {
                std::cout << i << "/" << testNum << ": AC" << nl;
            }
        }
    }
    std::cout << "AC All !!!" << nl;
}
