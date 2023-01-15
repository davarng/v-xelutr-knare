#include <iostream>
using namespace std;

int main()
{

   cout << "Det här programmet ska räkna ut hur mycket du får tillbaka i växel när du köper något.\n\n"; // välkomstmeddelande med 2 endl för läsvänligheten.
   float kostnad,betalning,summa;                                               // skapar decimaltalsvariabler för att kostnaden inte måste vara ett heltal.

   cout << "Ange vad produkten/produkterna kostar: " ;
   cin >> kostnad;                // inmatning av kostnad.
   while(kostnad<0||cin.fail())   // while för att ge ett felmeddelande om kostnaden är ett minustal eller om det sker ett inmatningsfel dvs inte ett nummer
   {
       cin.clear();
       cin.ignore(200, '\n');                              // cin clear tar bort felflaggningen och cin ignore gör så att flera inmatningsfel ignoreras
       cout << "Felaktig inmatning, ange kostnad igen: "; // i ett ord räknas varje bokstav som ett felmedelande så jag valde 200 som teckengräns
       cin >> kostnad;                                    // för att se till att man inte råkar trycka in fel. endl för att cout felmedelande ska komma
   }                                                      // nästa rad, annars kommer ingenting upp tills man har skrivit 200. repeterar tills giltligt cin.

   cout << "Ange hur mycket du betalade: ";
   cin >> betalning;                                      // samma som ovan fast med betalning istället för kostnad
   while(betalning<0||cin.fail())
   {
       cin.clear();
       cin.ignore(200, '\n');
       cout << "Felaktig inmatning, ange vad du betalade: ";
       cin >> betalning;
   }

   summa=betalning-kostnad;    // betalning-kostnad för att få mängden växel användaren ska få tillbaka.
   int kronor=summa;           // skapar heltalsvariabel för att runda av till ett heltal så man kan använda modulus operator.

   if(summa>0)                 // om man ska få tillbaka någon växel alls så används detta if statement.
   {
      summa=summa-kronor;             // för att separera kronor från ören. summa=antal ören, kronor= hela krontal

      if(summa>=0.25&&summa<= 0.75)
      {
         summa=kronor+0.5;            // om antalet ören är 25 till 75 så läggs 50 ören till antalet kronor
      }
      else if(summa>0.75)
      {
         summa=kronor+1;              // om antalet ören är över 75 så avrundas antalet kronor till nästa krona
      }
      else if(summa<0.25)
      {
         summa=kronor;                // om antalet ören är färre än 25 så tar man bort antalet ören
      }

      kronor=summa*100;               // omvandlar decimaltal till heltal så att jag kan använda modulusoperatorn

      cout << "\nväxel tillbaka: " << summa << " sek\ntusenlappar: " << kronor/100000;
      kronor=kronor%100000;                           // endl för radbrytning. anger hur många kronor man ska få tillbaka kronor/100000 för att det är
      cout << " , femhundralappar: " << kronor/50000; // 100000 ören på en tusenlapp. modulusoperatorn räknar sedan ut restvärdet efter divisionen och ger
      kronor=kronor%50000;                            // variabeln kronor restvärdet. denna process händer för alla valörer och ger den optimala
      cout << " , hundralappar: " << kronor/10000;    // fördelningen av växel.
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
      cout << " , femtioöringar: " << kronor/50 << endl;

   }
   else if(summa==0)                                            // else if statements ifall att man inte ska få någon växel tillbaka.
   {                                                            // om man har betalat lika mycket som produkten kostar så får man ett meddelande som
      cout << "Du har betalat exakt vad produkten kostar.";     // berättar att man har betalat vad det kostar. istället för att kodblocket ovan ska
   }                                                            // räkna ut att man ska få 0 av alla valörer.
   else if(summa<0)
   {                                                            // om man betalar mindre än produkten/produkterna kostar så får man ett meddelande om att
      cout << "Du har betalat " << -summa << " sek för lite.";  // man har betalat för lite och hur mycket man är skyldig. jag tog -summa för att omvandla
   }                                                            // variabeln summa som i detta fall är ett negativt tal till ett positivt tal.


   return 0;
}
