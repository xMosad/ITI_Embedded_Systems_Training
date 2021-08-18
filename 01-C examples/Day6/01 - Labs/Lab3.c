#include <stdio.h>

typedef unsigned char u8;

typedef struct
{
	u8 Math      ;
	u8 Language  ;
	u8 Physics   ;
	u8 Chemistry ;
}Student;

void main(void)
{
	u8 ID;
	Student Class[10] = {
		{50,60,70,80}  , /* Student 1 */
		{100,98,95,91} , /* Student 2 */
		{47,75,60,51}  , /* Student 3 */
		{64,75,75,90}  , /* Student 4 */
		{90,94,89,96}  , /* Student 5 */
		{70,80,75,84}  , /* Student 6 */
		{46,50,42,60}  , /* Student 7 */
		{78,64,51,90}  , /* Student 8 */
		{66,78,63,80}  , /* Student 9 */
		{64,67,69,85}    /* Student 10*/
	};
	printf("Please Enter Student ID: ");
	scanf ("%d",&ID);

	if (ID < 10)
	{
		printf("Math Grade: %d\n",Class[ID].Math);
		printf("Language Grade: %d\n",Class[ID].Language);
		printf("Math Grade: %d\n",Class[ID].Physics);
		printf("Math Grade: %d",Class[ID].Chemistry);
	}
	
	else
	{
		printf("Student ID is not correct");
	}
}