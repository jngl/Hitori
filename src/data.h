#ifndef DATA_H
#define DATA_H

#include <string>

using uint8 = unsigned char;

struct Point2f{
    float x;
    float y;
};

struct Vector2f{
    float x;
    float y;
};

struct ColorRGBA{
    uint8 red;
    uint8 green;
    uint8 blue;
    uint8 alpha;
};

struct Error{
    std::string message;
};

template<class T>
class DataView{
public:
    DataView(T& data, size_t stride, size_t size):
        m_dataBegin(data),
        m_stride(stride),
        m_size(size)
    {
    }

    T& operator[](size_t index){
        if(index>=m_size){
            throw Error{"out of bound index"};
        }
        T* ptr = &m_dataBegin;
        return ptr + m_stride*index;
    }

private:
    T& m_dataBegin;
    size_t m_stride;
    size_t m_size;
};


#endif // DATA_H
