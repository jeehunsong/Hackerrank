#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> genes;
vector<int> health;
vector<vector<int> > pi;

vector<int> getPartialMatch(const string& word)
{
    vector<int> retVal(word.length(), 0);

    int begin{1}, matched{0};

    while(begin + matched < word.length()) {
        if(word[begin + matched] == word[matched]) {
            ++matched;
            retVal[begin + matched - 1] = matched;
        }
        else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - retVal[matched - 1];
                matched = retVal[matched - 1];
            }
        }
    }
#if 0    
    cout << endl;
    for (int i = 0; i < word.length(); ++i)
    {
        cout << i << ": " << pi[i] << "\t";
    }
    cout << endl;
#endif
    return retVal;
}

int kmp (const string& str, const string& word, int idx)
{
    int strPos = 0, matched = 0, retVal{0};

    //cout << "kmp " << str << " " << word << endl << endl;

    //vector<int> pi = getPartialMatch(word);

    while(strPos <= str.length() - word.length()) {
        if (matched < word.length() && str[strPos + matched] == word[matched]) {
            ++matched;
            if (matched == word.length())
            {
                //cout << strPos << endl;
                retVal += health[idx];
            }
        }
        else {
            if (matched == 0) {
                ++strPos;
            }
            else {
                strPos += matched - pi[idx][matched - 1];
                matched = pi[idx][matched - 1];
            }
        }
    }
    return retVal;
}

int solve(int first, int last, const string& d)
{
    int ret = 0;
    for (int i = first ; i <= last; ++i) {
        /*
        auto pos = d.find(genes[i]);
        while(pos != string::npos) {
            ret += health[i];
            pos = d.find(genes[i], pos + 1);
        }
        */
        //cout << genes[i] << " " << kmp(d, genes[i], health[i]) << endl;
        ret += kmp(d, genes[i], i);
    }
    return ret;
}



int main(){
    int n;
    cin >> n;
    genes.resize(n);
    for(int genes_i = 0; genes_i < n; genes_i++){
       cin >> genes[genes_i];
       pi.push_back(getPartialMatch(genes[genes_i]));
    }
    health.resize(n);
    for(int health_i = 0; health_i < n; health_i++){
       cin >> health[health_i];
    }

    vector<int> sol;
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int first;
        int last;
        string d;
        cin >> first >> last >> d;
        // your code goes here
        sol.push_back(solve(first, last, d));
        //cout << sol.back() << endl;
    }
    cout << *(min_element(sol.begin(), sol.end())) << " " << *(max_element(sol.begin(), sol.end())) << endl;
    return 0;
}
