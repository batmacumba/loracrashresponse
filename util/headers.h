/*
  headers.h
  Created by Bruno Carneiro
  Released into the public domain
*/

#ifndef HEADERS_H
#define HEADERS_H

typedef struct {
    uint32_t eventID;
    uint16_t attempts;
    uint8_t hopCount;
    uint8_t type;
    float latitude;
    float longitude;
    uint8_t souls;
    uint8_t speed;
} CrashResponseHeader;

#endif	/* HEADERS_H */

