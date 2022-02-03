//
// Created by lilu on 26/01/2022.
//


#include "TaskManager.h"

TaskManager::TaskManager(size_t threadsCount)
{
    threadsCount = std::max<size_t>(1, threadsCount);


}
TaskQueue::TaskQueue()
{
    std::unique_lock<std::mutex> lk(_mutex);
    _cv.wait(lk, [this](){return !_tasks.empty();});
    while(isWork)
    {
        _cv.wait(lk, [this]()
        {
            return !_tasks.empty();
        });
    }

}

void TaskManager::add(std::shared_ptr<Task> task)
{

}