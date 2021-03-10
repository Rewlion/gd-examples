#pragma once

#include <vector>
#include <functional>

template<class Arg>
class OneParamEvent
{
public:
  typedef std::function<void(Arg)> ListenerCallback;
public:
  inline void Listen(const ListenerCallback& callback)
  {
    assert(callback);
    m_Listeners.push_back(callback);
  }

  inline void operator()(const Arg& arg)
  {
    for (const auto& listenerCallback : m_Listeners)
      listenerCallback(arg);
  }

private:
  std::vector<ListenerCallback> m_Listeners;
};
