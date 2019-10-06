#include "gtest/gtest.h"
#include <Vector2D.hpp>

TEST(Vector2D, construct)
{
    Vector2D<int> vec2d;

    EXPECT_EQ(vec2d.width(), 0);
    EXPECT_EQ(vec2d.height(), 0);
}

TEST(Vector2D, reset)
{
    constexpr size_t width = 8;
    constexpr size_t height = 9;
    
    Vector2D<int> vec2d;
    
    vec2d.reset(width, height, 0);
    
    const Vector2D<int>& vec2d_const = vec2d;

    EXPECT_EQ(vec2d_const.width(), width);
    EXPECT_EQ(vec2d_const.height(), height);
}

TEST(Vector2D, outOfBounds)
{
    constexpr size_t width = 8;
    constexpr size_t height = 9;
    
    Vector2D<int> vec2d;
    
    vec2d.reset(width, height, 0);
    
    EXPECT_THROW(vec2d.at(1,42), OutOfBounds);
    EXPECT_THROW(vec2d.at(42,1), OutOfBounds);
    EXPECT_THROW(vec2d.at(42,42), OutOfBounds);
}

TEST(Vector2D, at)
{
    constexpr size_t width = 8;
    constexpr size_t height = 9;
    
    Vector2D<int> vec2d;
    const Vector2D<int>& vec2d_const = vec2d;
    
    constexpr int resize_value = 12;
    vec2d.reset(width, height, resize_value);
    
    EXPECT_EQ(vec2d.at(0,0), resize_value);
    
    constexpr int set_value = 42;
    vec2d.at(0,0) = set_value;
    
    EXPECT_EQ(vec2d_const.at(0,0), set_value);
}
