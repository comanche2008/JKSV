#pragma once

#include "data.h"
#include "ui.h"
#include "type.h"

namespace fs
{
    typedef struct
    {
        std::string src, dst, dev;
        zipFile z;
        unzFile unz;
        bool cleanup = false, trimZipPath = false;
        uint8_t trimZipPlaces = 0;
        uint64_t offset = 0;
        ui::progBar *prog;
        threadStatus *thrdStatus;
        Mutex arglck = 0;
        void argLock() { mutexLock(&arglck); }
        void argUnlock() { mutexUnlock(&arglck); }
    } copyArgs;

    typedef struct
    {
        FsSaveDataType type;
        uint64_t tid;
        AccountUid account;
        uint16_t index;
    } svCreateArgs;

    typedef struct
    {
        const data::userTitleInfo *tinfo;
        uint64_t extSize;
    } svExtendArgs;

    typedef struct
    {
        std::string path;
        bool origin = false;
        unsigned dirCount = 0;
        unsigned fileCount = 0;
        uint64_t totalSize = 0;
    } dirCountArgs;
}
