# 343-Lab1

From Header File:

lite_vector.{c,h}
Haoyu Li
 
A lite vector is a struct that holds a current length, a maximum capacity,
and a dynamically allocated chunk of memory.  It will hold elements added
and will extend the memory if it needs more space.
 
Note that written as is it will only hold *pointers* to any kind of data.
  
So if you are passing a char* (string), no worries, just pass the char*.  But,
If you wish to store a non-pointer type, you will need to pass the address.
For instance, if you wish to store ints, you must
 
int x = 42;
lv_append(lv, &x);
 
This means that if x changes sometime before you retrieve it with a lv_get(),
you will get the *new* value as you are just storing an address.

This also means that if for some reason the variable goes out of scope
or the the lifetime ends for that variable, you run the risk of 
a memory error.
 
A better alternative for a vector implementation would likely be macro
based, where the compiler can create a specific vector implementation for our
type based on a template.
 
However, that wouldn't cause you nearly as many problems with pointers, and
since you need to learn them (really well!), we complete this version
instead!
  
This also means that the type_size is essentially worthless.  I'm leaving it
here to see who reads the comments as they should.
  
Extra Point Question: 
Can you avoid the risk of the variable going out of the scope without using macros?
Implement this correctly and you will get 2 extra points.
(Hint: use memcpy function)

