#include <iostream>
using namespace std;

typedef int labeltype;

struct element{
       labeltype label;
       int used;
};

struct bt
{
       element elements[10000];
};

void InitB(int x, bt *bstablo)
{
   if(bstablo)
   		delete bstablo;
   for(int i = 0; i < 10000; i++)
   {
           bstablo->elements[i].used = -1;
   }
   bstablo->elements[1].label = x;
   bstablo->elements[1].used = 1;
}

int RootB( bt *bstablo)
{
    return 1;
}
void CreateLeftB(int x, int oznaka, bt *bstablo)
{
    if(bstablo->elements[oznaka*2].used == 1)
    	cout << "Dijete vec postoji!" << endl;
    else
	{
          bstablo->elements[oznaka*2].label = x;
          bstablo->elements[oznaka*2].used = 1;
    }
}

void CreateRightB(int x, int oznaka, bt *bstablo)
{
     if(bstablo->elements[oznaka*2+1].used == 1)
    	cout << "Dijete vec postoji!" << endl;
     else
	 {
          bstablo->elements[oznaka*2+1].label = x;
          bstablo->elements[oznaka*2+1].used = 1;
     }
}    

int FindB(int x, bt *bstablo)
{
    for(int i=0; i<10000; i++)
	{
		if(bstablo->elements[i].label == x)
        return i;
    }
    
	cout << "Cvor ne postoji!" << endl;
	return 1;
}
int LeftChildB(int dijete, bt *bstablo)
{
	return dijete*2;
}

int RightChildB(int dijete, bt *bstablo)
{
    return dijete*2+1;
}

int LabelB(int oznaka, bt *bstablo)
{
    return bstablo->elements[oznaka].label;
}
void DeleteB(int x, bt *bstablo)
{
     if(bstablo->elements[x].used == 1)
	 {
        if(bstablo->elements[x*2].used == 1)
        	DeleteB(x*2, bstablo);
        	
        if(bstablo->elements[x*2+1].used == 1)
            DeleteB(x*2+1, bstablo);
            
        bstablo->elements[x].used = 0;
    	bstablo->elements[x].label = 0;
    }
     else
         cout << "Cvor ne postoji." << endl;
}
void ChangeLabelB(int x, int oznaka, bt *bstablo)
{
     bstablo->elements[oznaka].label = x;
}

int ParentB(int dijete, bt *bstablo)
{
    if(dijete == 1)
    	return 0;
    return dijete/2;
}

