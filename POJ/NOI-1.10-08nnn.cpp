#include <iostream>
#include <algorithm>
using namespace std;

struct patientStruct
{
    long long int order;
    char id[99];
    long long int age;
} sick[100032];

bool cmp(patientStruct a, patientStruct b)
{
    return a.age > b.age;
}

bool cmp_Old(patientStruct a, patientStruct b)
{
    if (a.age != b.age)
        return a.age > b.age;
    else
        return a.order < b.order;
}

bool cmp_Young(patientStruct a, patientStruct b)
{
    return a.order < b.order;
}

int main()
{
    long long int n, old;

    cin >> n;

    old = 0;

    for (long long int i = 0 ; i < n; i++)
    {
        cin >> sick[i].id >> sick[i].age;
        sick[i].order = i;
        if (sick[i].age >= 60)
        {
            sick[i].age = 1000000 + sick[i].age*1000+999-i;         //   old++;
        }
        else
        {
            sick[i].age =  1000-i;         //   old++;
        }
    }

    sort(sick , sick + n-1, cmp);
    //sort(sick + 1, sick + old, cmp_Old);
    //sort(sick + old + 1, sick + n, cmp_Young);

    for (long long int i = 0; i < n; i++)
    {
        cout << sick[i].id << endl;
    }

    //system("pause");
    return 0;
}
