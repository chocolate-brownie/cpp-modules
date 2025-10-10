#ifndef BASE_HPP
#define BASE_HPP

/*
 * The main lesson of this exercise is how to safely manage different object
 * types in a polymorphic hierarchy.
 *
 * This exercise simulates that exact problem. You have a generic Base* pointer,
 * but you need to figure out if it's really pointing to an A, a B, or a C so
 * you can handle it correctly. This is a fundamental concept in Object-Oriented
 * Programming called Runtime Type Identification (RTTI).
 * */
class Base {
  public:
    virtual ~Base();
};

#endif
