//
//  Despacito.h
//  Despacito
//
//  Created by Bryan Wong on 4/14/19.
//  Copyright © 2019 Bryan Wong. All rights reserved.
//

void Despacito() {
    NOTE_DUR = 58;  // Set tempo to be faster
    play(NOTE_D4, 1);
    play(NOTE_FS4, 1);
    play(NOTE_B4, 1);
    play(NOTE_D5, 1);
    play(NOTE_CS5, 1);
    play(NOTE_B4, 1);
    play(NOTE_AS4, 1);
    play(NOTE_B4, 16); //m2
    delay(NOTE_DUR*6);
    play(NOTE_B4, 6);
    play(NOTE_CS5, 6);
    play(NOTE_D5, 6);
    play(NOTE_E5, 6); //m3
    play(NOTE_FS5, 7);
    play(NOTE_D5, 7);
    play(NOTE_FS5, 8);
    play(NOTE_D5, 8);
    play(NOTE_FS5, 22);
    delay(NOTE_DUR*4);
    play(NOTE_FS4, 2); //m4
    play(NOTE_D5, 6);
    play(NOTE_E4, 2);
    play(NOTE_CS5, 6);
    play(NOTE_D4, 2);
    play(NOTE_B4, 4); //m5
    play(NOTE_D4, 2);
    play(NOTE_FS4, 4);
    play(NOTE_B4, 2);
    play(NOTE_D4, 4);
    play(NOTE_B4, 4);
    play(NOTE_D4, 2);
    play(NOTE_FS4, 2);
    play(NOTE_D5, 2);
    play(NOTE_CS5, 2);
    play(NOTE_B4, 2);
    play(NOTE_A4, 2);
    play(NOTE_B4, 4); //m6
    play(NOTE_D4, 2);
    play(NOTE_G4, 4);
    play(NOTE_B4, 2);
    play(NOTE_D4, 4);
    play(NOTE_B4, 4);
    play(NOTE_D4, 2);
    play(NOTE_G4, 2);
    play(NOTE_D5, 2);
    play(NOTE_CS5, 2);
    play(NOTE_B4, 2);
    play(NOTE_A4, 2);
    play(NOTE_D5, 4); //m7
    play(NOTE_FS4, 2);
    play(NOTE_A4, 4);
    play(NOTE_D5, 2);
    play(NOTE_FS4, 4);
    play(NOTE_D5, 4);
    play(NOTE_FS4, 2);
    play(NOTE_A4, 2);
    play(NOTE_D5, 2);
    play(NOTE_CS5, 2);
    play(NOTE_B4, 2);
    play(NOTE_A4, 2);
    play(NOTE_E5, 12); //m8
    delay(NOTE_DUR*2);
    play(NOTE_FS4, 2);
    play(NOTE_D5, 6);
    play(NOTE_E4, 2);
    play(NOTE_CS5, 6);
    play(NOTE_D4, 2);
    play(NOTE_B4, 10); //m9
}
