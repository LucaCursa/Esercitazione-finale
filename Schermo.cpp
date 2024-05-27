/// \file Schermo.cpp
/// \brief File che stampa a schermo un menu con varie opzioni.
/// 
/// \brief Prototipi delle funzioni
///
/// Sono forniti i prototipi delle funzioni che verranno usate nel programma.
/// - TutteForme() stampa a schermo, chiamando la funzione Drawing, tutte le caratteristiche di ogni forma.
/// - AggiungiForma() ti fa aggiungere forme alla tua lista.
/// - RimuoviForma() ti fa rimuovere forme dalla tua lista.
/// - RimuoviTutte() ti fa rimuovere tutte le forme dalla lista.
#include<iostream> 
#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"

/// \brief Prototipi delle funzioni
///
/// Sono forniti i prototipi delle funzioni che verranno usate nel programma.
/// - TutteForme() stampa a schermo, chiamando la funzione Drawing, tutte le caratteristiche di ogni forma.
/// - AggiungiForma() ti fa aggiungere forme alla tua lista.
/// - RimuoviForma() ti fa rimuovere forme dalla tua lista.
/// - RimuoviTutte() ti fa rimuovere tutte le forme dalla lista.

void TutteForme();
void AggiungiForma();
void RimuoviForma();
void RimuoviTutte();

/// \brief Array di puntatori a oggetti di tipo Quadrilateral.
/// 
/// Questo array può contenere fino a 50 puntatori a oggetti derivati dalla classe Quadrilateral.
/// Ogni elemento può essere NULL se non contiene una forma valida.

Quadrilateral* ListaForme[50];

/// \brief Funzione principale che presenta un menu con varie scelte.
///
/// La funzione main presenta un menu all'utente, permettendogli di scegliere diverse operazioni
/// sulle forme: visualizzazione, aggiunta, rimozione di forme singole o di tutte le forme.
///

int main()
{
	for (int i = 0; i < 50; i++)
	{
		ListaForme[i] = NULL;
	}

	int scelta = 0;

	while (scelta != 5)
	{
		cout << "Benvenuto nel menu delle forme!" << endl << "Scegli una delle opzioni disponibili digitando il numero corrispettivo" << endl;
		cout << "1.) Visualizzare TUTTE le Forme;" << endl;
		cout << "2.) Aggiungere delle Forme;" << endl;
		cout << "3.) Rimuovere delle Forme;" << endl;
		cout << "4.) Rimuovere TUTTE le Forme;\n" << endl;
		cout << "5.) Chiudi.\n" << endl;
		cout << "Scelta: " << endl;

		cin >> scelta;

		switch (scelta)
		{
		case 1:
			TutteForme();
			break;
		case 2:
			AggiungiForma();
			break;
		case 3:
			RimuoviForma();
			break;
		case 4:
			RimuoviTutte();
			break;
		case 5:
			cout << "Uscita avvenuta con successo" << endl;
			break;
		default:
			cout << "Scelta inesistente" << endl;
			break;
		}
	}
	return 0;
}

/// \brief Stampa a schermo tutte le forme presenti nella lista.
///
/// Questa funzione scorre l'array `ListaForme` e chiama il metodo `Drawing` di ogni forma non NULL
/// per visualizzarne i dettagli.
void TutteForme()
{
	for (int i = 0; i < 50; i++)
	{
		if (ListaForme[i] != NULL)
		{
			cout << "Forma numero: " << i << endl;
			ListaForme[i]->Drawing();
		}
	}
}

/// \brief Rimuove una forma specificata dalla lista.
///
/// Questa funzione chiede all'utente l'indice della forma da rimuovere. Se l'indice è valido e la
/// forma esiste, la forma viene eliminata e il puntatore nell'array `ListaForme` viene impostato a NULL.
void RimuoviForma()
{
	int scelta2;
	bool loop = true;
	cout << "Quale forma vuoi cancellare: " << endl;
	while (loop)
	{
		cin >> scelta2;
		if (ListaForme[scelta2] == NULL || scelta2 >= 50)
		{
			cout << "Forma inesistente" << endl;
		}
		else
		{
			delete ListaForme[scelta2];
			ListaForme[scelta2] = NULL;

			cout << "La forma numero " << scelta2 << " e' stata cancellata con successo" << endl;
		}
		int scelta3 = 9;
		cout << "Vuoi cancellare altre forme? Se si digita 1, se no digita 0: " << endl;
		cin >> scelta3;
		if(scelta3 == 0)
		{
			loop = false;
		}
		else
		{
			cout << "Quale forma vuoi cancellare: " << endl;
		}
	}
}

/// \brief Aggiunge una nuova forma alla lista.
///
/// Al momento, questa funzione è un placeholder e non aggiunge effettivamente nuove forme alla lista.
void AggiungiForma()
{
	cout << "Ci dispiace ma la opzione scelta al momento non e' ancora disponibile, a presto!" << endl;
}

/// \brief Rimuove tutte le forme presenti nella lista.
///
/// Questa funzione scorre l'array `ListaForme`, elimina ogni forma non NULL e imposta tutti i puntatori a NULL.
void RimuoviTutte()
{
	for (int i = 0; i < 50; i++)
	{
		if (ListaForme[i] != NULL)
		{
			delete ListaForme[i];
			ListaForme[i] = NULL;
		}
	}
	cout << "Cancellazione di tutte le forme avvenuta con successo" << endl;
}
