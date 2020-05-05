#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

// Define an exception
// Define it like a object
class BadLengthException : public exception {
    public:
        int n;
        BadLengthException(int n) : n {n} {}
        int what () {
            return n;
        }
};

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
        // using exception
		// throw mean throwing an error ==> it move to catch session, out of try session
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
        // try and catch error
		try {
			// if no error it will stay at try
			// if error move to catch
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			//  if any error  ==> running catch
			// if n < 5 , it will throw and error and move from try to catch
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}