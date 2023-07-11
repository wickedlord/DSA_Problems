#include <stdio.h>

int main() {
    float m1,m2,m3,m4,m5,per;
    printf("enter the five subjects marks");
    scanf("%f%f%f%f%f%",&m1,&m2,&m3,&m4,&m5);
    per=(m1+m2+m3+m4+m5)/500*100;
    if(per>40)
      {printf("you are pass \n");
        if(per>=60)
          printf("dividion1 \n");
        else
        {if((per<50) && (per>59))
           printf("division2 \n");
         else
         if((40<per) && (per<49));
           printf("division3 \n");
        }
      }
  else
  printf("you are fail");
  
    

    return 0;
}