//kuangfeng-blade 狂風刀法
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N手中$w輕揮，一招"+HIW"「風平浪靜」"NOR+"，看似平緩實則迅速地向$n的$l撩去",
	"lvl" : 0,
	"skill_name" : "風平浪靜",
]),
([	"action" : "$N一招"+HIW"「風起雲湧」"NOR+"，右腳一點，$w寒光閃閃，快速湧$n的$l",
	"lvl" : 10,
	"skill_name" : "風起雲湧",
]),
([	"action" : "$N一招"+HIY"「風捲殘雲」"NOR+"，手臂一掄，刀鋒一卷，自上而下斬向$n",
	"lvl" : 20,
	"skill_name" : "風捲殘雲",
]),
([	"action" : "$N一招"+HIC"「風流雲散」"NOR+"，側身而退，$w卻在胸前劃出一道圓弧，橫劈$n的$l",
	"lvl" : 32,
	"skill_name" : "風流雲散",
]),
([	"action" : "$N側身滑步而上，一招"+HIW"「風聲鶴唳」"NOR+"，欺至$n身前，$w猛砍$n的$l",
	"lvl" : 45,
	"skill_name" : "風聲鶴唳",
]),
([	"action" : "$N快速揮舞$w，使出一招"+RED"「風中殘燭」"NOR+"，幻起一片刀花罩向$n的$l",
	"lvl" : 58,
	"skill_name" : "風中殘燭",
]),
([	"action" : "$N一招"+HIC"「風刀霜劍」"NOR+"，只見漫天刀光閃爍，重重刀影向$n的全身湧去",
	"lvl" : 71,
	"skill_name" : "風刀霜劍",
]),
([	"action" : "$N使一招"+HIW"「風馳電掣」"NOR+"，$w舞出陣陣光影向$n的$l湧去",
	"lvl" : 86,
	"skill_name" : "風馳電掣",
]),
([	"action" : "$N一招"+HIB"「風雨飄搖」"NOR+"，$w刀光閃爍不定，似幻似真地逼$n的$l",
	"lvl" : 101,
	"skill_name" : "風雨飄搖",
]),
([	"action" : "$N挪步小退，一招"+HIC"「風花雪月」"NOR+"，手中$w輕描淡寫地揮出一刀，隨即又“唰唰”連劈出兩刀，後發先至，灑向$n的$l",
	"lvl" : 120,
	"skill_name" : "風花雪月",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; } 
int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的內力不夠。\n");
	if ((int)me->query_skill("force", 1) < 60)
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
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不對。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的體力不夠練狂風刀法。\n");
	me->receive_damage("qi", 25);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	if(level >= action[i]["lvl"])
		return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 60;
	int d_e2 = 35;
	int p_e1 = 5;
	int p_e2 = -10;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 30;
	int m_e2 = 140;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("kuangfeng-blade", 1);
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
		"damage_type" : "割傷",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"kuangfeng-blade/" + action;
}
int help(object me)
{
	write(HIC"\n狂風刀法："NOR"\n");
	write(@HELP

    田伯光的快刀。

	學習要求：
		基本內功60級
		基本輕功60級
		後天身法25以上
		內力300
HELP
	);
	return 1;
}

