//kuangfeng-jian 狂風快劍
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N縱身躍起手中$w輕揮，斬向$n後頸",
	"lvl"    : 0,
	"skill_name" : "風平浪靜"
]),
([	"action" : "$N手中$w連話三個弧形，向$n的右臂齊肩斬落",
	"lvl"    : 20,
	"skill_name" : "風起雲湧"
]),
([	"action" : "$N輕籲一聲，刷刷刷刷四劍，向$n胸，腹，腰，肩四處連刺",
	"lvl"    : 40,
	"skill_name" : "風捲殘雲"
]),
([	"action" : "$N仰天一聲清嘯，斜行向前，$w橫削直擊，迅捷無比，擊向$n的$l",
	"lvl"    : 60,
	"skill_name" : "風流雲散"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; } 
int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的內力不夠。\n");
	if ((int)me->query_skill("huashan-neigong", 1) < 60)
		return notify_fail("你的內功心法火候太淺。\n");
	if ((int)me->query_skill("dodge", 1) < 60)
		return notify_fail("你的輕功火候太淺。\n");
	if ((int)me->query_dex() < 25)
		return notify_fail("你的身法還不夠靈活。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("你的內力或氣不夠練狂風快劍。\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 15;
	int d_e2 = 35;
	int p_e1 = -15;
	int p_e2 = 5;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 80;
	int m_e2 = 180;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("kuangfeng-jian", 1);
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
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "割傷" : "刺傷",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"kuangfeng-jian/" + action;
}
int help(object me)
{
	write(HIC"\n狂風快劍："NOR"\n");
	write(@HELP

    狂風快劍爲華山劍宗的劍法。
    這套“狂風快劍”，是封不平在中條山隱居十五年而創制出來
的得意劍法，劍招一劍快似一劍。他胸懷大志，不但要執掌華山一
派，還想成了華山派掌門人之後，更進而爲五嶽劍派盟主，所憑持
的便是這套一百零八式“狂風快劍”。

	學習要求：
		華山內功60級
		基本輕功60級
		後天身法25以上
		內力300
HELP
	);
	return 1;
}

