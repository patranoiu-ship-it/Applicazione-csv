#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct location {
    double lon;
    double lat;
};

struct numerazioniciviche {
    string ClasseToponimo;
    string DescrizioneToponimo;
    int Numero;
    string Subalterno;
    int CAP;
    int SezioneISTAT;
    double lon;
    double lat;
    location posto;
};

int main(int argc, char** argv) {
    // Array per contenere i 1000 record
    numerazioniciviche elenco[1000]; 
    int d=0;
    int cont;
    string riga;

    do {
        cout << "menu" << endl;
        cout << "1. carica i primi 1000 record" << endl;
        cout << "2. visualizza i dati caricati" << endl;
        cout << "0. fine programma" << endl;
        cout << "Inserisci la funzione da fare: ";
        cin >> cont;

        if (cont == 1) {
            ifstream fileInput("Comune_Bergamo_-_Numerazione_civica.csv");

            if (fileInput.is_open()) {
                getline(fileInput, riga);
                d=0;
                
                // Legge riga per riga fino alla fine del file o fino a 1000 record
                while (getline(fileInput, riga) && d < 1000) {
                    
                    elenco[d].DescrizioneToponimo = riga;
                    
                    d++;
                }
                
                fileInput.close();
                cout<<"hai caricato i 1000 record"<<endl;
            } else {
                cout<<"impossibile aprire il file"<<endl;
            }
        }
        
        if (cont == 2) {
            if (d == 0) {
                cout<<"devi caricare prima i record con l'opzione 1"<<endl;
            } else {
                // Mostra i record caricati
                for (int i = 0; i < d; i++) {
                    cout <<"record " <<i+1<<": " <<elenco[i].DescrizioneToponimo<<endl;
                }
            }
        }

    } while (cont != 0);

    return 0;
}