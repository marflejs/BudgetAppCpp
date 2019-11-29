#ifndef TRANSACTIONSFILE_H
#define TRANSACTIONSFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Transaction.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"

using namespace std;

class TransactionsFile : public XMLFile
{
    int idOfLastTransaction;
    Transaction getTransactionData(string daneAdresataOddzielonePionowymiKreskami);
    //int getTransactionIdFromTransactionData();
    //int getUserIdFromTransactionData();

public:
    TransactionsFile(string fileName) : XMLFile(fileName) {
        idOfLastTransaction = 0;
    };

    bool addTransactionToFile(Transaction transaction);
    vector<Transaction> getTransactionsOfLoggedInUserFromFile(int idOfLoggedUser);
    int getIdOfLastTransactionFromFile();
    //void deleteFile(string fileNameWithExtension);
    //void changeFileName(string oldName, string newName);
    //void saveAllTransactionsInFile(vector<Transaction> transactions);
};

#endif


















/*
#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;

    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata);

public:

    PlikZAdresatami(string nazwaPliku, string nazwaTymczasowegoPlikuZAdresatami) :
        PlikTekstowy(nazwaPliku),
        NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI(nazwaTymczasowegoPlikuZAdresatami)
        {
            idOstatniegoAdresata = 0;
    };

    bool dopiszAdresataDoPliku(Adresat adresat);
    vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzZPlikuIdOstatniegoAdresata();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    void zaktualizujDaneWybranegoAdresataWPliku(Adresat adresat);
    void usunWybranaLinieWPliku(int idUsuwanegoAdresata);
};

#endif
*/
