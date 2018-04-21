#ifndef POINT20180421
#define POINT20180421

#include <stdint.h>
#include <cstring>
#include <vector>

class Point{
public:
    double GetX(uint32_t index) const {
        return m_xs[index];
    }
    double GetB() const {
        return m_b;
    }
    double GetY() const {
        return m_y;
    }

    void SetX(std::vector<double> xsIn) {
        m_xs = xsIn;
    }
    void SetB(double bIn) {
        m_b = bIn;
    }
    void SetY(double yIn) {
        m_y = yIn;
    }

    void ToString() const {
        for(uint32_t i = 0; i < m_xs.size(); ++i) {    
            printf("x%u : %f, ", i, m_xs[i]);
        }
        printf("b : %f, y : %f\n", m_b, m_y);
    }
private:
    std::vector<double> m_xs;
    double m_b;
    double m_y;
};

#endif //POINT20180421
