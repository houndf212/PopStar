#ifndef SCORECALCCONTAINER_H
#define SCORECALCCONTAINER_H
#include <list>
#include <map>
#include <mutex>
#include <atomic>
#include "scorecalc.h"

class ScoreCalcContainer
{
public:
    ScoreCalcContainer();
    void addScoreCalc(const ScoreCalc& calc);
    void setPrintStep(int64_t s) { step = s; }
//private:
    int64_t step;
    std::atomic<int64_t> counter;
//    std::map<int, int64_t> scoreMap;
    int maxScore;
    std::list<ScoreCalc> maxList;
private:
    void addCounter();
    void checkScore(const ScoreCalc& sc);
    void printNews();
private:
    std::mutex mutex;
    std::mutex printMutex;
};

#endif // SCORECALCCONTAINER_H
