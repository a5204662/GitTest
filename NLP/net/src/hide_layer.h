#ifndef HIDELAYER20180421
#define HIDELAYER20180421

#include "common.h"
#include "weight_point.h"


class HideLayer{
public:
    HideLayer(uint32_t pointSize, uint32_t inputSize) : m_points(pointSize, inputSize) {}
private:
    WeightPoints m_points;
};

#endif
