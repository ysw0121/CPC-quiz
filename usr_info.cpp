#include"usr_info.h"


struct user{
    QString name;
    QString password;
    int times;//比赛次数，0起始，3终止，参与排名的不为0
    int correct;// num of correct ones
    double time;//用时

};
struct question{
    //int seqnum;
    QString quest;
    QChar answer;
    QString option;
};

