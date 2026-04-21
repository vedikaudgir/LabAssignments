#include <bits/stdc++.h>
using namespace std;


struct Page
{
    int pageNo;
    int frameNo;
};


string toBinary(int num)
{
    return bitset<16>(num).to_string();
}


int main()
{
    int n;
    cout << "Enter number of pages - ";
    cin >> n;


    vector<Page> pages(n);


    for (int i = 0; i < n; i++)
    {
        pages[i].pageNo = i;
        cout << "Enter frame number for page " << i << " - ";
        cin >> pages[i].frameNo;
    }


    int pageSize;
    cout << "\nEnter page size - ";
    cin >> pageSize;


    int logicalAddr;
    cout << "Enter logical address - ";
    cin >> logicalAddr;


    int pageNo = logicalAddr / pageSize;
    int offset = logicalAddr % pageSize;


    if (pageNo >= n)
    {
        cout << "\nInvalid logical address";
        return 0;
    }


    int frameNo = pages[pageNo].frameNo;
    int physicalAddress = frameNo * pageSize + offset;


    cout << "\nPage number = " << pageNo;
    cout << "\nOffset = " << offset;
    cout << "\nFrame number = " << frameNo;
    cout << "\nPhysical address = " << physicalAddress;
    cout << "\nPhysical Address (Binary)  = " << toBinary(physicalAddress) << endl;


    return 0;
}


