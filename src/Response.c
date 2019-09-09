#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Response.h"

static void setSize(Response_t *self, char *message) {
  uint32_t size = 0;
  if (message[0] == 'G') {
    size = htonl(722);
    self->size_int = size;
  }
  memcpy(self->size,&(self->size_int), sizeof(uint32_t));
}

static void setMessage(Response_t *self, char *message) {
  self->message = (char *) malloc(sizeof(char) * self->size_int);
  /*if (command[0] == 'G') {
    //getResponse(response);
    uint32_t size_response = 0;
    size_response = htonl(722);
    char length[4] = {0};
    memcpy(length, &size_response, sizeof(uint32_t));
    for (int i = 0; i < 4; i++) {
      response[i] = length[i];
    }*/
  char graph[726] =
      {'U', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', 'U', '=', '=', '=', '=', '=', '=', '=', '=', '=',
       '=', '=', 'U', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', 'U', '\n', 'U', ' ', '3', ' ', '|',
       ' ', ' ', ' ', '|', ' ', '5', ' ', 'U', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', '8', ' ', 'U', ' ', ' ',
       ' ', '|', ' ', '1', ' ', '|', ' ', ' ', ' ', 'U', '\n', 'U', '-', '-', '-', '+', '-', '-', '-', '+', '-',
       '-', '-', 'U', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', 'U', '-', '-', '-', '+', '-', '-', '-',
       '+', '-', '-', '-', 'U', '\n', 'U', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', '7', ' ', 'U', ' ', ' ',
       ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', 'U', ' ', '5', ' ', '|', ' ', ' ', ' ', '|', ' ', '8', ' ', 'U',
       '\n', 'U', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', 'U', '-', '-', '-', '+', '-', '-', '-',
       '+', '-', '-', '-', 'U', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', 'U', '\n', 'U', ' ', '1',
       ' ', '|', ' ', '2', ' ', '|', ' ', ' ', ' ', 'U', ' ', '7', ' ', '|', ' ', '5', ' ', '|', ' ', ' ', ' ', 'U',
       ' ', ' ', ' ', '|', ' ', '9', ' ', '|', ' ', ' ', ' ', 'U', '\n', 'U', '=', '=', '=', '=', '=', '=', '=',
       '=', '=', '=', '=', 'U', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', 'U', '=', '=', '=', '=', '=',
       '=', '=', '=', '=', '=', '=', 'U', '\n', 'U', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', '9', ' ', 'U',
       ' ', ' ', ' ', '|', ' ', '7', ' ', '|', ' ', ' ', ' ', 'U', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', '4',
       ' ', 'U', '\n', 'U', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', 'U', '-', '-', '-', '+', '-',
       '-', '-', '+', '-', '-', '-', 'U', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', 'U', '\n', 'U',
       ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', '4', ' ', 'U', ' ', '3', ' ', '|', ' ', ' ', ' ', '|', ' ', '5',
       ' ', 'U', ' ', '9', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', 'U', '\n', 'U', '-', '-', '-', '+', '-',
       '-', '-', '+', '-', '-', '-', 'U', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', 'U', '-', '-', '-',
       '+', '-', '-', '-', '+', '-', '-', '-', 'U', '\n', 'U', ' ', '7', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ',
       ' ', 'U', ' ', ' ', ' ', '|', ' ', '9', ' ', '|', ' ', ' ', ' ', 'U', ' ', '8', ' ', '|', ' ', ' ', ' ', '|',
       ' ', ' ', ' ', 'U', '\n', 'U', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', 'U', '=', '=', '=',
       '=', '=', '=', '=', '=', '=', '=', '=', 'U', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', 'U',
       '\n', 'U', ' ', ' ', ' ', '|', ' ', '3', ' ', '|', ' ', ' ', ' ', 'U', ' ', ' ', ' ', '|', ' ', '4', ' ',
       '|', ' ', '6', ' ', 'U', ' ', ' ', ' ', '|', ' ', '5', ' ', '|', ' ', '7', ' ', 'U', '\n', 'U', '-', '-',
       '-', '+', '-', '-', '-', '+', '-', '-', '-', 'U', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', 'U',
       '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', 'U', '\n', 'U', ' ', '4', ' ', '|', ' ', ' ', ' ',
       '|', ' ', '6', ' ', 'U', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', 'U', ' ', '1', ' ', '|', ' ',
       ' ', ' ', '|', ' ', ' ', ' ', 'U', '\n', 'U', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', 'U',
       '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', 'U', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-',
       '-', 'U', '\n', 'U', ' ', ' ', ' ', '|', ' ', '7', ' ', '|', ' ', ' ', ' ', 'U', ' ', '5', ' ', '|', ' ',
       ' ', ' ', '|', ' ', ' ', ' ', 'U', ' ', '6', ' ', '|', ' ', ' ', ' ', '|', ' ', '9', ' ', 'U', '\n', 'U',
       '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', 'U', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=',
       '=', 'U', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', 'U', '\n'};
  for (int i = 0; i < 726; i++) {
    self->message[i] = graph[i];
  }
}

void responseCreate(Response_t *self, char *message) {
  self->size = (char *) malloc(sizeof(char) * 4);
  setSize(self, message);
  setMessage(self, message);
}

void responseDestroy(Response_t *self) {
  free(self->size);
  free(self->message);
}



