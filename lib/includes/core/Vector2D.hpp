#pragma once

#include <core/BasicTypes.hpp>
#include <core/Error.hpp>
#include <vector>

namespace core {
    template<class T>
    class Vector2D
    {
    public:
        Vector2D();
        
        void reset(Size p_width, Size p_height, const T& value);
        
        Size width() const;
        Size height() const;
        
        T& at(Size width, Size height);
        const T& at(Size width, Size height) const;
        
    private:
        Size m_width;
        Size m_height;
        std::vector<T> m_data;
    };

    template<class T>
    Vector2D<T>::Vector2D():
        m_width(0),
        m_height(0)
    {
    }

    template<class T>
    void Vector2D<T>::reset(Size p_width, Size p_height, const T& value){
        m_width = p_width;
        m_height = p_height;
        m_data.resize(m_width*m_height, value);
    }

    template<class T>
    Size Vector2D<T>::width() const{
        return m_width;
    }

    template<class T>
    Size Vector2D<T>::height() const{
        return m_height;
    }

    template<class T>
    T& Vector2D<T>::at(Size x, Size y){
        if(x>=m_width || y>=m_height){
            throw OutOfBounds();
        }
        
        return m_data[m_width*y+x];
    }

    template<class T>
    const T& Vector2D<T>::at(Size x, Size y) const {
        return at(x, y);
    }
}
