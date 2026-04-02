// murong-sword.c 慕容劍法
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N虛步提腰，上身微微前傾，一式"MAG"「洗耳恭聽」"NOR"，手中$w輕輕顫動，一劍點向$n的$l",
	"lvl"   : 0,
	"skill_name" : "洗耳恭聽"
]),
([	"action" : "$N向前跨上一步，左手劍訣，右手$w使出一式"GRN"「明察秋毫」"NOR"直刺$n的$l",
	"lvl"   : 20,
	"skill_name" : "明察秋毫"
]),
([	"action" : "$N身形往右一挫，左手劍訣，右手$w圈轉如輪，使出一式"BLU "「甜言蜜語」"NOR"，如雪片飄落般向$n削去",
	"lvl"   : 40,
	"skill_name" : "甜言蜜語"
]),
([	"action" : "$N轉身急行數步，雙膝猛地下沉，右手$w匹練般回刺，勁風煞然，劍
氣雄渾已極，正是一式"YEL"「望塵莫及」"NOR"",
	"lvl"   : 60,
	"skill_name" : "望塵莫及"
]),
([	"action" : "$N一招"HIB"「騎虎難下」"NOR"，飛身躍起，兩腿分腿平蹬，$w自上而下劃出一個大弧，平平地向$n的$l揮去",
	"lvl"   : 80,
	"skill_name" : "騎虎難下"
]),
([	"action" : "$N上身往左側一擰，一招"HIC"「拋磚引玉」"NOR"，右手$w反手向$n的$l斜斜揮去",
	"lvl"   : 100,
	"skill_name" : "拋磚引玉"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力不夠。\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 20)
		return notify_fail("你的神元功火候太淺。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 30 )
		return notify_fail("你的內力或氣不夠練慕容劍法。\n");
	if ((int)me->query_skill("parry", 1) < 10)
		return notify_fail("你的招架技能太低，沒法練慕容劍法。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -25);	
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
	int d_e1 = 0;
	int d_e2 = 20;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 130;
	int m_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("murong-sword", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"murong-sword/" + action;
}

int help(object me)
{
	write(HIC"\n慕容劍法："NOR"\n");
	write(@HELP

    慕容劍法為江南姑蘇慕容祖傳劍法。

	學習要求：
		神元功20級
		內力100
HELP
	);
	return 1;
}

