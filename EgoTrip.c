#include <Uefi.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Protocol/GraphicsOutput.h>
#include "GraphicsPatterns.h"

#define CELLSIZE 10

static EFI_GRAPHICS_OUTPUT_PROTOCOL* Gop = NULL;
static EFI_GRAPHICS_OUTPUT_BLT_PIXEL White = {0xFF, 0xFF, 0xFF, 0};
static EFI_GRAPHICS_OUTPUT_BLT_PIXEL Black = {0, 0, 0, 0};
static UINT32 SEED = 1337;



VOID DrawCell(UINT32 X, UINT32 Y, BOOLEAN Reset) {
  EFI_GRAPHICS_OUTPUT_BLT_PIXEL Color = (Reset)?Black:White;
  Gop->Blt(Gop, &Color, EfiBltVideoFill,
           0, 0,
           X*CELLSIZE, Y*CELLSIZE,
           CELLSIZE, CELLSIZE,
           0);
}


VOID DrawLetter(UINT8 letter[LETTER_HEIGHT][LETTER_WIDTH], UINT32 X, UINT32 Y, BOOLEAN reset) {
  UINT32 i, j;
  for(i = 0; i < LETTER_HEIGHT; i++){
    for(j = 0; j < LETTER_WIDTH; j++){
      if(letter[i][j]) {
	      DrawCell(X+j, Y+i, reset);
      }
    }
  }
}

VOID WaitForKeyEvent() {
  Print(L"Press any key to continiue...\n");
    UINTN EventIndex;
    gBS->WaitForEvent(1, &gST->ConIn->WaitForKey, &EventIndex);
}


VOID DrawName(UINT32 X, UINT32 Y, BOOLEAN reset) {
  UINT32 padding = LETTER_WIDTH + 1;

  DrawLetter(LETTER_J, X, Y, reset);
  DrawLetter(LETTER_A, X + padding, Y, reset);
  DrawLetter(LETTER_N, X + 2 * padding, Y, reset);

  DrawLetter(LETTER_G, X + 4 * padding, Y, reset);
  DrawLetter(LETTER_A, X + 5 * padding, Y, reset);
  DrawLetter(LETTER_S, X + 6 * padding, Y, reset);
  DrawLetter(LETTER_P, X + 7 * padding, Y, reset);
  DrawLetter(LETTER_E, X + 8 * padding, Y, reset);
  DrawLetter(LETTER_R, X + 9 * padding, Y, reset);
  DrawLetter(LETTER_L, X + 10 * padding, Y, reset);
  DrawLetter(LETTER_I, X + 11 * padding, Y, reset);
  DrawLetter(LETTER_N, X + 12 * padding, Y, reset);
}

VOID DrawSpaceInvader(UINT32 X, UINT32 Y, BOOLEAN reset) {
  UINT32 i, j;
  for(i = 0; i < SPACE_INVADER_HEIGHT; i++) {
    for(j = 0; j < SPACE_INVADER_WIDTH; j++) {
      if(SPACE_INVADER[i][j]) {
        DrawCell(X+j, Y+i, reset);
      }
    }
  }
}

VOID DrawSpaceInvaders(UINT32 X[10], UINT32 Y[10], BOOLEAN reset) {
  UINT32 i;
  for(i=0; i<10; i++) {
    DrawSpaceInvader(X[i], Y[i], reset);
  }
}

VOID UpdateSpaceInvaders(UINT32 X[10], UINT32 Y[10], INT32 D[10], UINT32 MAX_WIDTH, UINT32 MAX_HEIGHT) {
  UINT32 i;
  //EFI_STATUS Status;
  //EFI_TIME Time;

  for(i=0; i<10; i++) {
    if(Y[i] > MAX_HEIGHT || X[i] > MAX_WIDTH || X[i] == 0) {
      //Status = gRT->GetTime(&Time, NULL);

      // UINT32 New_X = (Time.Nanosecond % MAX_WIDTH) + 1;
      SEED += 13;
      UINT32 New_X = (SEED % MAX_WIDTH) + 1;

      Y[i] = 0;
      X[i] = New_X;

      if(New_X > MAX_WIDTH / 2) {
        D[i] = 0;
      } else {
        D[i] = 1;
      }
    } else {
      Y[i] += 1;

      if (D[i] > 0) {
        X[i] += 1;
      } else {
        X[i] -= 1;
      }      
    }
  }
}

EFI_STATUS EFIAPI
UefiMain(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable) {
  // Initialize the screen
  EFI_STATUS St = gBS->LocateProtocol(&gEfiGraphicsOutputProtocolGuid,
                                      NULL,
                                      (VOID**) &Gop);
  if (EFI_ERROR(St)) {
    Print(L"Unable to locate Graphics Output Protocol\n");
    WaitForKeyEvent();
    Exit(1);
  }
  
  CONST UINT32 ScreenWidth  = Gop->Mode->Info->HorizontalResolution;
  CONST UINT32 ScreenHeight = Gop->Mode->Info->VerticalResolution;

  CONST UINT32 ScreenCellWidth  = ScreenWidth / CELLSIZE;
  CONST UINT32 ScreenCellHeight = ScreenHeight / CELLSIZE;  

  BOOLEAN running = TRUE;
  UINT32 X = 0;
  UINT32 Y = 0;

  UINT32 S_X[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  UINT32 S_Y[10] = {8, 16, 30, 50, 70, 23, 16, 4, 17, 7};
  INT32 S_D[10] = {1, 1, 1, 1, 1, -1, -1, -1, -1, -1};

  UpdateSpaceInvaders(S_X, S_Y, S_D, ScreenCellWidth, ScreenCellHeight);

  while(running) {

    DrawName(X, Y, TRUE);
    DrawSpaceInvaders(S_X, S_Y, TRUE);

    UpdateSpaceInvaders(S_X, S_Y, S_D, ScreenCellWidth, ScreenCellHeight);

    X += 1;

    if(X > ScreenCellWidth) {
      X = 0;
      Y += 1;
    }

    if (Y > ScreenCellHeight) {
      running = FALSE;
    }

    DrawName(X, Y, FALSE);
    DrawSpaceInvaders(S_X, S_Y, FALSE);

    gBS->Stall(50000);  
  }
  

  WaitForKeyEvent();

  return EFI_SUCCESS;
}
