#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Details
{
    string CafeName;
    string dish;
    float rating;
    int price;
    int quantity;
};
int p = 0;

void Dash(int size)
{
    /*For Aesthetic Purpose*/
    for (int i = 0; i < size; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void Search_By_Dish(string DishName)
{
    /*This is the implemented code for Searching any dish using its name, 
    it will take the name of that dish as an input and then return its price, quantity and rating from different cafes.*/
    Details CafeDetails[20];
    int i = 0;
    string ar[5];
    string b;
    fstream in("cafe.txt", ios::out | ios::in);
    while (!in.eof())
    {

        in >> CafeDetails[i].CafeName;
        in >> CafeDetails[i].dish;
        in >> CafeDetails[i].rating;
        in >> CafeDetails[i].price;
        in >> CafeDetails[i].quantity;

        if (CafeDetails[i].dish == DishName)
        {
            Dash(105);
            cout << "|\tCafe Name\t|\tDish\t|\tRating\t|\tPrice\t|\tQuantity (In Plates)\t|" << endl;

            cout << "|\t" << CafeDetails[i].CafeName << "\t\t";
            cout << "|\t" << CafeDetails[i].dish << "\t";
            cout << "|\t" << CafeDetails[i].rating << "\t";
            cout << "|\t" << CafeDetails[i].price << "\t";
            cout << "|\t\t" << CafeDetails[i].quantity << "\t\t|";
            cout << endl;
            Dash(105);
        }
        i++;
    }
}

void UpdateRating(string cafe_name, string Dish, float rate)
{
    /*This is an implemented code in C++ which asks 
    the user about the deliciousness of a particular dish that he recently tried 
    and then update the average of previous database rating and the new rating.*/
    Details CafeDetails[5];
    int i = 0;
    string ar[5];
    string b;
    fstream in("cafe.txt", ios::out | ios::in);
    while (!in.eof())
    {

        in >> CafeDetails[i].CafeName;
        in >> CafeDetails[i].dish;
        in >> CafeDetails[i].rating;
        in >> CafeDetails[i].price;
        in >> CafeDetails[i].quantity;

        // ifstream  inf("data3.txt");

        if (CafeDetails[i].dish == Dish && CafeDetails[i].CafeName == cafe_name)
        {

            float r = (CafeDetails[i].rating + rate) / 2;
            CafeDetails[i].rating = r;
            cout << "\n\n\t!!! Thank You For Your Valuable Feedback !!!\n\t\tIt Will Help Us To Improve";
        }
        else
        {
            cout << "!!!Error!!!\nThis Cafe Doesn't Contain This Dish";
        }
        ofstream out("data.txt");
        for (int j = 0; j < 5; j++)
        {

            out << CafeDetails[j].CafeName << " ";
            out << CafeDetails[j].dish << " ";
            out << CafeDetails[j].rating << " ";
            out << CafeDetails[j].price << " ";
            out << CafeDetails[j].quantity << " " << endl;
        }
        out.close();
        i++;
    }
    in.close();
    remove("cafe.txt");
    rename("data.txt", "cafe.txt");
}

void merge(float *arr, Details *CafeDetails, int low, int high, int mid)
{
    /*This function returns the sorted array of the ratio of price and quantity of the dish */
    int i, j, k, c[50];
    Details d[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {

        if (arr[i] < arr[j])
        {

            c[k] = arr[i];
            d[k] = CafeDetails[i];
            k++;
            i++;
        }
        else
        {

            c[k] = arr[j];
            d[k] = CafeDetails[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {

        c[k] = arr[i];
        d[k] = CafeDetails[i];
        k++;
        i++;
    }
    while (j <= high)
    {

        c[k] = arr[j];
        d[k] = CafeDetails[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {

        arr[i] = c[i];
        CafeDetails[i] = d[i];
    }
}

void merge_sort(float *arr, Details *a, int low, int high)
{
    int mid;
    if (low < high)
    {

        mid = (low + high) / 2;
        merge_sort(arr, a, low, mid);
        merge_sort(arr, a, mid + 1, high);
        merge(arr, a, low, high, mid);
    }
}

void Search_By_Cafe(string CafName, int budget = 0)
{
    /*
    This is an implemented code in c++ for returning different dish 
    with all of its parameters like quantity, price and rating 
    so that user get to know that which dish is better in that particular café. 
    This code also asks from the user whether he wants the suggestions of dishes based on his budget 
    so that he need not waste his time in searching of dishes from that café menu 
    instead directly order those special dishes and starts enjoying them instantaneously.
    */
    string Suggested[5];
    float pw[5];
    int Bill = 0;
    int k = 0;
    int Profit = 0;
    Details CafeDetails[20];
    ifstream in("cafe.txt");
    for (int i = 0; i = !in.eof(); i++)
    {

        in >> CafeDetails[i].CafeName;
        if (CafeDetails[i].CafeName == CafName && budget == 0)
        {
            Dash(105);
            cout << "|\tCafe Name\t|\tDish\t|\tRating\t|\tPrice\t|\tQuantity (In Plates)\t|" << endl;

            in >> CafeDetails[i].dish;
            cout << CafeDetails[i].dish << " ";
            in >> CafeDetails[i].rating;
            cout << CafeDetails[i].rating << " ";
            in >> CafeDetails[i].price;
            cout << CafeDetails[i].price << " ";
            in >> CafeDetails[i].quantity;
            cout << CafeDetails[i].quantity << " ";
            pw[p] = CafeDetails[i].price / CafeDetails[i].quantity;
            p++;
        }
        cout << endl;
        cout << endl;
    }
    in.close();
    merge_sort(pw, CafeDetails, 0, 5);

    if (budget != 0)
    {
        Details sug[50];
        ifstream inf("cafe.txt");
        for (int u = 0; u < 200; u++)
        {
            inf >> sug[u].CafeName;
            inf >> sug[u].dish;
            inf >> sug[u].rating;
            inf >> sug[u].price;
            inf >> sug[u].quantity;

            if (budget > 0 && sug[u].price <= budget)
            {
                Suggested[k] = sug[u].dish;
                k++;
                budget = budget - sug[u].price;
                Bill = Bill + sug[u].price;
            }
            else if (budget > 0)
            {

                int temp = pw[u] * budget;
                Suggested[k] = sug[u].dish;
                k++;
                Bill = Bill + temp * sug[u].price;
                Profit = budget - Bill;
                break;
            }
        }
        inf.close();
        cout << "Your Suggestions are Listed Below - " << endl;
        Dash(41);
        cout << "|\tS.No.\t|\tSuggested Dish\t|" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "|\t" << i + 1 << ". \t|\t" << Suggested[i] << "\t\t|" << endl;
        }
        Dash(41);
        cout << endl;

        cout << "And you are remained with the profit of " << Profit << endl
             << endl;
    }
}

int main()
{
    int option = 0;
    string CafName;
    string DishName;

    cout<<"\n\t\t\tWelcome To The World of Cafe\n\n";
    cout<<"\tPlease Select The Helping Option \n\tSo That We Can Get A Chance To Help YOu- \n\n";

    cout << "\t1. Search for the dish" << endl;
    cout << "\t2. Search for the cafes" << endl;
    cout << "\t3. Rate the dishes of any Cafe" << endl;
    cout << "\t4. Exit\n" << endl;
    cout << "Enter your Choice - ";
    cin >> option;
    switch (option)
    {
    case 1:

        cout << "Drop Your Fvt Dish -> \n";
        cin >> DishName;
        Search_By_Dish(DishName);
        break;

    case 2:

        int choice;
        cout << "Enter the Name of Your Fvt Cafe -> \n";
        cin >> CafName;
        cout << "Press 1 if You want to get suggestion of dish from this cafe - "<<endl;
        cin >> choice;
        if (choice == 1)
        {
            int budget;
            cout << "Enter Your Budget -> ";
            cin >> budget;

            Search_By_Cafe(CafName, budget);
        }
        else
        {
            Search_By_Cafe(CafName);
            break;
        }
        break;

    case 3:

        float rate;
        cout << "Drop the Cafe Name -> \n";
        cin >> CafName;
        cout << "Drop the Dish you want to rate -> \n";
        cin >> DishName;
        while (true)
        {
            cout << "Rate your Dish out of 5 * -> \n";
            cin >> rate;
            if (rate <= 5)
            {
                break;
            }
            else
            {
                cout << "\nPlease Rate with the Appropriate Feedback \n";
            }
        }
        UpdateRating(CafName, DishName, rate);
        break;
    }
    return 0;
}