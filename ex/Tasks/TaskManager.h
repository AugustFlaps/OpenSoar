/* Generated by Together */

#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Util/Serialisable.hpp"
#include "Tasks/TaskInterface.h"
#include "Tasks/AbortTask.h"
#include "Tasks/GotoTask.h"
#include "Tasks/OrderedTask.h"

class TaskManager : public TaskInterface,
 public Serialisable
{
public:
  TaskManager(): mode(MODE_ORDERED)
  {};

    virtual void setActiveTaskPoint(unsigned);

    virtual TaskPoint* getActiveTaskPoint();

  enum TaskMode_t {
    MODE_NULL=0,
    MODE_ORDERED,
    MODE_ABORT,
    MODE_GOTO
  };

  virtual void report(const AIRCRAFT_STATE &location);

  virtual bool update(const AIRCRAFT_STATE &, const AIRCRAFT_STATE&);
  
private:

    /** @link aggregation */
    OrderedTask task_ordered;

    /** @link aggregation */
    GotoTask task_goto;

    /** @link aggregation */
    AbortTask task_abort;

    TaskMode_t mode;
};
#endif //TASKMANAGER_H
