#ifndef OUTPUTLAYER20180421
#define OUTPUTLAYER20180421

#include "common.h"
#include "weight_point.h"

class OutputLayer {
public:
    OutputLayer(uint32_t pointNum, uint32_t inputNum) : m_points(pointNum, inputNum) {}
private:
   WeightPoints m_points;     
};

#endif //OUTPUTLAYER20180421
