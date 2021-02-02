/*
 * Given special array [x, [y,[z,w]]] the product should return
 * x+2*(y+3*(z+w))
 *
 * use of any
 */

//time O(N) and space O(d), d - depth
int productSum(vector<any> array, int level=1) {
	// Write your code here.
	int sum=0;
	for(auto a: array){
		if(a.type()==typeid(int)){
			sum+=any_cast<int>(a);
		}else{
			sum+=productSum(any_cast<vector<any>>(a),level+1);
		}
	}
	return sum*level;
}
