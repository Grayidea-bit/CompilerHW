#include<iostream>
#include<fstream>
#include <string.h>
using namespace std;
int checkInt(string temp)
{
    int check=0,index=0;
    for(char i : temp)
    {
        if(i==45&&index==0)
        {
            index=1;
        }
        else if(i<48||i>57) check++;
    }
    if(check==0) return 1;
    else return -1;
}

int checkFloat(string temp)
{
    int check=0,index=0,dot_count=0;
    for(char i : temp)
    {
        if(i==45&&index==0)
        {
            index=1;
        }
        else if(i==46&&index!=0)
        {
            dot_count++;
        }
        else if(i<48||i>57) 
        {
            check++;
        }
        index++;
    }
    if(check==0&&temp[temp.size()-1]!=46&&dot_count==1) return 1;
    else return -1;
}

int checkId(string temp)
{
    int check=0,checkFirst=0,index=0;
    for(char i : temp)
    {
        if(((i>=65&&i<=90)||(i>=97&&i<=122))&&checkFirst==0)
        {
            checkFirst++;
        }
        else if((i==95||(i>=48&&i<=57))&&checkFirst!=0){}
        else if(i<65||(i>90&&i<97)||i>122) check++;
    }
    if(check==0&&checkFirst!=0) return 1;
    else return -1;
}

int main()
{
    int totalInt=0,totalFloat=0,totalId=0,totalError=0;
    string temp;
    ifstream in;
    in.open("test.txt");
    while(getline(in,temp,'\n'))
    {
        if(temp=="")
        {
            cout << endl;
        }
        else if(checkInt(temp)==1)
        {
            cout << "Find a Int: " << temp << endl;
            totalInt++;
        }
        else if(checkFloat(temp)==1)
        {
            cout << "Find a Float: " << temp << endl;
            totalFloat++;
        }
        else if(checkId(temp)==1)
        {
            cout << "Find an Identifier(ID): " << temp << endl;
            totalId++;
        }
        else
        {
            cout << "Find an Error: " << temp << endl;
            totalError++;
        }
    }
    printf("Total_Int = %d\n",totalInt);
    printf("Total_Float = %d\n",totalFloat);
    printf("Total_Identifier(ID) = %d\n",totalId);
    printf("Total_Error = %d\n",totalError);
}