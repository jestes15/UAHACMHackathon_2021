#include <iostream>
#include <curl/curl.h>

using namespace std;
int main(void)
{
	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://www.worldometers.info");
		res = curl_easy_perform(curl);		
	
		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();

	return 0;
}
