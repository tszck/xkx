// 這是玩家自創武功程序。
// waiter
// 店小二
// 武林至尊逍遙派護法使者
// 15395700
// 男性
// sword
// 龍騰
#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
string owner() {return "waiter";}

mapping *action = ({
});
// ZHAOSHI :0