#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct supportingfile
{
    string CafeName;
    string dish;
    float rating;
    int price;
    int quantity;
};

int main(){
    supportingfile arr[5];

    ofstream out("cafe.txt", ios::app | ios::out);
    for (int i = 0; i < 5; i++)
    {
        out<<arr[i].CafeName<<" ";
        out<<arr[i].dish<<" ";
        out<<arr[i].rating<<" ";
        out<<arr[i].price<<" ";
        out<<arr[i].quantity<<" "<<endl;
    }
    out.close();
}