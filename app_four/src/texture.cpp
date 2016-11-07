#include "texture.h"
#include "stb_image.h"
#include <cassert>
#include <iostream>
//https://youtu.be/17axYo6mKhY?list=PLEETnX-uPtBXT9T-hD0Bj31DSnwio-ywh&t=1838

Texture::Texture(const std::string& fileName)
{
    int width, height, numComponents;
    unsigned char* imageData = stbi_load(fileName.c_str(), &width, &height, &numComponents, 4);

    if(imageData == NULL)
        std::cerr << "Texture loading failed." << fileName << std::endl;

    glGenTextures(1, &m_texture); //alocate texture space in memory
    glBindTexture(GL_TEXTURE_2D, m_texture);

    // Set the behavior for non-exiting data, in this case, repeat texture in u and v dimensions
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    //Bahavior for maximize and minimazing texture. Set to linear
    glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

    stbi_image_free(imageData);
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_texture);
}

void Texture::Bind(unsigned int unit)
{
    //Check boundaries
    assert(unit >= 0 && unit <= 31);

    glActiveTexture(GL_TEXTURE0 + unit); //little trick for sequancial array access.
    glBindTexture(GL_TEXTURE_2D, m_texture);

}
