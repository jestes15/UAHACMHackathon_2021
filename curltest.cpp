#include <curl/curl.h>
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;


struct MemoryStruct 
{
	char* memory;
	size_t size;
}

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	size_t realsize = size*nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *)userp;

	char* ptr = realloc(mem->memory, mem->size + realsize + 1);
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

int main(void)
{
	CURL *curl;
	CURLcode res;

	struct MemoryStruct chunk;

	chunk.memory = malloc(1);
	chunk.size = 0;

	FILE *outFile;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl)
	{
		outFile = fopen("curl_output","w");

		curl_easy_setopt(curl, CURLOPT_URL, "https://data.cdc.gov/api/views/9mfq-cb36/rows.xml?accessType=DOWNLOAD");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

		res = curl_easy_perform(curl);		
		if (res != CURLE_OK)
			printf("ERROR: Update Failed!\n Could not find destination!\n");
		else
			printf("%lu bytes retrived\n", (unsigned long)chunk.size);

		fprintf(outFile, res); 
	
		curl_easy_cleanup(curl);


		fclose(outFile);
	}

	free(chunk.memory);
	curl_global_cleanup();

	return 0;
}
