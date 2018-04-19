/*
 * gcc -o example_04 ./example_04.c -I /home/zhangjianwei/package/cJson/include -lcjson
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cjson/cJSON.h"

int main(int argc, char **argv)
{
	printf("Version: %s\n", cJSON_Version());

	const char *json = "{\
		    \"result\": 0,\
		    \"dcdn_progress\": 0,\
			    \"message\": \"\",\
				    \"root_url\": \"http://up051.tw11a.filemail.xunlei.com\",\
					    \"uri\": \"request_upload\",\
						    \"query_str\": \"g=3CC8E3EF37A209501ED5694DA4418A6CA1BD29D2&s=66479822&t=1524205865&ver=1&tid=8ce92288b8d8cb22d394651fd42268c3&ui=150007900&e=1524810665&ms=10485760&ak=0:0:0:0&pk=filemail&aid=8d01cf85ec1a775e896c39f30d8793b6\",\
							    \"block_size\": 0\
}";

	cJSON *root = cJSON_Parse(json);
	if (root == NULL) {
		printf("cJSON_Parse() failed, error:%s\n", cJSON_GetErrorPtr());
		return -1;
	}
	printf("%s\n", cJSON_Print(root));

	cJSON *result = cJSON_GetObjectItemCaseSensitive(root, "result");
	if (result != NULL && cJSON_IsString(result) && result->valuestring != NULL) {
		printf("result:%s\n", result->valuestring);
	}

	cJSON *dcdn_progress = NULL;
	cJSON *message = NULL;
	cJSON *root_url = cJSON_GetObjectItemCaseSensitive(root, "root_url");
	if (root_url != NULL && cJSON_IsString(root_url) && root_url->valuestring != NULL) {
		printf("root_url:%s\n", root_url->valuestring);
	}
	cJSON *uri = NULL;
	cJSON *query_str = NULL;
	cJSON *block_size = NULL;

	cJSON_Delete(root);
	return 0;
}
