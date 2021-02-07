/* Given a matrix of size M*N, the matrix has 1s and 0s.
 * valid neighbors are elements with 1s and that are 
 * horizontally or veritcally neighbors. The contigous 
 * neighbhors form rivers. Find all the sizes of such rivers.
 */

void getNeighbors(vector<vector<int>> &matrix,
             vector<vector<bool>> &visited,
						 deque<vector<int>> &neighbors,
						 int m, int n)
{
	int rows[4]={1,-1, 0, 0};
	int cols[4]={0, 0, 1,-1};
	for(int k=0; k<4; k++){
		int i=m+rows[k];
		int j=n+cols[k];
		//i and j need be in the range of row and col lengths
		if(i<matrix.size() && i>=0 &&
				j<matrix[0].size() && j>=0){
			//ignore visited
			if(visited[i][j]){
				continue;
			}
			//ignore 0s
			if(matrix[i][j]==0){
				continue;
			}
			neighbors.push_back({i,j});
		}
	}
}

void traverseNode(int i, int j,
								 vector<vector<int>> &matrix,
								 vector<vector<bool>> &visited,
								 vector<int> &res){
	int size=0;
	deque<vector<int>> q;
	q.push_back({i,j});
	while(!q.empty()){
		vector<int> v=q.front();
		q.pop_front();
		int m=v[0];
		int n=v[1];
		//ignore visited
		if(visited[m][n]){
			continue;
		}
		//increment size
		size++;
		//mark visited
		visited[m][n]=true;
		//get neighbors
		getNeighbors(matrix, visited, q, m, n);
	}
	if(size!=0){
		res.push_back(size);
	}
}

//time O(MN) and space O(MN)
vector<int> riverSizes(vector<vector<int>> matrix) {
	vector<int> res;
	vector<vector<bool>> visited(matrix.size(),
			vector<bool>(matrix[0].size(), false));
	for(int i=0; i<matrix.size(); i++){
		for(int j=0; j<matrix[0].size(); j++){
			if(visited[i][j]){
				continue;
			}
			if(matrix[i][j]==0){
				continue;
			}
			traverseNode(i, j,
					matrix,
					visited,
					res);
		}
	}
	return res;
}


