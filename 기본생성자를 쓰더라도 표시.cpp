class gslice
{
private:
    valarray<size_t> size;
    valarray<size_t> stride;
    valarray<size_t> dl;
public:
    gslice() = default;
    ~gslice() = default;
    gslice(const gslice&) = default;
    gslice(gslice&&) = default;
    gslice& operator=(const gslice&) = default;
    gslice& operator=(gslice&&) = default;
};

class gslice
{
private:
    valarray<size_t> size;
    valarray<size_t> stride;
    valarray<size_t> dl;
public:
    // ...
};
