// What will be the output of the following program? find the bug.

#include <cstdio>
#include <cstring>
#include <array>
#define BUFFER_LEN 5 
using namespace std;

typedef struct { 
	int buffer[BUFFER_LEN]; 
	int index; 
} bufferT; 

int main1(void) { 

	bufferT bufferObj;

	memset(bufferObj.buffer, 0, sizeof(bufferObj.buffer));

	printf("buffer value = %d\n", bufferObj.buffer[0]);

	return 0;
}

typedef struct {
	array<int, BUFFER_LEN> buffer;
	int index;
} bufferT2;

int main2(void) {

	bufferT2 bufferObj;

	for (bufferObj.index = 0; bufferObj.index <= BUFFER_LEN; bufferObj.index++) {
		bufferObj.buffer.at(bufferObj.index) = 0;
	} 

	printf("buffer value = %d\n", bufferObj.buffer[0]);

	return 0;
}

int main(void) { 

	bufferT bufferObj;

	for (bufferObj.index = 0; bufferObj.index <= BUFFER_LEN; bufferObj.index++) {
		bufferObj.buffer[bufferObj.index] = 0;
	} 

	printf("buffer value = %d\n", bufferObj.buffer[0]);

	return 0;
}

/////////////////////////////////
//
/*

The error is known as a buffer overflow.

In this case, you are writing outside the bounds of the buffer array, which is part of the bufferT struct. When writing out of bounds, the data can overwrite adjacent memory, which in your example affects the index member of the struct. This happens because the memory layout of the struct places the array buffer next to the index member, and writing past the end of the array can corrupt the value stored in index.

Buffer overflows are dangerous as they can lead to unpredictable behavior, memory corruption, crashes, and security vulnerabilities, depending on the context. In more severe cases, it can be exploited to execute arbitrary code.

Solutions:
1. check the boundary when accessing the array
2. Use std::array Instead of C-Style Arrays: use .at() instead of [] so that we can automatic boundary check

3. wrap the array as a class
	template <typename T, std::size_t N>
	class SafeArray {
	private:
	    T data[N];
	public:
	    T& operator[](std::size_t index) {
		if (index >= N) {
		    throw std::out_of_range("Array index out of bounds");
		}
		return data[index];
	    }
	};

	typedef struct {
	    SafeArray<int, BUFFER_LEN> buffer;
	    int index;
	} bufferT;
4. use memory safe function: memset(myBuffer.buffer, 0, sizeof(myBuffer.buffer));


other issues:
bufferT.index is declared as int, but the size of buffer might exceed 2^31.


*/
