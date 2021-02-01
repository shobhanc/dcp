/*
 * Get nth Fibonacci number.
 */
//time O(N) and space O(1)
int getNthFib(int n) {
	if(n==1){
		return 0;
	}
	if(n==2){
		return 1;
	}
	// Write your code here.
	int f0=0, f1=1, f=0;
	for(int i=2; i<n; i++){
		f=f0+f1;
		//swap previously computed values
		f0=f1;
		f1=f;
	}
	return f;
}

//time O(2^N) and space O(N)
int getNthFib(int n) {
	if(n==1 || n==2){
     return n-1;
	}
	return getNthFib(n-1)+getNthFib(n-2);
}

//time O(N) and space O(N)
int getNthFib(int n) {
	vector<int> mem(n,0);
	mem[1]=1;
	for(int i=2; i<n; i++){
    mem[i]=mem[i-2]+mem[i-1];
	}
	return mem[n-1];
}

//memoization
//time O(N) and space O(N)
int helper(vector<int> mem, int n){
			if(mem[n] || n==0){
							return mem[n];
			}else{
							mem[n]=helper(mem,n-1)+helper(mem,n-2);
			}
			return mem[n];
}

int getNthFib(int n) {
			if(n==1||n==2){
							return n-1;
			}
			vector<int> mem(n,0);
			mem[1]=1;
			return helper(mem,n-1);
}
