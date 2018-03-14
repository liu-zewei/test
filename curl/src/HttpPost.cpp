#include <sys/stat.h>
#include <iostream>
#include <curl/curl.h>

int main()
{
	CURL *curl_handle;
	CURLcode res;
	struct stat file_info;

	stat("example.txt", &file_info);
	
	curl_handle = curl_easy_init();

	if (curl_handle)
	{
		curl_easy_setopt(curl_handle, CURLOPT_URL, "http://172.16.6.186/api.php?op=upload");
	
		curl_mime *mutipart = curl_mime_init(curl_handle);
		curl_mimepart *part = curl_mime_addpart(mutipart);
		//curl_mime_name(part, "op");
		//curl_mime_data(part, "upload", CURL_ZERO_TERMINATED);
		//part = curl_mime_addpart(mutipart);
		curl_mime_name(part, "file[]");
		curl_mime_filedata(part, "demo.mp4");

		curl_easy_setopt(curl_handle, CURLOPT_MIMEPOST, mutipart);

		curl_easy_setopt(curl_handle, CURLOPT_INFILESIZE_LARGE, (curl_off_t)file_info.st_size);

		//curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, "op=upload");

		res = curl_easy_perform(curl_handle);
		if (res != CURLE_OK )
		{
			std::cout << "curl_easy_perform() failed!" << std::endl;
		}
		curl_mime_free(mutipart);
	}
	curl_easy_cleanup(curl_handle);
	return 0;
}
