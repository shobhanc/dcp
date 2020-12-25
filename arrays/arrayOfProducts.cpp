/*
 * array=[5,1,4,2]
 * result=[1*4*2,5*4*2,5*1*2,5*1*4]
 *
 * Each element output[i] in the output array is equal to the product of every number in the input array other than the input[i].
 *
 * Do not use division.
 */

//time O(N) space(N)
vector<int> arrayOfProducts(vector<int> array) {
	// Write your code here.
	int p=1;
	vector<int> res(array.size(),1);
	for(int i=0; i< array.size(); i++){
		res[i]=p;
		p*=array[i];
	}
	p=1;
	for(int j=array.size()-1; j>=0; j--){
		res[j]*=p;
		p*=array[j];
	}
	return res;
}

//O(N^2) time and O(N) space
vector<int> arrayOfProducts(vector<int> array) {
	vector<int> res(array.size(),1);
	// Write your code here.
	for(int i=0; i<array.size(); i++){
		int p=1;
		for(int j=0; j<array.size(); j++){
			if(i!=j){
				p*=array[j];
			}
		}
		res[i]=p;
	}
	return res;
}

//O(N) time and O(N) space
vector<int> arrayOfProducts(vector<int> array) {
  // Write your code here.
	vector<int> left(array.size(),1);
	vector<int> right(array.size(),1);
	int p=1;
	for(int i=0;i<array.size(); i++){
		left[i]=p;
		p*=array[i];
	}
	p=1;
	for(int i=array.size()-1;i>=0; i--){
		right[i]=p;
		p*=array[i];
	}
	for(int i=0; i<array.size(); i++){
		left[i]=left[i]*right[i];
	}
  return left;
}
