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

ROUTINGKIT_API ContractionHierarchy* build_contraction_hierarchy(unsigned node_count, unsigned edge_count, unsigned tail[], unsigned head[], unsigned weight[]);
ROUTINGKIT_API void free_contraction_hierarchy(ContractionHierarchy* contraction_hierarchy);
ROUTINGKIT_API ContractionHierarchyQuery* build_contraction_hierarchy_query(ContractionHierarchy* contraction_hierarchy);
ROUTINGKIT_API void free_contraction_hierarchy_query(ContractionHierarchyQuery* contraction_hierarchy_query);
ROUTINGKIT_API void reset_contraction_hierarchy_query(ContractionHierarchyQuery* contraction_hierarchy_query);
ROUTINGKIT_API void contraction_hierarchy_query_add_source(ContractionHierarchyQuery* contraction_hierarchy_query, unsigned source);
ROUTINGKIT_API void contraction_hierarchy_query_add_target(ContractionHierarchyQuery* contraction_hierarchy_query, unsigned target);
ROUTINGKIT_API void run_contraction_hierarchy_query(ContractionHierarchyQuery* contraction_hierarchy_query);
ROUTINGKIT_API unsigned contraction_hierarchy_query_get_distance(ContractionHierarchyQuery* contraction_hierarchy_query);
ROUTINGKIT_API unsigned* contraction_hierarchy_query_get_node_path(ContractionHierarchyQuery* contraction_hierarchy_query, unsigned* num_of_nodes);
ROUTINGKIT_API void contraction_hierarchy_query_free_node_path(unsigned* node_path);
