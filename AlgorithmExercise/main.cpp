#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s);

int main()
{
	string str = "babad";
	string ans;
	ans = longestPalindrome(str);
	cout << ans << endl;

	cin.get();
	return 0;
}