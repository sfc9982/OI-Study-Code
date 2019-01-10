#include <iostream>
#include <algorithm>
using namespace std;

struct patientStruct
{
    long long int order;
    char id[11];
    long long int age;
} sick[101];

bool cmp(patientStruct x, patientStruct y)
{
    if (x.age >= 60 && y.age < 60)
        return 1;
    if (x.age < 60 && y.age >= 60)
        return 0;
    if (x.age >= 60 && x.age >= 60 && x.age > y.age)
        return 1;
    if (x.age >= 60 && x.age == y.age && x.order < y.order)
        return 1;
    if (x.age < 60 && x.order < y.order)
        return 1;
    return 0;
}

//bool cmp_Old(patientStruct a, patientStruct b)
//{
//    if (a.age != b.age)
//        return a.age > b.age;
//    else
//        return a.order < b.order;
//}
//
//bool cmp_Young(patientStruct a, patientStruct b)
//{
//    return a.order < b.order;
//}

int main()
{
    long long int n, old;

    cin >> n;

    old = 0;

    for (long long int i = 1; i <= n; i++)
    {
        cin >> sick[i].id >> sick[i].age;
        sick[i].order = i;
        if (sick[i].age >= 60)
        {
            old++;
        }
    }

    sort(sick + 1, sick + n + 1, cmp);
    //sort(sick + 1, sick + old + 1, cmp_Old);
    //sort(sick + old + 1, sick + n, cmp_Young);

    for (long long int i = 1; i <= n; i++)
    {
        cout << sick[i].id << endl;
    }

    //system("pause");
    return 0;
}