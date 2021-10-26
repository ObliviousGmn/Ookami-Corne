
static void draw_line_x(int x1, int x2, int y)
{
   for (uint8_t x = x1; x < x2; x++) {
       oled_write_pixel(x,y,true);
   }
}

static void draw_line_y(int x, int y1, int y2)
{
   for (uint8_t y = y1; y < y2; y++) {
       oled_write_pixel(x,y,true);
   }
}

// set coordinates for visualizer to show
#define MATRIX_DISPLAY_X 3
#define MATRIX_DISPLAY_Y 100
#define DISTANCE 5
// function to draw pixels when keys are pressed. call this in oled_task_user

static void print_matrix(void) {

   uint8_t offset = MATRIX_ROWS + DISTANCE;

   for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
       for (uint8_t y = 0; y < MATRIX_COLS; y++) {
           if (x >= 4) {
               oled_write_pixel(MATRIX_DISPLAY_X - y + MATRIX_ROWS * 2 + DISTANCE, MATRIX_DISPLAY_Y + x - 2, (matrix_get_row(x) & (1 << y)) > 0);
           } else {
               oled_write_pixel(MATRIX_DISPLAY_X + y + 2, MATRIX_DISPLAY_Y + x + 2, (matrix_get_row(x) & (1 << y)) > 0);
           }
       }
   }

/*
   #####5######    #####6######
  #            #  #            #
  1            2  3            4
  #            #  #            #
   ##7###      #  #      ##0###
         ##8###    ##9###
*/

   draw_line_x(MATRIX_DISPLAY_X + 1         , MATRIX_DISPLAY_X + 9          , MATRIX_DISPLAY_Y); //Top left 5
   draw_line_x(MATRIX_DISPLAY_X + 2 + offset, MATRIX_DISPLAY_X + offset + 10, MATRIX_DISPLAY_Y); //Top right 6

   draw_line_x(MATRIX_DISPLAY_X + 4         , MATRIX_DISPLAY_X + 9         , MATRIX_DISPLAY_Y + MATRIX_ROWS - 1); //Bottom left lower-right 8
   draw_line_x(MATRIX_DISPLAY_X + 2 + offset, MATRIX_DISPLAY_X + offset + 7, MATRIX_DISPLAY_Y + MATRIX_ROWS - 1);  //Bottom right lower left 9

   draw_line_x(MATRIX_DISPLAY_X + 1         , MATRIX_DISPLAY_X + 4          , MATRIX_DISPLAY_Y + MATRIX_ROWS - 2); //Bottom left upper left 7
   draw_line_x(MATRIX_DISPLAY_X + 7 + offset, MATRIX_DISPLAY_X + offset + 10, MATRIX_DISPLAY_Y + MATRIX_ROWS - 2); //Bottom right upper right 0

   draw_line_y(MATRIX_DISPLAY_X                                 , MATRIX_DISPLAY_Y + 1, MATRIX_DISPLAY_Y + 6); //1
   draw_line_y(MATRIX_DISPLAY_X + MATRIX_ROWS + 1               , MATRIX_DISPLAY_Y + 1, MATRIX_DISPLAY_Y + 7); //2
   draw_line_y(MATRIX_DISPLAY_X + MATRIX_ROWS + 1 + DISTANCE    , MATRIX_DISPLAY_Y + 1, MATRIX_DISPLAY_Y + 7); //3
   draw_line_y(MATRIX_DISPLAY_X + 2 * MATRIX_ROWS + 2 + DISTANCE, MATRIX_DISPLAY_Y + 1, MATRIX_DISPLAY_Y + 6); //4
}
