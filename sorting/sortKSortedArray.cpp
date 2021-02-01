/*
 * Sort K-Sorted Array
 * Given a non-negative integer k and a k-sorted array of integers and return sorted version of the array.
 *
 * a k sorted array is a partially sorted array in which all elements are
 * at most k positions away from their sorted position.
 */

class MinHeap{

	public:
		vector<int> heap;
		MinHeap(vector<int>& v){ heap=buildHeap(v);}
		vector<int> buildHeap(vector<int> &v){
			int i=(v.size()-2)/2;
			for(;i>=0; i--){
				siftDown(i,v.size()-1,v);
			}
			return v;
		}
		int peek(){ return heap[0];}
		void insert(int val){
			heap.push_back(val);
			siftUp(heap.size()-1);
		}
		int remove(){
			int v = heap[0];
			swap(heap[0],heap[heap.size()-1]);
			heap.pop_back();
			siftDown(0, heap.size()-1, heap);
			return v;
		}
		void siftUp(int cur){
			int parent=(cur-1)/2;
			while(cur>0 && heap[parent]>heap[cur]){
				swap(heap[cur], heap[parent]);
				cur=parent;
				parent=(cur-1)/2;
			}
		}
		void siftDown(int cur, int endIdx, vector<int> &v){
			int ch1=cur*2+1;
			while(ch1<=endIdx){
				int ch2=cur*2+2;
				int swapIdx;
				if(ch2<=endIdx && v[ch2]<v[ch1]){
					swapIdx=ch2;
				}else{
					swapIdx=ch1;
				}
				if(v[swapIdx]<v[cur]){
					swap(v[swapIdx], v[cur]);
					cur=swapIdx;
					ch1=cur*2+1;
				}else{
					return;
				}
			}
		}

		bool isEmpty(){
			return heap.size()==0;
		}

};

//time O(nlogk) and space O(k)
vector<int> sortKSortedArray(vector<int> array, int k) {
	//create a auxillary heap with copy of first k+1 elements
	vector<int> inv(array.begin(),array.begin()+min(k+1,(int)array.size()));
	MinHeap mHeap(inv);
	int i=k+1;
	int j=0;
	for(;i<array.size();i++){
		int v=mHeap.remove();
		//take out elements from heap and start placing in the original array
		array[j]=v;
		j++;
		//add remaining elements to the heap
		mHeap.insert(array[i]);
	}
	while(!mHeap.isEmpty()){
		int v=mHeap.remove();
		array[j]=v;
		j++;
	}
	return array;
}
