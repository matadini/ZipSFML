/*
 * ZipSFML
 * Copyright (C) 2016 Matadini (matadini@hotmail.com)
 *
 * This software is provided 'as-is', without any express
 * or implied warranty. In no event will the authors be
 * held liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software
 * for any purpose, including commercial applications, and
 * to alter it and redistribute it freely, subject to the
 * following restrictions:
 *
 * 1. The origin of this software must not be misrepresented;
 * you must not claim that you wrote the original software.
 * If you use this software in a product, an acknowledgment
 * in the product documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such,
 * and must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

#include "zip_sfml.h"

#include <physfs.h>
#include <iostream>


ZipSFML::ZipSFML() {}


ZipSFML::~ZipSFML() {}


ZipSFML::ZipSFML(const std::string& fileName)
    : m_fileName(fileName) {}


sf::Font*
ZipSFML::getFontFromZip(std::string name) const
{
    PHYSFS_init(nullptr);
    PHYSFS_addToSearchPath(m_fileName.c_str(), 1);

    sf::Font* ptrToReturn = nullptr;

    if(PHYSFS_exists(name.c_str()))
    {
        PHYSFS_File* fileFromZip = PHYSFS_openRead(name.c_str());

        const int fileLenght = PHYSFS_fileLength(fileFromZip);
        char* buffer = new char[fileLenght];
        int readLength = PHYSFS_read (fileFromZip, buffer, 1, fileLenght);

        ptrToReturn = new sf::Font();
        if(!ptrToReturn->loadFromMemory(buffer, readLength)){
            std::cout << __func__ << " -load font from memory problem\n";
        }

        /* Why not delete[]
         * http://fr.sfml-dev.org/forums/index.php?topic=12360.0 */

        PHYSFS_close(fileFromZip);


    } else {
        std::cout << name + " - doesn't exists. \n";
    }
    PHYSFS_deinit();
    return ptrToReturn;
}


sf::Texture*
ZipSFML::getTextureFromZip(std::string name) const
{
    PHYSFS_init(nullptr);
    PHYSFS_addToSearchPath(m_fileName.c_str(), 1);

    sf::Texture* ptrToReturn = nullptr;

    if(PHYSFS_exists(name.c_str()))
    {
        PHYSFS_File* fileFromZip = PHYSFS_openRead(name.c_str());

        const int fileLenght = PHYSFS_fileLength(fileFromZip);
        char* buffer = new char[fileLenght];
        int readLength = PHYSFS_read (fileFromZip, buffer, 1, fileLenght);

        ptrToReturn = new sf::Texture();
        if(!ptrToReturn->loadFromMemory(buffer, readLength)){
            std::cout << __func__ << " -load font from memory problem\n";
        }

        delete[] buffer;
        PHYSFS_close(fileFromZip);

    } else {
        std::cout << name + " - doesn't exists. \n";
    }

    PHYSFS_deinit();

    return ptrToReturn;
}


sf::SoundBuffer*
ZipSFML::getSoundBufferFromZip(std::string name) const
{
    PHYSFS_init(nullptr);
    PHYSFS_addToSearchPath(m_fileName.c_str(), 1);

    sf::SoundBuffer* soundBufferPtr = nullptr;

    if(PHYSFS_exists(name.c_str()))
    {
        PHYSFS_File* fileFromZip = PHYSFS_openRead(name.c_str());

        const int fileLenght = PHYSFS_fileLength(fileFromZip);
        char* buffer = new char[fileLenght];
        int readLength = PHYSFS_read (fileFromZip, buffer, 1, fileLenght);

        soundBufferPtr = new sf::SoundBuffer();
        soundBufferPtr->loadFromMemory(buffer, readLength);

        delete[] buffer;
        PHYSFS_close(fileFromZip);

    } else {
        std::cout << name + " - doesn't exists. \n";
    }

    PHYSFS_deinit();

    return soundBufferPtr;
}




