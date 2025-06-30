#ifndef EASYFIND_TPP
#define EASYFIND_TPP

// Template implementation file for easyfind function template
template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator it =
      std::find(container.begin(), container.end(), value);
  if (it == container.end()) throw ElementNotFoundException();
  return it;
}

// Const version
template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {
  typename T::const_iterator it =
      std::find(container.begin(), container.end(), value);
  if (it == container.end()) throw ElementNotFoundException();
  return it;
}

#endif  // EASYFIND_TPP
