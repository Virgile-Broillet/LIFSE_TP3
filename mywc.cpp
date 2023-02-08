/* Exercice wc, fichiers, LIFASR5 2020, N. Louvet, L.Gonnord, 2023 M. Moy */
#include <unistd.h> // read
#include <fcntl.h> // open
#include <iostream>
#include <string.h> // strerror

// Décommenter la ligne suivante pour activer le wrapper de test de read, qui
// fait échouer "read" plus souvent que nécessaire.
#include "test-read.h"

using namespace std;
static const size_t BUFSIZE = 4096;

// Fonction de documentation utilisateur
void print_usage(char *name) {
  cerr << name << ": count the number of bytes in a file" << endl;
  cerr << "usage: " << name <<" filename" << endl;
}

int main(int argc, char *argv[]) {
  int fd; // descripteur de fichier
  int nbbytes = 0; // nombre d'octets lus dans le fichier
    int nbbytesBefore = 0;
  if(argc < 2) {
    print_usage(argv[0]);
    return -1;
  }

  // REMPLIR ICI
  // TODO : Ouvrir le fichier en lecture (read only)
    fd = open(argv[1], O_RDONLY);
    if(fd < 0 ){
        cout<<strerror(errno)<<endl;
        return 0;
    }
    char tab[BUFSIZE];
    nbbytes = read(fd, tab, sizeof(char)*BUFSIZE);
    close(fd);
  // TODO : n'oubliez pas de fermer le fichier à la fin.
    
    do {
        nbbytesBefore = nbbytes;
        nbbytes += read(fd, tab, sizeof(char)*BUFSIZE);
    } while (nbbytesBefore != nbbytes);

  cout << "Number of bytes = " << nbbytes << endl;
  
  return 0;
}

