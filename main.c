#include<stdio.h>


int main()
{
char s[1001], b[101], *p[1001], *temp;
int w;
for(w=0; w<1001; w++)
{
s[w]='0';
}
gets(b);
gets(s);
int i, j, k=1;
p[0]=&s[0];
for(i=0; i<1000; i++)
{
for(j=0; j<100; j++)
{
if(s[i]==b[j]){s[i]='0'; p[k]=&s[i+1]; k++; break;}
}
}

for(i=0;i<1000;i++)
{
   if(s[i]==0) {s[i]='0'; break;}
}


for(i=0; i<k-2; i++)
{
for(j=i+1; j<k-1; j++)
{
int q=0;
temp = 0;
while(1)
{
if(*p[i]>*p[j] && *p[i]-*p[j]!=32){temp=p[i]; p[i]=p[j]; p[j]=temp; break;}
else if(*p[i]<*p[j] && *p[j]-*p[i]!=32){break;}
else if(*p[i]=='0' && *p[j]!='0'){break;}
else if(*p[j]=='0' && *p[i]!='0'){temp=p[i]; p[i]=p[j]; p[j]=temp; break;}
else if(i==j){break;}
else{p[i]=p[i]+1; p[j]=p[j]+1; q++;}
}
p[i]=p[i]-q; p[j]=p[j]-q;
}
}
char output[1001];
int h;
for(h=0; h<1000; h++)
{
output[h]='0';
}
int t=0;
for(i=0; i<k-1; i++)
{
for(j=0; *(p[i]+j)!='0'; j++)
{
output[t]= *(p[i]+j);
t++;
}
output[t]=' ';
t++;
}
t=0;
for(i=0; i<1000; i++)
{
if(output[i]==' '){t++;}
else break;
}
int u=0, d=999;
for(u=999; u>=0; --u)
{
if(output[u]=='0'){--d;}
else break;
}
int e;
for(e=t; e<d; e++)
{
printf("%c", output[e]);
}
return 0;
}