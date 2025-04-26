#pragma once
#ifndef TREEBAVIOR_H
#define TREEBAVIOR_H

#include <assert.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#define ASSERT(X) assert(X); __analysis_assume(X)
#define ASSERT_MSG(X, M) ASSERT(X)
#else
#define ASSERT(X) assert(X)
#define ASSERT_MSG(X, M) ASSERT(X)
#endif

#endif