//
// Created by lilu on 26/01/2022.
//

#ifndef ZUMA_TASKMANAGER_H
#define ZUMA_TASKMANAGER_H
#include <optional>
#include <functional>
#include <memory>
#include <mutex>
#include <thread>
#include <atomic>
#include <deque>
#include <condition_variable>
#include <queue>

struct Task
{
    std::atomic_bool IsDone;
    std::function<void()> body;
};
class TaskQueue
{
public:
    TaskQueue();
    void add(std::shared_ptr<Task>);
private:
    std::deque<std::shared_ptr<Task>> _tasks;
    std::thread _thread;
    std::condition_variable _cv;
    std::mutex _mutex;
    std::atomic_bool isWork{true};
};

class TaskManager
{
    TaskManager(size_t threadsCount);

    std::queue<std::shared_ptr<Task>> _tasks;
    void UpdateMain();
    std::thread _thread;

    void add(std::shared_ptr<Task> task);
};


#endif //ZUMA_TASKMANAGER_H
