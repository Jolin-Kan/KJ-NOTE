#include <stdio.h>
 enum COLOR {red = 1,yellow,green=5,numCOLOR};

int main(int argc, const char*argv[])
{
 enum COLOR color=0; //儘管COLOR中冇color，但同樣可以賦值

 printf("code for green is %d\n", green);
 printf("color is %d\n", color);
printf("code for red is %d\n", red);
 return 0;
}