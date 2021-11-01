#include <bits/stdc++.h>

using namespace std;

string word;
string anagram;
int length = 0;

inline void printStack(stack<char> s)
{
    stack<char> tmp;
    while(!s.empty())
    {
        cout<<s.top()<<' ';
        tmp.push(s.top());
        s.pop();
    }
    while(!tmp.empty())
    {
        s.push(tmp.top());
        tmp.pop();
    }
}
inline void searchActions(int actionsNumber, string anagram1, stack<char> w, stack<char> s, string actions)
{
    cout<<"stack w : ";
    printStack(w);
    cout<<"\nstack s : ";
    printStack(s);
    cout<<"\nAnagram1 : "<<anagram1<<'\n';
	if(actionsNumber == (length << 1))
	{
		if(anagram1 == anagram)
        {
            string actions_ = actions; actions_.pop_back();
            cout << "THIS ANAGRAM : " << actions_ << "\n";
        }
		return;
	}

	if(!w.empty())
    {
        stack<char> w1 = w; w1.pop();
        stack<char> s1 = s; s1.push(w.top());
        searchActions(actionsNumber + 1, anagram1, w1, s1, actions + "i ");
    }


	if(!s.empty() && s.top() == anagram[anagram1.length()])
	{
	    //cout<<"compare choosen : " << anagram[anagram1.length()]<<'\n';
	    stack<char> s1 = s; s1.pop();
	    string tmp {s.top()};
		searchActions(actionsNumber + 1, anagram1 + tmp, w, s1, actions + "o ");
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> word >> anagram)
	{
		length = word.length();
        stack<char> w,s;
        for(int i = length - 1; i >= 0; --i)    w.push(word[i]);
		cout << "[\n";
		if(length == anagram.length())
			searchActions(0, "", w, s, "");

		cout << "]\n";
	}
	return 0;
}
