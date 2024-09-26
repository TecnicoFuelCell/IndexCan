// CAN System

#ifndef MULTIPLESIGNALS_H
#define MULTIPLESIGNALS_H

#include <stdio.h>
#include <stdint.h>

// Signal: pedal_voltage
typedef struct pedal_voltage {
    char* name;
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    float min_value;
    float max_value;
    char* type;
    char* byte_order;
} pedal_voltage;


// Signal: pedal_position
typedef struct pedal_position {
    char* name;
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* blablabla;
    float min_value;
    float max_value;
} pedal_position;


// pedal_mod Module
typedef struct pedal_msg {
    char* name;
    uint8_t id;
    uint8_t prio;
    uint8_t dlc;
    pedal_voltage pedal_voltage;
    pedal_position pedal_position;
} pedal_msg;


static pedal_msg pedal_msg_instance = {
    .name = "mensagem do pedal",
    .id = 1,
    .prio = 1,
    .dlc = 8,
    .pedal_voltage = {
        .name = "tensão do pedal",
        .start = 0,
        .length = 9,
        .scale = 0.00644,
        .offset = 0.0,
        .unit = "V",
        .comment = "Voltage from the pedal sensor (0.00 to 3.3 V)",
        .min_value = 0.0,
        .max_value = 3.3,
        .type = "unsigned",
        .byte_order = "little_endian",
    },
    .pedal_position = {
        .name = "posição do pedal",
        .start = 9,
        .length = 7,
        .scale = 0.392,
        .offset = 0.0,
        .unit = "%",
        .comment = "Position of the pedal (0 to 100%)",
        .blablabla = "blablabla",
        .min_value = 0.0,
        .max_value = 100.0,
    },
};


#endif // MULTIPLESIGNALS_H
