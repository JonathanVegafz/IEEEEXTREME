#include <iostream>
#include<algorithm>
#include<stack>

using namespace std;

stack<int> s;
int main() {
    int N,a;
    cin >> N;
    while(N--)
    {
        cin >> a;
        if(s.size() && s.top()>a)
        {
            int b = s.top();
            s.pop();
            while(s.size()&&s.top()>a) s.pop();
            s.push(b);
        }
        else s.push(a);
    }
    cout << s.size() <<endl;
}