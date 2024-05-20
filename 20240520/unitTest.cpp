#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <vector>
#include "BookingScheduler.cpp"
#include "Schedule.cpp"
#include "Customer.cpp"

using namespace testing;
using namespace std;
class BookingItem : public testing::Test {
protected:
	void SetUp() override{
		NOT_ON_THE_HOUR = getTime(2021, 3, 26, 9, 5);
		ON_THE_HOUR = getTime(2021, 3, 26, 9, 0);
	}
public:
	tm getTime(int year, int mon, int day, int hour, int min) {
		tm result = { 0,min,hour,day,mon - 1,year - 1900,0,0,-1 };
		mktime(&result);
		return result;
	}

	tm NOT_ON_THE_HOUR;
	tm ON_THE_HOUR;
	Customer CUSTOMER{ "Fake Name", "010-9984-8486" };
};

TEST_F(BookingItem, 정시예약이_아닌경우) 
{
	tm TimeData = getTime(2021, 03, 26, 9, 5);
	Customer customer("Fake Name", "010-9984-8486");
	Schedule *schedule = new Schedule(TimeData, 2, customer);
	BookingScheduler bookScheduler{ 10 };

	EXPECT_THROW(bookScheduler.addSchedule(schedule), std::exception);
}


