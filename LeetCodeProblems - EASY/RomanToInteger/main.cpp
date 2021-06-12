#include <iostream>

using namespace std;

int convert(string s, int len)
{
    int sum = 0;
    int n = len;
       for(int i=0;i<n;i++)
       {
           if(s[i]=='I')
           {
               if(i+1<n && s[i+1]=='V')
                   sum+=4;
               else if(i+1<n && s[i+1]=='X')
                   sum+=9;
               else
                   sum+=1;
           }
           else if(s[i]=='V')
           {
               if(i-1>=0 && s[i-1]=='I')
                   sum+=0;
               else
                   sum+=5;
           }
           else if(s[i]=='X')
           {
               if( i-1>=0 && s[i-1]=='I')
                   sum+=0;
               else if(i+1<n && s[i+1]=='L')
                   sum+=40;
               else if(i+1<n && s[i+1]=='C')
                   sum+=90;
               else
                   sum+=10;
           }
           else if(s[i]=='L')
           {
               if(i-1>=0 && s[i-1]=='X')
                   sum+=0;
               else
                   sum+=50;
           }
           else if(s[i]=='C')
           {
               if(i-1>=0 && s[i-1]=='X')
                   sum+=0;
               else if(i+1<n && s[i+1]=='D')
                   sum+=400;
               else if( i+1<n && s[i+1]=='M')
                   sum+=900;
               else
                   sum+=100;

           }
           else if(s[i]=='D')
           {
               if(i-1>=0 && s[i-1]=='C')
                   sum+=0;
               else
                   sum+=500;
           }
           else if(s[i]=='M')
           {
               if(i-1>=0 && s[i-1]=='C')
                   sum+=0;
               else
                   sum+=1000;
           }

       }
        return sum;
}

int main()
{
    cout << "Enter a String of Roman Letters(caps): " << endl;
    string s;cin >> s;
    int len = s.size();
    int k = convert(s,len);
    cout << "\nOutput : " << k;
    return 0;
}
