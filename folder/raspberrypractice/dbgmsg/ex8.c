#include <stdio.h>

#define SUM(x,y) x + y
#define SUM3(x,y,z) x + y + z
#define STRCAT_V1(x,y) x y
#define STRCAT_V2(x,y) #x #y
#define STR(x) #x
#define MERGE_V1(x,y) x ## y
#define MERGE_V2(x,y) STR(x ## y)

int
main(void)
{
	int val1 = SUM(1,2);
	int val2 = SUM3(1,2,3);
	char *str1 = "string1" "string2";
	char *str2 = STRCAT_V1("I am ","shchoi82.");
	char *str3 = STRCAT_V2(I am\x20,shchoi82..);
	char *str4 = STRCAT_V2(\x48,\x69);
	char *str5 = STR(I am\x20) STR(shchoi82...);
	char *str6 = MERGE_V1(str,1);
	char *str7 = MERGE_V2(str,2);

	printf("val1: %d\n", val1);
	printf("val2: %d\n", val2);
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("str3: %s\n", str3);
	printf("str4: %s\n", str4);
	printf("str5: %s\n", str5);
	printf("str6: %s\n", str6);
	printf("str7: %s\n", str7);

	return 0;
}


