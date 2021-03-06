#ifndef ACLK_VERSION_INCLUDED
#define ACLK_VERSION_INCLUDED

#define MAKE_STR_HELPER(a_str) #a_str
#define MAKE_STR(a_str) MAKE_STR_HELPER(a_str)

#define ACLK_VERSION_MAJOR 1
#define ACLK_VERSION_MINOR 3
#define ACLK_VERSION_PATCH 0
#define ACLK_VERSION_BETA 0
#define ACLK_VERSION_VERSTRING   \
	MAKE_STR(ACLK_VERSION_MAJOR) \
	"." MAKE_STR(ACLK_VERSION_MINOR) "." MAKE_STR(ACLK_VERSION_PATCH) "." MAKE_STR(ACLK_VERSION_BETA)

#endif
