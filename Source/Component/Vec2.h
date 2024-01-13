#pragma once
#include <cassert>
#include <cmath>
#include <numbers>

namespace Project::Component
{
    template<typename T>
    class Vec2
    {
    public:
        T x, y;
        
        constexpr Vec2();
        
        constexpr Vec2(T x, T y);
        
        template<typename K>
        Vec2<T>& operator=(Vec2<K> const& v);

        template<typename K>
        constexpr bool operator==(Vec2<K> const& v) const;
        
        template<typename K>
        constexpr Vec2<T> operator+(Vec2<K> const& v) const;
        
        template<typename K>
        constexpr Vec2<T> operator-(Vec2<K> const& v) const;

        template<typename K>
        constexpr Vec2<T> operator*(Vec2<K> const& v) const;

        template<typename K>
        constexpr Vec2<T> operator/(Vec2<K> const& v) const;

        template<typename K>
        constexpr Vec2<T>& operator+=(Vec2<K> const& v);

        template<typename K>
        constexpr Vec2<T>& operator-=(Vec2<K> const& v);

        template<typename K>
        constexpr Vec2<T>& operator*=(Vec2<K> const& v);

        template<typename K>
        constexpr Vec2<T>& operator/=(Vec2<K> const& v);

        template<typename K>
        constexpr Vec2<T> operator+(K v) const;
        
        template<typename K>
        constexpr Vec2<T> operator-(K v) const;

        template<typename K>
        constexpr Vec2<T> operator*(K v) const;

        template<typename K>
        constexpr Vec2<T> operator/(K v) const;

        template<typename K>
        constexpr Vec2<T>& operator+=(K v);

        template<typename K>
        constexpr Vec2<T>& operator-=(K v);

        template<typename K>
        constexpr Vec2<T>& operator*=(K v);

        template<typename K>
        constexpr Vec2<T>& operator/=(K v);

        float angle() const;

        template<typename K>
        float distance(Vec2<K> const& v) const;

        float length() const;

        Vec2<T> clamp_magnitude(float max) const;

        Vec2<T> normalized() const;

        Vec2<T>& rotate(float degrees);

        template<typename K>
        Vec2<T>& rotate_around(float degrees, Vec2<K> const& v);
    };
    
    using Vec2f = Project::Component::Vec2<float>;
}

template<typename T>
constexpr Project::Component::Vec2<T>::Vec2(): x((T) 0), y((T) 0)
{
}

template<typename T>
constexpr Project::Component::Vec2<T>::Vec2(T x, T y): x(x), y(y)
{
}

template<typename T>
template<typename K>
Project::Component::Vec2<T>& Project::Component::Vec2<T>::operator=(Project::Component::Vec2<K> const& v)
{
    this->x = (T) v.x;
    this->y = (T) v.y;
    return *this;
}

template<typename T>
template<typename K>
constexpr bool Project::Component::Vec2<T>::operator==(Project::Component::Vec2<K> const& v) const
{
    return (this->x == v.x && this->y == v.y);
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T> Project::Component::Vec2<T>::operator+(Project::Component::Vec2<K> const& v) const
{
    return Project::Component::Vec2<T>(this->x + (T) v.x, this->y + (T) v.y);
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T> Project::Component::Vec2<T>::operator-(Project::Component::Vec2<K> const& v) const
{
    return Project::Component::Vec2<T>(this->x - (T) v.x, this->y - (T) v.y);
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T> Project::Component::Vec2<T>::operator*(Project::Component::Vec2<K> const& v) const
{
    return Project::Component::Vec2<T>(this->x * (T) v.x, this->y * (T) v.y);
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T> Project::Component::Vec2<T>::operator/(Project::Component::Vec2<K> const& v) const
{
    assert((T) v.x != (T) 0);
    assert((T) v.y != (T) 0);
    return Project::Component::Vec2<T>(this->x / (T) v.x, this->y / (T) v.y);
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T>& Project::Component::Vec2<T>::operator+=(Project::Component::Vec2<K> const& v)
{
    this->x += (T) v.x;
    this->y += (T) v.y;
    return *this;
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T>& Project::Component::Vec2<T>::operator-=(Project::Component::Vec2<K> const& v)
{
    this->x -= (T) v.x;
    this->y -= (T) v.y;
    return *this;
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T>& Project::Component::Vec2<T>::operator*=(Project::Component::Vec2<K> const& v)
{
    this->x *= (T) v.x;
    this->y *= (T) v.y;
    return *this;
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T>& Project::Component::Vec2<T>::operator/=(Project::Component::Vec2<K> const& v)
{
    assert((T) v.x != (T) 0);
    assert((T) v.y != (T) 0);
    this->x /= (T) v.x;
    this->y /= (T) v.y;
    return *this;
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T> Project::Component::Vec2<T>::operator+(K v) const
{
    return Project::Component::Vec2<T>(this->x + (T) v, this->y + (T) v);
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T> Project::Component::Vec2<T>::operator-(K v) const
{
    return Project::Component::Vec2<T>(this->x - (T) v, this->y - (T) v);
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T> Project::Component::Vec2<T>::operator*(K v) const
{
    return Project::Component::Vec2<T>(this->x * (T) v, this->y * (T) v);
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T> Project::Component::Vec2<T>::operator/(K v) const
{
    assert((T) v != (T) 0);
    return Project::Component::Vec2<T>(this->x / (T) v, this->y / (T) v);
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T>& Project::Component::Vec2<T>::operator+=(K v)
{
    this->x += (T) v;
    this->y += (T) v;
    return *this;
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T>& Project::Component::Vec2<T>::operator-=(K v)
{
    this->x -= (T) v;
    this->y -= (T) v;
    return *this;
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T>& Project::Component::Vec2<T>::operator*=(K v)
{
    this->x *= (T) v;
    this->y *= (T) v;
    return *this;
}

template<typename T>
template<typename K>
constexpr Project::Component::Vec2<T>& Project::Component::Vec2<T>::operator/=(K v)
{
    assert((T) v != (T) 0);
    this->x /= (T) v;
    this->y /= (T) v;
    return *this;
}

template<typename T>
float Project::Component::Vec2<T>::angle() const
{
    return atan2f(this->y, this->x);
}

template<typename T>
template<typename K>
float Project::Component::Vec2<T>::distance(Project::Component::Vec2<K> const& v) const
{
    return (*this - v).length();
}

template<typename T>
float Project::Component::Vec2<T>::length() const
{
    if (this->x == (T) 0 && this->y == (T) 0)
    {
        return 0.0f;
    }
    else
    {
        return std::sqrt((float) (this->x * this->x) + (float) (this->y * this->y));
    }
}

template<typename T>
Project::Component::Vec2<T> Project::Component::Vec2<T>::clamp_magnitude(float max) const
{
    return this->normalized() * std::min(this->length(), max);
}

template<typename T>
Project::Component::Vec2<T> Project::Component::Vec2<T>::normalized() const
{
    Project::Component::Vec2<T> norm = *this;
    float len = norm.length();
    if (len != 0.0f)
    {
        norm /= len;
    }
    return norm;
}

template<typename T>
Project::Component::Vec2<T>& Project::Component::Vec2<T>::rotate(float degrees)
{
    return this->rotate_around(degrees, Project::Component::Vec2<T>(0, 0));
}

template<typename T>
template<typename K>
Project::Component::Vec2<T>& Project::Component::Vec2<T>::rotate_around(float degrees, Project::Component::Vec2<K> const& v)
{
    float angle_radians = degrees * (std::numbers::pi / 180.0f);
    T x_ = (T) (std::cos(angle_radians) * (this->x - v.x)) - (std::sin(angle_radians) * (this->y - v.y)) + v.x; 
    T y_ = (T) (std::sin(angle_radians) * (this->x - v.x)) + (std::cos(angle_radians) * (this->y - v.y)) + v.y;
    this->x = x_;
    this->y = y_;
    return *this;
}

constexpr void Vec2_static_test()
{
    {
        constexpr auto a = Project::Component::Vec2<int>(1, 1);
        constexpr auto b = Project::Component::Vec2<int>(1, 1);
        static_assert(a == b);
    }
    {
        constexpr auto a = Project::Component::Vec2<int>(5, 6);
        constexpr auto b = Project::Component::Vec2<int>(7, 8);
        static_assert(a != b);
    }
    {
        constexpr auto a = Project::Component::Vec2<int>(1, 9);
        constexpr auto b = Project::Component::Vec2<int>(2, 4);
        constexpr auto c = Project::Component::Vec2<int>(3, 13);
        static_assert(a + b == c);
    }
    {
        constexpr auto a = Project::Component::Vec2<int>(3, 5);
        constexpr auto b = Project::Component::Vec2<int>(2, 1);
        constexpr auto c = Project::Component::Vec2<int>(1, 4);
        static_assert(a - b == c);
    }
    {
        constexpr auto a = Project::Component::Vec2<int>(2, 3);
        constexpr auto b = Project::Component::Vec2<int>(2, 5);
        constexpr auto c = Project::Component::Vec2<int>(4, 15);
        static_assert(a * b == c);
    }
    {
        constexpr auto a = Project::Component::Vec2<int>(8, 10);
        constexpr auto b = Project::Component::Vec2<int>(4, 2);
        constexpr auto c = Project::Component::Vec2<int>(2, 5);
        static_assert(a / b == c);
    }
    {
        constexpr auto a = Project::Component::Vec2<int>(8, 10);
        constexpr auto b = Project::Component::Vec2<int>(4, 5);
        constexpr auto c = a + b;
        static_assert(c.x == 12);
        static_assert(c.y == 15);
    }
    {
        constexpr auto a = Project::Component::Vec2<int>(8, 10);
        constexpr auto b = Project::Component::Vec2<int>(4, 5);
        constexpr auto c = a - b;
        static_assert(c.x == 4);
        static_assert(c.y == 5);
    }
    {
        constexpr auto a = Project::Component::Vec2<int>(8, 10);
        constexpr auto b = Project::Component::Vec2<int>(4, 5);
        constexpr auto c = a * b;
        static_assert(c.x == 32);
        static_assert(c.y == 50);
    }
    {
        constexpr auto a = Project::Component::Vec2<int>(8, 10);
        constexpr auto b = Project::Component::Vec2<int>(4, 5);
        constexpr auto c = a / b;
        static_assert(c.x == 2);
        static_assert(c.y == 2);
    }
    {
        constexpr auto a = Project::Component::Vec2<int>(8, 10);
        constexpr auto b = a + 1;
        constexpr auto c = Project::Component::Vec2<int>(9, 11);
        static_assert(b == c);
    }
    {
        constexpr auto a = Project::Component::Vec2<int>(4, 7);
        constexpr auto b = a - 3;
        constexpr auto c = Project::Component::Vec2<int>(1, 4);
        static_assert(b == c);
    }
    {
        constexpr auto a = Project::Component::Vec2<int>(8, 10);
        constexpr auto b = a * 5;
        constexpr auto c = Project::Component::Vec2<int>(40, 50);
        static_assert(b == c);
    }
    {
        constexpr auto a = Project::Component::Vec2<int>(8, 10);
        constexpr auto b = a / 2;
        constexpr auto c = Project::Component::Vec2<int>(4, 5);
        static_assert(b == c);
    }
}