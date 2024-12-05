#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int numC=0,symC=0;
int nextMinus=0;
int numArray[100];
char symArray[100];

int prec(char symbol)
{
    if(symbol=='+'||symbol=='-') return 1;
    if(symbol=='*'||symbol=='/') return 2;   
    return 0; 
}

void readNeg(string num)
{
    if(num[symC+numC]=='-')
    {
        nextMinus=1;
    }
}

void dostringToInt(string num)
{
    int number=0;
    for(char i : num)
    {
        if(i!=13) number=(i-'0')+number*10;
    }
    if(nextMinus==1) {number*=-1;nextMinus=0;}
    numArray[numC++] = number;
}

void doCalculate() 
{
    int a = numArray[numC-2];
    int b = numArray[numC-1];
    int c = symArray[symC-1];
    if(c=='+') {cout << a << "+" << b << "=" << a+b << endl;numArray[numC-2]=a+b;}
    if(c=='-') {cout << a << "-" << b << "=" << a-b << endl;numArray[numC-2]=a-b;}
    if(c=='*') {cout << a << "*" << b << "=" << a*b << endl;numArray[numC-2]=a*b;}
    if(c=='/') {cout << a << "/" << b << "=" << a/b << endl;numArray[numC-2]=a/b;}
    symC--;
    numC--;
}

void dealBracket() 
{
    while(symArray[symC-1]!='(')
    {
        doCalculate();
    }
    symC--;
}


void throwIntoArray(string input) 
{
    int last;
    string numTemp;
    if(input[0]=='('||input[0]=='-') last=0;
    else last=1;

    for(char c : input)
    {
        if(c=='(') 
        {
            readNeg(input);
            if(numTemp!="") {dostringToInt(numTemp);numTemp="";}
            symArray[symC++]=c;
            last=0;
        }
        else if(c==')')
        {
            if(numTemp!="") {dostringToInt(numTemp);numTemp="";}
            dealBracket();
            last=0;
        }
        else if(c=='*'||c=='/'||c=='+'||c=='-') 
        {
            readNeg(input);
            if(numTemp!="") {dostringToInt(numTemp);numTemp="";}
            if(nextMinus==1&&c=='-') continue;
            if(symC==0) symArray[symC++]=c;
            else
            {
                while(prec(c)<=prec(symArray[symC-1]))
                {
                    doCalculate();
                }
                if(prec(c)>prec(symArray[symC-1])) symArray[symC++]=c;
            }
            last=0;
        }
        else if(c!='\r')
        {
            numTemp+=c;
            last=1;
        }
    }
    if(numTemp!="") {dostringToInt(numTemp);numTemp="";}
    while(symC>0){doCalculate();}
    cout << "ans:" << numArray[0] << endl << "------" << endl;
}
void init()
{
    for(int i=0;i<100;i++)
    {
        numArray[i]=0;
        symArray[i]=' ';
    }
    numC=0;
    symC=0;
}

int main()
{
    string input;
    ifstream in;
    in.open("test.txt");
    while(getline(in,input,'\n'))
    {
        throwIntoArray(input);
        init();
    }
}