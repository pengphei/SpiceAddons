/*
 * Copyright 2022, Haiku.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Han Pengfei <pengphei@qq.com>
 */

#ifndef DRIVERINTERFACE_H
#define DRIVERINTERFACE_H

#include <GraphicsDefs.h>
#include <Accelerant.h>
#include <Drivers.h>
#include <PCI.h>
#include <OS.h>

#include "qxl.h"
#include <spice/protocol.h>
#include <spice/qxl_dev.h>
#include <spice/macros.h>

/*--------------------------------------------------------------------*/
/* Structure shared between the kernel driver and the accelerant */

typedef struct {
    /* Device info and capabilities */
    uint16			vendorId;
    uint16			deviceId;
    uint8			revision;
    uint32			maxWidth;
    uint32			maxHeight;
    void			*fbDma;
    uint32			fbSize;
    void			*fifoDma;
    uint32			fifoSize;

    void			*ramDma;
    uint32			ramSize;
    void			*vramDma;
    uint32			vramSize;
    void			*romDma;
    uint32			romSize;

    uint32			fifoMin;
    uint32			capabilities;
    uint32			fifoCapabilities;
    uint32			fifoFlags;

    /* For registers access */
    uint16			indexPort;
    uint16			valuePort;

    /* Mapped areas */
    area_id			fbArea;
    void			*fb;
    area_id			fifoArea;
    void			*fifo;

    area_id			ramArea;    /* Command RAM */
    void			*ram;
    area_id			vramArea;   /* Surface RAM */
    void			*vram;
    area_id			romArea;
    void			*rom;       /* Parameter RAM */

    /* This changes when we switch to another mode */
    uint32			fbOffset;
    uint32			bytesPerRow;

    /* Current display mode */
    display_mode	dm;

    Benaphore		engineLock;
    Benaphore		fifoLock;
    uint32			fifoNext;

    /* Cursor state */
    bool			cursorShow;
    uint16			cursorX;
    uint16			cursorY;
} SharedInfo;

#endif
