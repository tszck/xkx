// damo-jian.c 達摩劍
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N使一式"MAG"「萬事隨緣往」"NOR"，手中$w嗡嗡微振，幻成一條疾光刺向$n的$l",
	"lvl" : 0,
	"skill_name" : "萬事隨緣往"
]),
([	"action":"$N錯步上前，使出"HIC"「來去若夢行」"NOR"，劍意若有若無，$w淡淡地向$n的$l揮去",
	"lvl" : 10,
	"skill_name" : "來去若夢行"
]),
([	"action":"$N一式"YEL"「浮世滄桑遠」"NOR"，縱身飄開數尺，運發劍氣，手中$w遙搖指向$n的$l",
	"lvl" : 20,
	"skill_name" : "浮世滄桑遠"
]),
([	"action":"$N縱身輕輕躍起，一式"BLU"「輪迴法舟輕」"NOR"，劍光如輪疾轉，霍霍斬向$n的$l",
	"lvl" : 30,
	"skill_name" : "輪迴法舟輕"
]),
([	"action":"$N手中$w中宮直進，一式"HIW"「水月通禪寂」"NOR"，無聲無息地對準$n的$l刺出一劍",
	"lvl" : 40,
	"skill_name" : "水月通禪寂"
]),
([	"action":"$N手中$w斜指蒼天，劍芒吞吐，一式"HIM"「魚龍聽梵音」"NOR"，對準$n的$l斜斜擊出",
	"lvl" : 50,
	"skill_name" : "魚龍聽梵音"
]),
([	"action":"$N左指凌空虛點，右手$w逼出丈許雪亮劍芒，一式"GRN "「千里一葦去」"NOR"刺向$n的$l",
	"lvl" : 60,
	"skill_name" : "千里一葦去"
]),
([	"action":"$N合掌跌坐，一式"HIG"「禪心頓自明」"NOR"，$w自懷中躍出，如疾電般射向$n的胸口",
	"lvl" : 70,
	"skill_name" : "禪心頓自明"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力不夠。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一氣功火候太淺。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("qi") < 30
	|| (int)me->query("neili") < 15 )
		return notify_fail("你的內力或氣不夠練達摩劍。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -15);
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
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = 0;
	int p_e2 = 20;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 40;
	int m_e2 = 140;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("damo-jian", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"damo-jian/" + action;
}

int help(object me)
{
	write(HIC"\n達摩劍："NOR"\n");
	write(@HELP

    達摩劍為少林七十二絕技之一。

	學習要求：
		混元一氣功20級
		內力100
HELP
	);
	return 1;
}

