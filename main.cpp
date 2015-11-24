#include <iostream>
#include "PojazdSamochod.h"

using namespace std;

int main(void)
{

	cout << "\n\nZasady łapania obiektow CONST/NON-CONST przez CATCH \n\n";

	for(int i=0; i<6; i++){
		try{
	
			if(i==0){
				int* liczba = new int(7);
				cout << "	Rzucam       int "<<endl;
				throw *liczba;
			}
			if(i==1){
				const int* liczba = new int(7);
				cout << "	Rzucam       const int "<<endl;
				throw *liczba;
			}
			if(i==2){
				int* liczba = new int(7);
				cout << "	Rzucam       int* "<<endl;
				throw liczba;
			}
			if(i==3){
				const int* liczba;
				liczba = new const int(7);
				cout << "	Rzucam       const int* "<<endl;
				throw liczba;
			}
			if(i==4){
				int* const liczba = new int(7);
				cout << "	Rzucam       int* const "<<endl;
				throw liczba;
			}
			if(i==5){
				const int* const liczba = new int(7);
				cout << "	Rzucam       const int* const"<<endl;
				throw liczba;
			}
	
		}
		catch(int a){
			a *= 7; // <- w celu pokazania, że można zmienić to na co wskazuje
			cout << "	Zlapal catch(int a), a = "<<a<<endl<<endl;
		}
		catch(const int a){
			cout << "	Zlapal catch(const int a), a = "<<a<<endl<<endl;
		}
		catch(int* a){
			(*a) *= 7*7; // <- w celu pokazania, że można zmienić to na co wskazuje
			cout << "	Zlapal catch(int* a), a = "<<*a<<endl<<endl;
		}
		catch(const int* a){
			a = new int(7*7*7*7); // <- w celu pokazania, że można zmienić to na co wskazuje
			cout << "	Zlapal catch(const int* a), a = "<< *a <<endl<<endl;
		}
		catch(int* const a){
			(*a) *= 7*7*7*7*7; // <- w celu pokazania, że można zmienić to na co wskazuje
			cout << "	Zlapal catch(int* const a), a = "<<*a<<endl<<endl;
		}
		catch(const int* const a){
			cout << "	Zlapal catch(const int* const a), a = "<< *a <<endl<<endl;
		}
	}



	// KOMENTARZ-WNIOSKI (dałem "dużo niżej" by każdy mógł najpierw sam to przemyśleć)






























	/* Poprawne* ustawienie bloków catch: 
	   (Wykomentowałem te których nie trzeba żeby łatwiej było zobaczyć te zbędne )
	*/
	try{

	}
	// catch(int a){
	// 	a *= 7;
	// 	cout << "	Zlapal catch(int a), a = "<<a<<endl<<endl;
	// }
	catch(const int a){
		cout << "	Zlapal catch(const int a), a = "<<a<<endl<<endl;
	}
	catch(int* a){
		(*a) *= 7*7;
		cout << "	Zlapal catch(int* a), a = "<<*a<<endl<<endl;
	}
	catch(const int* a){
		a = new int(7*7*7*7);
		cout << "	Zlapal catch(const int* a), a = "<< *a <<endl<<endl;
	}
	// catch(int* const a){
	// 	(*a) *= 7*7*7*7*7;
	// 	cout << "	Zlapal catch(int* const a), a = "<<*a<<endl<<endl;
	// }
	// catch(const int* const a){
	// 	cout << "	Zlapal catch(const int* const a), a = "<< *a <<endl<<endl;
	// }


	/* 
	 Poprawne* - właściwie to z którego korzystamy w mainie też jest poprawne ale te
	 bloki i tak nigdy się nie wykonają ponieważ catch nie jest w stanie sprawdzić
	 czy obiektu automatycznego. Dla przypomnienia:

	 Chcemy mieć wskaźnik wskazujący na const inta - czyli nie można zmienić
	 wartości pod adresem na który wskazuje.

	 Aby dobrze pokazać zachowanie CONST'ów rozbijamy definicję na 2 części:

	 const int* liczba;  		<- wskaźnik jest obiektem automatycznym 
	 							   (przechowywanym na stosie)
	 liczba= new const int(7);  <- obiekt int(7) jest "bezimienny" 
	 							   (przechowywany w zapasie pamieci)
	 						 	   A obiekt 'liczba' przechowuje tylko jego adres.

	 Więc gdy dajemy throw:
	 	-> URUCHAMIA sie odwiklanie stosu
	 		-> Tworzy sie kopia wskaznika 'liczba' przechowywana jak obiekty
	 		   typu static, dostepny globalnie ale tylko dla catch'ów
	 			-> Usuwa sie wszystkie obiekty automatyczne z bloku 'try'
					-> KOŃCZY się odwikłanie stosu

	 I przy tym całym 'kopiowaniu' jest gubiona informacja, czy sam obiekt automatyczny
	 byl const czy nie... ALE! ponieważ nasz obiekt int(7) byl alokowany od razu dynamicznie
	 to pozostaje informacja, że on był const - stąd są rozróżniane catch'e:
		catch(int* a)
		catch(const int* a)


	*/

	return 0;
}












