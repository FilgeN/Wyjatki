#include <iostream>
#include "PojazdSamochod.h"

using namespace std;

int main(void)
{

	cout << "\n\nZasady łapania obiektow CONST/NON-CONST przez CATCH \n\n";

	for(int i=0; i<6; i++){
		try{
	
			if(i==0){
				int liczba = 7;
				cout << "	Rzucam       int "<<endl;
				throw liczba;
			}
			if(i==1){
				const int liczba = 7;
				cout << "	Rzucam       const int "<<endl;
				throw liczba;
			}
			if(i==2){
				static int* liczba = new int(7);
				cout << "	Rzucam       int* "<<endl;
				throw liczba;
			}
			if(i==3){
				static const int* liczba;
				liczba = new const int(7);
				cout << "	Rzucam       const int* "<<endl;
				throw liczba;
			}
			if(i==4){
				static int* const liczba = new int(7);
				cout << "	Rzucam       int* const "<<endl;
				throw liczba;
			}
			if(i==5){
				static const int* const liczba = new int(7);
				cout << "	Rzucam       const int* const"<<endl;
				throw liczba;
			}
	
		}
		catch(const int a){
			cout << "	Zlapal catch(const int a), a = "<<a<<endl<<endl;
		}
		catch(int* a){
			(*a) *= 7*7;
			cout << "	Zlapal catch(int* a), a = "<<*a<<endl<<endl;
			delete a;
		}
		catch(const int* a){
			cout << "	Zlapal catch(const int* a), a = "<< *a <<endl;
			int* b = new int(7*7*7*7);

			delete a;
			a = b;
			cout << "	Mozna zmienic adres na jaki wskazuje a, a = "<< *a <<endl<<endl;
			delete a;
		}

	}



	

	return 0;
}












