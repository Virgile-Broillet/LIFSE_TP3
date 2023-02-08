#include <cstdio>
#include <cstring>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
  int fd;
  bool print_char = false;
  const char *filename = "test.dat"; // si pas de parametre, le nom  par defaut du fichier 

  if (argc > 3) // 2 parametres au maximum 
  {
    fprintf(stderr, "error: too many command-line arguments.");
    return 1;
  }
  if (argc == 3) // Si 2 parametres fournis (qq soit le 2e), booleen mis a vrai
    print_char = true;

  if (argc >= 2) // 1er parametre = nom du fichier en lecture
    filename = argv[1]; // rappel, argv[0] = nom du programme

  fd = open(filename, O_RDONLY); 
  if (fd == -1) return 1;

  unsigned char c;
  int ret;
  while ((ret = read(fd, &c, 1)) == 1) { 
    if (print_char)
      printf("%02x '%c'\n", c, c); // affiche c en hexadécimal et caractère 
    else
      printf("%02x ", c); // affiche c en hexadécimal  
  }

  if (ret == -1)
    return 2;
  if (!print_char)
    printf("\n");

  ret = close(fd);
  if (ret == -1)
    return 5;
  
  return 0;
}
