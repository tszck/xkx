// Last Modified by winder on May. 29 2001
// qianye-shou.c 如來千葉手 和韋陀掌互備 截自《佛展千手法》。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIR"「兩手結印」"NOR"，雙手抬起，手心向上，兩大拇指指尖輕輕接觸，向前架起",
	"lvl"   : 0,
	"skill_name" : "兩手結印"
]),
([	"action" : "$N以手印勢抬起，向上轉掌，一式"YEL"「彌勒伸腰」"NOR"，全身逐漸抻直，雙手向$n的方向晃出",
	"lvl"   : 10,
	"skill_name" : "彌勒伸腰"
]),
([	"action" : "$N一式"CYN"「如來灌頂」"NOR"，兩手同時向外轉掌，以手成漏斗狀，接着伸腕落掌，下落$n頂門",
	"lvl"   : 20,
	"skill_name" : "如來灌頂"
]),
([	"action" : "$N提起兩手到胸前，漸漸"BLU"「雙手合十」"NOR"，跟着手心空開，兩肘架起來，兩小臂成一直線直揮$n",
	"lvl"   : 30,
	"skill_name" : "雙手合十"
]),
([	"action" : "$N使一式"HIC"「掌指乾坤」"NOR"，兩掌鬆開轉掌，左手立指在胸前，右手卻掌心向下，拍向$n$l",
	"lvl"   : 40,
	"skill_name" : "掌指乾坤"
]),
([	"action" : "$N一式"HIY"「金猴分身」"NOR"，兩手由胸前拉開向兩側伸展，與$n肩平，接着向兩邊用力一甩",
	"lvl"   : 50,
	"skill_name" : "金猴分身"
]),
([	"action" : "$N兩手一邊分開，一邊向前下方伸展，一式"MAG"「雙龍下海」"NOR"，手臂變幻，在$n胸前印了不下十掌",
	"lvl"   : 60,
	"skill_name" : "雙龍下海"
]),
([	"action" : "$N一式"CYN"「菩薩扶蓮」"NOR"，全身逐漸抻直，手指尖向$n力點，然後全身立即放鬆，兩手恢復到胸前合十",
	"lvl"   : 70,
	"skill_name" : "菩薩扶蓮"
]),
([	"action" : "$N一式"HIG"「羅漢背山」"NOR"，兩手一邊分開，一邊向$n體後伸展，同時兩掌心轉向後方，將$p摔了出去",
	"lvl"   : 80,
	"skill_name" : "羅漢背山"
]),
([	"action" : "$N一式"HIM"「金剛排山」"NOR"，指尖向上，臂與肩同高，當臂伸直後，用力一抻，向$n立掌推出",
	"lvl"   : 90,
	"skill_name" : "金剛排山"
]),
([	"action" : "$N兩手緩緩下落，並將掌心轉向$n腹部，一式"GRN"「疊扣小腹」"NOR"，兩手重疊，猛地放勁",
	"lvl"   : 100,
	"skill_name" : "疊扣小腹"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo){ return combo=="weituo-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練如來千葉手必須空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 20)
		return notify_fail("你的站樁功火候不夠，無法學如來千葉手。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的內力太弱，無法練習如來千葉手。\n");
	if (me->query_skill("fengyun-hand", 1) < 20 ||
		me->query_skill("luohan-cuff", 1) < 20)
		return notify_fail("你還未掌握風雲手和羅漢拳，無法學習如來千葉手。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的內力不夠練如來千葉手。\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = -45;
	int d_e2 = -15;
	int p_e1 = 15;
	int p_e2 = 45;
	int f_e1 = 150;
	int f_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("qianye-hand", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	 return __DIR__"qianye-hand/" + action;
}

int help(object me)
{
	write(HIC"\n如來千葉手："NOR"\n");
	write(@HELP

    如來千葉手是南少林手法，和韋陀掌互備。出自《佛展千手法》。

	學習要求：
		站樁功20級
		羅漢拳20級
		風雲手20級
		內力修為50
HELP
	);
	return 1;
}

