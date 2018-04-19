/*
 * gcc -o example_03 ./example_03.c -I /home/zhangjianwei/package/cJson/include -lcjson
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cjson/cJSON.h"

int main(int argc, char **argv)
{
    printf("Version: %s\n", cJSON_Version());

	int numbers[3][3] = {
		{0, -1, 0}, 
		{1, 0, 0}, 
		{0, 0, 1}
	};

	cJSON *root = NULL;
	root = cJSON_CreateArray();
	int i;
	for (i = 0; i < 3; i++) {
		cJSON_AddItemToArray(root, cJSON_CreateIntArray(numbers[i], 3));
	}

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
