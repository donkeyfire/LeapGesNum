#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std; 

int caculate(char* buffer, int num){
	//long *x = new long[10];
	int k=0;
	const char **last;
	int i=0;
	*last=buffer+3;
	/*last=buffer+i;
	//temp[0][0]=buffer[0];

	/*for (int i=0;i<num;i++)
	{
		if (buffer[i]=='+' || buffer[i]=='-'||buffer[i]=='x'||buffer[i]=='/'||i==num-1)
		{
			
			*last=buffer;
			
			//strtol(buffer,end,0)
			k++;
			cout<<k<<endl;
		}
	
	}*/






	return 999;

/*do {
while (not + - x \)
{
	if (=)
	{
		break;
	}
}
}while (+,-,x,/)*/

	//read buffer 
}


int main(){
	char buffer[100];
	int num=0;
	char x;
	int result=0;
while(1){
	cout<<"Enter a Char"<<endl;
	cin>>x;
if (x=='1') {
  buffer[num]='1';
  num++;}
  else if (x=='2')
{
    buffer[num]='2';
  num++;
}
else if (x=='3')

{

	    buffer[num]='3';
  num++;
}
 
else if(x=='4')
{
	 buffer[num]='4';
  num++;
}


 
else if(x=='5')
{
	 buffer[num]='5';
  num++;
}

 
else if(x=='6')
{
	 buffer[num]='6';
  num++;
}

 
else if(x=='7')
{
	 buffer[num]='7';
  num++;
}
 
else if(x=='8')
{
	 buffer[num]='8';
  num++;
}

 
else if(x=='9')
{
	 buffer[num]='9';
  num++;
}
    
else if (x=='+')
{
	buffer[num]='+';
   num++;
}
else if (x=='-')
{
	     buffer[num]='-';
   num++;
}
else if (x=='x')
{
	     buffer[num]='x';
   num++;
}
else if (x=='/'){
     buffer[num]='/';
   num++;

}

else if (x=='d')

{

    if (num>0)
    	num--;

}
   //  delete 
   else if (x=='=')
   {
   for (int i=0;i<num;i++)
   {
   	cout<<buffer[i];
   }
   cout<<"=";
   result=caculate(buffer,num);
   cout<<result<<endl;



   return 0;

   }


}
}
