#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int main() {
    int n, max = 0, max_first_len = 0;
    cout<<"輸入人數:"<<endl;
    cin>>n;
    cin.ignore();//因為getline會讀到上一行cin的\n所以只能叫他忽略

    vector<string> name_in_vector(n);

    cout<<"輸入學生名字:"<<endl;
    for(int i = 0 ; i < n ; i++) {
        getline(cin, name_in_vector[i]);

        int space = name_in_vector[i].find(' ');
        if(space != string::npos && space > max_first_len)
            max_first_len = space;
        if(name_in_vector[i].length() > max)
            max = name_in_vector[i].length();
    }

    char **names = new char*[n];
    for(int i = 0 ; i < n ; i++) {
        names[i] = new char[max+1];
        strncpy(names[i], name_in_vector[i].c_str(), max);
        names[i][name_in_vector[i].length()] = '\0'; //不加會炸，因為上一行不會自己補\0
    }

    for(int i = n -1 ; i > 0 ; i--) {
        for(int j = 0 ; j < i ; j++) {
            char *name_1 = *(names + j);
            char *name_2 = *(names + j + 1);

            int lenth_1 = strlen(name_1);
            int lenth_2 = strlen(name_2);

            char last_1 = *(name_1 + lenth_1 - 1);
            char last_2 = *(name_2 + lenth_2 - 1);

            if((int)last_1 > (int)last_2) {
                char *temp = *(names + j);
                *(names + j) = *(names + j + 1);
                *(names + j + 1) = temp;
            }
        }
    }

    cout<<endl;
    for(int i = 0 ; i < n ; i++) {
        char *p = names[i]; //指向第一個字母
        char *spaceptr = strchr(p,' '); //指向第一個空格
        if(spaceptr) { 
            int first_length = spaceptr - p;
            int needed_space = max_first_len - first_length;
            for(int j = 0 ; j < needed_space ; j++) 
                cout<<' ';
        }
        cout<<*(names+i)<<endl;
        delete[] *(names+i);
    }
    
    delete[] names;

    return 0;
}
