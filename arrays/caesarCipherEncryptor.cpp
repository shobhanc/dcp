/*
 * Caesar Cipher Encryptor
 *
 * Given a string "xyz"
 * shift every letter by k=2 to reture "zab".
 *
 * shift should wrap around 26 alphabets
 */

//time O(N) and space O(1)
string caesarCypherEncryptor(string str, int key) {
	key=key%26;
	for(int i=0; i<str.length(); i++){
		int idx=(str[i]-'a'+key)%26;
		str[i]='a'+idx;
	}
	return str;
}
