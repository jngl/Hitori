#pragma once

#include <BasicTypes.hpp>
#include <Error.hpp>
#include <vector>

template<class T>
class Vector2D
{
public:
    Vector2D();
    
    void reset(size_t p_width, size_t p_height, const T& value);
    
    size_t width() const;
    size_t height() const;
    
    T& at(size_t width, size_t height);
    const T& at(size_t width, size_t height) const;
    
private:
    size_t m_width;
    size_t m_height;
    std::vector<T> m_data;
};

template<class T>
Vector2D<T>::Vector2D():
    m_width(0),
    m_height(0)
{
}

template<class T>
void Vector2D<T>::reset(size_t p_width, size_t p_height, const T& value){
    m_width = p_width;
    m_height = p_height;
    m_data.resize(m_width*m_height, value);
}

template<class T>
size_t Vector2D<T>::width() const{
    return m_width;
}

template<class T>
size_t Vector2D<T>::height() const{
    return m_height;
}

template<class T>
T& Vector2D<T>::at(size_t x, size_t y){
    if(x>=m_width || y>=m_height){
        throw OutOfBounds();
    }
    
    return m_data[m_width*y+x];
}

template<class T>
const T& Vector2D<T>::at(size_t x, size_t y) const {
    return at(x, y);
}
