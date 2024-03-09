/*

  when to use pointers vs. references parameters


  - pass-by-value
    1. when the function does not modify the actual parameter.
    2. the parameter is small and efficient to copy like simple types(int, char, double, bool, etc).

  - pass-by-reference using a pointer
    1. when the function does modify the actual parameter.
    2. the parameter is expensive to copy.
    3. it's ok to the pointer to allowed a nullptr value.

  - pass-by-reference using a pointer to const
    1. when the function does not modify the actual parameter.
    2. the parameter is expensive to copy.
    3. it's ok to the pointer to allowed a nullptr value.

  - pass-by-reference using a const pointer to const
    1. when the function does not modify the actual parameter.
    2. the parameter is expensive to copy.
    3. it's ok to the pointer to allowed a nullptr value.
    4. you don't want to modify the pointer itself.

  - pass-by-reference using a reference
    1. when the function does modify the actual parameter.
    2. the parameter is expensive to copy.
    3. the parameter will never be nullptr.

  - pass-by-reference using a const reference
    1. when the function does not modify the actual parameter.
    2. the parameter is expensive to copy.
    3. the parameter will never be nullptr.

*/
