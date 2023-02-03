<br/>
<p align="center">
  <a href="https://github.com/adyoblu/SantaClausApp">
    <img src="craciun.jpg" alt="craciun" width="80" height="80">
  </a>

  <h3 align="center">SantaClausApp</h3>

  <p align="center">
    O aplicatie de gestiune a copiilor si cadourilor lui Mos Craciun.
    <br/>
    <br/>
  </p>
</p>

![Downloads](https://img.shields.io/github/downloads/adyoblu/SantaClausApp/total) 

## Table Of Contents

* [About the Project](#about-the-project)
* [Built With](#built-with)
* [Authors](#authors)

## About The Project

![Screen Shot](screenshot.png)

Dragă programatorule,<br/>

Sunt ajutorul principal al lui Moș Crăciun în perioada sărbătorilor de iarnă, spiridușul Alabaster, și îți scriu tocmai de la Polul Nord pentru a-ți cere ajutorul.<br/>
Sărbătorile de anul acesta au fost cu ceva peripeții pentru Moș Crăciun, pentru că Moșul, încăpățânat că nu a îmbătrânit, a vrut să păstreze doar pe hârtie listele cu copiii cuminți și cadourile pe care aceștia și le doreau. Toate lucrurile au mers bine, până cu câteva zile înainte de Crăciun, când Moșul, puțin răcit fiind, a strănutat mai puternic și a amestecat toate hârtiile. În grabă și bazându-se pe memoria sa, Moșul a refăcut listele, însă acum nu mai este sigur că le-a refăcut corect și recunoaște că este posibil să fi încurcat unele cadouri (cel puțin este bine că nu a uitat să ducă vreun cadou). De aceea, Moșul a acceptat modernizarea atelierului prin implementarea unei aplicații software care să gestioneze tot ceea ce își nota pe hârtiile sale.
Rugămintea mea este să ne sprijini în dezvoltarea acestei aplicații, care să ne permită să facem următoarele operațiuni:<br/>

Crearea și actualizarea listelor cu copii și anumite caracteristici ale acestora, precum:<br/>
Nume și prenume<br/>
Data nașterii (în format Zi / Lună / An)<br/>
Cadoul/cadourile dorit/e<br/>
Cadoul/cadourile primit/e<br/>
Dacă a fost cuminte sau nu<br/>
Adresa sau adresele la care poate fi găsit (în cazul mai multor adrese, care dintre acestea este cea curentă)<br/>
Crearea și actualizarea stocurilor de cadouri, ținând cont că:<br/>
Fiecare cadou poate avea mai multe componente;<br/>
Fiecare componentă poate avea atât atribute comune (precum culoare sau dimensiune), precum și anumite atribute specifice (precum număr cai putere în cazul, motorului unei mașinuțe);<br/>
Pentru expediere, fiecare cadou va putea fi ambalat fie prin punerea într-o cutie, fie prin împachetarea cu hârtie de cadouri;<br/>
Vor fi create conturi diferite pentru accesul la aplicație, astfel:<br/>
Listele de cadouri și de copii vor putea fi administrată doar de către Moș Crăciun, printr-un cont specific;<br/>
Lista cu cadourile create în atelier va putea fi administrată doar de către spiriduși (fiecare spiriduș va avea contul propriu)<br/>
Conturile vor fi create de către fiecare persoană în parte, prin intermediul unei opțiuni de înregistrare.<br/>
Fiecare cont va fi identificat pe baza unui nume de utilizator și a unei parole.<br/>
Pentru a ușura procesul de actualizare a funcționalităților aplicației, toate elementele care presupun stocarea unor informații (de exemplu: listele de cadouri, listele cu componentele aferente cadourilor, listele cu copii, lista cu conturile de utilizator, etc.) vor fi păstrate într-o structură de tip Bază de date (BD). Această BD va fi creată sub forma unor tabele care vor fi legate între ele prin relații între id-uri stabilite intern, de către dezvoltator (un exemplu de cum pot fi stabilite aceste relații, îl găsești aici ). Fiecare tabelă din BD va avea asignat un fișier pe disc, în care va fi salvată starea acestora atunci când aplicația este închisă. Toate operațiile cu datele din BD vor fi făcute prin intermediul unui nivel intermediar, care va implementa operații de tipul:<br/>

Create, pentru introducerea unor informații în BD;<br/>
Read, pentru citirea unor informații din BD;<br/>
Update, pentru actualizarea unor informații din BD;<br/>
Delete, pentru ștergerea unor informații din BD.<br/>
Orice acțiune efectuată de un utilizator va fi jurnalizată prin intermediul unui logger unic la nivelul aplicației, care va scrie într-un fișier-jurnal cu extensia .log, toate aceste acțiuni. Intrările din acest fișier-jurnal vor cuprinde informații despre momentul la care s-a întâmplat acțiunea, numele utilizatorului care a realizat acțiunea și câteva informații despre acțiune. De asemenea, pentru a fi simplă de utilizat, aplicația va avea nevoie de un meniu prin care utilizatorii să poată accesa funcționalitățile menționate anterior, care le vor permite să administreze eficient atelierul cu jucării al lui Moș Crăciun. Dacă vei identifica alte elemente care ar trebui introduse sau legături între acestea, care nu au fost menționate în această scrisoare, le poți introduce fără probleme, cât timp funcționalitățile cerute sunt îndeplinite, iar cerințele de aici sunt atinse integral. Sper că vei da curs cererii de ajutor și că vei putea implementa cât mai rapid această aplicație, pentru a fi pregătiți pentru următoarele sărbători de Crăciun.<br/>

Cu multă recunoștință,<br/>
Alabaster<br/>
Spiridușul lui Moș Crăciun<br/>

Clarificări suplimentare:<br/>

Pot fi utilizate toate noțiunile discute în cadrul laboratoarelor și la curs, inclusiv elemente din STL.<br/>
Nu vor fi folosite SGBD (Sisteme de Gestiune a Bazelor de Date), precum Microsoft SQL Server sau MySQL, pentru implementarea cerințelor privind crearea unei BD și a structurii acesteia.<br/>
Nu există o limitare privind structura fișierelor aferente BD, prin urmare puteți introduce orice informații considerați că vă sunt necesare.<br/>
Se vor trata cazurile de excepție (de exemplu: parola greșită la logare introdusa de prea multe ori, nu exista anumite intrări în tabele, etc.) prin afișarea unor mesaje corespunzătoare de eroare.<br/>
Trebuie să existe mecanismul de copiere a unui cadou pe baza altui cadou deja construit.<br/>
Ce ne dorim să vedem:<br/>

Aplicarea tuturor conceptelor POO acumulate;<br/>
Implementarea corectă a relațiilor dintre clase;<br/>
Identificarea necesității folosirii Design Pattern-urilor și implementarea corectă a acestora;<br/>
Utilizarea conceptelor de Încapsulare, Moștenire, Polimorfism, Abstractizare;<br/>
Utilizarea de clase Abstracte și de Interfețe;<br/>
Utilizarea conceptului de destructor virtual;<br/>
Identificarea operatorilor ce pot fi supraîncărcați și supraîncărcarea lor pentru o soluție intuitivă;<br/>
Aplicarea șabloanelor (template-urilor), ori de câte ori găsiți că sunt necesare, și specializarea lor la nevoie;<br/>
Modularizarea programului prin toate mijloacele puse la dispoziție (ex. clase, namespace-uri) (Același sfat: lucrați ca și cum altcineva ar urma să folosească sursele voastre);<br/>
Implementarea unui mecanism de excepții la nivelul proiectului, mecanism aflat în strânsă legătură cu cel de logare;<br/>
Utilizarea containerelor și algoritmilor din Standard Template Library ori de câte ori situația o impune.<br/>

## Built With

C++

## Authors

* **Oblu Adrian** - *Student* - [profile](https://github.com/adyoblu)
