#include <iostream>

using namespace std;

void PreOrder(int n, tr *stablo)
{
     cout << LabelT(n, stablo);
     cout << " ";
     
     if(FirstChildT(n, stablo) != -1)
     	PreOrder(FirstChildT(n, stablo), stablo);
     if(NextSiblingT(n, stablo) != -1)
     	PreOrder(NextSiblingT(n, stablo), stablo);
}

void InOrder(int n, tr *stablo)
{
     if(FirstChildT(n, stablo) != -1)
     	InOrder(FirstChildT(n, stablo), stablo);
     	
     cout << LabelT(n, stablo);
     cout << " ";
     
     if(FirstChildT(n, stablo) != -1)
	 {
        n = FirstChildT(n, stablo);
        while(NextSiblingT(n, stablo) != -1)
		{
        	n = NextSiblingT(n, stablo);
            InOrder(n, stablo);
        }
    }
}

void PostOrder(int n, tr *stablo)
{
     if(FirstChildT(n, stablo) != -1)
     	PostOrder(FirstChildT(n, stablo), stablo);
     
	 int temp = n;
     if(FirstChildT(temp, stablo) != -1)
	 {
        temp = FirstChildT(temp, stablo);
        while(NextSiblingT(temp, stablo) != -1)
		{
            temp = NextSiblingT(temp, stablo);
            PostOrder(temp, stablo);
        }
    }
     cout << LabelT(n, stablo);
     cout << " ";
}
