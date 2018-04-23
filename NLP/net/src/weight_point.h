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
public:
    //计算一个权重点的正向输出和反向传递。
    double FrontCal(Point point) {
        double sum = 0;
        for(uint32_t i = 0; i < m_weights.size(); ++i) {
            sum += m_weights[i] * point.GetPoint(i);
        }
        return sum + b;
    }

    vector<double> BackCal(Point realPoint, double lr) {
    
    }
    vector<double> BackCal(double delta){
        
    }
private:
    Weights m_weights;
    double m_bWeight;
};

typedef std::vector<WeightPoint> WeightPoints;

#endif //WEIGHTPOINT20180421
