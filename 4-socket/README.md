# Esercitazione 4: socket

Compilazione su Windows:

```bash
tcc socket.c -o socket.exe -lWs2_32
```

oppure, su Linux/macOS:

```
gcc file.c -o file
```

## Svolgimento

Il file `socket-lib.h` contiene una serie di funzioni di libreria che permettono di usare le socket sia su Windows che su Linux/macOS senza modificare il codice.
La libreria contiene anche delle funzioni di utilità, come ad esempio `socket_read_all`, che permette di leggere tutti i byte in arrivo tramite una socket fino all’esaurimento dei dati trasmessi (o fino al riempimento del _buffer_ fornito come parametro).

La coppia di programmi `server.c` e `client.c` servono da esempio per dimostrare la comunicazione di due processi in esecuzione sullo stesso sistema.
Entrambi aprono una socket usando l’indirizzo&nbsp;IP locale (`127.0.0.1` o `localhost` per convenzione) e la porta `1234`, con la differenza che il programma `server.c` si mette in ascolto e `client.c` invece si connette (operazione che ha successo soltanto se la socket è già aperta in ascolto).

Effettuare degli esperimenti con i due programmi e verificarne il funzionamento esaminando il codice.

## Consegna

Sviluppare un nuovo programma, sulla base di `client.c`, che effettui una richiesta&nbsp;HTTP ad un qualsiasi servizio/sito web, tramite una semplice socket, e stampi il risultato ottenuto.

Una richiesta HTTP di tipo _GET_ al documento di base di un qualsiasi servizio web contiene _almeno_ la seguente intestazione (ma può chiaramente contenere header aggiuntivi):
```
GET / HTTP/1.1
```

_Nota bene:_ le richieste HTTP terminano sempre con un corpo, separato dal resto dell’intestazione da due “a capo”, anche se vuoto.
Molti server web richiedono un certo numero di header per assicurare che la richiesta sia gestita in maniera soddisfacente.
Nei casi più comuni, questi header sono:
* `User-Agent`: nome e versione del programma che sta effettuando la connessione,
* `Host`: autorità dell’URI al quale ci si connette, nel caso di una richiesta HTTP ad un URL, inserire qui il dominio (ad esempio: `Host: example.org`),
* `Content-Length`: lunghezza del corpo della richiesta, nel caso in cui fosse vuoto inserire `0`.

Se si verificano errori o le risposte HTTP che si ottengono non sembrano corrette, verificare le richieste HTTP effettuate da un qualsiasi browser HTTP (aprendo gli strumenti di debug con \[CTRL\]+\[SHIFT\]+\[I\]) e replicarle.

Aggiungere il programma così sviluppato alla directory come `http.c`.
