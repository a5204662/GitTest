#ifndef INPUTLAYER20180421
#define INPUTLAYER20180421

#include "common.h"
#include "input_point.h"

typedef std::vector<InputPoint> Points;

class InputLayer {
public:
    InputPoint GetPoint(uint32_t index) const {
        if(index < m_points.size()) {
            return m_points[index];
        }
        return InputPoint();
    }
private:
    Points m_points;
};

#endif //INPUTLAYER20180421
