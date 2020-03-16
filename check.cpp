#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

const int numTest = 100;
const string ADDR = "~/Atom\\ Projects/";

int32_t main() {
    system(("g++ " + ADDR + "gen.cpp -o " + ADDR + "gen.out").c_str());
    system(("g++ " + ADDR + "good.cpp -o " + ADDR + "good.out").c_str());
    system(("g++ " + ADDR + "bad.cpp -o " + ADDR + "bad.out").c_str());
    cerr << "gen" << endl;
    int tst = 1;
    long double badTime = 0, goodTime = 0;
    for (int test = 0; test < numTest; test++){
        tst++;
        if (tst % 50 == 0) cerr << tst << endl;
        system((ADDR + "gen.out").c_str());
        vector<string> good, bad;
        string s;
        ifstream fin;
        long double zxc = clock();
        system((ADDR + "good.out").c_str());
        badTime += (clock() - zxc) / CLOCKS_PER_SEC;
        fin.open("output.txt");
        while (getline(fin, s)) good.push_back(s);
        fin.close();
        zxc = clock();
        system((ADDR + "bad.out").c_str());
        goodTime += (clock() - zxc) / CLOCKS_PER_SEC;
        fin.open("output.txt");
        while (getline(fin, s)) bad.push_back(s);
        fin.close();
        if (good != bad) {
            fin.open("input.txt");
            // freopen("debug.txt", "`w", stdout);
            while (getline(fin, s)) cout << s << '\n';
            fin.close();
            cout << "Good\n";
            for (auto &i : good) cout << i << '\n';
            cout << "\nBad\n";
            for (auto &i : bad) cout << i << '\n';
            cout << endl;
            cout << "Difference :" << endl;
            if (good.size() != bad.size())
                cout << "Size differs -> Bad : " << bad.size() <<  " Good : " << good.size() << endl;
            for (int i = 0; i < (int)min(good.size(), bad.size()); i++)
                if (good[i] != bad[i]) {
                    cout << "Line " << i+1 << " :\n";
                    cout << "Good : " << good[i] << endl;
                    cout << "Bad : " << bad[i] << endl;
                }
            return 0;
        }
    }

    cout << "Bad time " << badTime / numTest << endl;
    cout << "Good time " << goodTime / numTest << endl;
}
