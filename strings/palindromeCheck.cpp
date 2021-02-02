/*
 * Check whether a string is a palindrome
 * palindrome examples:
 * ABA
 * ABBA
 */

//time O(N) and space O(1)
bool isPalindrome(string str) {
	// Write your code here.
	int l=0, r=str.length()-1;
	while(l<=r){
		if(str[l]!=str[r])
			return false;
		l++;
		r--;
	}
	return true;
}

//time O(N) and space O(N)
bool helper(string str, int l, int r){
				if(l>r){
								return true;
				}
				if(str[l]!=str[r]){
								return false;
				}
				return helper(str, l+1, r-1);
}

bool isPalindrome(string str) {
				// Write your code here.
				return helper(str, 0, str.length()-1);
}


//time O(N) and space(N)
bool isPalindrome(string str) {
	string rev=str;
	reverse(rev.begin(), rev.end());
	return (rev==str);
}
