#include <stdio.h>

typedef unsigned char *pointer;

void showBytes(pointer, size_t);

int main()
{
int endianCheck;

if(sizeof(long) == 8){
printf("당신의 컴퓨터는 64bit 입니다.\n\n");
}
else{
printf("당신의 컴퓨터는 32bit 입니다.\n\n");
}

endianCheck = 0x01234567;
showBytes((pointer)&endianCheck, sizeof(int));
return 0;
}

void showBytes(pointer start, size_t len){
size_t i;
int check = 0;

for (i = 0; i < len; i++){
printf("%p\t0x%.2x\n", start + i, start[i]);
if((i == 0 )&&(start[0] == 0x67)){
check = 1;
}
}
if (check == 1){
printf("\nLittle Endian\n");
}
else{
printf("\nBig Endian\n");
}
}



