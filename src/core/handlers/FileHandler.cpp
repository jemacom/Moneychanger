#ifndef STABLE_H
#include <core/stable.h>
#endif

#include "FileHandler.h"


bool FileHandler::removeFile(QString fileName)
{
    bool error = false;
    error = QFile::remove(fileName);
    
    if(error == false)
    {
        qDebug() << fileHandlerstr + " " + fileNotRemovedStr;
        return error;
    }
    
    qDebug() << fileHandlerstr + " " + fileRemovedStr;
    return error;
    
}


bool FileHandler::isFileExist(QString fileName)
{
    bool error = false;
    error = QFile::exists(fileName);
    
    if(error == false)
    {
        qDebug() << fileHandlerstr + " " + fileNotExistStr;
        return error;
    }
    return error;
}
