/*
 * Given a buffer and can read only 4 bytes per read. the read pointer progresses by as many bytes read. If the read call is called multiple times. Implement read of n bytes from the buffer.
 *
 * input buffer "abc"
 * reads [1,2,1]
 *
 * output ["a","bc",""]
 */

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */ 
    //use global temp buffer to use left over bytes to copy
    char buf4[4];
    //number of bytes left to read
    int left=0;
    //len of last read4 read
    int last_len=0;
    int read(char *buf, int n) {
        int bytes_read=0, len=4;
        int cur_bytes_to_copy=0;
        int index=0;
	//copy any left over bytes from global buffer
        if(left!=0){
            cur_bytes_to_copy=min(n,left);
            index=last_len-left;
            memcpy(buf, buf4+index, cur_bytes_to_copy);
            bytes_read+=cur_bytes_to_copy;
            left=left-cur_bytes_to_copy;
        }
	//copy till the buffer has bytes to read
	//and buffer has stil space to copy
        while(len==4 && bytes_read<n){
            if(n-bytes_read>=4)
	       //buffer has more space than 4 directly copy to buffer
               cur_bytes_to_copy=len=read4(buf+bytes_read);
            else{
	       //buffer has less than 4 bytes of space 
	       //then use global buffer and keep 
	       //track of left space and lenght of last read
               last_len=len=read4(buf4);
	       //copy minimum of left buffer size or 4
               cur_bytes_to_copy=min(len, n-bytes_read);
               memcpy(buf+bytes_read, buf4, cur_bytes_to_copy);
               left=len-cur_bytes_to_copy;
            }

            bytes_read+=cur_bytes_to_copy;
        }
        return bytes_read;
    }
};
