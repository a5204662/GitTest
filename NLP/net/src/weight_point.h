#ifndef WEIGHTPOINT20180421
#define WEIGHTPOINT20180421

#include "common.h"

typedef std::vector<double> Weights;

class WeightPoint {
public:
    WeightPoint(uint32_t weightSize) : m_weights(weightSize, 0), m_bWeight(0) {}
public:
    void SetWeights(Weights weightsIn) {
        m_weights = weightsIn;
    }
    void SetBWeight(double bWeightIn) {
        m_bWeight = bWeightIn;
    }
private:
    Weights m_weights;
    double m_bWeight;
};

typedef std::vector<WeightPoint> WeightPoints;

#endif //WEIGHTPOINT20180421
