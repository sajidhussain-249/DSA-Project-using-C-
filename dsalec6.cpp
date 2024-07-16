#include <iostream>
using namespace std;
int main(){
    int marks;
    cout<<"Student, please enter the marks to calculate the grade:";
    cin>>marks;
    if(marks>90){
        cout<<"A";
    }
    else if(marks>80 && marks<90){
        cout<<"B";
    }
    else if(marks>70 && marks<80){
        cout<<"C";
    }
    else{
        cout<<"Pass";
    }
    return 0;
}