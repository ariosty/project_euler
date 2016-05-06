#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream in("cipher.txt");
    ofstream out("decode.txt");
    vector<int> data;
    char key[] = "god";
    int buffer;
    while (in >> buffer) data.push_back(buffer);
    /* use brutal force, then search for ' the ' since the word can be frequently seen in English. It can be found the word is 'god'.
    for (char a = 'a'; a <= 'z'; ++a) {
        for (char b = 'a'; b <= 'z'; ++b) {
            for (char c = 'a'; c <= 'z'; ++c) {
                out << a << b << c << endl;
                key[0] = a;
                key[1] = b;
                key[2] = c;
                for (int i = 0; i < data.size(); ++i)
                    out << char(data[i] ^ key[i % 3]);
                out << endl;
            }
        }
    }
    */
    int result = 0;
    for (int i = 0; i < data.size(); ++i)
        result += (data[i] ^ key[i % 3]);
    cout << result << endl;
    return 0;
}
