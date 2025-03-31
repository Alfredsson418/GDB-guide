# Omfattning
- Breakpoints
- Köra program tillsammans med breakpoints
- Skriva ut variabler

# Hur pausar vi program?
Detta kanske kommer som en shock, men med GDB kan vi pausa ett program mitt i exekveringen, häftigt va? Så hur åstakommer vi detta?

När vi har lagt in våran körbara fil i GDB så kan vi använda kommandot *run* för att köra programmet, men det blir svårt att debugga då det bara kommer köra programmet. Det är här **break** kommer in!

Med kommandot *break* kan vi lägga in så-kallade *breakpoints*, det är platser i programmet som GDB kommer pausas vid när vi sedan kommer köra programmet i GDB, smidigt va?

Men hur funkar break? Hur specificerar vi vart vi vill att GDB ska stoppa? Detta är väldigt bra frågor! Det är inte mer kompilcerat än att specificera vilken funktion vi vill stoppa i!

```
# Stoppar när vi kallar funktionen "main"
(gdb) break main
```

Vi kan också specificera filer och radnummer! Via denna metod kan vi specificera en breakpoint mitt i en funktion, detta kan exempelvis vara en for-loop.
```
# Stoppar när vi kommer till rad 10 i filen main.c
(gdb) break main.c:10
```
Dessa två sätt att specificera platser använder man sig mest av, men man kan även specificera raden hos funktioner!

Notera: När vi använder break så kommer GDB stoppa där vi har specificerat, så det kan hända att programmet inte kommer pausa om vi inte kommer till just den platsen i programmet.

# Hur fortsätter vi?
Om du redan har testat ovanstående exempel kanske du har listat ut att vi ännu inte vet hur vi fortsätter att exekvera programmet efter att vi har stannat vid breakpointen. Detta är med design, när vi har stannat vid dessa punkter så kan vi skriva ut variablers värden och mycket mer (detta tar jag upp i nästa rubrik), men för att fortsätta till nästa breakpoint eller för att komma till slutet av programmet använder vi kommandot **continue**.

```
(gdb) contine
```
Det är inte smidigare än sådär!

# Funktionaliteten i att pausa programmet
Än så länge har vi lärt oss hur vi startar,pausar och fortsätter i programmet, men vi har ännu inte lärt oss hur vi kan nyttja dessa kunskaper!

*In kommer kommandot* **print**, våran bästa vänn!

Man kan säga att kommandot print fungerar precis som printf, men ännu bättre!

```
# Skriver ut värdet på variabeln foo
(gdb) print foo
```
