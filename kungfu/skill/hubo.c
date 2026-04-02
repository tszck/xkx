// hubo.c 左右互博
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me) 
{
	if( (int)me->query("int") > 24 )
		return notify_fail("你的天性不適合學習左右互博之術！\n" ) ;
	if( (int)me->query("cps") < 20 )
		return notify_fail("你的天性不適合學習左右互博之術！\n" ) ;
	if( !me->query("double_attack") )
		return notify_fail("左右互博之術要向周伯通討教！\n" ) ;
	if( me->query_skill("qimen-wuxing"))
    return notify_fail("你的雜學太多，一時無法領會左右互博！\n");
	return 1;
}
int help(object me)
{
	write(HIC"\n左右互博："NOR"\n");
	write(@HELP

    左右互搏是周伯通在桃花島被困十五年，苦於沒人拆招，只有
左手和右手打架中無意悟得。其要旨是「心分二用，左手畫方，右
手畫圓」。左右互搏可稱得天下最奇特的武功，能雙手分使不同武
功，同時攻擊敵人。然唯有淳厚質樸之人，能一神守內，一神遊外，
或練過玉女心經，能摒除七情六慾，方能習之。

	學習要求：
		先天悟性不大於24級
		其它天賦條件
HELP
	);
	return 1;
}

