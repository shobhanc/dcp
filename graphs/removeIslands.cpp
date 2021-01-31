/*
 * Given a matrix
 * input:
 * [1,0,0,0,0,0
    0,1,0,1,1,1
    0,0,1,0,1,0
    1,1,0,0,1,0
    1,0,1,1,0,0
    1,0,0,0,0,1 ]
 * output:
 * [1,0,0,0,0,0
    0,0,0,1,1,1
    0,0,0,0,1,0
    1,1,0,0,1,0
    1,0,0,0,0,0
    1,0,0,0,0,1]
 *
 * Remove all islands are removed. An island is one which is not connected 
 * horizontally or verically to its neighbor.
 */

//space O(WH) and time O(WH) W-width & H-height
//
// find vertical and horizontal neighbors
void addNeighborsToStack(vector<vector<int>> &matrix, int i, int j,
												 stack<vector<int>> &s){
   if(i-1>=0 && matrix[i-1][j]==1){
        s.push({i-1,j});
	 }
	 if(i+1<matrix.size() && matrix[i+1][j]==1){
        s.push({i+1,j});
	 }
	 if(j+1<matrix[0].size() && matrix[i][j+1]==1){
        s.push({i,j+1});
	 }
	 if(j-1>=0 && matrix[i][j-1]==1){
        s.push({i,j-1});
	 }
}

void markConnected(vector<vector<int>> &matrix,
									 int i, int j){
	stack<vector<int>> s;
	s.push({i,j});
	while(!s.empty()){
      auto a=s.top();
		  s.pop();
			//mark visited nodes as 2
		  matrix[a[0]][a[1]]=2;
		  addNeighborsToStack(matrix, a[0], a[1], s);
	}
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
  // Write your code here.
	//
	//get all the nodes with 1s sitting on the outermost row and column
	//find their connected neighbors  and mark them with 2 to indicated visited 
	for(int i=0; i<matrix.size(); i++){
      for(int j=0; j<matrix[0].size();j++){
				if(matrix[i][j]==1){
					 if((i==0 || i==matrix.size()-1 ||
						  j==0 || j==matrix.size()-1) && 
						  matrix[i][j]){
                     markConnected(matrix,i,j);
					 }
				}
			}
	}
	
	//find all nodes that are not connected which are 1s and replace with 0
	//replace connected nodes which are marked as 2 to 1
	for(int i=0; i<matrix.size(); i++){
      for(int j=0; j<matrix[0].size();j++){
				if(matrix[i][j]==1){
            matrix[i][j]=0;
				}else if(matrix[i][j]==2){
            matrix[i][j]=1;
				}
			}
	}
	return matrix;
}


