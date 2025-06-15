#include<iostream>

using namespace std;

int fibonacci (int n)
{
    if (n<0){
        cerr<<"Invalid term index for fibonacci";
        exit(1);
    }
    else if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n;
    cout<<"Enter: ";
    cin>>n;
    cout<<"Fibonnaci term "<<n<<" is "<<fibonacci(n)<<".";
    return 0;
}