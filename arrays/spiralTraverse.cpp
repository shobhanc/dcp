/*
 * Given a matrix return spiral traverse.
 * input : [1,2,3,4]
 *         [12,13,14,5]
 *         [11,16,15,6]
 *         [10,9,8,7]
 *
 * output: [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
 */

vector<int> spiralTraverse(vector<vector<int>> array) {
	int iMn=0, jMn=0;
	int iMx=array.size()-1, jMx=array[0].size()-1;
	int i=0, j=0;
	vector<int> res;
	//got right, down, right and up and update the
	//iMn,iMx,jMn and jMx as needed
	while(iMn<=iMx && jMn<=jMx){
		//go right jMn to jMx
		for(i=iMn,j=jMn; j<=jMx; j++){
			res.push_back(array[i][j]);
		}
		iMn++;
		//check if the range of columns and rows is valid
		if(iMn>iMx) break;
		//go down iMn to iMx
		for(i=iMn, j=jMx; i<=iMx; i++){
			res.push_back(array[i][j]);
		}
		jMx--;
		//check if the range of columns and rows is valid
		if(jMn>jMx) break;
		//go left jMx to jMn
		for(i=iMx, j=jMx; j>=jMn; j--){
			res.push_back(array[i][j]);
		}
		iMx--;
		//check if the range of columns and rows is valid
		if(iMn>iMx) break;
		//go up iMx to iMn
		for(i=iMx, j=jMn; i>=iMn; i--){
			res.push_back(array[i][j]);
		}
		jMn++;
	}
	return res;
}
