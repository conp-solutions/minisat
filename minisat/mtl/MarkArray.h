/*************************************************************************************[MarkArray.h]
Copyright (c) 2003-2007, Niklas Een, Niklas Sorensson
Copyright (c) 2007-2010, Niklas Sorensson
Copyright (c) 2018, Norbert Manthey

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT
OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**************************************************************************************************/

#ifndef Minisat_MarkArray_h
#define Minisat_MarkArray_h

#include "minisat/mtl/Vec.h"

namespace Minisat {

//=================================================================================================

/** Container to perform simple set operations on numbers with fast clear */
class MarkArray {
    vec<uint32_t>   permDiff;
    uint32_t        MYFLAG;
public:

    MarkArray       () : MYFLAG(0) {}

    /** increase capacity by one */
    void push       () { permDiff.push(0); }

    /** return current size */
    size_t size     () const { return permDiff.size(); }

    /** add an element to the set */
    void add        (const size_t index) { permDiff[index] = MYFLAG;}

    /** check whether the given element is in the set */
    bool contains   (const size_t index) const { return permDiff[index] == MYFLAG;}

    /** clear the set by incrementing the MYFLAG counter */
    void clear      () {
      if(MYFLAG ++ == 0) {
        size_t s = permDiff.size();
        permDiff.clear();
        permDiff.growTo(s, 0);
        MYFLAG = 1; } }
};


//=================================================================================================
}

#endif
