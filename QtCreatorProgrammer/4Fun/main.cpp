#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    double alder;
    double høyde;
    double vekt;
    double bmi;
    string navn;
    string svar;

    cout    << "Halla sjef! \n"
            << "Før vi starter trenger vi litt info om deg. \n"
            << "\n \nHva er ditt fulle navn? ";

    getline(cin, navn);

    cout << "\n \nHei, " << navn << ". \nDet neste vi trenger å vite er "
                                    "alder, vekt og høyde." << endl;
    cout << "\n \nHøyde: ";
    cin >> høyde;
    cout << "\n \nAlder: ";
    cin >> alder;
    cout << "\n \nVekt: ";
    cin >> vekt;

    cout << "\nTakk! \n\nInfoen vi fikk er:\n\nHøyde: " << høyde << "\nAlder: "
         << alder << "\nVekt: " << vekt << endl;
    cout << "\nEr dette korrekt? \n\n";

    cin >> svar;

    if (svar == "Ja" || "ja" )
        cout << "\n\nSå bra. Nå skal jeg kalkulere din BMI. \n\nBMI'en din er: ";
    else {
        cout << "\n\nOMFG, idiot. Prøv igjen..." << endl;

        return 0;}

    usleep(1500000);

    bmi = (vekt/(høyde*høyde))*10000.0;
    cout << bmi << endl;

    usleep(1500000);

    cout << "\n\nTil å være " << alder << " år gammel ";

    if (bmi > 25.0)
         cout << "er du for tjukk. Løp deg en tur. Lykke til." << endl;

    else if (bmi < 20.0)
        cout << "er du for tynn. Ta den en bolle istedenfor å sitte her å glo." << endl;
    else
        cout << "er du i fin form. Gratulerer!" << endl;


    return 0;

}
