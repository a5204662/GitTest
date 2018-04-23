#ifndef HIDELAYER20180421
#define HIDELAYER20180421

#include "common.h"
#include "weight_point.h"


class HideLayer{
public:
    HideLayer(uint32_t pointSize, uint32_t inputSize) : m_points(pointSize, inputSize) {}
public:
    vector<double> FrontCal(Point point){
        vector<double> weightPointsOutputRes;
        for(uint32_t i = 0; i < m_points.size(); ++i) {
            weightPointsOutputRes.push_back(m_points[i].FrontCal(point));
        } 
    }
    void BackCal(vector<double> deltas) {
        for (uint32_t i = 0; i < m_points.size(); ++i) {
            m_points.BackCal(deltas[i]);
        }
    }
private:
    WeightPoints m_points;
};

#endif
