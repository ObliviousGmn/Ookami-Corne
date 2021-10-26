// Dokuu // Okami // April 2021

/* Blank */
void render_space(void) {
    oled_write_P(PSTR("                     "), false);
}

/* Seperator */
void render_separator(void) {
    oled_write_P(PSTR("X-------------------X"), false);
}

/* Badge */
void render_brand(void) {
   oled_write_P(PSTR("    CORNE X OKAMI    "), false);
}

/* Weapon Layer */
void render_w(void) {
   oled_write_P(PSTR("    CORNE X WEAPON   "), false);
}


/* Layer State */
void render_layer_state(void){
    switch (get_highest_layer(layer_state)){
        case _BASE:
            oled_write_P(PSTR("     MODE X DEFAULT  "), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("     MODE X NUMBERS  "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("     MODE X SYMBOLS  "), false);
            break;
        case _ADJUST :
            oled_write_P(PSTR("     MODE X ADJUST   "), false);
            break;
        case _FCTION :
            oled_write_P(PSTR("     MODE X FUNCTION "), false);
            break;
        case _GAME :
            oled_write_P(PSTR("     MODE X GAMING   "), false);
            break;
        case _WEAPON :
            oled_write_P(PSTR("     MODE X GAMING   "), false);
            break;
        default:
            oled_write_P(PSTR("     MODE X UNKNOWN  "), false);
    }
}
