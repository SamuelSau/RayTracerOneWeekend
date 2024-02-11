#ifndef INTERVAL_H
#define INTERVAL_H

#include <limits>

class interval {
public:
    double min, max;

    interval() : min(std::numeric_limits<double>::infinity()), max(-std::numeric_limits<double>::infinity()) {} // Default interval is empty

    interval(double _min, double _max) : min(_min), max(_max) {}

    bool contains(double x) const {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const {
        return min < x && x < max;
    }

    static const interval empty, universe;
};

const interval interval::empty(std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity());
const interval interval::universe(-std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());

#endif