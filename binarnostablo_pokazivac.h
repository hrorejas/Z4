#include <iostream>
using namespace std;

typedef int labeltype;


struct bt
{
       labeltype label;
       bt *left, *right;
};

typedef bt *bs;

bs InitB(int k, bt *bstablo)
{
    bstablo->label = k;
    bstablo->left = NULL;
    bstablo->right = NULL;
}


bs RootB(bt *bstablo)
{
	if(bstablo)
    	return bstablo;
    else
    	cout << "Stablo ne postoji!" << endl;
}

void CreateLeftB(int ime, bt *cvor, bt *bstablo)
{
	if(cvor->left != NULL)
    	cout << "Dijete vec postoji!" << endl;
    else
	{
		bt *pom = new bt;
        pom->right = NULL;
        pom->left = NULL;
        pom->label = ime;
        cvor->left = pom;
    }
}
void CreateRightB(int ime, bt *cvor, bt *stablo)
{
	if(cvor->right != NULL)
        cout << "Dijete vec postoji!" << endl;
    else 
	{
		bt *pom = new bt;
        pom->right = NULL;
        pom->left = NULL;
        pom->label = ime;
        cvor->right = pom;
	}
}
bs FindB(int x, bt *bstablo)
{
	bt *tekuci, *tekuci2;
    tekuci = bstablo;
    while(tekuci)
	{
		if(tekuci->label == x)
        	return tekuci;
        else
        	tekuci = tekuci->right;
    }
    tekuci2 = bstablo;
    while(tekuci2)
	{
		if(tekuci2->label == x)
    		return tekuci2;
    	else
    		tekuci2 = tekuci2->left;
    }
   	cout << "Cvor nije nadjen!" << endl;
   	bt *zadnji;
   	zadnji = bstablo;
   	
   	while(zadnji->left)
		zadnji = zadnji->left;
	
   	return zadnji;
}

int LabelB(bt *cvor, bt *stablo)
{
    if(cvor == NULL)
            cout << "Cvor ne postoji!" << endl;
    else
        return cvor->label;
}

bs LeftChildB(bt *cvor, bt *bstablo)
{
	if(cvor == NULL)
    	cout << "Lijevo dijete ne postoji!" << endl;
    else
    	return cvor->left;
}
bs ParentB(bt *cvor, bt *bstablo)
{
	if(cvor == bstablo)
    	cout << "Cvor je korijen" << endl;
    else
	{
		bt *pom = NULL;
		
        if(bstablo->left)
		{
			if(bstablo->left == cvor)
            	return bstablo;
            pom = ParentB(cvor, bstablo->left);
        }
        if(bstablo->right)
		{
            if(bstablo->right == cvor)
            	return bstablo;
            pom = ParentB(cvor, bstablo->right);
        }
        return pom;
    }
}
bs RightChildB(bt *cvor, bt *bstablo)
{  
   if(cvor == NULL)
           cout << "Desno dijete ne postoji!" << endl;
   else
       return cvor->right;
}
void DeleteB(bt *cvor, bt *bstablo)
{
	if(cvor == bstablo)
	{
    	cout << "Korijen se ne moze obrisati!" << endl;
        return;
    }
    if(cvor->left != NULL)
    	DeleteB(cvor->left, bstablo);
    
	if(cvor->right != NULL)
    	DeleteB(cvor->right, bstablo);
    
	if(cvor != RootB(bstablo) && LeftChildB(ParentB(cvor,bstablo),bstablo) == cvor)
		ParentB(cvor, bstablo)->left = NULL;
    
	else if(cvor != RootB(bstablo))
		ParentB(cvor, bstablo)->right = NULL;
    
	delete cvor;
}

void ChangeLabelB(int ime, bt *cvor, bt *bstablo)
{
	if(!bstablo)
    	cout << "Nije moguce promjeniti!" << endl;
    else
    	cvor->label = ime;
}

