#include <stdio.h>
#include <string.h>
// To execute C, please define "int main()"
#define SET_BIT(x,p)(x |= 1ul << p)// set (set to 1) proper bit into the "x" byte by "p" position
#define CLR_BIT(x,p)(x &= ~1ul << p) // clear (set to 0) proper bit into the "x" byte by "p" position
#define TGL_BIT(x,p)(x ^= 1ul << p) // flip/toggle proper bit into the "x" byte by "p" position
#define CHK_BIT(x,p)((x >> p) & 1ul) // check proper bit into the "x" byte by "p" position





void Int2BitStr(int x, char* str)
{
char strTmp[9] = {};
  unsigned char i, j, k;
  unsigned char bt[4] = {0};
   for (j=0; j<4; j++){
    if(((x >> j*8)==0) && (j>0))  break;
      bt[j] = (unsigned char) (x >> j*8);
  }

  strcpy(str,"0b");

  for (k=0; k<j; k++){
    for (i=0; i<8; i++){
      switch ((bt[j-k-1] >> i) & 0b00000001){
        case 1:  strTmp[7-i] = '1'; break;
        case 0:  strTmp[7-i] = '0'; break;
      }
    }
    strcat(str,strTmp);
  }
}




int main() {
  

char str[32] = {};  
int num = 100;
printf("%d befor macro-funcs : \n",num);
printf("Decimal : %d \n", num);
Int2BitStr(num,str);
printf("Binary : %s \n\n",str);

printf("Macro set bit\n");
SET_BIT(num,0);
SET_BIT(num,1);
SET_BIT(num,2);
printf("Decimal : %d \n", num);
Int2BitStr(num,str);
printf("Binary : %s \n\n",str);

printf("Macro clear bit\n");
CLR_BIT(num,0);
CLR_BIT(num,1);
CLR_BIT(num,2);
printf("Decimal : %d \n", num);
Int2BitStr(num,str);
printf("Binary : %s \n\n",str);

printf("Macro toggle bit\n");
TGL_BIT(num,0);
TGL_BIT(num,1);
TGL_BIT(num,7);
printf("Decimal : %d \n", num);
Int2BitStr(num,str);
printf("Binary : %s \n\n",str);


printf("Use Macro for cheking bits\n");
//int values for testing CHK_BIT macro
int bit0;
int bit1;
int bit2;
int pos0 = 0;
int pos1 = 1;
int pos2 = 2;
bit0 = CHK_BIT(num,pos0);
bit1 = CHK_BIT(num,pos1);
bit2 = CHK_BIT(num,pos2);

printf("Decimal : %d \n", num);
Int2BitStr(num,str);
printf("Binary : %s \n",str);
printf("pos : %d  = %d\n",pos0,bit0);
printf("pos : %d  = %d\n",pos1,bit1);
printf("pos : %d  = %d\n",pos2,bit2);



  return 0;
}
