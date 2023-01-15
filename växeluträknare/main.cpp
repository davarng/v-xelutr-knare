#include <iostream>
using namespace std;

int main()
{

   cout << "Det h�r programmet ska r�kna ut hur mycket du f�r tillbaka i v�xel n�r du k�per n�got.\n\n"; // v�lkomstmeddelande med 2 endl f�r l�sv�nligheten.
   float kostnad,betalning,summa;                                               // skapar decimaltalsvariabler f�r att kostnaden inte m�ste vara ett heltal.

   cout << "Ange vad produkten/produkterna kostar: " ;
   cin >> kostnad;                // inmatning av kostnad.
   while(kostnad<0||cin.fail())   // while f�r att ge ett felmeddelande om kostnaden �r ett minustal eller om det sker ett inmatningsfel dvs inte ett nummer
   {
       cin.clear();
       cin.ignore(200, '\n');                              // cin clear tar bort felflaggningen och cin ignore g�r s� att flera inmatningsfel ignoreras
       cout << "Felaktig inmatning, ange kostnad igen: "; // i ett ord r�knas varje bokstav som ett felmedelande s� jag valde 200 som teckengr�ns
       cin >> kostnad;                                    // f�r att se till att man inte r�kar trycka in fel. endl f�r att cout felmedelande ska komma
   }                                                      // n�sta rad, annars kommer ingenting upp tills man har skrivit 200. repeterar tills giltligt cin.

   cout << "Ange hur mycket du betalade: ";
   cin >> betalning;                                      // samma som ovan fast med betalning ist�llet f�r kostnad
   while(betalning<0||cin.fail())
   {
       cin.clear();
       cin.ignore(200, '\n');
       cout << "Felaktig inmatning, ange vad du betalade: ";
       cin >> betalning;
   }

   summa=betalning-kostnad;    // betalning-kostnad f�r att f� m�ngden v�xel anv�ndaren ska f� tillbaka.
   int kronor=summa;           // skapar heltalsvariabel f�r att runda av till ett heltal s� man kan anv�nda modulus operator.

   if(summa>0)                 // om man ska f� tillbaka n�gon v�xel alls s� anv�nds detta if statement.
   {
      summa=summa-kronor;             // f�r att separera kronor fr�n �ren. summa=antal �ren, kronor= hela krontal

      if(summa>=0.25&&summa<= 0.75)
      {
         summa=kronor+0.5;            // om antalet �ren �r 25 till 75 s� l�ggs 50 �ren till antalet kronor
      }
      else if(summa>0.75)
      {
         summa=kronor+1;              // om antalet �ren �r �ver 75 s� avrundas antalet kronor till n�sta krona
      }
      else if(summa<0.25)
      {
         summa=kronor;                // om antalet �ren �r f�rre �n 25 s� tar man bort antalet �ren
      }

      kronor=summa*100;               // omvandlar decimaltal till heltal s� att jag kan anv�nda modulusoperatorn

      cout << "\nv�xel tillbaka: " << summa << " sek\ntusenlappar: " << kronor/100000;
      kronor=kronor%100000;                           // endl f�r radbrytning. anger hur m�nga kronor man ska f� tillbaka kronor/100000 f�r att det �r
      cout << " , femhundralappar: " << kronor/50000; // 100000 �ren p� en tusenlapp. modulusoperatorn r�knar sedan ut restv�rdet efter divisionen och ger
      kronor=kronor%50000;                            // variabeln kronor restv�rdet. denna process h�nder f�r alla val�rer och ger den optimala
      cout << " , hundralappar: " << kronor/10000;    // f�rdelningen av v�xel.
      kronor=kronor%10000;
      cout << " , femtiolappar: " << kronor/5000;
      kronor=kronor%5000;
      cout << " , tjugolappar: " << kronor/2000;
      kronor=kronor%2000;
      cout << " , tiokronor: " << kronor/1000;
      kronor=kronor%1000;
      cout << " , femkronor: " << kronor/500;
      kronor=kronor%500;
      cout << " ,enkronor: " << kronor/100;
      kronor=kronor%100;
      cout << " , femtio�ringar: " << kronor/50 << endl;

   }
   else if(summa==0)                                            // else if statements ifall att man inte ska f� n�gon v�xel tillbaka.
   {                                                            // om man har betalat lika mycket som produkten kostar s� f�r man ett meddelande som
      cout << "Du har betalat exakt vad produkten kostar.";     // ber�ttar att man har betalat vad det kostar. ist�llet f�r att kodblocket ovan ska
   }                                                            // r�kna ut att man ska f� 0 av alla val�rer.
   else if(summa<0)
   {                                                            // om man betalar mindre �n produkten/produkterna kostar s� f�r man ett meddelande om att
      cout << "Du har betalat " << -summa << " sek f�r lite.";  // man har betalat f�r lite och hur mycket man �r skyldig. jag tog -summa f�r att omvandla
   }                                                            // variabeln summa som i detta fall �r ett negativt tal till ett positivt tal.


   return 0;
}
