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

## Hur tar jag bort breakpoints?
Detta tar bort alla breakpoints:
```
(gdb) delete break
```

Detta tar bort en specifik breakpoint:
```
(gdb) delete break [num]
```
Notera att nummret kommer från när du gör själva breakpointen!
```
(gdb) break main.c:10
Breakpoint 1 at 0xXXXXXX: file main.c, line 10.
```

# Hur fortsätter vi?
Om du redan har testat ovanstående exempel kanske du har listat ut att vi ännu inte vet hur vi fortsätter att exekvera programmet efter att vi har stannat vid breakpointen. Detta är med design, när vi har stannat vid dessa punkter så kan vi skriva ut variablers värden och mycket mer (detta tar jag upp i nästa rubrik), men för att fortsätta till nästa breakpoint eller för att komma till slutet av programmet använder vi kommandot **continue**.

```
(gdb) contine
```
Det är inte smidigare än sådär!

# Funktionaliteten i att pausa programmet
Än så länge har vi lärt oss hur vi startar,pausar och fortsätter i programmet, men vi har ännu inte lärt oss hur vi kan nyttja dessa kunskaper!

*In kommer kommandot* **print**, våran bästa vänn!

*Print* är mycket enklare att använda än printf som är i C, man behöver inte specifiera något format eller datatyper, detta gör det mycket enklare att använda än om man skulle använda printf som debugging.

```
# Skriver ut värdet på variabeln foo, foo har värdet "bar"
(gdb) print foo
$X = "bar"
```

Om du använder structs så kan man också skriva ut dessa.

```
# Skriver ut variabeln bar från structen foo, bar har värdet 10
(gdb) print foo->bar
$X = 10
```
```
(gdb) print foo
$X = {bar = 10, vaar = 0x402128 "Hello World!"}
```

Visste du att du kan skriva ut funktioner? Det kommer fungera precis som om du skulle köra funktionen i programmet! Funktionen i sig behöver inte köras i programmet för att kunna köra det i GDB!

Notera: Om du skulle använda någon typ av optimering vid kompilering så kan funktioner och variabler som inte används i programmet tas bort, då går det inte att kalla på dessa i GDB.

```
  (gdb) print print_me()
```

# Exempel
Nu kommer vi till det praktiska, vi ska faktiskt börja använda GDB!

Som du kanske ser så har vi [ex1.c](./ex1.c) och en makefile, jag kommer inte gå in på vad makefile är förutom att det fungerar som ett scripting språk för att exempelvis enklare kompilera program.

Programmet i sig är inte så kompilcerat, det vi ska göra kommer häller inte vara så komplicerat, vi ska bara testa de saker vi har läst fram tills nu!

Installerad mujukvarukrav:
- gcc
- makefile
- GDB

### Steg 1
Kompilera och starta GDB

<details>
  <summary>Svar</summary>

  ```
  make
  ```
  ```
  gdb ./ex1
  ```
</details>

### Steg 2
Skapa en breakpoint vid rad 21

<details>
  <summary>Svar</summary>

  ```
  break ex1.c:20
  ```
</details>

### Steg 3
Kör programmet

<details>
  <summary>Svar</summary>

  ```
  run
  ```
</details>

### Steg 4
Vid första pausen, skriv ut strukturen ex och notera värderna. När du har gjort detta, fortsätt i programmet en gång till.

<details>
  <summary>Svar</summary>

  ```
  print ex
  ```
  ```
  continue
  ```
</details>

### Steg 5
Använda print för att skriva ut värdet som du får av funktionen *print_me*.

<details>
  <summary>Svar</summary>

  ```
  print print_me()
  ```
</details>

### Steg 6
Avsluta GDB med hjälp av *quit* eller *exit*

<details>
  <summary>Svar</summary>

  ```
  quit
  ```
  ```
  exit
  ```
</details>

## Slutord
Nu har vi gått igenom några praktiska exempel på hur vi skulle kunna använda GDB, så nu är du redo för att kunna använda GDB i dina egna projekt.
