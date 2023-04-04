// dma.h ---- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_

class DMA
{
private:
    char *ClassType;
public:
    DMA(const char *ct = "DMA");
    DMA(const DMA& dma);
    virtual ~DMA();
    DMA &operator=(const DMA &dma);
    virtual void View() const = 0;
};

// Base Class Using DMA
class baseDMA : public DMA
{
private:
    char *ClassName;

public:
    baseDMA(const char *cn = "baseDMA is from ");
    baseDMA(const baseDMA &rs);
    virtual ~baseDMA();
    baseDMA &operator=(const baseDMA &rs);
    void View() const;
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public DMA
{
private:
    char ClassName[40];

public:
    lacksDMA(const char *c = "lacksDMA is from ");
    lacksDMA(const lacksDMA &ld);
    void View() const;
};

// derived class with DMA
class hasDMA : public DMA
{
private:
    char *ClassName;

public:
    hasDMA(const char *s = "hasDMA is from ");
    hasDMA(const hasDMA &hs);
    ~hasDMA();
    void View() const;
    hasDMA &operator=(const hasDMA &rs);
};

#endif