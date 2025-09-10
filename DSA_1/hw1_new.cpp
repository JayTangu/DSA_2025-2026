#include <iostream>
#include <cstring>

using namespace std;
int main() {
    int n, m;
    cout<<"輸入人數:"<<endl;
    cin>>n;
    cout<<"輸入姓名長度"<<endl;
    cin>>m;
    cin.ignore();//因為getline的\n所以只能叫他忽略

    char **names = new char*[n]; //row
    for(int i = 0 ; i < n ; i++) {
        names[i] = new char[m+1]; //尾是\0，這是column
    }

    cout<<"輸入學生名字:"<<endl;
    for(int i = 0 ; i < n ; i++) {
        string line;
        getline(cin, line);
        strncpy(names[i], line.c_str(), m); //c_str是要把string改char形式
        names[i][m] = '\0';
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
        cout<<*(names+i)<<endl;
        delete[] *(names+i);
    }
    
    delete[] names;

    return 0;
}
