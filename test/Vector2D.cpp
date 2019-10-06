#include "gtest/gtest.h"
#include <core/Vector2D.hpp>

TEST(Vector2D, construct)
{
    core::Vector2D<int> vec2d;

    EXPECT_EQ(vec2d.width(), 0);
    EXPECT_EQ(vec2d.height(), 0);
}

TEST(Vector2D, reset)
{
    constexpr core::Size width = 8;
    constexpr core::Size height = 9;
    
    core::Vector2D<int> vec2d;
    
    vec2d.reset(width, height, 0);
    
    const core::Vector2D<int>& vec2d_const = vec2d;

    EXPECT_EQ(vec2d_const.width(), width);
    EXPECT_EQ(vec2d_const.height(), height);
}

TEST(Vector2D, outOfBounds)
{
    constexpr core::Size width = 8;
    constexpr core::Size height = 9;
    
    core::Vector2D<int> vec2d;
    
    vec2d.reset(width, height, 0);
    
    EXPECT_THROW(vec2d.at(1,42),  core::OutOfBounds);
    EXPECT_THROW(vec2d.at(42,1),  core::OutOfBounds);
    EXPECT_THROW(vec2d.at(42,42), core::OutOfBounds);
}

TEST(Vector2D, at)
{
    constexpr core::Size width = 8;
    constexpr core::Size height = 9;
    
    core::Vector2D<int> vec2d;
    const core::Vector2D<int>& vec2d_const = vec2d;
    
    constexpr int resize_value = 12;
    vec2d.reset(width, height, resize_value);
    
    EXPECT_EQ(vec2d.at(0,0), resize_value);
    
    constexpr int set_value = 42;
    vec2d.at(0,0) = set_value;
    
    EXPECT_EQ(vec2d_const.at(0,0), set_value);
}
