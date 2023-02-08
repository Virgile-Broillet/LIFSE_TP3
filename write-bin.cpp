#include <cstdio>
#include <cstring>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
  int ret, fd, n;
  
  fd = open("test.dat", O_CREAT | O_TRUNC | O_WRONLY,  S_IRUSR | S_IWUSR);
  if(fd == -1) return 1;
  
  char msg[] = "value";
  n = (strlen(msg) + 1) * sizeof(char);
  ret = write(fd, msg, n);              
  if(ret != n) return 2;
  
  unsigned int x = 42;
  n = sizeof(unsigned int);
  ret = write(fd, &x, n);
  if(ret != n) return 3;
  
  unsigned int tab[3] = {1, 2, 0x12345678};
  n = 3 * sizeof(unsigned int);
  ret = write(fd, tab, n);
  if(ret != n) return 4;
  
  ret = close(fd);
  if(ret == -1) return 5;
  
  return 0; 
}


