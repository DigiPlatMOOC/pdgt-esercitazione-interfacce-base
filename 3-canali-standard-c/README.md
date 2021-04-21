# Esercitazione 3: interfaccia con canali standard

## Introduzione

Come visto nell'esercitazione precedente, ogni processo ha 3 canali di comunicazione “di base” (può ovviamente aprirne altri durante la sua esecuzione).
In linguaggio&nbsp;C, questi canali di comunicazione possono essere utilizzati come se fossero dei generici “puntatori a file” (di tipo `FILE *`).
In particolare, esistono 3&nbsp;costanti disponibili al programmatore:

* `stdin`: stream in input,
* `stdout`: stream in output,
* `stderr`: stream di errore.

Tutti i canali sono già aperti dal runtime&nbsp;C quando il programma inizia la sua esecuzione dentro `main()`.
È possibile sfruttare i canali sfruttando le funzioni standard di C che operano su file, come `fprintf`, `fscanf`, `fgets` e così via.

Dare un'occhiata al programma `test.c` come esempio.

## Consegna

Scrivere un programma in C che sfrutti i canali standard e che converta tutti i caratteri in input e che li stampi in output seguendo lo [Spongebob casing](https://lingojam.com/sPoNgEbobMoCkINgtexTgenEratoR) (ossia, ogni carattere ha una probabilità del&nbsp;50% di essere convertito in minuscolo e una probabilità del&nbsp;50% di essere convertito in maiuscolo).

In sostanza, dato il programma della consegna compilato come `consegna`, il comando:

```bash
echo "Ciao mondo" | consegna
```

dovrà stampare a video “cIAo MonDO” (o simile, essendo la scelta tra minuscolo e maiuscolo casuale).

Aggiungere il codice del programma come file `spongebob.c` a questa directory.
