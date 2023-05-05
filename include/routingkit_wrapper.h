#ifndef ROUTINGKIT_WRAPPER
#define ROUTINGKIT_WRAPPER

#include <routingkit/contraction_hierarchy.h>
#include <vector>


#ifdef _MSC_VER
#pragma once
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

ROUTINGKIT_API RoutingKit::ContractionHierarchy* build_contraction_hierarchy(unsigned node_count, unsigned edge_count, unsigned tail[], unsigned head[], unsigned weight[]);
ROUTINGKIT_API void free_contraction_hierarchy(RoutingKit::ContractionHierarchy* contraction_hierarchy);
ROUTINGKIT_API RoutingKit::ContractionHierarchyQuery* build_contraction_hierarchy_query(RoutingKit::ContractionHierarchy* contraction_hierarchy);
ROUTINGKIT_API void free_contraction_hierarchy_query(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query);
ROUTINGKIT_API void reset_contraction_hierarchy_query(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query);
ROUTINGKIT_API void contraction_hierarchy_query_add_source(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query, unsigned source);
ROUTINGKIT_API void contraction_hierarchy_query_add_target(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query, unsigned target);
ROUTINGKIT_API void run_contraction_hierarchy_query(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query);
ROUTINGKIT_API unsigned contraction_hierarchy_query_get_distance(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query);
ROUTINGKIT_API unsigned* contraction_hierarchy_query_get_node_path(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query, unsigned* num_of_nodes);
ROUTINGKIT_API void contraction_hierarchy_query_free_node_path(unsigned* node_path);

#endif
