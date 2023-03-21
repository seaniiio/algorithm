#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

int main() {
	int N; string str;
	cin >> N >> str;
	int* arr = new int[N];
	stack<double> s1;

	for (int i{ 0 }; i < N; i++) {
		int k; cin >> k;
		arr[i] = k;
	}
	for (int i{ 0 }; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			s1.push(arr[str[i] - 'A']);
		}
		else {
			double x = s1.top();
			s1.pop();
			double y = s1.top();
			s1.pop();
			if (str[i] == '*') {
				s1.push(x * y );
			}
			else if (str[i] == '/') {
				s1.push(y / x);
			}
			else if (str[i] == '+') {
				s1.push(x + y);
			}
			else if (str[i] == '-') {
				s1.push(y - x);
			}
		}
	}
	cout << fixed << setprecision(2) << double(s1.top()) << '\n';
}