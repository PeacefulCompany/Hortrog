#include "ActionMap.h"

template <typename T>
inline void ActionMap<T>::map(const T& key, const Action& action) {}

template <typename T>
inline const Action& ActionMap<T>::get(const T& key) const {}