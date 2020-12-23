/*
 * Take a n*n square array with 0s and 1s return boolean if any square of size>=2 in the array has all 0s
 * 0 0 0 1
 * 0 1 0 1
 * 0 0 0 0
 * 1 1 1 1
 *
 * output: true found 3*3 square array
 */

//time O(N) and space O(1)
bool isSquare(vector<vector<int>> matrix, int r1, int r2, int c1, int c2){
	cout<<r1<<","<<c1<<":"<<r2<<","<<c2<<endl;
	cout<<"[ "<<endl;
	//check all elements of the top and bottom row
	for(int i=c1; i<=c2; i++){
		cout<<r1<<","<<i<<":"<<r2<<","<<i<<" "<<endl;
		if(matrix[r1][i]!=0 || matrix[r2][i]!=0){
			cout<<"]"<<endl;
			return false;
		}
	}
	cout<<", "<<endl;
	//check all elements of the left and right columns
	for(int i=r1; i<=r2; i++){
		cout<<i<<","<<c1<<":"<<i<<","<<c2<<" "<<endl;
		if(matrix[i][c1]!=0 || matrix[i][c2]!=0){
			cout<<"]"<<endl;
			return false;
		}
	}
	cout<<"] "<<endl;
	return true;
}

//O(N^4) time and O(1) space
bool iterSquareOfZeroes(vector<vector<int>> matrix) {
  // Write your code here.
	for(int i=0; i<matrix.size();i++){
		for(int j=0; j<matrix[0].size(); j++){
			//at each cell start checking from size 2 squares if the perimeter
			//of the square is all zeros
			int r1=i, c1=j,r2=i+1, c2=j+1;

			while(r2<matrix.size() && c2<matrix[0].size()){
				if(isSquare(matrix,r1,r2,c1,c2))
					return true;
				r2++;
				c2++;
			}
		}
	}
  return false;
}


bool recurHelper(vector<vector<int>> matrix, int r1, int r2, int c1, int c2, string str)
{
	//cout<<str<<r1<<","<<c1<<":"<<r2<<","<<c2<<" ";
	if(r1>=matrix.size() || r2<0 ||
		 c1>=matrix[0].size() || c2<0 ||
		 r2-r1<1 || c2-c1<1 ||
		 r2-r1 != c2-c1){
		//cout<<str<<" false"<<endl;
		return false;
	}
	if(isSquare(matrix,r1,r2,c1,c2,str)){
		      //cout<<str<<" true"<<endl;
					return true;
	}

	return recurHelper(matrix, r1, r2-1, c1, c2-1,str+" ") ||
		     recurHelper(matrix, r1+1, r2, c1+1, c2, str+" ") ||
		     recurHelper(matrix, r1+1, r2, c1, c2-1, str+" ") ||
		     recurHelper(matrix, r1, r2-1, c1+1, c2, str+" ");

}

//O(N^4) time and  exponential space
//recursion without optimization
bool recur1SquareOfZeroes(vector<vector<int>> matrix) {
	// Write your code here.
	for(int i=0; matrix.size()-i>=2;i++){
		for(int j=0; matrix[0].size()-j>=2; j++){
	  	if(recurHelper(matrix, i, matrix.size()-1, j, matrix[0].size()-1,""))
			{
				return true;
			}
		}
	}
	return false;
}

bool recurHelperWithCache(vector<vector<int>> matrix,
								 int r1, int r2,
								 int c1, int c2,
								 unordered_map<string,int> &cache,
								 string str)
{
	string ostr=to_string(r1)+" "+to_string(r2)+" "+
		          to_string(c1)+" "+to_string(c2);
	if(cache.find(ostr)!=cache.end()){
		return false;
	}
	//cout<<str<<r1<<","<<c1<<":"<<r2<<","<<c2<<" ";
	if(r1>=matrix.size() || r2<0 ||
		 c1>=matrix[0].size() || c2<0 ||
		 r2-r1<1 || c2-c1<1 ||
		 r2-r1 != c2-c1){
			cache.insert({ostr,false});
		//cout<<str<<" false"<<endl;
		return false;
	}
	if(isSquare(matrix,r1,r2,c1,c2,str)){
		      //cout<<str<<" true"<<endl;
					return true;
	}else{
		cache.insert({ostr,false});
	}

	return recurHelperWithCache(matrix, r1, r2-1, c1, c2-1, cache, str+" ") ||
		     recurHelperWithCache(matrix, r1+1, r2, c1+1, c2, cache, str+" ") ||
		     recurHelperWithCache(matrix, r1+1, r2, c1, c2-1, cache, str+" ") ||
		     recurHelperWithCache(matrix, r1, r2-1, c1+1, c2, cache, str+" ");

}

//O(N^4) time and O(N^3) space
bool squareOfZeroes(vector<vector<int>> matrix) {
	// Write your code here.
	unordered_map<string,int> cache;
	for(int i=0; matrix.size()-i>=2;i++){
		for(int j=0; matrix[0].size()-j>=2; j++){
	  	if(recurHelperWithCache(matrix, i, matrix.size()-1, j,
										 matrix[0].size()-1, cache, ""))
			{
				return true;
			}
		}
	}
	return false;
}

bool dpIsSquare(int r1, int r2, int c1, int c2,vector<vector<int>> &horizontal ,
						 vector<vector<int>> &vertical){
	int squareSize = r2-r1;
	//check the vertical
	//vertical[r1][c1]>squareSize- - - - - vertical[r1][c2]>squareSize
	//horizontal[r1][c1]>squareSize
	// |
	// |
	//horizontal[r2][c1]>squareSize
	if(vertical[r1][c1]>squareSize &&
		 vertical[r1][c2]>squareSize &&
		 horizontal[r1][c1]>squareSize &&
		 horizontal[r2][c1]>squareSize
		 ){
	  //cout<<r1<<","<<c1<<":"<<r2<<","<<c2<<" true"<<endl;
		return true;
	}
	//cout<<r1<<","<<c1<<":"<<r2<<","<<c2<<" false"<<endl;
	return false;
}

//time O(N^3) and O(N^2) space
bool dpSquareOfZeroes(vector<vector<int>> matrix) {
  // Write your code here.
	// for matrix
	// 0 0 0 1
	// 0 1 0 0
	// 0 1 0 0
	// 0 1 0 1
	//
	// build vertical sum of num of zeros from below
	// 4 1 4 0
	// 3 0 3 2
	// 2 0 2 1
	// 1 0 1 0
	//
	// build horizontal sum of zeros from right 
	// 3 2 1 0
	// 1 0 2 1
	// 1 0 2 1
	// 1 0 1 0
	vector<vector<int>> horizontal(matrix.size(),vector<int>(matrix[0].size(),0));
	vector<vector<int>> vertical(matrix.size(),vector<int>(matrix[0].size(),0));
	for(int i=matrix.size()-1; i>=0; i--){
		for(int j=matrix[0].size()-1; j>=0; j--){
			if(matrix[i][j]==0){
		   	if(i==matrix.size()-1 && j==matrix[0].size()-1){
			   	horizontal[i][j]=1;
			  	vertical[i][j]=1;
			  }else if(j==matrix[0].size()-1){
          horizontal[i][j]=1;
				  vertical[i][j]=1+vertical[i+1][j];
				}else if(i==matrix.size()-1){
          horizontal[i][j]=1+horizontal[i][j+1];
				  vertical[i][j]=1;
				}else{
					//calculate from bottom up how many contigous zeros
					//are present from top to bottom and left to right
          horizontal[i][j]=1+horizontal[i][j+1];
				  vertical[i][j]=1+vertical[i+1][j];
			  }
	    }
		}
	}
	/*
	cout<<"=======vertical==========="<<endl;
	for(int i=0; i<matrix.size(); i++){
		for(int j=0; j<matrix[0].size();j++){
			cout<<vertical[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"=======horizontal==========="<<endl;
  for(int i=0; i<matrix.size(); i++){
		for(int j=0; j<matrix[0].size();j++){
			cout<<horizontal[i][j]<<" ";
		}
		cout<<endl;
	}
  */


	for(int i=0; i<matrix.size(); i++){
		for(int j=0; j<matrix[0].size();j++){
			int r1=i, r2=r1+1, c1=j, c2=c1+1;
			while(r2<matrix.size() && c2<matrix[0].size()){
				if(dpIsSquare(r1,r2,c1,c2,horizontal,vertical)){
					return true;
				}
				r2++;
				c2++;
			}
		}
	}

  return false;
}
