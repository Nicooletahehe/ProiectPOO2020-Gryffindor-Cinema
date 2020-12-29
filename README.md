# ProiectPOO2020-Griffindor-Cinema

<h4>Specificații proiect POO 2020-2021</h4><br>
<p>Proiectul din acest an își propune realizarea unei aplicații de emitere și gestionare a biletelor de
film (cinema) în C++, ce utilizează fișiere binare și dispune de o interfață în linia de comandă.</p><br>
Cerințe:<br>
<h4>Faza 1</h4><br>
• Definirea a minim 5 clase ce au legătură cu tema proiectului (ex: Film, Bilet, etc)<br>
• În clase trebuie să existe minim un câmp de tip șir de caractere alocat dinamic (char*) și minim un vector de valori numerice alocat dinamic<br>
• În clase trebuie să existe minim un câmp static și un câmp constant<br>
• Toate atributele vor fi definite pe zona privată a clasei, cu definirea de metode de acces acolo unde acestea sunt necesare<br>
• Funcțiile de tip set vor conține validări pentru a asigura corectitudinea datelor<br>
• Fiecare clasa conține minim un constructor cu parametri, iar pentru cele ce conțin câmpuri alocate dinamic se vor defini obligatoriu constructor de copiere, destructor și forma supraîncarcată a operatorului = <br>
• Pentru fiecare clasă se vor încărca următorii operatori:<br>
o >> și<<<br>
o operatorul pentru idexare []<br>
o minim un operator matematic (+,-,* sau /)<br>
o ++ sau -- (cu cele 2 forme)<br>
o operatorul cast (catre orice tip) explicit sau implicit<br>
o operatorul pentru negatie !<br>
o un operator conditional (<.>,=<,>=)<br>
o operatorul pentru testarea egalitatii dintre 2 obiecte ==<br><br>
<h4>Faza 2</h4><br>
• Se implementează modulul prin care aplicația poate primi următoarele comenzi prin intermediul unui meniu:<br>
o Emitere bilet (cu selectare film, sala, loc, etc) => biletul este salvat într-un fișier text pentru<br>
a putea fi ulterior printat<br>
o Situație locuri libere (afișare în consolă sau fișier text)<br>
o Situație filme (ce filme rulează, la ce ore, în ce săli)<br>
o Operații de tip CRUD (Create Read Update Delete) pentru toate entitățile: Adăugare bilet, modificare bilet, ștergere bilet, adăugare sală, modificare sală, ștergere sală, adăugare filme, modificare film, ștergere film, etc.<br>
• Toate datele sunt salvate pe disc în fișiere binare astfel încât să se asigure persistența acestora<br>
• Toate comenzile vor fi tratate cu atenție astfel încât să nu existe erori de execuție<br><br>
<h4>Faza 3</h4><br>
• Utilizarea conceptelor de derivare și compunere a claselor<br>
• Se implementează minim o clasă abstractă (cu sau fără atribute) ce trebuie să conțintă minim 2 metode virtuale pure<br>
• Se implementeaza minim 2 metode virtuale (altele decât cele virtuale pure)<br>
• Se va folosi conceptul de clase șablon (template) pentru gestionarea unei anumite entități<br>
• Se va modifica (refactoring) codul existent pentru a utiliza minim 3 containere STL în locul vectorilor/matricelor clasice<br><br>
<h4>Observații:</h4><br>
• Implementarea proiectului în minim 2 faze (evidențiate prin commit-uri distincte în repository-ul utilizat) condiționează prezentarea acestuia<br>
• Copierea codului sursă aferent oricărei faze, duce la anularea întregului punctaj de seminar și implicit imposibilitatea susținerii examenului în sesiunea normală.<br>
• Prezentarea proiectului este obligatorie pentru a putea fi punctat<br>
