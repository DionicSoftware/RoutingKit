// #include <routingkit/contraction_hierarchy.h>

using namespace std;
// using namespace RoutingKit;

#if defined(_MSC_VER)
#ifdef ROUTINGKIT_EXPORTS
/* We are building this library */
#   define ROUTINGKIT_API extern "C" __declspec(dllexport)
#else
/* We are using this library */ 
#   define ROUTINGKIT_API extern "C" __declspec(dllimport)
#endif
#else
    #define ROUTINGKIT_API extern "C"  
#endif

ROUTINGKIT_API int* get_number();