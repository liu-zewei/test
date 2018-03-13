#include <iostream>
#include <curl/curl.h>

int main()
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://www.baidu.com");
		res = curl_easy_perform(curl);
		if ( res != CURLE_OK )
		{
			std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
		}
	}
	curl_easy_cleanup(curl);
	return 0;
}
