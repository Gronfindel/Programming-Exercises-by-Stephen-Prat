#include "mytime3.h"
Time::Time(){hours=minutes=0;}
Time::Time(int h,int m){hours=h;minutes=m;}
void Time::AddMin(int m){minutes+=m;hours+=minutes/60;minutes%=60;}
void Time::AddHour(int h){hours+=h;}
void Time::Reset(int m,int h){hours=h;minutes=m;}
// Time Time::operator+(const Time &t)const
// {
//     Time summ;
//     summ.minutes=minutes+t.minutes;
//     summ.hours=hours+t.hours+summ.minutes/60;
//     summ.minutes%=60;
//     return summ;
// }
// Time Time::operator-(const Time &t)const
// {
//     Time diff;
//     int tot1,tot2;
//     tot1=t.minutes+60*t.hours;
//     tot2=minutes+60*hours;
//     diff.minutes=(tot2-tot1)%60;
//     diff.hours=(tot2-tot1)/60;
//     return diff;
// }
// Time Time::operator*(double mult)const
// {
//     Time result;
//     long totalminutes=hours*mult*60+minutes*mult;
//     result.hours=totalminutes/60;
//     result.minutes=totalminutes%60;
//     return result;
// }
Time operator+(const Time &t1,const Time &t2)
{
    Time result;
    result.minutes=(t1.minutes+t2.minutes)%60;
    result.hours=(t1.hours+t2.hours)+(t1.minutes+t2.minutes)/60;
    return result;
}
Time operator-(const Time &t1,const Time &t2)
{
    Time result;
    int tot1,tot2;
    tot1=t1.hours*60+t1.minutes;
    tot2=t2.hours*60+t2.minutes;
    result.minutes=(tot1-tot2)%60;
    result.hours=(tot1-tot2)/60;
    return result;
}
Time operator*(const Time &t,double n)
{
    Time result;
    long totalminutes=t.hours*60*n+t.minutes*n;
    result.hours=totalminutes/60;
    result.minutes=totalminutes%60;
    return result;
}
std::ostream &operator<<(std::ostream &os, const Time&t)
{
    os<<t.hours<<" hours, "<<t.minutes<<" minutes";
    return os;
}
Time::~Time(){}