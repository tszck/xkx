// tianyu-qijian.c 天羽奇劍
// Last Modified by sir 10.22.2001

#include <ansi.h>
#include <xiaoyao.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N使一式"HIC"「海天一線」"NOR"，手中$w嗡嗡微振，幻成一條疾光刺向$n的$l",
	"lvl" : 0,
	"skill_name" : "海天一線"
]),
([	"action":"$N錯步上前，使出"HIM"「閃電驚虹」"NOR"，手中$w劃出一道劍光劈向$n的$l",
	"lvl" : 9,
	"skill_name" : "閃電驚虹"
]),
([	"action":"$N手中$w一抖，一招"HIY"「日在九天」"NOR"，斜斜一劍反腕撩出，攻向$n的$l",
	"lvl" : 18,
	"skill_name" : "日在九天"
]),
([	"action":"$N手中劍鏘啷啷長吟一聲，一式"HIB"「咫尺天涯」"NOR"，一道劍光飛向$n的$l",
	"lvl" : 27,
	"skill_name" : "咫尺天涯"
]),
([	"action":"$N一式"HIR"「怒劍狂花」"NOR"，手中$w舞出無數劍花，使$n難斷虛實，無可躲避",
	"lvl" : 36,
	"skill_name" : "怒劍狂花"
]),
([	"action":"$N手中$w斜指蒼天，劍芒吞吐，一式"BLU"「九弧震日」"NOR"，對準$n的$l斜斜擊出",
	"lvl" : 44,
	"skill_name" : "九弧震日"
]),
([	"action":"$N一式"HIW"「漫天風雪」"NOR"，手腕急抖，揮灑出萬點金光，刺向$n的$l",
	"lvl" : 52,
	"skill_name" : "漫天風雪"
]),
([	"action":"$N一式"GRN"「天河倒瀉」"NOR"，$w飛斬盤旋，如疾電般射向$n的胸口",
	"lvl" : 60,
	"skill_name" : "天河倒瀉"
]),
([	"action":"$N一式"HIG"「天外飛仙」"NOR"，$w突然從天而降，一片金光圍掠$n全身",
	"lvl" : 70,
	"skill_name" : "天外飛仙"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if(((int)me->query_skill("bahuang-gong", 1) < 20 ))
		return notify_fail("你的本門內功還不夠嫺熟。\n");
	if ((int)me->query("max_neili") < 80)
		return notify_fail("你的內力不夠。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 35 )
		return notify_fail("你的內力或氣不夠練天羽奇劍。\n");
	me->receive_damage("qi", 45);
	me->add("neili", -30);
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
	int d_e1 = -15;
	int d_e2 = 5;
	int p_e1 = -45;
	int p_e2 = -25;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 170;
	int m_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tianyu-qijian", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 5; }
int power_point(object me) { 
	if (fam_type(me)=="lingjiu")
	  return 1.4; 
  return 1.0;
}

string perform_action_file(string action)
{
	return __DIR__"tianyu-qijian/" + action;
}
int help(object me)
{
	write(HIC"\n天羽奇劍："NOR"\n");
	write(@HELP

    天羽奇劍為天山靈鷲宮劍法。

	學習要求：
		八荒六合惟我獨尊功20級
		內力80
HELP
	);
	return 1;
}

