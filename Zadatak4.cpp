#include <iostream>
#include "opcenito_stablo.h"
#include "ophodenje_stabla.h"
#include "binarnostablo_pokazivac.h"
//#include "binarnostablo_polje.h"opce
using namespace std;

tr *stablo = new tr;
bt *bstablo = new bt;
void opStablo()
{
	int korijen, izbor,cvor,dijete,ime;

	cout <<"Unesite korijen stabla: "<<endl;
	cin >> korijen;
	
	IniT(korijen,stablo);
	
	do
	{
		cout <<"---------------" << endl;
     	cout <<"OPCENITO STABLO" << endl;
     	cout <<"---------------" << endl;
     	cout <<"1. Ispis korijena stabla " <<endl;
     	cout <<"2. Dodavanje cvora" << endl;
     	cout <<"3. Prvo dijete" << endl;
     	cout <<"4. Braca" << endl;
     	cout <<"5. Roditelj dijeteta" << endl;
     	cout <<"6. Provjena oznake cvora" <<endl;
     	cout <<"7. Promjena oznake cvora" <<endl;
     	cout <<"8. Brisanje cvora" <<endl;
		cout <<"9. Povratak u glavni izbornik" << endl;
		cin >>izbor;
		cout <<"---------------" << endl;
		switch(izbor)
		{
			case 1:
				cout <<"Korijen stabla je: " << RootT(stablo) <<endl;
				break;
				
			case 2:
				cout << "Unesite cvor gdje zelite stvoriti dijete: ";
                cin >> cvor;
                
				cout << "Unesite cvor dijeteta: ";
                cin >> dijete;
                
				CreateT(dijete, cvor, stablo);
				break;
			
			case 3:
				cout <<"Prvo dijete cvora: ";
				cin >>cvor;
				
				cout <<"Prvo dijete cvora " << cvor << " je " << FirstChildT(cvor,stablo)<<endl;
				break;
			
			case 4:
				cout << "Unesite cvor: ";
                cin >> cvor;
                
				cout << "Brat cvora " << cvor << " je " << NextSiblingT(cvor, stablo) << endl;
                break;
                
            case 5:
            	cout << "Unesite cvor: ";
                cin >> cvor;
                
                cout << "Roditelj cvora " << cvor << " je " << ParentT(cvor,stablo) << endl;
                break;
            
            case 6:
            	cout << "Unesite cvor: ";
                cin >> cvor;
                
                cout << "Cvor " << cvor << " ima oznaku " << LabelT(cvor, stablo) << endl;
                break;
            case 7:
            	cout << "Unesite cvor: ";
            	cin >> cvor;
            	
                cout << "Unesite novu oznaku cvora: ";
                cin >> ime;
                
                ChangeLabelT(ime, cvor, stablo);
                break;
                
            case 8:
            	 cout << "Unesite cvor koji zelite obrisati: ";
                cin >> cvor;
                
				DeleteT(cvor, stablo);
                break;
            
			default: cout << "Upisali ste krivi broj!" << endl;

				
		}
	}while(izbor != 9);
}

void drugi()
{
	int izbor;
	do
	{
		cout << "---------------" << endl;
     	cout << "OPHODENJE STABLA" << endl;
     	cout << "---------------" << endl;
		cout << "1. PreOrder" << endl;
     	cout << "2. InOrder" << endl;
     	cout << "3. PostOrder" << endl;
     	cout << "4. Povratak u glavni izbornik" <<endl;
     	cin >> izbor;
     	
     	switch(izbor)
     	{
     		case 1:
     			cout << "--------" << endl;
     			cout << "Preorder" << endl;
                cout << "--------" << endl;
     			PreOrder(RootT(stablo), stablo);
     			break;

     		case 2:
     			cout << "--------" << endl;
     			cout << "Inorder" << endl;
                cout << "--------" << endl;
                InOrder(RootT(stablo), stablo);
                break;
                
     		case 3:
     			cout << "--------" << endl;
     			cout << "Postorder" << endl;
                cout << "--------" << endl;
                PostOrder(RootT(stablo), stablo);
                break;
            
			default: cout << "Upisali ste krivi broj!" << endl;

     	}
	}while (izbor != 4);
}

void treci()
{
	 int k, izbor, oznaka, cvor;
     cout << "Korijen binarnog stabla: ";
     cin >> k;
     InitB(k,bstablo);
     
     do
     {
     	cout <<"---------------" << endl;
     	cout <<"Binarno STABLO" << endl;
     	cout <<"---------------" << endl;
     	cout <<"1. Korijen" <<endl;
		cout <<"2. Dodaj lijevo dijete" << endl;
     	cout <<"3. Dodaj desno dijete" << endl;
     	cout <<"4. Ispis lijevog dijeteta" << endl;
     	cout <<"5. Ispis denog dijeteta" << endl;
        cout <<"6. Brisanje cvora" <<endl;
     	cout <<"7. Promjena oznake cvora" <<endl;
     	cout <<"8. Roditelj cvora" <<endl;
		cout <<"9. Povratak u glavni izbornik" << endl;
		cin >>izbor;
		cout <<"---------------" << endl;
	
		switch(izbor)
		{
			case 1:
				cout <<"Korijen stabla je: " << LabelB(RootB(bstablo), bstablo) <<endl;
				break;
				
			case 2:
				cout << "Unesite oznaku cvora kojem stvarate dijete: ";
                cin >> oznaka;
                
				cout << "Unesite lijevi cvor: ";
                cin >> cvor;
                
				CreateLeftB(cvor, FindB(oznaka, bstablo), bstablo);
				break;
			case 3:
				
				cout << "Unesite oznaku cvora kojem stvarate dijete: ";
                cin >> oznaka;
                
            	cout << "Unesite desni cvor: ";
                cin >> cvor;
                
				CreateRightB(cvor, FindB(oznaka, bstablo), bstablo);
                break;
                
			case 4:
				cout << "Unesite oznaku cvora: ";
                cin >> oznaka;
                cout << "Lijevo dijete je " << LabelB(LeftChildB(FindB(oznaka, bstablo), bstablo), bstablo) << endl;
				break;
				
			case 5:
				cout << "Unesite oznaku cvora: ";
                cin >> oznaka;
                cout << "Desno dijete je " << LabelB(RightChildB(FindB(oznaka, bstablo), bstablo), bstablo) << endl;
				break;
				
			case 6:
				cout << "Koji cvor zelite obrisati: ";
                cin >> cvor;
                
            	DeleteB(FindB(oznaka, bstablo), bstablo);
				break;
				
			case 7:
				cout << "Unesite oznaku cvora: ";
                cin >> oznaka;
                
				cout << "Unesite novu vrijednost: ";
                cin >> cvor;
                                
				ChangeLabelB(cvor, FindB(oznaka, bstablo), bstablo);
				break;
				
			case 8:
				cout << "Unesite oznaku cvora: ";
                cin >> oznaka;
                
				cout << "Roditelj je " << LabelB(ParentB(FindB(oznaka, bstablo), bstablo), bstablo) << endl;
				break;
			
			default: cout << "Upisali ste krivi broj!" << endl;

		}
     	
     }while(izbor !=9);
}

int main ()
{
	int izbor;
    do
	{
		  cout << "---------------" << endl;
          cout << "GLAVNI IZBORNIK" << endl;
     	  cout << "---------------" << endl;
          cout << "1. Opcenito stablo" << endl;
          cout << "2. Ophodjenje stabla"<< endl;
          cout << "3. Binarno stablo " << endl;
          cout << "9. Izlaz iz programa" << endl;
          cin >> izbor;
          cout <<"---------------"<<endl;
          
          switch(izbor)
		  {
                        case 1: 
							opStablo();
                            break;
                            
                        case 2: 
                        	drugi();
                            break;
                            
                        case 3:
							treci(); 
                            break;
                            
                        case 9: 
							break;
							
                        default: 
						cout << "Upisali ste krivi broj!" << endl;
          }
	} while(izbor != 9);
      return 0;
	
	return 0;
}
