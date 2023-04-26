#include <routingkit/contraction_hierarchy.h>
#include <vector>

using namespace std;
using namespace RoutingKit;

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

ROUTINGKIT_API ContractionHierarchy* get_number(unsigned node_count, unsigned tail[], unsigned head[], unsigned weight[]);