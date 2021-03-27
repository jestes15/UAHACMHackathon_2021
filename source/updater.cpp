#include <curl/curl.h>
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

//Memory Struct writes the data from curl and the size of that data into memory
struct MemoryStruct 
{
	char* memory;
	size_t size;
};



//Write Memory Callback qrites to memory and calculates the real size of the data
static size_t 
WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void *userp)
{
	size_t realsize = size*nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *)userp;

	char *ptr = (char*)realloc(mem->memory, mem->size + realsize + 1);
	if(ptr == NULL)
	{
		printf("ERROR: Not enough memory!\n");
		return 0;
	}
		
	mem->memory = ptr;
	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;

	return realsize;
}



int updateData(void)
{
	//set curl dependant variables
	CURL *curl;
	CURLcode res;

	//create chunk and set its values
	struct MemoryStruct chunk;
	chunk.memory = (char*)malloc(1);
	chunk.size = 0;

	// Set up Output file
	FILE *outFile;
	outFile = fopen("data.xml","w");

	curl_global_init(CURL_GLOBAL_ALL); //init curl

	curl = curl_easy_init(); //put curl into easy mode
	if (curl)
	{

		// Set curl Settings
		curl_easy_setopt(curl, CURLOPT_URL, "https://data.cdc.gov/api/views/9mfq-cb36/rows.xml?accessType=DOWNLOAD");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (char *)&chunk);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

		res = curl_easy_perform(curl);	//Actually grab the data

		// Print the bytes retrieved
		if (res != CURLE_OK)
			cout << "ERROR: Update Failed!\n Could not find destination!\n";
		else
			cout << (unsigned long)chunk.size << "bytes retrived\n";

		fprintf(outFile, chunk.memory); //Print the website contents to the output file
	
	}

	// Cleanup
	curl_easy_cleanup(curl);
	fclose(outFile);
	free(chunk.memory);
	curl_global_cleanup();

	return 0;
}
