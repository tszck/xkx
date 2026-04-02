// Last Modified by winder on May. 29 2001
// wuxiang-finger.c 無相劫指 不能互備
// 取自佛法十二字“廣大，智慧，真如，性海，穎悟，圓覺”。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N將雙手攏在衣袖之中，一招"HIW"「廣大無相劫」"NOR"，暗勁自袖中悄悄湧出，刺向$n",
	"lvl"   : 0,
	"skill_name" : "廣大無相劫" 
]),
([	"action" : "$N微微一笑，一招"HIW"「智慧無相劫」"NOR"，衣袖連擺，指勁隨機彈出，叫人琢磨不透，無法躲避",
	"lvl"   : 10,
	"skill_name" : "智慧無相劫" 
]),
([	"action" : "$N垂手站立，絲毫不動，但聞$n身前哧的一聲，聞聲不見物，是那招"HIW"「真如無相劫」"NOR"",
	"lvl"   : 30,
	"skill_name" : "真如無相劫" 
]),
([	"action" : "$N抬頭往天，一指"HIW"「性海無相劫」"NOR"暗襲$n$l，本人卻見絲毫不動，仿若無事發生一樣",
	"lvl"   : 60,
	"skill_name" : "性海無相劫" 
]),
([	"action" : "$N一招"HIW"「穎悟無相劫」"NOR"向$n點出，聞得一破空之聲，卻見$P微笑點頭，卻再無任何動靜",
	"lvl"   : 100,
	"skill_name" : "穎悟無相劫" 
]),
([	"action" : "但聞哧哧兩聲，$n臉色突變，$N卻悠閒自在，並無動過手的跡象，這好象是那招"HIW"「圓覺無相劫」"NOR"",
	"lvl"   : 150,
	"skill_name" : "圓覺無相劫" 
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練無相劫指必須空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 170)
		return notify_fail("你的站樁功火候不夠，無法學無相劫指。\n");
	if ((int)me->query("max_neili") < 2500)
		return notify_fail("你的內力太弱，無法練無相劫指。\n");
	if (me->query_skill("one-finger", 1) < 50)
		return notify_fail("你的一指禪火候不夠，無法學無相劫指。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 55)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的內力不夠練無相劫指。\n");
	me->receive_damage("qi", 50);
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
	int d_e1 = 10;
	int d_e2 = 30;
	int p_e1 = -45;
	int p_e2 = -25;
	int f_e1 = 450;
	int f_e2 = 550;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wuxiang-finger", 1);
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
		"damage_type" : random(2) ? "刺傷" : "瘀傷",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"wuxiang-finger/" + action;
}

int help(object me)
{
	write(HIC"\n無相劫指："NOR"\n");
	write(@HELP

    無相劫指是南少林高級指法，不能互備，取自佛法十二字“廣大，智慧，
真如，性海，穎悟，圓覺”。

	學習要求：
		站樁功170級
		一指禪50級
		內力修為2500
HELP
	);
	return 1;
}

