# Esercitazione interfacce di base

Tutto il necessario per lo svolgimento di esercitazioni base per interfacce (codice&nbsp;C, linking, comunicazione inter-processo, socket).

## Download toolkit

Toolkit portabile per Windows, composto da compilatore e linker minimali: [TinyCC](http://download.savannah.gnu.org/releases/tinycc/).
Scaricare sia toolkit che header Win32, assicurarsi che l'eseguibile `tcc` sia nel *path*.

Windows:
```
tcc file.c -o file.exe -lWs2_32
```

Linux/macOS:
```
gcc file.c -o file
```

## Svolgimento

L’esercitazione è suddivisa in 4&nbsp;sezioni, ognuna rappresentata da una cartella di questa repository.
Ogni cartella contiene una parte dell’esercitazione e un compito da svolgere.
Eventuali informazioni aggiuntive sono contenuto nel file `README.md` della cartella.

* `1-codice`: nulla da consegnare, seguire la guida per la compilazione del codice in C e prove di linking.
* `2-processi`: creazione di comandi con piping, da fornire come modifiche al file `README.md` della directory.
* `3-canali-standard-c`: scrittura di un programma, da consegnare come nuovo file `consegna.c`, che produca in _standard output_ una trasformazione dei dati in _standard input_.
* `4-socket`: scrittura di un programma che faccia una richiesta HTTP ad un servizio/sito web qualsiasi usando solamente una _socket_, da aggiungere alla cartella come file `http.c`.

Per la **consegna** sarà necessario effettuare un _fork_ di questa repository, effettuare le modifiche come richiesto dalle specifiche e poi creare una pull request verso questa repository.
