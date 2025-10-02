#ifndef SCALERCONVERTER_HPP
#define SCALERCONVERTER_HPP

#include <string>
/*
* static_cast: You are performing a sensible, compile-time-checked conversion.

* dynamic_cast: You are navigating a class hierarchy and need a runtime safety
 check.

* reinterpret_cast: You are doing something low-level and potentially dangerous
 with the raw bits of your data.

* const_cast: You are specifically changing the const-ness of a variable.  */

class ScalerConverter {
  public:
    ScalerConverter();
    ScalerConverter(const ScalerConverter& other);
    ScalerConverter& operator=(const ScalerConverter& other);
    ~ScalerConverter();

    static void convert(const std::string& str);
};

#endif
