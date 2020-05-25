// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#if defined (_MSC_VER)
#pragma once
#include "targetver.h"

// TODO: reference additional headers your program requires here
#pragma warning(push)
// 'std::tr1': warning STL4002: 
// The non-Standard std::tr1 namespace and TR1-only machinery are deprecated and will be REMOVED. 
// You can define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING to acknowledge that you have received this warning.
#pragma warning(disable:4996)
#include "gtest\gtest.h"
#pragma warning(pop)

#else // !defined (_MSC_VER)
#include "gtest\gtest.h"
#endif // _MSC_VER

#include "log4cpp\log4cpp.h"

#include <functional>
#include <memory>
#include <iostream>
