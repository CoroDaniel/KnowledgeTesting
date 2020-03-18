#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <locale>
#include <ctime>
#include <fstream>

using namespace std;


void uppercaseResponse(string &c){
 //transformam in majuscule stringul utilizatorului pentru a compara raspunsul din fisier cu raspunsul dat de acesta ->
 // -> indiferent de modul in care scrie utilizatorul raspunsul (majuscule sau odar peima litera majuscula ori toate literele mici)
   locale loc;
   for (int i=0; i<c.length(); ++i)
                    c[i]=toupper(c[i],loc);
}


//urmatoarea functie verificam raspunsul utilizatorului cu raspunsul corect
void VerifyResp(string Quest, string CorectResp, int &good, int time_per_quest){ //good-parametrul care tine evidenta raspunsurilor corecte
                                                                                //time_per_quest timpul alocat unei intrebari in functie de materie
    clock_t start, end;
    double time_spent;

    string UserResp;

    start = clock();
    cin>>UserResp;    //raspunsul utilizatorului
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    uppercaseResponse(UserResp); //transformarea in majuscule a raspunsului utilizatorului
    uppercaseResponse(CorectResp); //transformarea in majuscule a raspunsului corect
                                    //cele 2 transfomari pentru a usura compararea celor 2 stringuri si verificarea raspunsului
    if(time_spent<time_per_quest){
        if(CorectResp.compare(UserResp)!=0) //compararea intre raspunsului dat de utilizator si cel corect
                cout<<"Raspuns gresit! Raspunsul corect este: "<<CorectResp<<endl<<endl; //raspuns gresit => afisare raspuns corect
        else {cout<<"Raspuns corect!"<<endl<<endl;
                good++; //daca raspunsul a fost corect incrementam numarul raspunsurilor date corect
             }
    }
    else cout<<"Ati depasit limita de "<<time_per_quest<<" secunde!"<<endl<<"Raspunsul corect este: "<<CorectResp<<endl<<endl;

}

 void FinalPointsMesage ( int good){
    //pentru design mesajul este incadrat intr-un chenar discontinu cu ajutorul codurilor ascii
    cout<<char(201);
    cout<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205);
    cout<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205);
    cout<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205);
    cout<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205);
    cout<<"  "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" ";
    cout<<char(187);

    cout<<endl<<" Ati obtinut "<<good*10+10<<" puncte din 100 (10 pct din oficiu)"<<endl;

    cout<<char(200);
    cout<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205);
    cout<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205);
    cout<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205);
    cout<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205);
    cout<<"  "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" "<<char(205)<<" ";
    cout<<char(188);

  }

void testRo(){

    ifstream fRo("Romana.txt");
    string Quest,CorectResp,UserResp;
    int good=0; //variabila care tine evidenta raasp corecte

    cout<<endl<<"                  ~TEST Romana~ "<<endl;
    cout<<"Aveti la dispozitie 10 secunde pentru fiecare intrebare"<<endl<<endl;

    if(fRo.is_open()){
         for(int i=1;i<=9;i++)//9 questions
            {
                //pentru fiecare ciclu (bucla) din for se va citi automat 2 linii: prima este intrebarea (Quest),  a dpua este raspunsul (CorectResp)
                getline (fRo,Quest); //citirea intrebari nr i,
                getline (fRo,CorectResp); //citire raspunsul numarul i aferent intrebarii i,

                cout<<Quest<<endl; //afisarea intrebarii
                VerifyResp(Quest,CorectResp,good,10); //se aloca 10 secunde unei intrebari la romana
            }
         FinalPointsMesage(good);
    }
    else cout<<"Ne cerem scuze! Intrebari indisponibile momentan."; //daca fisierul nu a fost deschis din diverse motive tehnice
    fRo.close();
}

void testMath(){
    ifstream fMat("Mate.txt");
    string Quest,CorectResp,UserResp;
    int good=0; //variabila care tine evidenta raasp corecte

    cout<<endl<<"               ~TEST Matematica~ "<<endl;
    cout<<"Aveti la dispozitie 10 secunde pentru fiecare intrebare"<<endl<<endl;

    if(fMat.is_open()){
         for(int i=1;i<=9;i++)//9 questions
            {
                //pentru fiecare ciclu (bucla) din for se va citi automat 2 linii: prima este intrebarea (Quest),  a dpua este raspunsul (CorectResp)
                getline (fMat,Quest); //citirea intrebari nr i,
                getline (fMat,CorectResp); //citire raspunsul numarul i aferent intrebarii i,

                cout<<Quest<<endl; //afisarea intrebarii i
                VerifyResp(Quest,CorectResp,good, 15); //se aloca 15 secunde unei intrebari la matematica
            }
         FinalPointsMesage(good);
    }
    else cout<<"Ne cerem scuze! Intrebari indisponibile momentan."; //daca fisierul nu a fost deschis din diverse motive tehnice
    fMat.close();
}

void testGeo(){
    ifstream fGeo("Geografie.txt");
    string Quest,CorectResp,UserResp;
    int good=0; //variabila care tine evidenta raasp corecte

    cout<<endl<<"                ~TEST Geografie~ "<<endl<<endl;
    cout<<"Aveti la dispozitie 10 secunde pentru fiecare intrebare"<<endl<<endl;

    if(fGeo.is_open()){
         for(int i=1;i<=9;i++)//9 questions
            {
                //pentru fiecare ciclu (bucla) din for se va citi automat 2 linii: prima este intrebarea (Quest),  a dpua este raspunsul (CorectResp)
                getline (fGeo,Quest); //citirea intrebari nr i,
                getline (fGeo,CorectResp); //citire raspunsul numarul i aferent intrebarii i,

                cout<<Quest<<endl; //afisarea intrebarii i
                VerifyResp(Quest,CorectResp,good,10); //se aloca 10 secunde unei intrebari la geografie
            }
         FinalPointsMesage(good);
    }
    else cout<<"Ne cerem scuze! Intrebari indisponibile momentan."; //daca fisierul nu a fost deschis din diverse motive tehnice
    fGeo.close();
  }

int main(){
    char x;
    cout << "Alegeti testul la materia dorita (introducand cifra corespunzatoare: 1, 2 sau 3):"<< endl<<endl;
    cout<<"1.Romana"<<endl<<endl<<"2.Matematica"<<endl<<endl<<"3.Geografie"<<endl<<endl;
    cin >> x;
    cout<<endl;

    switch (x){
      //in functie de ce numar a ales uttilizatorul se va apela o functie catre un test
        case '1':
            testRo();
            break;
        case '2':
            testMath();
            break;
        case '3':
            testGeo();
            break;
        default:
      //cazul in care userul nu a ales un numar corespunzator unui test disponibil se va afisa mesajul urmator
            cout << "Nu ati ales niciun test disponibil!";
            break;
    }

    return 0;
}
