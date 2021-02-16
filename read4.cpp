/*
 * Given a buffer that you can read 4 bytes at a time with a wrapper
 * read4, need to read n bytes into a buffer.
 *
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
    int read(char *buf, int n) {
	//init len 4 so that bytes read
	//len check succeeds even first time
        int fp=0, read_bytes=0, len=4;
	//use temporary buffer to avoid buffer overflow
	//if the original buffer is used.
        char buf4[4];
	//read till bytes read is less than n
	//and the read bytes on single read4
	//has read atleat 4 bytes
	int cur_bytes_to_copy=0;
        while(read_bytes<n && len==4){
            len=read4(buf4);
	    cur_bytes_to_copy=min(len,n-read_bytes);
            memcpy(buf+read_bytes, buf4, cur_bytes_to_copy);
            read_bytes+=cur_bytes_to_copy;
        }
        return read_bytes;
    }
};
