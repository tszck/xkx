// huoyan-dao.c 火焰刀
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N使出一招"RED"「鑽木取火」"NOR"，飛身急轉，雙掌向前平平拍向$n",
	"skill_name" : "鑽木取火",
	"lvl" : 0
]),
([	"action" : "$N使出一招"HIR"「祝融懷焰」"NOR"，手掌如刀，斜斜劈向$n的$l",
	"skill_name" : "祝融懷焰",
	"lvl" : 10
]),
([	"action" : "$N使出一招"HIR"「風火無邊」"NOR"，雙掌一拍，一道內力自掌中攻向$n的$l",
	"skill_name" : "風火無邊",
	"lvl" : 20
]),
([	"action" : "$N使出一招"RED"「六道輪迴」"NOR"，雙手合十，當頭劈向$n",
	"skill_name" : "六道輪迴",
	"lvl" : 30
]),
([	"action" : "$N使出一招"HIR"「雙龍吐焰」"NOR"，雙掌一錯，兩道內力交叉攻向$n的$l",
	"skill_name" : "雙龍吐焰",
	"lvl" : 40
]),
([	"action" : "$N使出一招"HIB"「刀山火海」"NOR"，雙掌向下斜拍，頓時萬千道內力從四面八方攻向$n",
	"skill_name" : "刀山火海",
	"lvl" : 60
]),
([	"action" : "$N使出一招"RED"「白佛光度」"NOR"，左臂回收，右掌引內力直刺$n的$l",
	"skill_name" : "白佛光度",
	"lvl" : 80
]),
([	"action" : "$N使出一招"RED"「火內蓮花」"NOR"，雙掌微並，兩臂前伸，一道內勁如排山倒海般攻向$n",
	"skill_name" : "火內蓮花",
	"lvl" : 100
]),
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練火焰刀必須空手。\n");

	else if ((int)me->query("max_neili") < 800)
//	火焰刀要有很高的內力才能學
		return notify_fail("你的內力不夠。\n");

	if ((int)me->query_skill("xiaowuxiang", 1) < 60)
		return notify_fail("你的小無相功火候太淺。\n");

	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練火焰刀必須空手。\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("你的體力不夠，練不了火焰刀。\n");
	if ((int)me->query("neili")<40)
		return notify_fail("你的內力不夠，練不了火焰刀。\n");
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
	int d_e2 = -35;
	int p_e1 = -15;
	int p_e2 = 15;
	int f_e1 = 310;
	int f_e2 = 460;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("huoyan-dao", 1);
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
		"damage_type" : "割傷",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"huoyan-dao/" + action;
}

int help(object me)
{
	write(HIR"\n火焰刀："NOR"\n");
	write(@HELP

    火焰刀為雪山大輪寺住持鳩摩智的獨門絕技。
    原為少林七十二絕技之一，後鳩摩智得慕容博相助，得窺少林
絕藝，並輔以小無相功，另創新招。

	學習要求：
		小無相功60級
		內力800
HELP
	);
	return 1;
}

