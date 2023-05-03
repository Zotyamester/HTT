cmake_minimum_required(VERSION 3.24)
project(HTT)

set(CMAKE_CXX_STANDARD 17)

add_executable(HTT main.cpp Serializable.h utils/String.h utils/Vector.hpp utils/String.cpp DataUsage.cpp DataUsage.h billing/BillingStrategy.hpp billing/FixedBilling.hpp billing/MultiLevelBilling.hpp billing/DynamicBilling.hpp plan/Plan.cpp plan/PlanFactory.cpp plan/ZoomerNet.cpp plan/Basic.cpp plan/AllInMax.cpp Client.cpp Provider.h Provider.cpp ../../../../../gtest_lite.h)
