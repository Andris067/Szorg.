#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

string beszuro(string, string);

int main()
{
    string termekek="";
    int db=0;
    ifstream olvas("vasarlasok.txt");
        string seged;
        getline(olvas,seged);
        while(!olvas.eof()){
            db++;
            getline(olvas,seged);
            while(seged.find("vasarlas")>seged.length() && !olvas.eof()){
                if(termekek.find(seged)>termekek.length()){
                    termekek+=seged;
                }
                termekek=beszuro(termekek,seged);
                getline(olvas,seged);
            }

        }
    olvas.close();
    ofstream iras("Termekek gyakorisaga.txt");
    for(int i=0;i<termekek.length();i++){
        iras << termekek[i];
        if(termekek[i+1]=='_'){
            iras << ": ";
            int k=0;
            while(termekek[i+1]=='_'){
                k++;
                i++;
            }
            iras << fixed << setprecision(2) << (k*100.0)/db << "%" << endl;
        }
    }
    iras.close();
}

string beszuro(string eredeti, string termek){
    int k=eredeti.find(termek);
    string eleje="", vege="";
    for(int i=0;i<k+termek.length();i++){
        eleje+=eredeti[i];
    }
    for(int i=k+termek.length();i<eredeti.length();i++){
        vege+=eredeti[i];
    }
    string vegleges=eleje+'_'+vege;
    return vegleges;
}
/**
A vasarlasok.txt szerkezeti felépítése:
1. vasarlas:
tej
cukor
bor
alma
2. vasarlas:
papucs
3. vasarlas:
mososzer
szivacs
papir
4. vasarlas:
banan
viz
palinka
5. vasarlas:
whisky
kola
almale
6. vasarlas:
tej
whisky
tej
banan
7. vasarlas:
papucs
cukor

*/
