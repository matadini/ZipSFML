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

#ifndef ZIP_SFML_H
#define ZIP_SFML_H

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>



class ZipSFML
{
public:
    ZipSFML();

    ZipSFML(const std::string& fileName);

    ~ZipSFML();

    sf::Font* getFontFromZip(std::string name) const;
    sf::Texture* getTextureFromZip(std::string name) const;
    sf::SoundBuffer* getSoundBufferFromZip(std::string name) const;

private:
    std::string m_fileName;

};



#endif // ZIP_SFML_H
