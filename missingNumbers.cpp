#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the missingNumbers function below.
vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    int frequency[100001];
    for(int i=1;i<100000;i++){
        frequency[i]=0;
    }
    for(int i=0;i<arr.size();i++){
        frequency[arr[i]]++;
    }
    for(int i=0;i<brr.size();i++){
        frequency[brr[i]]--;
    }

    vector<int> result;

    for(int i=1;i<10000;i++){
        if(frequency[i]!=0){
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split_string(brr_temp_temp);

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    vector<int> result = missingNumbers(arr, brr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}