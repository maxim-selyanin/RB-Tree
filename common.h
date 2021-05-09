#pragma once

#include "pch.h"

template <typename T>
extern constexpr bool any_int = std::is_integral_v<T> && !std::is_same_v<T, bool>;

template <typename T>
using integral = std::enable_if_t<any_int<T>>;