#include<iostream>

using namespace std;

int factorial (int n)
{
    if (n<0){
        cerr<<"Invalid input for factorial";
        exit(1);
    }
    else if (n == 0) return 1;
    else return n*factorial(n-1);
}

int main()
{
    int n;
    cout<<"Enter: ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is "<<factorial(n)<<"."<<endl;
    return 0;
}