// dma.cpp ----- dma class methods
#include <iostream>
#include "dma.h"
#include <cstring>

DMA::DMA(const char *ct)
{
    ClassType = new char[strlen(ct) + 1];
    strcpy(ClassType, ct);
}

DMA::DMA(const DMA &dma)
{
    ClassType = new char[strlen(dma.ClassType) + 1];
    strcpy(ClassType, dma.ClassType);
}

DMA::~DMA()
{
    delete[] ClassType;
}

DMA &DMA::operator=(const DMA &dma)
{
    if (this == &dma)
        return *this;
    ClassType = new char[strlen(dma.ClassType) + 1];
    strcpy(ClassType, dma.ClassType);
    return *this;
}

void DMA::View() const
{
    std::cout << ClassType << std::endl;
}

// baseDMA methods
baseDMA::baseDMA(const char *cn)
{
    ClassName = new char[std::strlen(cn) + 1];
    std::strcpy(ClassName, cn);
}

baseDMA::baseDMA(const baseDMA &rs)
{
    ClassName = new char[std::strlen(rs.ClassName) + 1];
    std::strcpy(ClassName, rs.ClassName);
}

baseDMA::~baseDMA()
{
    delete[] ClassName;
}

baseDMA &baseDMA::operator=(const baseDMA &rs)
{
    if (this == &rs)
        return *this;
    delete[] ClassName;
    ClassName = new char[std::strlen(rs.ClassName) + 1];
    std::strcpy(ClassName, rs.ClassName);
    DMA::operator=(rs);
    return *this;
}

void baseDMA::View() const
{
    std::cout << ClassName;
    DMA::View();
}

// lacksDMA methods
lacksDMA::lacksDMA(const char *c)
{
    std::strncpy(ClassName, c, 39);
    ClassName[39] = '\0';
}

lacksDMA::lacksDMA(const lacksDMA &ld) : DMA(ld)
{
    strncpy(ClassName, ld.ClassName, 40);
}

void lacksDMA::View() const
{
    std::cout << ClassName;
    DMA::View();
}

// hasDMA methods
hasDMA::hasDMA(const char *s)
{
    ClassName = new char[std::strlen(s) + 1];
    std::strcpy(ClassName, s);
}

hasDMA::hasDMA(const hasDMA &hs) : DMA(hs) // invoke base class copy constructor
{
    ClassName = new char[std::strlen(hs.ClassName) + 1];
    std::strcpy(ClassName, hs.ClassName);
}

hasDMA::~hasDMA()
{
    delete[] ClassName;
}

void hasDMA::View() const
{
    std::cout << ClassName;
    DMA::View();
}

hasDMA &hasDMA::operator=(const hasDMA &hs)
{
    if (this == &hs)
        return *this;
    DMA::operator=(hs); // copy base portion
    delete[] ClassName;         // prepare for new style
    ClassName = new char[std::strlen(hs.ClassName) + 1];
    std::strcpy(ClassName, hs.ClassName);
    return *this;
}