# En bra början
Vart ska man börja??? Alla har olika behov när de programmerar och alla har olika metoder till hur de själva debuggar kod. Jag kan själv enkänna att har använder *print* metoden när jag programmerar, det är en väldigt simpel och generellt snabbt sätt att hitta eventuella fel. **MEN** vad säger du ifall det finns ett bättre sätt? En metod där du kan pausa programmet där du vill och skriva ut alla variabler i minnet direkt i terminalen!

För nybörjare kanske det låter konstigt med vissa nyckelord (Vad är minne i relation till programmering????), men tro mig, du kommer fatta rätt snabbt vad som kommer dyka upp i denna guide!

## Hur startar jag GDB? {#start}
```
  gdb ./exe
```
Det var visst lätt!

Exemplet ovan kommer göra det möjligt att köra file "exe" i GDB. Man kan också åstakomma desamma ifall man skulle använda kommandot "file" i GDB.

```
gdb
(gdb) file ./exe
```

### EN SAK TILL
Detta är viktigt, man kan köra kompilerade program med GDB, men en viktig sak att ha i åtanke är att kompilatorn inte kommer tilldela mycket hjälp som standard. Detta betyder att man inte kommer kunna utnyttja GDB till sin fulla potential. Men vad betyder detta????

Vi kommer använda kompilatorn GCC för denna guide, och gcc tilldelar ingen debugging information vid kompilering som standard, utan vi behöver säga till gcc att spara undan olika typer av information i den körbara filen för att kunna använda denna information i program som GDB. Detta kommer man behöva använda flaggan **-g** för.

```
gcc exe.c -o exe -g
```
Flaggan kommer göra det möjligt att bl.a:
- Se källkodsnummer vid en krasch
- Köra GDB steg-för-steg
- Inspektera variabler
- Få mer information vid backtrace

Mycket av detta kanske ser nytt ut, men oroa dig inte, vi kommer ta upp vad dessa är senare i guiden!

## Hur stänger jag ner GDB?
Bra fråga! Det är inte mer simpelt än att använda "exit" eller "quit" kommandot!
```
(gdb) exit
```
```
(gdb) quit
```
Toppen! Då vet vi hur man stänger ner det också!

## Hur kör jag då program i GDB?
Efter att du har kopplat en körbar fil till GDB (Se [Hur startar jag GDB?](#start)) så är det bara att köra kommandot "run", visst var det simpelt?

```
(gdb) run
```

Vet du vad som är bättre? Kommandot run fungerar precis som du skulle köra det från vanliga terminalen! Det som är viktigast är att du kan enkelt använda parametrar med hjälp av run kommandot!

```
(gdb) run param1 param2 param3 (...)
```

### För oss terminal nördar
GDB stödjer också många terminal funktioner som pipar, omdirigeringsoperator och andra kommandon(och mycket mer!).

Här är några exempel:
```
(gdb) run param1 | grep text # Pipe tillsammans med grep
```

```
(gdb) run param1 > out.txt # Skriv utdata till out.txt
```
```
(gdb) run param1 2> /dev/null # Skriv alla error till /dev/null
```
