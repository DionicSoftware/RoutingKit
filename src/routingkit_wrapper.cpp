#include <routingkit_wrapper.h>


ROUTINGKIT_API RoutingKit::ContractionHierarchy* build_contraction_hierarchy(unsigned node_count, unsigned edge_count, unsigned tail[], unsigned head[], unsigned weight[]) {
    std::vector<unsigned> tail_vector(tail, tail + edge_count);
    std::vector<unsigned> head_vector(head, head + edge_count);
    std::vector<unsigned> weight_vector(weight, weight + edge_count);
    RoutingKit::ContractionHierarchy* contraction_hierarchy = new RoutingKit::ContractionHierarchy();
    *contraction_hierarchy = RoutingKit::ContractionHierarchy::build(node_count, tail_vector, head_vector, weight_vector);
    return contraction_hierarchy;
}

ROUTINGKIT_API void free_contraction_hierarchy(RoutingKit::ContractionHierarchy* contraction_hierarchy) {
    delete contraction_hierarchy;
}

ROUTINGKIT_API RoutingKit::ContractionHierarchyQuery* build_contraction_hierarchy_query(RoutingKit::ContractionHierarchy* contraction_hierarchy) {
    RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query = new RoutingKit::ContractionHierarchyQuery(*contraction_hierarchy);
    return contraction_hierarchy_query;
}

ROUTINGKIT_API void free_contraction_hierarchy_query(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query) {
    delete contraction_hierarchy_query;
}

ROUTINGKIT_API void reset_contraction_hierarchy_query(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query) {
    contraction_hierarchy_query->reset();
}

ROUTINGKIT_API void contraction_hierarchy_query_add_source(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query, unsigned source, bool* failed) {
    contraction_hierarchy_query->add_source(source, failed);
}

ROUTINGKIT_API void contraction_hierarchy_query_add_target(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query, unsigned target, bool* failed) {
    contraction_hierarchy_query->add_target(target, failed);
}

ROUTINGKIT_API void run_contraction_hierarchy_query(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query) {
    contraction_hierarchy_query->run();
}

ROUTINGKIT_API unsigned contraction_hierarchy_query_get_distance(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query) {
    return contraction_hierarchy_query->get_distance();
}

ROUTINGKIT_API unsigned* contraction_hierarchy_query_get_node_path(RoutingKit::ContractionHierarchyQuery* contraction_hierarchy_query, unsigned* num_of_nodes) {
    std::vector<unsigned> node_path_vector = contraction_hierarchy_query->get_node_path();
    *num_of_nodes = node_path_vector.size();
    unsigned* node_path = new unsigned[node_path_vector.size()];
    std::copy(node_path_vector.begin(), node_path_vector.end(), node_path);
    return node_path;
}

ROUTINGKIT_API void contraction_hierarchy_query_free_node_path(unsigned* node_path) {
    delete[] node_path;
}
