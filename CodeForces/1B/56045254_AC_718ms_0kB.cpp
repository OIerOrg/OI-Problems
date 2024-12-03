#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string str;
int n,len;
void trans(bool mode)
{
    char apt[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int col = 0,row = 0;
    if(mode)
    {
        int R = str.find("R"),C = str.find("C");
        for(int i = R + 1;i < C;i++)
            row = row * 10 + str[i] - '0';
        for(int i = C + 1;i < len;i++)
            col = col * 10 + str[i] - '0';
        string ans;
        while(col > 0)
        {
            int temp = col % 26;
            if(temp == 0) temp = 26,col -= 26;
            ans += apt[temp];
            col /= 26;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<row<<endl;
    }
    else
    {
        for(int i = 0;i < len;i++)
        {
            if(!isdigit(str[i])) 
                col = col * 26 + str[i] - 'A' + 1;
            else row = row * 10 + str[i] - '0';
        }
        printf("R%dC%d\n",row,col);
    }
} 
int main()
{
    scanf("%d",&n);    
    for(int i = 1;i <= n;i++)
    {
        cin>>str;
        bool flag = 0,mode = 0;
        len = str.length();
        for(int i = 0;i < len;i++)
        {
            if(isdigit(str[i])) flag = 1;
            if(flag&&str[i] == 'C')
            {
                mode = 1; 
                break;
            }
        }
        trans(mode);
    }
    return 0;
}
