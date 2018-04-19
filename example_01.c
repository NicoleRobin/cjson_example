/*
 * gcc -o example_01 ./example_01.c -I /home/zhangjianwei/package/cJson/include -lcjson
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cjson/cJSON.h"

static int print_preallocated(cJSON *root)
{
	char *out = NULL;
	out = cJSON_Print(root);
	printf("%s\n", out);
}

int main(int argc, char **argv)
{
	printf("Version:%s\n", cJSON_Version());
	cJSON *root = NULL;
	cJSON *fmt = NULL;
	int i = 0;

	/*
	 * name
	 * format
	 *		type
	 *		width
	 *		height
	 *		interlace
	 *		frame
	 */
	root = cJSON_CreateObject();
	cJSON_AddItemToObject(root, "name", cJSON_CreateString("Jack (\"Bee\") Nimble"));
	cJSON_AddItemToObject(root, "format", fmt = cJSON_CreateObject());
	cJSON_AddStringToObject(fmt, "type", "rect");
	cJSON_AddNumberToObject(fmt, "width", 1920);
	cJSON_AddNumberToObject(fmt, "height", 1080);
	cJSON_AddFalseToObject(fmt, "interlace");
	cJSON_AddNumberToObject(fmt, "frame rate", 24);

	// print to text
	if (print_preallocated(root) != 0) {
		cJSON_Delete(root);
		exit(EXIT_FAILURE);
	}
	cJSON_Delete(root);

	return 0;
}
