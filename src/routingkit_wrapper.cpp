#include <routingkit_wrapper.h>


ROUTINGKIT_API ContractionHierarchy* build_contraction_hierarchy(unsigned node_count, unsigned tail[], unsigned head[], unsigned weight[])
{
    vector<unsigned> tail_vector(tail, tail + node_count);
    vector<unsigned> head_vector(head, head + node_count);
    vector<unsigned> weight_vector(weight, weight + node_count);
    ContractionHierarchy* test = new ContractionHierarchy();
    *test = ContractionHierarchy::build(node_count, tail_vector, head_vector, weight_vector);
    return test;
}