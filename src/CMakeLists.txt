cmake_minimum_required(VERSION 3.24)
project(HTT)

set(CMAKE_CXX_STANDARD 17)

add_executable(HTT main.cpp Basic.h Client.h DataPlan.h MobiNet.h Provider.h Serializable.h SmsMax.h String.h Vector.hpp Basic.cpp DataPlan.cpp Client.cpp String.cpp gtest_lite.h MobiNet.cpp DataUsage.cpp DataUsage.h Provider.cpp SmsMax.cpp DataPlanFactory.cpp DataPlanFactory.h)
