#pragma once

template <typename T, typename U>
inline bool is_same_v = false;

template <typename T>
inline bool is_same_v<T, T> = true;
