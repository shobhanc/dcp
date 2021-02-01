/*
 * MIN HEAP
 *
 * parent is less than both childred
 * array representation of heap.

 */
class MinHeap {
	public:
		vector<int> heap;

		MinHeap(vector<int> v) { heap = buildHeap(v); }

		//time O(n) and space O(1)
		vector<int> buildHeap(vector<int> &v) {
			//start from middle and go to 0 index
			//at each index sift down
			int i=(v.size()-2)/2;
			for(;i>=0;i--){
				siftDown(i,v.size()-1, v);
			}
			return v;
		}

		//time O(n) and space O(1)
		void siftDown(int currentIdx, int endIdx, vector<int> &heap) {

			//get first child
			int child1=currentIdx*2+1;
			while(child1<=endIdx){
				//get second child
				int child2=currentIdx*2+2;
				int swapIdx;
				//get index of lowest child
				if(child2<=endIdx && heap[child2]<heap[child1]){
					swapIdx=child2;
				}else{
					swapIdx=child1;
				}
				//swap parent with the lowest child
				//repeat for the current swappedIndex
				if(heap[swapIdx]<heap[currentIdx]){
					swap(heap[currentIdx],heap[swapIdx]);
					currentIdx=swapIdx;
					child1=currentIdx*2+1;
				}else{
					return;
				}
			}
		}

		//time O(n) and space O(1)
		void siftUp(int currentIdx) {
			int parent=(currentIdx-1)/2;
			//keep swapping parent with the child
			//till cur index > 0 and parent is greater than current index
			while(currentIdx>0 && heap[currentIdx]< heap[parent]){
				swap(heap[currentIdx],heap[parent]);
				currentIdx=parent;
				parent=(currentIdx-1)/2;
			}
		}

		int peek() {
			return heap[0];
		}

		int remove() {
			int v=heap[0];
			//swap first element with last element
			//and pop the last element and siftDown from 0
			swap(heap[0],heap[heap.size()-1]);
			heap.pop_back();
			siftDown(0,heap.size()-1,heap);
			return v;
		}

		void insert(int value) {
			//add element at the end and siftUp
			heap.push_back(value);
			siftUp(heap.size()-1);
		}
};


