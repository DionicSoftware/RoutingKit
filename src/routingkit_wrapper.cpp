#include <routingkit_wrapper.h>


ROUTINGKIT_API ContractionHierarchy* build_contraction_hierarchy(unsigned node_count, unsigned tail[], unsigned head[], unsigned weight[]) {
    vector<unsigned> tail_vector(tail, tail + node_count);
    vector<unsigned> head_vector(head, head + node_count);
    vector<unsigned> weight_vector(weight, weight + node_count);
    ContractionHierarchy* contraction_hierarchy = new ContractionHierarchy();
    *contraction_hierarchy = ContractionHierarchy::build(node_count, tail_vector, head_vector, weight_vector);
    return contraction_hierarchy;
}

ROUTINGKIT_API void free_contraction_hierarchy(ContractionHierarchy* contraction_hierarchy) {
    delete contraction_hierarchy;
}

ROUTINGKIT_API ContractionHierarchyQuery* build_contraction_hierarchy_query(ContractionHierarchy* contraction_hierarchy) {
    ContractionHierarchyQuery* contraction_hierarchy_query = new ContractionHierarchyQuery(*contraction_hierarchy);
    return contraction_hierarchy_query;
}

ROUTINGKIT_API void free_contraction_hierarchy_query(ContractionHierarchyQuery* contraction_hierarchy_query) {
    delete contraction_hierarchy_query;
}

ROUTINGKIT_API void reset_contraction_hierarchy_query(ContractionHierarchyQuery* contraction_hierarchy_query) {
    contraction_hierarchy_query->reset();
}

ROUTINGKIT_API void contraction_hierarchy_query_add_source(ContractionHierarchyQuery* contraction_hierarchy_query, unsigned source) {
    contraction_hierarchy_query->add_source(source);
}

ROUTINGKIT_API void contraction_hierarchy_query_add_target(ContractionHierarchyQuery* contraction_hierarchy_query, unsigned target) {
    contraction_hierarchy_query->add_target(target);
}

ROUTINGKIT_API void run_contraction_hierarchy_query(ContractionHierarchyQuery* contraction_hierarchy_query) {
    contraction_hierarchy_query->run();
}

ROUTINGKIT_API unsigned contraction_hierarchy_query_get_distance(ContractionHierarchyQuery* contraction_hierarchy_query) {
    return contraction_hierarchy_query->get_distance();
}

ROUTINGKIT_API unsigned* contraction_hierarchy_query_get_node_path(ContractionHierarchyQuery* contraction_hierarchy_query, unsigned* num_of_nodes) {
    vector<unsigned> node_path_vector = contraction_hierarchy_query->get_node_path();
    *num_of_nodes = node_path_vector.size();
    unsigned* node_path = new unsigned[*num_of_nodes];
    std::copy(node_path_vector.begin(), node_path_vector.end(), node_path);
    return node_path;
}

ROUTINGKIT_API void contraction_hierarchy_query_free_node_path(unsigned* node_path) {
    delete[] node_path;
}
