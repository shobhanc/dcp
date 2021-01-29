/*
 * sunset views
 *
 * buildings=[3,5,4,4,3,1,3,2]
 * direction="EAST"
 *
 * view from <--
 * output=[1,3,6,7] 
 *
 * direction="WEST"
 * view from -->
 * output=[0,1] 
 *
 */
//time O(N) space O(N)
vector<int> sunsetViews(vector<int> buildings, string direction) {
  // Write your code here.
	vector<int> v;
	int cur=-1;
	int i=0, count=0, step=1;
	if(direction.compare("EAST")==0){
		i=buildings.size()-1;
		step=-1;
	}
	while(count<buildings.size()){
     if(cur<buildings[i]){
        v.push_back(i);
			 cur=buildings[i];
		 }
		 i+=step;
     count++;
	}
	if(direction.compare("EAST")==0){
	   sort(v.begin(),v.end());
	}
	return v;
}


//time O(N) space O(N)
vector<int> sunsetViews(vector<int> buildings, string direction) {
  // Write your code here.
	vector<int> v;
	int cur=-1;
	int i=0, count=0, step=1;
	if(direction.compare("WEST")==0){
		i=buildings.size()-1;
		step=-1;
	}
	while(count<buildings.size()){

     while(v.size()>0 && buildings[v[v.size()-1]]<=buildings[i]){
        v.pop_back();
		 }
		 v.push_back(i);
		 i+=step;
     count++;
	}
	if(direction.compare("WEST")==0){
	   reverse(v.begin(),v.end());
	}
	return v;
}


