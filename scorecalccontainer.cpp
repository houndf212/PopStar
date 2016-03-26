#include "scorecalccontainer.h"
#include <iostream>
#include <chrono>
using namespace std;

ScoreCalcContainer::ScoreCalcContainer()
    :step(10*10000), counter(0), maxScore(0)
{
}

void ScoreCalcContainer::addScoreCalc(const ScoreCalc &calc)
{
    addCounter();
    checkScore(calc);
}

void ScoreCalcContainer::addCounter()
{
    ++counter;
    if (counter % step == 0)
    {
        if (printMutex.try_lock())
        {
            std::unique_lock<std::mutex> lck(printMutex, std::adopt_lock);
            printNews();
        }
    }
}

void ScoreCalcContainer::checkScore(const ScoreCalc &sc)
{
    int s = sc.geScore();
//    ++scoreMap[s];

    if (s < maxScore)
        ;
    else
    {
        std::lock_guard<std::mutex> lck(mutex);
        if (s > maxScore)
        {
            maxScore = s;
            maxList.clear();
            maxList.push_back(sc);
        }
        else if ( s == maxScore)
        {
            maxList.push_back(sc);
        }
    }
}

void ScoreCalcContainer::printNews()
{
    using namespace std::chrono;
    time_t time = system_clock::to_time_t(system_clock::now());
    cout<< ctime(&time);

//    int64_t allsc = 0;
//    for (auto it=scoreMap.cbegin(); it!=scoreMap.cend(); ++it)
//    {
//        allsc += it->first * it->second;
//    }
//    int avg = double(allsc) / counter;
//    cout<<"sum: "<<counter<< ", avg: "<<avg<<endl;
    cout <<"sum: "<<counter<<endl;
    cout<<"max score: "<<maxScore<<", maxlist size: "<<maxList.size()<<endl;
    cout<<"a current solve:"<<endl;
    cout<<*maxList.cbegin();
}

