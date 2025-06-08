#include<iostream>

using namespace std;

int tail_fibonacci (int n, int a = 0 , int b = 1)
{
    if (n<0){
        cerr<<"Invalid term index for fibonacci";
        exit(1);
    }
    else if (n == 0) return a;
    else return tail_fibonacci (n-1, b , a+b);
    
}

int main()
{
    int n;
    cout<<"Enter: ";
    cin>>n;
    cout<<"Fibonnaci term "<<n<<" is "<<tail_fibonacci(n)<<".";
    return 0;
}