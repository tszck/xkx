// duoming-jinhua.c 奪命金花
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N使一招「金花乍綻」，手中$w疾風般四散飛射$n的$l",
	"lvl" : 0,
	"skill_name" : "金花乍綻",
]),
([	"action":"$N使出「隔日黃花」，雙手猛抖，$w紛飛墜葉般直襲$n的$l",
	"lvl" : 20,
	"skill_name": "隔日黃花",
]),
([	"action":"$N一招「飛雪黃花」，長袖一揮，手中$w風捲殘雪般漫天激
射$n的$l",
	"lvl" : 40,
	"skill_name": "飛雪黃花",
]),
([	"action":"$N手中$w一式「金花耀日」，$w幻作一道白光直奔$n的$l",
	"lvl" : 80,
	"skill_name": "金花耀日",
]),
([	"action":"$N縱身一躍，手中$w一招「遍地黃花」從上向下射向$n全身",
	"lvl" : 100,
	"skill_name":"遍地黃花",
]),
([	"action":"$N手扣$w，身形一晃，憑空一指，一招「金花奪目」灑
向$n的$l",
	"lvl" : 120,
	"skill_name": "金花奪目",
]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的內力不夠，沒有辦法練奪命金花。\n");
	if( me->query_skill("jiuyang-shengong") < 40 )
		return notify_fail("你九陽神功還不到火候，沒法學奪命金花。\n");
	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "throwing" )
		return notify_fail("你必須先找一些飛鏢之類的東西才能練暗器。\n");
	return 1;
}

int valid_enable(string usage) { return usage=="throwing" || usage=="parry"; }

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("qi") < 30 ||(int)me->query("neili") < 3 )
		return notify_fail("你的內力或氣不夠，沒有辦法練習奪命金花。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -3);
//	write("你按著所學練了一遍奪命金花。\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 10;
	int d_e2 = 45;
	int p_e1 = -20;
	int p_e2 = 0;
	int f_e1 = 20;
	int f_e2 = 200;
	int m_e1 = 70;
	int m_e2 = 550;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("duoming-jinhua", 1);
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
		"damage"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
  	"post_action": (: call_other, WEAPON_D, "throw_weapon" :),
		"damage_type" : random(2) ? "內傷" : "瘀傷",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"duoming-jinhua/" + action;
}

int help(object me)
{
	write(HIC"\n奪命金花："NOR"\n");
	write(@HELP

    奪命金花為明教紫衫龍王金花婆婆黛綺絲的絕技。以其狠、毒
而聞名。金花一出，其美無比。

	學習要求：
		九陽神功40級
		內力100
HELP
	);
	return 1;
}

