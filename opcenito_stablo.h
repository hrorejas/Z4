#include <iostream>
using namespace std;
#define MAX_ELEMENTS 100000

typedef int labeltype;

struct elem {
  labeltype label;
  int firstchild, nextsibling;
};

struct tr {
  elem elements[MAX_ELEMENTS];
  int first;
};

void IniT (int x, tr *stablo)
{
	for(int i=0; i<MAX_ELEMENTS; i++)
	{
             stablo->elements[i].firstchild = -1;
             stablo->elements[i].nextsibling = -1;
             stablo->elements[i].label = -1;
    }
     stablo->first = x;
     cout << "Upisite oznaku korijena: "<<endl;
     cin >> stablo->elements[x].label;
    
}

int RootT(tr *stablo)
{
    return stablo->first;
}

void CreateT(int x, int n, tr *stablo) // x dijete cvora n
{
	 //Provjerava da li cvor uopce i postoji
     if(stablo->elements[n].label == -1)
    	cout << "Cvor ne postoji!" << endl;
    	
     // Ako èvor nema dijece dodaj mu djete	
     else if(stablo->elements[n].firstchild == -1)
	 {
         stablo->elements[n].firstchild = x;
         cout << "Oznaka: ";
         cin >> stablo->elements[x].label;
     }
    
    //ako èvor ima dijete 
     else
	 {
	 	int brat;
        bool provjera = true;
          
        brat = stablo->elements[n].firstchild;
        do
        {
        	if(stablo->elements[brat].nextsibling == -1)
        		provjera = false;
        	
            else
            	brat = stablo->elements[brat].nextsibling;
     	}while(provjera);
     	
	 	stablo->elements[brat].nextsibling = x;
     	cout << "Oznaka: ";
     	cin >> stablo->elements[x].label;
     }
}

int FirstChildT(int x, tr *stablo)
{
    return stablo->elements[x].firstchild;
}

int NextSiblingT(int n, tr *stablo)
{
    return stablo->elements[n].nextsibling;
}

int ParentT(int n, tr *stablo)
{
    for(int i=0; i<MAX_ELEMENTS; i++)
	{
            if(stablo->elements[i].firstchild == n)
            	return i;
            else if(stablo->elements[i].nextsibling == n)
                return ParentT(i, stablo);
    }
    return -1;
}

int LabelT(int n, tr *stablo)
{
     if(stablo->elements[n].label == -1)
     	return -1;
     else
     	return stablo->elements[n].label; 
}
void ChangeLabelT(int x, int n, tr *stablo)
{
	if (stablo->elements[n].label ==-1)
	{
		cout << "Cvor ne postoji!" << endl;
		return;
	}
    
	stablo->elements[n].label = x;
}

void Delete(int n, tr *stablo)
{
     if(stablo->elements[n].nextsibling == -1 && stablo->elements[ParentT(n,stablo)].firstchild == n)
	 {
	 	stablo->elements[ParentT(n,stablo)].firstchild = -1;
        stablo->elements[ParentT(n,stablo)].label = -1;
        stablo->elements[n].label = -1;
    }
     else if(stablo->elements[n].nextsibling != -1 && stablo->elements[ParentT(n,stablo)].firstchild == n)
          stablo->elements[ParentT(n,stablo)].firstchild = stablo->elements[n].nextsibling;
     else 
	 {
          int brat = stablo->elements[ParentT(n,stablo)].firstchild;
          while(stablo->elements[brat].nextsibling != n)
          brat = stablo->elements[brat].nextsibling; 
          stablo->elements[brat].nextsibling = stablo->elements[n].firstchild;
    }
}

void DeleteT(int n, tr *stablo)
{
     if(stablo->elements[n].label == -1)
        cout << "Cvor ne postoji!" << endl;
     
	 else if(stablo->elements[n].firstchild != -1)
	 {
          while(stablo->elements[n].firstchild != -1)
          	Delete(stablo->elements[n].firstchild, stablo);
     	Delete(n, stablo);
     }
     else
         Delete(n,stablo);
}
