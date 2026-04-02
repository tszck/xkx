// tiezhang-zhangfa.c 鐵掌掌法
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N右掌一拂而起，一招"CYN"「推窗望月」"NOR"，自側面連消帶打，登時將$n的力道帶斜。",
	"lvl"    : 0,
	"skill_name" : "推窗望月"
]),
([	"action" : "$N使一招"YEL"「分水擒龍」"NOR"，左掌陡然沿着伸長的右臂，飛快的一削而出，斬向$n的$l",
	"lvl"    : 10,
	"skill_name" : "分水擒龍"
]),
([	"action" : "$N突然使一式"HIW"「白雲幻舞」"NOR"，雙臂如旋風一般一陣狂舞，颳起一陣旋轉的氣浪。 ",
	"lvl"    : 20,
	"skill_name" : "白雲幻舞"
]),
([	"action" : "$N一招"HIY"「掌中乾坤」"NOR"，猛地側過身來，右臂自左肋下疾翻而出，拇，中兩指扣圈猛彈$n的$l",
	"lvl"    : 30,
	"skill_name" : "掌中乾坤"
]),
([	"action" : "$N一招"RED"「落日趕月」"NOR"，伸掌一拍一收，一拍無絲毫力道，一收之間，一股陰柔無比的力道才陡然發出。",
	"lvl"    : 40,
	"skill_name" : "落日趕月"
]),
([	"action" : "$N身行暴起，一式"BLU"「蟄雷為動」"NOR"，雙掌橫橫切出，掌緣才遞出，嗚嗚呼嘯之聲狂作。",
	"lvl"    : 50,
	"skill_name" : "蟄雷為動"
]),
([	"action" : "$N一招"MAG"「天羅地網」"NOR"，左掌大圈而出，右掌小圈而出，兩股奇異的力道一會之下，擊向$n的$l",
	"lvl"    : 60,
	"skill_name" : "天羅地網"
]),
([	"action" : "$N一招"HIG"「五指幻山」"NOR"，猛一吐氣，單掌有如推門，另一掌卻是迅疾無比的一推即收。",
	"lvl"    : 80,
	"skill_name" : "五指幻山"
]),
([	"action" : "$N突然大吼一聲，一招"HIR"「猛虎下山」"NOR"身行疾飛而起，猛向$n直撲而下，空氣中暴出“嗚”的一聲刺耳尖嘯。",
	"lvl"    : 100,
	"skill_name" : "猛虎下山"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練鐵掌掌法必須空手。\n");
	if ((int)me->query_skill("guiyuan-tunafa", 1) < 100)
		return notify_fail("你歸元吐吶法火候不夠，無法練鐵掌掌法。\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的內力修為不夠，無法練鐵掌掌法。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 60)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的內力不夠練鐵掌掌法。\n");
	if (me->query_skill("tiezhang-zhangfa", 1) < 50)
		me->receive_damage("qi", 60);
	else
		me->receive_damage("qi", 55);
	me->add("neili", -35);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -55;
	int d_e2 = -30;
	int p_e1 = -10;
	int p_e2 = 15;
	int f_e1 = 300;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tiezhang-zhangfa", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 獲得招數序號上限 */
			break;
		}
	seq = random(seq);       /* 選擇出手招數序號 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "內傷" : "瘀傷",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"tiezhang-zhangfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lev,damage, i;
	string msg;
	object weap;
	object piece;
	weap = victim->query_temp("weapon");
	lev =me->query("tiezhang-zhangfa");

	if( (me->query("neili") > 1000) &&
		(victim->query_temp("weapon")) &&
		(me->query_temp("tzzf")) &&
		(random(me->query_str()) > victim->query_str()/2) )
	{	
		if (random((int)weap->query("rigidity")) <3)
		{
			message_combatd(HIW"$N運掌如刀，連擊三十六下，只聽見「啪」地一聲，$n手中的" + weap->name() + "已經斷為兩截！\n" NOR, me, victim );
			seteuid(getuid());
			piece = new("/clone/misc/piece");
			piece->set_name("斷掉的" + weap->query("name"),({weap->query("id"),"piece"}));
			piece->move(environment(me));
			destruct(weap);
		}
		else
		{
			message_combatd(HIW"$N運掌如刀，連擊三十六下，只聽見「當」地一聲，$n手中的" + weap->name() + "被刀氣震落到地上！\n" NOR, me,victim );
			weap->move(environment(me));
		}
		victim->reset_action();
		me->add("neili", -100);
		return 1;
	}
}

int help(object me)
{
	write(HIC"\n鐵掌掌法："NOR"\n");
	write(@HELP

    鐵掌掌法是鐵掌幫鎮幫掌法。
    鐵掌掌力渾厚惡毒，與降龍十八掌、黯然銷魂掌並稱天下。


	學習要求：
		歸元吐納法100級
		內力修為1000
HELP
	);
	return 1;
}

