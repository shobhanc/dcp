/*
 * find lowest value which is also the index of the array in sorted array
 * [-2,-1,0,3,4,5,6]
 * output is 3
 */

//O(N) time and O(1) space

int getLowestVal(vector<int> &v)
{
	for(int i=0; i<v.size(); i++)
	{
		if(i==v[i])
			return i;
	}
	return -1;
}


//time O(log(N)) space O(1)
int indexEqualsValue(vector<int> array) {
  // Write your code here.
	int l=0, r=array.size()-1;
	while(l<=r){
		int m=l+(r-l)/2;
		if(array[m]<m){
			 l=m+1;
		}else if(m==array[m] && m==0){
			return m;
		}else if(m==array[m] && array[m-1]<m-1){
			return m;
		}else{
			r=m-1;
		}
	}
  return -1;
}

//time O(log(N)) space O(log(N))
int recurIndexEqualsValue(vector<int> array, int l, int r) {
	if(l>r){
		return -1;
	}
	int m=l+(r-l)/2;
	if(array[m]<m){
		return recurIndexEqualsValue(array, m+1, r);
	}else if(m==array[m] && m==0){
		return m;
	}else if(m==array[m] && array[m-1]<m-1){
		return m;
	}else{
		return recurIndexEqualsValue(array, l, m-1);
	}
}
