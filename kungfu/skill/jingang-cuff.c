// Last Modified by winder on May. 29 2001
// jingang-cuff.c 大金剛拳 不能互備 截自佛經中之“八正道”。

#include <ansi.h>
inherit "/inherit/skill/cuff.c";
string type() { return "martial"; }
string martialtype() { return "skill"; }
 
mapping *action = ({
([	"action" : "$N雙臂一揮，第一式"HIY"「正見」"NOR"打出，以通臂之勢，拳消力不消，勁風直逼$n而去",
	"lvl"   : 0,
	"skill_name" : "正見"
]),
([	"action" : "$N躬腰曲背，左臂一掄，架起一道氣牆，接着右手握拳，對着$n，一招"HIY"「正思」"NOR"穿牆而出",
	"lvl" : 10,
	"skill_name" : "正思"
]),
([	"action" : "$N一個馬步式"HIY"「正業」"NOR"，雙拳凝力，跟着兩臂相併，對準$n$l一式揮出，勁力異常",
	"lvl" : 20,
	"skill_name" : "正業"
]),
([	"action" : "$N使出一招"HIY"「正語」"NOR"，雙臂連連揮動，拳風伴着口中的獅子吼，如猛獸下山般襲向$n",
	"lvl" : 40,
	"skill_name" : "正語"
]),
([	"action" : "$N單臂掄起一式"HIY"「正命」"NOR"打出，接着又是一拳相隨，後浪推前浪，兩波勁力合擊$n",
	"lvl" : 60,
	"skill_name" : "正命"
]),
([	"action" : "$N揮出數拳，正當$n質疑這花拳之勢時，一股勁風爆出，正對$p胸口，是招虛實的"HIY"「正勤」"NOR"",
	"lvl" : 70,
	"skill_name" : "正勤"
]),
([	"action" : "$N口頌佛經，打出一招"HIY"「正念」"NOR"，直轟$n前胸，拳風至剛至陽，正大光明，不帶絲毫陰氣",
 	"lvl" : 80,
	"skill_name" : "正念"
]),
([	"action" : "只見$N合十而立，以這"HIY"「正定」"NOR"一招為本，以身為拳，勁力佈滿全身，重重壓向$n",
	"lvl" : 100,
	"skill_name" : "正定"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		 return notify_fail("練大金剛拳必須空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 140)
		 return notify_fail("你的站樁功火候不夠，無法學大金剛拳。\n");
	if ((int)me->query("max_neili") < 2000)
		return notify_fail("你的內力太弱，無法練大金剛拳。\n");
	if ((me->query_skill("shaolin-cuff", 1) < 50) ||
		(me->query_skill("one-finger", 1) < 50))
		return notify_fail("你的少林南拳和一指禪火候不夠，無法學大金剛拳。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的內力不夠練大金剛拳。\n");
	me->receive_damage("qi", 45);
	me->add("neili", -20);
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
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = -40;
	int p_e2 = -20;
	int f_e1 = 210;
	int f_e2 = 410;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jingang-cuff", 1);
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
		"damage_type" : "瘀傷",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"jingang-cuff/" + action;
}

int help(object me)
{
	write(HIC"\n大金剛拳："NOR"\n");
	write(@HELP

    大金剛拳是南少林高級拳法，出自佛經中之“八正道”。

	學習要求：
		站樁功140級
		少林南拳50級
		一指禪50級
		內力修為2000

HELP
	);
	return 1;
}

