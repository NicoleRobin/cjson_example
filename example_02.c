/*
 * gcc -o example_02 ./example_02.c -I /home/zhangjianwei/package/cJson/include -lcjson
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cjson/cJSON.h"

int main(int argc, char **argv)
{
    printf("Version: %s\n", cJSON_Version());

	const char *strings[7] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};

	cJSON *root = NULL;
	root=cJSON_CreateStringArray(strings,7);
	printf("root:%p\n", root);
	if (root == NULL) {
		printf("cJSON_CreateStringArray() failed\n");
		return -1;
	} else {
		char *out = cJSON_Print(root);
		printf("out:%p\n", out);
		printf("%s\n", out);
		cJSON_Delete(root);
	}

	return 0;
}
