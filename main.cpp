#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


using namespace std;
int tabela_kolorow[13][4] = {0};
class Karta{
    public:
    Karta(){
    }
    int wartosc=0;
    char symbol= 32;
    int kolor_wartosc;
    char kolor_symbol=32;
    void ustal_wartosc(){
        wartosc = (rand()*100)%(14-1)+1;
        switch(wartosc){
            case 1:
                symbol = 'A';
                break;
            case 10:
                symbol = 'D';
                wartosc = 10;
                break;
            case 11:
                symbol = 'J';
                wartosc = 10;
                break;
            case 12:
                symbol = 'Q';
                wartosc = 10;
                break;
            case 13:
                symbol = 'K';
                wartosc = 10;
                break;
            default:
                symbol = (char)wartosc+48;
        }
        kolor_wartosc = rand()%4;
        switch(kolor_wartosc){
            case 0:
                kolor_symbol = 'H';
                break;
            case 1:
                kolor_symbol = 'D';
                break;
            case 2:
                kolor_symbol = 'C';
                break;
            default:
                kolor_symbol = 'S';
        }
        if(tabela_kolorow[wartosc-1][kolor_wartosc]==0){
            tabela_kolorow[wartosc-1][kolor_wartosc]=1;
        } else{
            ustal_wartosc();
        }
    }

};

void zeruj_karty(){
    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){
        tabela_kolorow[i][j]=0;
        }
    }
}

void rysuj_ui(Karta *reka_krupiera,Karta *reka_gracza,int punkty_gracza,int punkty_krupiera,int zapalki){
    system("cls");
    printf("------------------------------------------------------------\n");
    printf("|                  Twoje zapalki:%05d                     |\n",zapalki);
    printf("|                                                          |\n");
    printf("|Twoje punkty:%02d                         Punkty krupiera:%02d|\n",punkty_gracza,punkty_krupiera);
    printf("|                                                          |\n");
    printf("|Karty krupiera:  |----| |----| |----| |----| |----| |----||\n");
    printf("|                 | %c%c | | %c%c | | %c%c | | %c%c | | %c%c | | %c%c ||\n",reka_krupiera[0].symbol,reka_krupiera[0].kolor_symbol,reka_krupiera[1].symbol,reka_krupiera[1].kolor_symbol,reka_krupiera[2].symbol,reka_krupiera[2].kolor_symbol,reka_krupiera[3].symbol,reka_krupiera[3].kolor_symbol,reka_krupiera[4].symbol,reka_krupiera[4].kolor_symbol,reka_krupiera[5].symbol,reka_krupiera[5].kolor_symbol);
    printf("|                 |----| |----| |----| |----| |----| |----||\n");
    printf("|                                                          |\n");
    printf("|Twoje karty:     |----| |----| |----| |----| |----| |----||\n");
    printf("|                 | %c%c | | %c%c | | %c%c | | %c%c | | %c%c | | %c%c ||\n",reka_gracza[0].symbol,reka_gracza[0].kolor_symbol,reka_gracza[1].symbol,reka_gracza[1].kolor_symbol,reka_gracza[2].symbol,reka_gracza[2].kolor_symbol,reka_gracza[3].symbol,reka_gracza[3].kolor_symbol,reka_gracza[4].symbol,reka_gracza[4].kolor_symbol,reka_gracza[5].symbol,reka_gracza[5].kolor_symbol);
    printf("|                 |----| |----| |----| |----| |----| |----||\n");
    printf("------------------------------------------------------------\n");

}
int sumuj_punkty(Karta *reka){
    int suma=0;
    for(int i=0;i<5;i++){
        if(reka[i].wartosc == 1){
            if(((21-(suma+11))<(21-(suma+1)))&&(21-(suma+11))>=0){
                suma += 11;
            }else {
                suma+=1;
            }
        }else {
        suma += reka[i].wartosc;
        }
    }
    return suma;
}
void wstep(int zapalki){
    cout<<"Witaj w cyfrowej wersji gry hazardowej ,,Blackjack\""<<endl;
    cout<<"Posiadasz "<<zapalki<<" zapalek."<<endl;
    cout<<"Aby rozpoczac nowa gre nacisnij 1"<<endl;
    cout<<"Aby przeczytac instrukcje nacisnij 0"<<endl;
    cout<<"Aby wyjsc nacisnij dowolny przycisk"<<endl;
    cout<<endl;
}
void instrukcja(){
    cout<<endl;
    cout<<"Celem gry w Blackjack'a jest pokonanie krupiera."<<endl;
    cout<<"Mozna to zrobic poprzez uzyskanie sumy punktow rownej lub mniejszej od 21."<<endl;
    cout<<"Na poczatku gry gracz otrzymuje dwie karty, a krupier jedna."<<endl;
    cout<<"Gracz moze dobrac karte (hit) lub sprawdzic (stand)"<<endl;
    cout<<"Istnieje tez mozliwosc wygrania 1.5 x postawionej sumy, ale w tym wypadku gracz otrzymuje tylko jedna karte (double)"<<endl;
    cout<<"Jezeli gracz po dobraniu kart ma wiecej niz 21 punktow, przegrywa zaklad i krupier zabiera jego zapalki."<<endl;
    cout<<"Jezeli natomiast gracz ma 21 punktow lub mniej i sprawdza, krupier w zaleznosci od liczby swoich punktow moze dobrac wiecej kart."<<endl;
    cout<<"Krupier musi grac wedlug nastepujacych zasad: "<<endl;
    cout<<"Wziac karte, jezeli ma 16 punktow lub mniej i nie brac wiecej kart, gdy ma 17 punktow lub wiecej."<<endl;
    cout<<"Wygrywa ten, ktory ma sume punktow blizsza lub rowna 21."<<endl;
    cout<<"W wypadku remisu postawione zapalki zwracane sa graczowi"<<endl;
    cout<<endl;

}
int zapalki = 1000;
int gra = 1;
int dialog = 1;
int main()
{
    if(zapalki==0){
            gra = 0;
            dialog = 0;
            return 0;
        }
    while(dialog){
        srand((time(NULL)));
        wstep(zapalki);
        char wybor1;
        wybor1=getch();
        switch(wybor1){
            case '1':
                dialog = 0;
                break;
            case '0':
                instrukcja();
                break;
            default:
                cout<<"Wyjscie z gry :("<<endl;
                dialog = 0;
                return 0;
        }
    }
    int stawka;
    int karty_gracza = 2;
    int karty_krupiera=1;
    Karta reka_krupiera[6];
    Karta reka_gracza[6];
    reka_krupiera[0].ustal_wartosc();
    reka_gracza[0].ustal_wartosc();
    reka_gracza[1].ustal_wartosc();
    cout<<"Posiadasz "<<zapalki<<" zapalek."<<endl;
    cout <<"Ile chcesz postawic?"<<endl;
    cin>>stawka;
    while(stawka<=0 || stawka>zapalki || !cin.good()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<"Niepoprawna liczba"<<endl;
        cout <<"Ile chcesz postawic zapalek ?"<<endl;
        cin>>stawka;
    }
    zapalki-=stawka;
    int tura = 1;
    while(gra){
        rysuj_ui(reka_krupiera,reka_gracza,sumuj_punkty(reka_gracza),sumuj_punkty(reka_krupiera),zapalki);
        char wybor2;
        cout<<"Wybierz akcje:"<<endl;
        cout<<"(1) Dobierz karte (hit)"<<endl;
        cout<<"(2) Spasuj (stand)"<<endl;
        cout<<"(3) Podwoj stawke (double)"<<endl;
        wybor2=getch();
        switch(wybor2){
            case '1':
                reka_gracza[karty_gracza].ustal_wartosc();
                karty_gracza++;
                rysuj_ui(reka_krupiera,reka_gracza,sumuj_punkty(reka_gracza),sumuj_punkty(reka_krupiera),zapalki);
                if(sumuj_punkty(reka_gracza)>21){
                    cout<<"Przegrana! Suma Twoich punktow przekroczyla 21."<<endl<<endl;
                    zeruj_karty();
                    main();
                }
                tura++;
                break;
            case '2':
                while(sumuj_punkty(reka_krupiera)<=16){
                    reka_krupiera[karty_krupiera].ustal_wartosc();
                    karty_krupiera++;
                    rysuj_ui(reka_krupiera,reka_gracza,sumuj_punkty(reka_gracza),sumuj_punkty(reka_krupiera),zapalki);
                }
                if(sumuj_punkty(reka_krupiera)>21){
                    cout<<"Wygrana! Suma punktow krupiera przekroczyla 21."<<endl<<endl;
                    zapalki+=(2*stawka);
                    zeruj_karty();
                    main();
                }
                if(sumuj_punkty(reka_krupiera)==sumuj_punkty(reka_gracza)){
                    cout<<"Remis! Odzyskujesz swoje zapalki."<<endl<<endl;
                    zapalki+=stawka;
                    zeruj_karty();
                    main();
                }
                if((sumuj_punkty(reka_krupiera)>sumuj_punkty(reka_gracza))&&(sumuj_punkty(reka_krupiera)<=21)){
                    cout<<"Przegrana! Krupier zdobyl wiecej punktow."<<endl<<endl;
                    zeruj_karty();
                    main();
                }
                if((sumuj_punkty(reka_krupiera)<sumuj_punkty(reka_gracza))&&(sumuj_punkty(reka_krupiera)<=21)){
                    cout<<"Wygrana! Zdobyles wiecej punktow niz krupier."<<endl<<endl;
                    zapalki+=(2*stawka);
                    zeruj_karty();
                    main();
                }
                break;

            case '3':
                if(tura == 1){
                reka_gracza[karty_gracza].ustal_wartosc();
                rysuj_ui(reka_krupiera,reka_gracza,sumuj_punkty(reka_gracza),sumuj_punkty(reka_krupiera),zapalki);
                while(sumuj_punkty(reka_krupiera)<=16){
                    reka_krupiera[karty_krupiera].ustal_wartosc();
                    karty_krupiera++;
                    rysuj_ui(reka_krupiera,reka_gracza,sumuj_punkty(reka_gracza),sumuj_punkty(reka_krupiera),zapalki);
                }
                if(sumuj_punkty(reka_gracza)>21){
                    cout<<"Przegrana! Suma Twoich punktow przekroczyla 21."<<endl<<endl;
                    zeruj_karty();
                    main();
                }
                if(sumuj_punkty(reka_krupiera)>21){
                    cout<<"Wygrana! Suma punktow krupiera przekroczyla 21."<<endl<<endl;
                    zapalki+=(3*stawka);
                    zeruj_karty();
                    main();
                }
                if(sumuj_punkty(reka_krupiera)==sumuj_punkty(reka_gracza)){
                    cout<<"Remis! Odzyskujesz swoje zapalki."<<endl<<endl;
                    zapalki+=stawka;
                    zeruj_karty();
                    main();
                }
                if((sumuj_punkty(reka_krupiera)>sumuj_punkty(reka_gracza))&&(sumuj_punkty(reka_krupiera)<=21)){
                    cout<<"Przegrana! Krupier zdobyl wiecej punktow."<<endl<<endl;
                    zeruj_karty();
                    main();
                }
                if((sumuj_punkty(reka_krupiera)<sumuj_punkty(reka_gracza))&&(sumuj_punkty(reka_krupiera)<=21)){
                    cout<<"Wygrana! Zdobyles wiecej punktow niz krupier."<<endl<<endl;
                    zapalki+=(3*stawka);
                    zeruj_karty();
                    main();
                }
                }else {
                    cout<<"Podwoic stawke mozna tylko w pierwszej turze"<<endl;
                    break;
                }

            default:
                rysuj_ui(reka_krupiera,reka_gracza,sumuj_punkty(reka_gracza),sumuj_punkty(reka_krupiera),zapalki);
                break;
        }
    }
    return 0;
}
