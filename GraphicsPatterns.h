#ifndef GRAPHICS_PATTERNS_H
#define GRAPHICS_PATTERNS_H

#define LETTER_HEIGHT 5
#define LETTER_WIDTH  4

#define SPACE_INVADER_HEIGHT 8
#define SPACE_INVADER_WIDTH  11

UINT8 SPACE_INVADER[SPACE_INVADER_HEIGHT][SPACE_INVADER_WIDTH] = {
  {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
  {0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
  {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
  {0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
};

UINT8 LETTER_J[LETTER_HEIGHT][LETTER_WIDTH] = {
  {0, 0, 0, 1},
  {0, 0, 0, 1},
  {0, 1, 0, 1},
  {0, 1, 0, 1},
  {0, 1, 1, 1}
};

UINT8 LETTER_A[LETTER_HEIGHT][LETTER_WIDTH] = {
  {1, 1, 1, 1},
  {1, 0, 0, 1},
  {1, 1, 1, 1},
  {1, 0, 0, 1},
  {1, 0, 0, 1}
};

UINT8 LETTER_N[LETTER_HEIGHT][LETTER_WIDTH] = {
  {1, 0, 0, 1},
  {1, 1, 0, 1},
  {1, 0, 1, 1},
  {1, 0, 1, 1},
  {1, 0, 0, 1}
};

UINT8 LETTER_G[LETTER_HEIGHT][LETTER_WIDTH] = {
  {1, 1, 1, 1},
  {1, 0, 0, 0},
  {1, 0, 1, 1},
  {1, 0, 0, 1},
  {1, 1, 1, 1}
};

UINT8 LETTER_S[LETTER_HEIGHT][LETTER_WIDTH] = {
  {1, 1, 1, 1},
  {1, 0, 0, 0},
  {1, 1, 1, 1},
  {0, 0, 0, 1},
  {1, 1, 1, 1}
};

UINT8 LETTER_P[LETTER_HEIGHT][LETTER_WIDTH] = {
  {1, 1, 1, 1},
  {1, 0, 0, 1},
  {1, 1, 1, 1},
  {1, 0, 0, 0},
  {1, 0, 0, 0}
};

UINT8 LETTER_E[LETTER_HEIGHT][LETTER_WIDTH] = {
  {1, 1, 1, 1},
  {1, 0, 0, 0},
  {1, 1, 1, 1},
  {1, 0, 0, 0},
  {1, 1, 1, 1}
};

UINT8 LETTER_R[LETTER_HEIGHT][LETTER_WIDTH] = {
  {1, 1, 1, 1},
  {1, 0, 0, 1},
  {1, 1, 1, 1},
  {1, 0, 1, 0},
  {1, 0, 0, 1}
};

UINT8 LETTER_L[LETTER_HEIGHT][LETTER_WIDTH] = {
  {1, 0, 0, 0},
  {1, 0, 0, 0},
  {1, 0, 0, 0},
  {1, 0, 0, 0},
  {1, 1, 1, 1}
};

UINT8 LETTER_I[LETTER_HEIGHT][LETTER_WIDTH] = {
  {0, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 0, 0}
};

#endif
