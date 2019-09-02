#include "Board.h"
#include "SudokuFileManager.h"

void board_load(board_t *self, const char *filepath) {
  loadBoardFromFile(self, filepath);
}

void board_put(board_t *self, const int row, const int column, int value) {
  // CHEQUEAR VALORES DE ROW Y COLUMN
  if (self->cells[row - 1][column - 1].preFixed) {
    // AVISAR QUE NO SE PUEDE CAMBIAR
  }
  self->cells[row - 1][column - 1].value = value;
}

int board_get(board_t *self, const int row, const int column) {
  return self->cells[row - 1][column - 1].value;
}