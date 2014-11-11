#include<stdio.h>


int main()
{
  char input[1001], delims[101], *tokens[1001], *temp;
  int w;

  for(w=0; w<1001; w++)
  {
    input[w]='0';
  }

  gets(delims);
  gets(input);

  int i, j, k=1;
  tokens[0]=&input[0];
  for(i=0; i<1000; i++)
  {
    for(j=0; j<100; j++)
    {
      if(input[i]==delims[j]){input[i]='0'; tokens[k]=&input[i+1]; k++; break;}
    }
  }

  for(i=0;i<1000;i++)
  {
    if(input[i]==0) {input[i]='0'; break;}
  }


  for(i=0; i<k-2; i++)
  {
    for(j=i+1; j<k-1; j++)
    {
      int q=0;
      temp = 0;
      while(1)
      {
        if(*tokens[i]>*tokens[j] && *tokens[i]-*tokens[j]!=32){temp=tokens[i]; tokens[i]=tokens[j]; tokens[j]=temp; break;}
        else if(*tokens[i]<*tokens[j] && *tokens[j]-*tokens[i]!=32){break;}
        else if(*tokens[i]=='0' && *tokens[j]!='0'){break;}
        else if(*tokens[j]=='0' && *tokens[i]!='0'){temp=tokens[i]; tokens[i]=tokens[j]; tokens[j]=temp; break;}
        else if(i==j){break;}
        else{tokens[i]=tokens[i]+1; tokens[j]=tokens[j]+1; q++;}
      }
      tokens[i]=tokens[i]-q; tokens[j]=tokens[j]-q;
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
    for(j=0; *(tokens[i]+j)!='0'; j++)
    {
      output[t]= *(tokens[i]+j);
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
