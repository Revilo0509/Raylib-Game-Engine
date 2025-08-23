/*
 * GETTER / GETTERSETTER code taken from Raylib-cpp wrapper
 */

#pragma once

#ifndef GETTER
/**
 * Defines a getter method for a class property.
 *
 * @param type   The type of the property.
 * @param method The PascalCase suffix for the method name.
 * @param name   The member variable name.
 */
#define GETTER(type, method, name)                         \
    /** Get the value of @p name. */                       \
    type Get##method() const { return name; }
#endif

#ifndef GETTERSETTER
/**
 * Defines getter and setter methods for a class property.
 *
 * @param type   The type of the property.
 * @param method The PascalCase suffix for the methods.
 * @param name   The member variable name.
 */
#define GETTERSETTER(type, method, name)                   \
    GETTER(type, method, name)                             \
    /** Set the value of @p name. */                       \
    void Set##method(type value) { name = value; }
#endif
