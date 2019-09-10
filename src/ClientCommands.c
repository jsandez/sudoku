#include <stdint.h>
#include <string.h>
#include "ClientCommands.h"

static void getSubstringMsg(const char *stdIn,
                            char *sub_str,
                            int position,
                            int length) {
  int c = 0;
  while (c < length) {
    sub_str[c] = stdIn[position + c - 1];
    c++;
  }
  sub_str[c] = '\0';
}

static int evaluatePut(const char *stdIn, char *message) {
  char substring_1[5], substring_2[5], substring_3[2];
  getSubstringMsg(stdIn, substring_1, 1, 4);
  getSubstringMsg(stdIn, substring_2, 6, 4);
  getSubstringMsg(stdIn, substring_3, 11, 1);
  if ((!strcmp(substring_1, "put "))
      && (!strcmp(substring_2, " in "))
      && (!strcmp(substring_3, ","))) {
    char value, row, column;
    getSubstringMsg(stdIn, &value, 5, 1);
    getSubstringMsg(stdIn, &row, 10, 1);
    getSubstringMsg(stdIn, &column, 12, 1);
    message[0] = 'P';
    message[1] = (uint8_t) row;
    message[2] = (uint8_t) column;
    message[3] = (uint8_t) value;
    return 0;
  }
  return 1;
}

/*
 * Comandos que se van a leer desde stdIn. Si es incorrecto, vuelve a preguntar hasta que se ingrese
 * uno correcto.
 * Devuelve: 0 si el comando es correcto
 *           1 si quiere salir del juego
 *           2 si es incorrecto
 */
int decode(char *stdIn, char *message) {
  if (!evaluatePut(stdIn, message))
    return 0;
  if (!strcmp(stdIn, "verify")) {
    message[0] = 'V';
    return 0;
  }
  if (!strcmp(stdIn, "reset")) {
    message[0] = 'R';
    return 0;
  }
  if (!strcmp(stdIn, "get")) {
    message[0] = 'G';
    return 0;
  }
  if (!strcmp(stdIn, "exit")) {
    message[0] = 'X';
    return 1;
  }
  return 2;
}
