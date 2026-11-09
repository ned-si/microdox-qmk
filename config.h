#pragma once

// Rotary encoder added to the v1 PCB; upstream boardsource/microdox/v1 has none.
#define ENCODER_A_PINS { D5 }
#define ENCODER_B_PINS { B7 }
#define ENCODER_DIRECTION_FLIP
#define ENCODER_RESOLUTION 4

#define SPLIT_TRANSPORT_MIRROR
