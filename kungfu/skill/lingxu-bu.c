// lingxu-bu 凌虛步
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$n一式"HIW"「雪地蓮花」"NOR"，身子掣忽一轉，$N只覺的眼前一花，失去了目標。\n",
	"$n一式"HIY"「一狐沖天」"NOR"，雙腳點地，身子突然拔高了丈許，緩緩飄落在$N身後。\n",
	"$n一式"CYN"「移行幻影」"NOR"，身行一晃，頓時無數條身影一下子出現在$N的面前。\n",
	"$n一式"MAG"「狡兔三窟」"NOR"，飄然向後一退，躲開$N的凌厲攻勢。\n",
	"$n一式"BLU"「煙雨飄渺」"NOR"，身體急轉，化為一道白光，虛幻不定的出現在$N的周圍。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("baiyun-xinfa", 1) < 10 )
	return notify_fail("你的白雲心法不夠精熟，無法領會凌虛步。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("你的體力太差了，無法能練習凌虛步。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -6);
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.3; }

int help(object me)
{
	write(HIC"\n凌虛步："NOR"\n");
	write(@HELP

    凌虛步為恆山派輕功。

	學習要求：
          白雲心法10級
HELP
	);
	return 1;
}

