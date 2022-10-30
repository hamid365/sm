#include <iostream>
#include <fstream>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


map<string, int> readFile(string Nfile) {

    ifstream file;
    file.open(Nfile);

    string line;
    map<string, int> mfile;

    while (getline(file, line)){
        

        int index = 0;
        string letter = "";
        string space = " ";

        for (int i=0; i<line.length(); i++){
            
            string c = "";
            c += tolower(line[i]);

            if ((c != space) & (int(line[i]) != 13) & (c.length() > 0)){
                letter += c;
            } else{  // end letter
                if (int(letter[0]) != 0){  // not empty
                    
                    if (mfile.count(letter) == 1){  // already exist in map
                        mfile[letter] ++;
                    }else{
                        mfile[letter] = 1;
                    }
                    letter = "";
                    index = i+1;
                }
            }
        }

        // last letter
        if ((int(letter[0]) != 13) & (int(letter[0]) != 0)){  // not empyt or \n
            if (mfile.count(letter) == 1){
                mfile[letter] ++;
            }else{
                mfile[letter] = 1;
            }
        }

    }
    file.close();

    return mfile;
}


int main(int argc, car *argv[]) {

    map<string, int> f1, f2;

    f1 = readFile(argv[1]);
    f2 = readFile(argv[2]);

    vector<string> keys;

    for (auto it = f1.begin(); it != f1.end(); ++it) {
        
        if (find(keys.begin(), keys.end(), it->first) == keys.end()){
            // not found
            keys.push_back(it->first);
        }
    }

    for (auto it = f2.begin(); it != f2.end(); ++it) {
        
        if (find(keys.begin(), keys.end(), it->first) == keys.end()){
            // not found
            keys.push_back(it->first);
        }
    }


    int s, m, n = 0;
    int a, b = 0;
    float c = 1.0;
    
    for (int i=0; i<keys.size(); i++){

        if (f1.count(keys[i]) == 1){
            a = mfile[keys[i]];}else a = 0;
        
        if (f2.count(keys[i]) == 1){
            b = f2[keys[i]];}else b = 0;

        cout << keys[i] << ": " << a << " | " << b << endl;

        s += a*b;
        m += pow(a, 2);
        n += pow(b, 2);

    }

    float x = (s / (sqrt(m) * sqrt(n))) * 100;
    cout << x << "%\n";

    return 0;
}